cmake_minimum_required(VERSION 3.23)
project(listCLass)

set(CMAKE_CXX_STANDARD 14)

add_executable(listCLass main.cpp LinkedList.cpp LinkedList.h Stack.cpp PostfixCalculator.cpp Stack.h PostfixCalculator.h Queue.cpp Queue.h Parser.cpp Parser.h InfixCalculator.cpp InfixCalculator.h)
