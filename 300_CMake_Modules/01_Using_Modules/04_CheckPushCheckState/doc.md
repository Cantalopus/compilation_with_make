CMakePushCheckState
-------------------

This module provides commands for managing the state of variables that influence
how various CMake check commands (e.g., ``check_symbol_exists()``, etc.)
are performed.

Load this module in a CMake project with:

 include(CMakePushCheckState)

This module provides the following commands, which are useful for scoped
configuration, for example, in CMake modules or when performing checks in a
controlled environment, ensuring that temporary modifications are isolated
to the scope of the check and do not propagate into other parts of the build
system:

* ``cmake_push_check_state()``
* ``cmake_reset_check_state()``
* ``cmake_pop_check_state()``

Affected Variables
^^^^^^^^^^^^^^^^^^

The following CMake variables are saved, reset, and restored by this module's
commands:  
  
|Variable |	What it controls |
|:-|:-|
|CMAKE_REQUIRED_FLAGS|	Compiler flags|
|CMAKE_REQUIRED_DEFINITIONS|	Preprocessor definitions|
|CMAKE_REQUIRED_INCLUDES|	Include search paths|
|CMAKE_REQUIRED_LIBRARIES|	Libraries to link|
|CMAKE_REQUIRED_LINK_OPTIONS|	Linker options|
|CMAKE_REQUIRED_LINK_DIRECTORIES|	Library search paths|
|CMAKE_REQUIRED_QUIET|	Check-related status messages|
|CMAKE_EXTRA_INCLUDE_FILES|	Additional headers for certain checks|

``CMAKE_REQUIRED_FLAGS``
  A space-separated string of additional flags to pass to the compiler.
  A :ref:`semicolon-separated list <CMake Language Lists>` will not work.
  The contents of ``CMAKE_<LANG>_FLAGS`` and its associated
  configuration-specific ``CMAKE_<LANG>_FLAGS_<CONFIG>`` variables
  are automatically prepended to the compiler command before the contents of
  this variable.

``CMAKE_REQUIRED_DEFINITIONS``
  A :ref:`semicolon-separated list <CMake Language Lists>` of compiler
  definitions, each of the form ``-DFOO`` or ``-DFOO=bar``.  A definition for
  the name specified by the result variable argument of the check
  command is also added automatically.

``CMAKE_REQUIRED_INCLUDES``
  A :ref:`semicolon-separated list <CMake Language Lists>` of header
  search paths to pass to the compiler.  These will be the only header
  search paths used; the contents of the ``INCLUDE_DIRECTORIES``
  directory property will be ignored.

``CMAKE_REQUIRED_LINK_OPTIONS``
  .. versionadded:: 3.14

  A :ref:`semicolon-separated list <CMake Language Lists>` of options to
  add to the link command (see ``try_compile()`` for further details).

``CMAKE_REQUIRED_LIBRARIES``
  A :ref:`semicolon-separated list <CMake Language Lists>` of libraries to
  add to the link command.  These can be the names of system libraries, or
  they can be :ref:`Imported Targets` (see ``try_compile()`` for further
  details).

``CMAKE_REQUIRED_LINK_DIRECTORIES``
  .. versionadded:: 3.31

  A :ref:`semicolon-separated list <CMake Language Lists>` of library search
  paths to pass to the linker (see ``try_compile()`` for further
  details).

``CMAKE_REQUIRED_QUIET``
  .. versionadded:: 3.1

  If this variable evaluates to a boolean true value, all status messages
  associated with the check will be suppressed.

``CMAKE_EXTRA_INCLUDE_FILES``
  .. versionadded:: 3.6
    Previously used already by the ``check_type_size()`` command;  now
    also supported by this module.

  A :ref:`semicolon-separated list <CMake Language Lists>` of extra header
  files to include when performing the check.

.. note::

  Other CMake variables, such as ``CMAKE_<LANG>_FLAGS``, propagate
  to all checks regardless of commands provided by this module, as those
  fundamental variables are designed to influence the global state of the
  build system.

Commands
^^^^^^^^

.. command:: cmake_push_check_state

  Pushes (saves) the current states of the above variables onto a stack:

  .. code-block:: cmake

    cmake_push_check_state([RESET])

  Use this command to preserve the current configuration before making
  temporary modifications for specific checks.

  ``RESET``
    When this option is specified, the command not only saves the current states
    of the listed variables but also resets them to empty, allowing them to be
    reconfigured from a clean state.

.. command:: cmake_reset_check_state

  Resets (clears) the contents of the variables listed above to empty states:

  .. code-block:: cmake

    cmake_reset_check_state()

  Use this command when performing multiple sequential checks that require
  entirely new configurations, ensuring no previous configuration
  unintentionally carries over.

.. command:: cmake_pop_check_state

  Restores the states of the variables listed above to their values at the time
  of the most recent ``cmake_push_check_state()`` call:

  .. code-block:: cmake

    cmake_pop_check_state()

  Use this command to revert temporary changes made during a check.  To
  prevent unexpected behavior, pair each ``cmake_push_check_state()`` with a
  corresponding ``cmake_pop_check_state()``.

Examples
^^^^^^^^

Example: Isolated Check With Compile Definitions
""""""""""""""""""""""""""""""""""""""""""""""""

In the following example, a check for the C symbol ``memfd_create()`` is
performed with an additional ``_GNU_SOURCE`` compile definition,  without
affecting global compile flags.  The ``RESET`` option is used to ensure
that any prior values of the check-related variables are explicitly cleared
before the check.

 include(CMakePushCheckState)

 # Save and reset the current state
 cmake_push_check_state(RESET)

 # Perform check with specific compile definitions
 set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE)
 include(CheckSymbolExists)
 check_symbol_exists(memfd_create "sys/mman.h" HAVE_MEMFD_CREATE)

 # Restore the original state
 cmake_pop_check_state()

Example: Nested Configuration Scopes
""""""""""""""""""""""""""""""""""""

In the following example, variable states are pushed onto the stack multiple
times, allowing for sequential or nested checks.  Each
``cmake_pop_check_state()`` restores the most recent pushed states.

 include(CMakePushCheckState)

 # Save and reset the current state
 cmake_push_check_state(RESET)

 # Perform the first check with additional libraries
 set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_DL_LIBS})
 include(CheckSymbolExists)
 check_symbol_exists(dlopen "dlfcn.h" HAVE_DLOPEN)

 # Save current state
 cmake_push_check_state()

 # Perform the second check with libraries and additional compile definitions
 set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE)
 check_symbol_exists(dladdr "dlfcn.h" HAVE_DLADDR)

 message(STATUS "${CMAKE_REQUIRED_DEFINITIONS}")
 # Output: -D_GNU_SOURCE

 # Restore the previous state
 cmake_pop_check_state()

 message(STATUS "${CMAKE_REQUIRED_DEFINITIONS}")
 # Output here is empty

 # Reset variables to prepare for the next check
 cmake_reset_check_state()

 # Perform the next check only with additional compile definitions
 set(CMAKE_REQUIRED_DEFINITIONS -D_GNU_SOURCE)
 check_symbol_exists(dl_iterate_phdr "link.h" HAVE_DL_ITERATE_PHDR)

 # Restore the original state
 cmake_pop_check_state()