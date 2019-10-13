#include <iostream>
#include <cstdio>

#include "fg_link.hpp"

using namespace std;

float float_swap_endian(float value)
{
	int temp = htonl(*(unsigned int*)&value);
	return *(float*)&temp;
}

int main()
{
	flightgear_link_udp fg_link;
	fg_link.connect_receiver((char *)"127.0.0.1", 6789);
	fg_link.connect_transmitter((char *)"127.0.0.1", 6666);

	flightgear_ctl_data fg_ctl = {0};
	flightgear_recv_data fg_recv = {0};

	/* receiver test */
	while(1) {
		int ret = fg_link.recv_onboard(&fg_recv);

		fg_recv.roll = float_swap_endian(fg_recv.roll);
		fg_recv.pitch = float_swap_endian(fg_recv.pitch);
		fg_recv.yaw = float_swap_endian(fg_recv.yaw);

		printf("roll:%lf pitch:%lf yaw:%lf\n", fg_recv.roll, fg_recv.pitch, fg_recv.yaw);
	}

	cout << "0: turn off engine\n"
		"1: turn on engine\n"
		"------------------\n";

	/* sender test */
	while(1) {
		char c = getc(stdin);

		if(c == '0') {
			cout << "[flightgear]engine off\n";	
			fg_ctl.starter = false;
			fg_link.send_ctl(&fg_ctl);
		} else if (c == '1') {
			cout << "[flightgear]engine on\n";
			fg_ctl.starter = true;
			fg_link.send_ctl(&fg_ctl);
		}
	}

	return 0;
}
