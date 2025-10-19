cmake_minimum_required(VERSION 4.0)
project(rastorant_danshgoe)

set(CMAKE_CXX_STANDARD 11)

add_executable(rastorant_danshgoe
        main.cpp
        rastorant-danshgoe.cpp
        MenuItem.h
        OrderItem.h
        StudentOrder.h
        RestaurantSystem.h
        MenuItem.cpp
        OrderItem.cpp
        StudentOrder.cpp
        ReataurantSystem.cpp)
