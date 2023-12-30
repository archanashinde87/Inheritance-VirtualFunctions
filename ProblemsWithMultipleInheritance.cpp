// ProblemsWithMultipleInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class USBDevice
{
private:
    long m_id{};

public:
    USBDevice(long id)
        :m_id{ id }
    {}
    long getId() const { return m_id; }
};
class NetworkDevice
{
private:
    long m_id{};

public:
    NetworkDevice(long id)
        :m_id{ id }
    {}
    long getId() const { return m_id; }

};
class WirelessAdapter : public USBDevice, public NetworkDevice
{
public:
    WirelessAdapter(long usbId, long networkId)
        : USBDevice{usbId}
        , NetworkDevice{networkId}
    {}
};
int main()
{
    WirelessAdapter c54g{ 5442, 181742 };
    //std::cout << c54g.getId() << '\n'; // Which getID() do we call?

    std::cout << c54g.USBDevice::getId() << '\n';
    std::cout << c54g.NetworkDevice::getId() << '\n';

    return 0;
}

