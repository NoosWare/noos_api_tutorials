# Callable Tutorials

`noos::cloud::callable` is the most important class of the API because is the one in charge of comunicating with the Cloud Platform.

Every `callable` object needs:
- `cloud_type` object: `cloud_type` is the service which it is going to be called. 
- `callback` functor: `callback` has to be the correct type according to the service called.

The object can change if you use the same service more than once and you need to send different information to 
the platform. However, the callback can't be modified for the same `callable` object.

This class is templated, so some parameters have to be specified:
- `cloud_type`: the name of the class you are going to use
- `keep_alive`: boolean for keep the connection open in the platform in case you reuse the same callable object to do multiples calls
- `socket_type`: the type of connection which is going to be used. This parameter is defined by default to `asio_https`. So it is not neccessary to write it unless you need to change the value of the next parameter. _NOTE_: `asio_http` option is allow too, although the platform is going to reject the connection.
- `error_handler`: is the class or struct which is going to handle the errors obtained by the communication with the platform. It is set by default to `default_error_handler` class. You can check the documentation [here](https://docs.noos.cloud/0.8.3/structnoos_1_1cloud_1_1default__error__handler.php).

Once the object has been initialized, the information can be sent to the platform.
It has different constructors which you can check [here](https://docs.noos.cloud/0.8.3/classnoos_1_1cloud_1_1callable.php).
__WARNING: Copy constructor, assing and move the object are not allowed.__

For example, to check the services which are availables in the platform, the service `available_services` will return a `std::vector<std::string>` with all the services.

```cpp
    using namespace noos::cloud;

    /*
     * `callback` is defined before creating the `callable` object.
     * It is going to print all the services that the platform has.
     */
    auto callback = [](std::vector<std::string> services) {
         std::cout << "available services: " << std::endl;
         for (const auto name : services) {
            std::cout << name << std::endl;
         }
     };
    // We need to create a platform object with our user and password for using 
    // the NOOS Cloud 
    // IMPORTANT: You have to change your user and password. The example doesn't work
    //
    platform node = {"demo.noos.cloud", "9001", "your_pass", "your_user"};

    /*
     * `callable` object is created specifying the name of the service
     * `available_services`, `keep_alive` is `false` in this case, due to
     * the service is going to be called only once, the callback and the
     * `node`(explained in `platform` tutorial).
     */
    callable<available_services,false> query(callback, node);

    /*
     * Finally the information is sent to the platform
     */
    query.send(2);
```

