#include <iostream>

#include "fg_link.hpp"

using namespace std;

flightgear_link_udp::flightgear_link_udp(char *ip_addr, int port)
{
	this->ip_addr = ip_addr;
	this->port = port;

	this->socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	//create the sockaddr_in struct
	this->socket_addr_in.sin_family = AF_INET;
	this->socket_addr_in.sin_port = htons(this->port);
	this->socket_addr_in.sin_addr.s_addr = inet_addr(this->ip_addr);

 	//determinate the size of the sockaddr_in struct
	this->socket_addr_size = sizeof(this->socket_addr_in);

	//initialize a sockaddr struct pointer from sockaddr_in struct
	this->socket_addr = (struct sockaddr *)&this->socket_addr_in;
}

int flightgear_link_udp::send(const void *msg, int size)
{
	int ret = sendto(this->socket_fd, msg, size, MSG_CONFIRM,
			 this->socket_addr, this->socket_addr_size);

	return ret;
}

int flightgear_link_udp::_close()
{
	return close(this->socket_fd);
}

int flightgear_link_udp::send_ctl(flightgear_ctl_data *ctl)
{
	send(ctl, sizeof(*ctl));
}
