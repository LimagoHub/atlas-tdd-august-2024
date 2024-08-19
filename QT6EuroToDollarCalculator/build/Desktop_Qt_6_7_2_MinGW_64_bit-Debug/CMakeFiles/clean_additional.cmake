# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QT6EuroToDollarCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QT6EuroToDollarCalculator_autogen.dir\\ParseCache.txt"
  "QT6EuroToDollarCalculator_autogen"
  "tests\\CMakeFiles\\QT6EuroToDollarCalculatorTest_autogen.dir\\AutogenUsed.txt"
  "tests\\CMakeFiles\\QT6EuroToDollarCalculatorTest_autogen.dir\\ParseCache.txt"
  "tests\\QT6EuroToDollarCalculatorTest_autogen"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_autogen.dir\\ParseCache.txt"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\ParseCache.txt"
  "tests\\google\\googlemock\\gmock_autogen"
  "tests\\google\\googlemock\\gmock_main_autogen"
  "tests\\google\\googletest\\CMakeFiles\\gtest_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googletest\\CMakeFiles\\gtest_autogen.dir\\ParseCache.txt"
  "tests\\google\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\ParseCache.txt"
  "tests\\google\\googletest\\gtest_autogen"
  "tests\\google\\googletest\\gtest_main_autogen"
  )
endif()
