cmake_minimum_required(VERSION 3.22)
project(TuringMachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(TuringMachine main.cpp State.cpp TuringMachine.cpp Transition.cpp App.cpp App.h)
