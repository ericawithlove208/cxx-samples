cmake_minimum_required(VERSION 3.10)

project(cxx-samples)

add_definitions(-Dtrace)

add_executable(mergeSort sort/mergeSort.cxx)
add_executable(BalancedTreeTest balancedTree/BalancedTreeTest.cxx)
