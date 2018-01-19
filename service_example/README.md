# Example
-----

_Noos API has to be installed._ 
You can find it [here](https://github.com/ortelio/noos-api-cpp)

Now we have all the pieces together, you can run your first example:

`main.cpp` is in `src/main.cpp`.

```cpp
#include <noos/noos>
#include <iostream>
// 
// Example to detect faces in a picture
// 
int main()
{
    using namespace noos::cloud;
    // 
    // An image is loaded from a PNG on disk.
    // 
    auto pic = noos::object::picture("../data/lenna.png");
    // 
    // We make a callable object of face_detection class 
    // and send the query to the platform to detect faces 
    // For more information @see noos::cloud::face_detection
    // In this example, we use an inline lambda which will print
    // the coordinates of detected faces.
    // We also specify that we won't keep alive the connection, using `false`
    // as the second template parameter.
    // 
    auto callback = [&](std::vector<noos::object::face> faces) { 
                        std::cout << "faced detected: " << faces.size() << std::endl;
                    };
	// Change the variable `default_node` for your own `platform` object
    callable<face_detection, false> query(callback, default_node, pic);
    query.send();
    return 0;
}
```

`CMakeLists.txt`

```cpp
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
```

In the `CMakeLists.txt` file, the _Noos API_ and the _its dependencies_ are included.
Also a cmake flag is added to be sure that C++14 is used.

To run the example:

```shell
cd noos_api_tutorials/service_example
mkdir build
cd build
cmake ..
make
./face_detection
```
