#include <iostream>
#include <cstdio>

#include "fg_link.hpp"

using namespace std;

int main()
{
	flightgear_link_udp fg_link;
	fg_link.connect_receiver((char *)"127.0.0.1", 6789);
	fg_link.connect_transmitter((char *)"127.0.0.1", 6666);

	cout << "0: turn off engine\n"
		"1: turn on engine\n"
		"------------------\n";

	flightgear_ctl_data fg_ctl = {0};

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
