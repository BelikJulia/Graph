# CMake generated Testfile for 
# Source directory: E:/pp_2020_spring/modules/test_tasks/test_omp
# Build directory: E:/pp_2020_spring/build/modules/test_tasks/test_omp
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_omp_omp "E:/pp_2020_spring/build/bin/test_omp_omp.exe")
  set_tests_properties(test_omp_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_omp_omp "E:/pp_2020_spring/build/bin/test_omp_omp.exe")
  set_tests_properties(test_omp_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_omp_omp "E:/pp_2020_spring/build/bin/MinSizeRel/test_omp_omp.exe")
  set_tests_properties(test_omp_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_omp_omp "E:/pp_2020_spring/build/bin/RelWithDebInfo/test_omp_omp.exe")
  set_tests_properties(test_omp_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/test_tasks/test_omp/CMakeLists.txt;0;")
else()
  add_test(test_omp_omp NOT_AVAILABLE)
endif()
