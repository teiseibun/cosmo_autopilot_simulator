#include <iostream>

#include "fg_link.hpp"

using namespace std;

void flightgear_link_udp::connect_receiver(char *ip_addr, int port)
{
	this->out.ip_addr = ip_addr;
	this->out.port = port;

	this->out.socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	//create the sockaddr_in struct
	this->out.socket_addr_in.sin_family = AF_INET;
	this->out.socket_addr_in.sin_port = htons(this->out.port);
	this->out.socket_addr_in.sin_addr.s_addr = inet_addr(this->out.ip_addr);

 	//determinate the size of the sockaddr_in struct
	this->out.socket_addr_size = sizeof(this->out.socket_addr_in);

	//initialize a sockaddr struct pointer from sockaddr_in struct
	this->out.socket_addr = (struct sockaddr *)&this->out.socket_addr_in;
}

void flightgear_link_udp::connect_transmitter(char *ip_addr, int port)
{
	this->in.ip_addr = ip_addr;
	this->in.port = port;

	this->in.socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	//create the sockaddr_in struct
	this->in.socket_addr_in.sin_family = AF_INET;
	this->in.socket_addr_in.sin_port = htons(this->in.port);
	this->in.socket_addr_in.sin_addr.s_addr = inet_addr(this->in.ip_addr);

 	//determinate the size of the sockaddr_in struct
	this->in.socket_addr_size = sizeof(this->in.socket_addr_in);

	//initialize a sockaddr struct pointer from sockaddr_in struct
	this->in.socket_addr = (struct sockaddr *)&this->in.socket_addr_in;

	if (bind(this->in.socket_fd, this->in.socket_addr, this->in.socket_addr_size) == -1) {
		printf("bind failed\n");
	}
}

int flightgear_link_udp::send(const void *msg, int size)
{
	int ret = sendto(this->out.socket_fd, msg, size, MSG_CONFIRM,
			 this->out.socket_addr, this->out.socket_addr_size);

	return ret;
}

int flightgear_link_udp::recv(void *msg, int size, socklen_t *addr_len)
{
	char buff[100] = {0};

	int ret = recvfrom(this->in.socket_fd, buff, 100, 0,
			   this->in.socket_addr, addr_len);

	//printf("test:%d\n", ret);

	return ret;
}

int flightgear_link_udp::_close()
{
	return close(this->out.socket_fd);
	return close(this->in.socket_fd);
}

int flightgear_link_udp::send_ctl(flightgear_ctl_data *ctl)
{
	return send(ctl, sizeof(*ctl));
}

int flightgear_link_udp::recv_onboard(flightgear_recv_data *_recv)
{
	socklen_t addr_len;
	return recv(_recv, sizeof(*_recv), &addr_len);
}
