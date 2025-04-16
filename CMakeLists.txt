cmake_minimum_required(VERSION 3.10)
project(OrderEngine)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Source files
add_executable(order_engine
    src/main.cpp
    src/order_book.cpp
)
