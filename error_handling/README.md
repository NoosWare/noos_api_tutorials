# Error Handling Tutorial
-----

NOOS API has its own error handler. It reads if there have been any error in the communication
with the platform, and it throws an exception if it detects an error. It will stop the program
and print the error in the terminal.

However, you need to handler the error in another way or clasify them, etc. In this case, you can
create your own error handler.

In the following code an example has been done to show you how to add your error handler:

```cpp
#include <noos/noos>
#include <iostream>
// 
// Example to create a custom error handler
// 

/*
 * A new struct to handle the errors about communication
 * with the platform
 */
struct my_error_handler
{
    /* This method is compulsory. It will manage the errors */
    void operator()(boost::system::error_code & error) const
    {
        if (error.value() != 0) {
            std::cout << "Error value: " << error.value() <<
                        " Error message: " << error.message() << std::endl; 
        }
        else {
            std::cout << "Success" << std::endl;
        }
    }
};

int main()
{
    using namespace noos::cloud;
    // 
    // An image is loaded from a PNG on disk.
    // 
    auto pic = noos::object::picture("path/to/your_image.png");
    // 
    // We make a callable object of face_detection class 
    // and send the query to the platform to detect faces 
    // For more information @see noos::cloud::face_detection
    // In this example, we use an inline lambda which will print
    // the coordinates of detected faces.
    //      
    auto callback = [&](std::vector<noos::object::face> faces) { 
                        std::cout << "faced detected: " << faces.size() << std::endl;
                    };

    // We need to create a platform object with our user and password for using 
    // the NOOS Cloud 
    // IMPORTANT: You have to change your user and password. The example doesn't work
    //
    platform node = {"demo.noos.cloud", "9001", "your_pass", "your_user"};

    //
    // For adding our error handler, we have to specify all the template parameters
    // that callable class needs. For more information @see noos::cloud::callable
    //
    callable<face_detection,
             false,
             asio_https,
             my_error_handler> query(callback, 
                                     node, 
                                     pic);

    query.send(2);
    return 0;
}
```

In the example the new error handler just print the error in the terminal or `success` if not.
The difference here is that the constructor of `callable` needs to specify all the template parameters 
(`service`, `keep_alive`, `socket_type` and `error_handler`).
