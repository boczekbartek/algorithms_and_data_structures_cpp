cmake_minimum_required (VERSION 3.15)
project (algorithms_and_data_structures_cpp)
set(Boost_NO_BOOST_CMAKE ON)
enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(BOOST_INCLUDE_DIRS /usr/local/include/boost/include)

# ------------- vector -------------
add_executable(test_vector vector/vector.cpp)
target_include_directories(test_vector PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(test_vector ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME test_vector COMMAND test_vector)
# --------------------------------

# ------------- heap -------------
add_executable(test_heap heap/heap.cpp)
target_include_directories(test_heap PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(test_heap ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME test_heap COMMAND test_heap)
# --------------------------------

# ------------- heap -------------
add_executable(test_int2int_hashmap hash_map/hash_map.cpp)
target_include_directories(test_int2int_hashmap PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(test_int2int_hashmap ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(NAME test_int2int_hashmap COMMAND test_int2int_hashmap)
# --------------------------------
