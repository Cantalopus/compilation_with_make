CMakePrintHelpers
-----------------

This module provides convenience commands, primarily intended for debugging,
to print the values of properties and variables.

Load this module in CMake with:

 include(CMakePrintHelpers)

Commands
^^^^^^^^

This module provides the following commands:

.. command:: cmake_print_properties

  Prints the values of properties for the specified targets, source files,
  directories, tests, or cache entries:

  .. code-block:: cmake

    cmake_print_properties(
      <TARGETS       [<targets>...] |
       SOURCES       [<sources>...] |
       DIRECTORIES   [<dirs>...]    |
       TESTS         [<tests>...]   |
       CACHE_ENTRIES [<entries>...] >
      PROPERTIES [<properties>...]
    )

  Exactly one of the scope keywords must be specified.  The scope keyword
  and its arguments must appear before the ``PROPERTIES`` keyword in the
  argument list.

.. command:: cmake_print_variables

  Prints each variable name followed by its value:

  .. code-block:: cmake

    cmake_print_variables([<vars>...])

Examples
^^^^^^^^

Printing the ``LOCATION`` and ``INTERFACE_INCLUDE_DIRECTORIES`` properties for
both targets ``foo`` and ``bar``:

 include(CMakePrintHelpers)

 cmake_print_properties(
   TARGETS foo bar
   PROPERTIES LOCATION INTERFACE_INCLUDE_DIRECTORIES
 )

Gives::

 --
  Properties for TARGET foo:
    foo.LOCATION = "/usr/lib/libfoo.so"
    foo.INTERFACE_INCLUDE_DIRECTORIES = "/usr/include;/usr/include/foo"
  Properties for TARGET bar:
    bar.LOCATION = "/usr/lib/libbar.so"
    bar.INTERFACE_INCLUDE_DIRECTORIES = "/usr/include;/usr/include/bar"

Printing given variables:

 include(CMakePrintHelpers)

 cmake_print_variables(CMAKE_C_COMPILER CMAKE_MAJOR_VERSION NOT_EXISTS)

Gives::

 -- CMAKE_C_COMPILER="/usr/bin/cc" ; CMAKE_MAJOR_VERSION="3" ; NOT_EXISTS=""