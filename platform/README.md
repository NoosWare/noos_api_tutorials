# Platform Tutorial

For connecting our program to the Cloud Platform we have to specify a few parameters
to the [`callable` object](../callable/README.md).

For this purpose, the `platform` variable has been created.
It is composed of the following parameters:

- `address`: It is the IP or domain name where the platform is allocated. `demo.noos.cloud` is the domain name of the Noos Cloud Platform.
- `port`: It is the port of the platform. `9001` is the open port for the Noos Cloud Platform
- `token`: It is the password that you obtained when you sign up to [Noos Cloud](https://noos.cloud/)
- `user`: It is the user that you obtained when you sign up to [Noos Cloud](https://noos.cloud/)

__IMPORTANT__
In order to access the platform you need to sign up [here](https://noos.cloud/) and in your profile
you will find the `user` and the `token` data that you need to connect to the platform.

In order to fill the `platform` object with the data, there are 2 ways:
- Initialize directly in the code

```cpp
    noos::cloud::platform your_platform = {"demo.noos.cloud", "9001", "your_password", "your_username"};
```

- Load a file with the data in a JSON format

file `.json`

```shell
{
    "platform" : { "address" : "demo.noos.cloud",
                   "port" : "9001",
                   "token" : "my_password",
                   "user" : "my_user"
                 }
}

```

And in the code, you just have to call the following method:

```cpp
	noos::cloud::platform your_platform;
	your_platform()("path/my_file.json");
```

In the examples you can find a variable called `default_node`. This is a platform object used for tests and it is limited.
You have to create your own platform object.
