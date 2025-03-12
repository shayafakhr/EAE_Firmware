#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <net/if.h>
#include <cstring>
#include <unistd.h>
#include <iostream>

int main() {
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;

    int socket_can = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    strcpy(ifr.ifr_name, "can0"); // Use virtual interface can0

    ioctl(socket_can, SIOCGIFINDEX, &ifr);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(socket_can, (struct sockaddr *)&addr, sizeof(addr));

    frame.can_id = 0x123;
    frame.can_dlc = 2;
    frame.data[0] = 0xAB;
    frame.data[1] = 0xCD;

    write(socket_can, &frame, sizeof(struct can_frame));
    std::cout << "Sent CAN frame: 0x123 with data [0xAB, 0xCD]" << std::endl;

    close(socket_can);
    return 0;
}
