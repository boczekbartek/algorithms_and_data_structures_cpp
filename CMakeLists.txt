cmake_minimum_required (VERSION 3.15)
project (algorithms_and_data_structures_cpp)
set(Boost_NO_BOOST_CMAKE ON)
enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(BOOST_INCLUDE_DIRS /usr/local/include/boost/include)

add_executable(vector vector.cpp)
target_include_directories(vector PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(vector ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# declares a test with our executable
add_test(NAME test_vector COMMAND vector)