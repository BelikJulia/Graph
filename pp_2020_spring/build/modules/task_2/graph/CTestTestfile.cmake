# CMake generated Testfile for 
# Source directory: E:/pp_2020_spring/modules/task_2/graph
# Build directory: E:/pp_2020_spring/build/modules/task_2/graph
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(graph_omp "E:/pp_2020_spring/build/bin/graph_omp.exe")
  set_tests_properties(graph_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(graph_omp "E:/pp_2020_spring/build/bin/graph_omp.exe")
  set_tests_properties(graph_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(graph_omp "E:/pp_2020_spring/build/bin/MinSizeRel/graph_omp.exe")
  set_tests_properties(graph_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(graph_omp "E:/pp_2020_spring/build/bin/RelWithDebInfo/graph_omp.exe")
  set_tests_properties(graph_omp PROPERTIES  _BACKTRACE_TRIPLES "E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;19;add_test;E:/pp_2020_spring/modules/task_2/graph/CMakeLists.txt;0;")
else()
  add_test(graph_omp NOT_AVAILABLE)
endif()
