CheckIncludeFile
----------------

This module provides a command to check C header file.

Load this module in a CMake project with:

 include(CheckIncludeFile)

Commands
^^^^^^^^

This module provides the following command:

.. command:: check_include_file

  Checks once whether a header file exists and can be included in C code:

  .. code-block:: cmake

    check_include_file(<include> <variable> [<flags>])

  .. rubric:: The arguments are:

  ``<include>``
    A header file to be checked.

  ``<variable>``
    The name of the variable to store the result of the check.  This
    variable will be created as an internal cache variable.

  ``<flags>``
    (Optional) A space-separated string of
    additional compilation flags to be added to the check.  Alternatively,
    flags can be also specified with the ``CMAKE_REQUIRED_FLAGS`` variable
    below.

  .. rubric:: Variables Affecting the Check

  The following variables may be set before calling this command to modify
  the way the check is run:

  .. include:: /module/include/CMAKE_REQUIRED_FLAGS.rst

  .. include:: /module/include/CMAKE_REQUIRED_DEFINITIONS.rst

  .. include:: /module/include/CMAKE_REQUIRED_INCLUDES.rst

  .. include:: /module/include/CMAKE_REQUIRED_LINK_OPTIONS.rst

  .. include:: /module/include/CMAKE_REQUIRED_LIBRARIES.rst

  .. include:: /module/include/CMAKE_REQUIRED_LINK_DIRECTORIES.rst

  .. include:: /module/include/CMAKE_REQUIRED_QUIET.rst

  .. versionadded:: 3.12
    The ``CMAKE_REQUIRED_LIBRARIES`` variable, if policy ``CMP0075`` is
    set to ``NEW``.

Examples
^^^^^^^^

Example: Checking C Header
""""""""""""""""""""""""""

Checking whether the C header ``<unistd.h>`` exists and storing the check
result in the ``HAVE_UNISTD_H`` cache variable:

 include(CheckIncludeFile)

 check_include_file(unistd.h HAVE_UNISTD_H)

Example: Isolated Check
"""""""""""""""""""""""

In the following example, this module is used in combination with the
``CMakePushCheckState`` module to temporarily modify the required
compile definitions (via ``CMAKE_REQUIRED_DEFINITIONS``) and verify whether
the C header ``<ucontext.h>`` is available.  The result is stored
in the internal cache variable ``HAVE_UCONTEXT_H``.

For example, on macOS, the ``ucontext`` API is deprecated, and headers may
be hidden unless certain feature macros are defined.  In particular,
defining ``_XOPEN_SOURCE`` (without a value) can expose the necessary
symbols without enabling broader POSIX or SUS (Single Unix Specification)
features (values 500 or greater).

 include(CheckIncludeFile)
 include(CMakePushCheckState)

 cmake_push_check_state(RESET)
   if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
     set(CMAKE_REQUIRED_DEFINITIONS -D_XOPEN_SOURCE)
   endif()

   check_include_file(ucontext.h HAVE_UCONTEXT_H)
 cmake_pop_check_state()

See Also
^^^^^^^^

* The ``CheckIncludeFileCXX`` module to check for single C++ header.
* The ``CheckIncludeFiles`` module to check for one or more C or
  C++ headers at once.