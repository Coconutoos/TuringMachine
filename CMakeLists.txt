cmake_minimum_required(VERSION 3.22)
project(TuringMachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(TuringMachine main.cpp TuringMachine.cpp TuringMachine.h State.cpp State.h Transition.cpp Transition.h)
