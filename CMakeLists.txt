cmake_minimum_required(VERSION 3.25)
project(Snackautomat)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snackautomat main.cpp Ware.h Snack.cpp Snack.h Getraenk.cpp Getraenk.h Ware.cpp Platz.cpp Platz.h Snackautomat.cpp Snackautomat.h)
