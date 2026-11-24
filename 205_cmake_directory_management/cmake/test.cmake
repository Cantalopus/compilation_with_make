message(STATUS "Hello from cmake/test.cmake!")
message([[Naming the file with the postfix .cmake is only conventional, 
the include() command will include any file you'd like included.]])
message(STATUS "CMAKE_SOURCE_DIR in cmake/test.cmake: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR in cmake/test.cmake: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR in cmake/test.cmake: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR in cmake/test.cmake: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_PROJECT_DESCRIPTION in cmake/test.cmake: ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "PERSON_NAME from end of cmake/test.cmake: ${PERSON_NAME}")

# Prints directory of the current file
message(STATUS [[${CMAKE_CURRENT_LIST_DIR}: Prints 
the location of this file 
from cmake/test.cmake:]] " ${CMAKE_CURRENT_LIST_FILE}")