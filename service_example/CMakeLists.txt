cmake_minimum_required(VERSION 2.8)
project(example)

add_executable(face_detection src/main.cpp)

find_package(noos REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads REQUIRED)

include_directories(${NOOS_INCLUDE_DIRS})

target_link_libraries(face_detection ${NOOS_LIBRARIES}
					  ${OPENSSL_LIBRARIES} 
					  ${Boost_LIBRARIES}
					  ${CMAKE_THREAD_LIBS_INIT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
