#ifndef __FG_LINK_HPP__
#define __FG_LINK_HPP__

#include <cstdio> 
#include <cstdlib> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

typedef struct {
	double mixture;
	double throttle;
	double aileron;
	double elevator;
	double rudder;
	int magnetos;
	bool starter;
} flightgear_ctl_data;

class flightgear_link_udp {
	public:
	flightgear_link_udp(char* ip_addr, int port);
	int _close();
	int send_ctl(flightgear_ctl_data *ctl);

	private:
	struct sockaddr_in socket_addr_in;
	struct sockaddr *socket_addr;
	int socket_addr_size;
	char *ip_addr;
	int port;
	int  socket_fd;

	private:
	int send(const void *msg, int size);
};

#endif
