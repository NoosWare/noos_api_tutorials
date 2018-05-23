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
    // We need to create a platform object with our user and password for using 
    // the NOOS Cloud 
    // IMPORTANT: You have to change your user and password. The example doesn't work
    //
    platform node = {"demo.noos.cloud", "9001", "your_pass", "your_user"};

	// Change the variable `default_node` for your own `platform` object
    callable<face_detection, false> query(callback, node, pic);
    query.send();
    return 0;
}
