#enable_testing()
#find_package(GTest REQUIRED)

add_executable(${TEST_EXE} 
  test_random.cxx
)

#set(SRC_EXE "../src/random.cxx")

message(STATUS "Test: ${TEST_EXE}")

target_link_libraries(${TEST_EXE} ${LIBRARY_NAME} -lgsl -lgslcblas -lgtest -lgtest_main -lpthread)