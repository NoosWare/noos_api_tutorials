# Keep Alive Tutorial

`Keep_alive` is a parameter used to indicate if the platform has to leave the connection opened to receive more
calls or not.

For example, if we are going to call a service repeatly in a program, the value of this variable has to be `true`.
Otherwise, if the service is going to be called only once the value has to be `false`.

In the case of call multiple times the same service with the parameter being `false`, the result will be that the 
platform will open and close multiple connections, which is a bad practise.

The opposite is keep `true` a connection which is going to be called only once. In this case, the platform will close 
the connection after a while. 

This parameter is set up when the `callable` object is created. 
For more information about `callable` you can check [this tutorial](../callable/README.md) 
