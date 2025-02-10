#include <iostream>
#include <thread>

#include "crazyflieLinkCpp/Connection.h"
#include "PacketUtils.hpp"

using namespace bitcraze::crazyflieLinkCpp;

int main()
{
    Connection connection("radio://*/80/2M/E7E7E7E7E7");


    for (int i = 0; i < 10; ++i) {
        std::cout << "Sending cmdLegacy" << std::endl;
        connection.send(PacketUtils::cmdLegacy(0, 0, 10.0, 32000));
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
   
    connection.close();
    std::cout << "Done." << std::endl;
    return 0;
}