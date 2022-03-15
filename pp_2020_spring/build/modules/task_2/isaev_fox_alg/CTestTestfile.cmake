# CMake generated Testfile for 
# Source directory: E:/pp_2020_spring/modules/task_2/isaev_fox_alg
# Build directory: E:/pp_2020_spring/build/modules/task_2/isaev_fox_alg
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(isaev_fox_alg_omp "E:/pp_2020_spring/build/bin/isaev_fox_alg_omp.exe")
  set_tests_properties(isaev_fox_alg_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(isaev_fox_alg_omp "E:/pp_2020_spring/build/bin/isaev_fox_alg_omp.exe")
  set_tests_properties(isaev_fox_alg_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(isaev_fox_alg_omp "E:/pp_2020_spring/build/bin/MinSizeRel/isaev_fox_alg_omp.exe")
  set_tests_properties(isaev_fox_alg_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(isaev_fox_alg_omp "E:/pp_2020_spring/build/bin/RelWithDebInfo/isaev_fox_alg_omp.exe")
  set_tests_properties(isaev_fox_alg_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/isaev_fox_alg/CMakeLists.txt;0;")
else()
  add_test(isaev_fox_alg_omp NOT_AVAILABLE)
endif()
