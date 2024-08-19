# Install script for directory: C:/Users/JoachimWagner/Documents/git/Atlas/tdd/atlas-tdd-august-2024/QT6EuroToDollarCalculator/tests/google/googlemock

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/QT6EuroToDollarCalculator")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/applications/Qt67/Tools/mingw1120_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/Users/JoachimWagner/Documents/git/Atlas/tdd/atlas-tdd-august-2024/QT6EuroToDollarCalculator/tests/google/googlemock/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/JoachimWagner/Documents/git/Atlas/tdd/atlas-tdd-august-2024/QT6EuroToDollarCalculator/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/lib/libgmock.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/JoachimWagner/Documents/git/Atlas/tdd/atlas-tdd-august-2024/QT6EuroToDollarCalculator/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/lib/libgmock_main.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/JoachimWagner/Documents/git/Atlas/tdd/atlas-tdd-august-2024/QT6EuroToDollarCalculator/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/tests/google/googletest/generated/gmock.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/JoachimWagner/Documents/git/Atlas/tdd/atlas-tdd-august-2024/QT6EuroToDollarCalculator/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/tests/google/googletest/generated/gmock_main.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/JoachimWagner/Documents/git/Atlas/tdd/atlas-tdd-august-2024/QT6EuroToDollarCalculator/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/tests/google/googletest/cmake_install.cmake")

endif()

