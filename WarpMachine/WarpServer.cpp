/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Server implementation
*/

#include "WarpServer.hpp"

WarpServer::WarpServer(const std::string &addr, int port)
	: _addr(addr), _port(port)
{
	struct ip_mreq imreq;

	_sockFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
	if (_sockFD == -1) {
		std::cerr << "Could not create server socket" << std::endl;
		return;
	}
	this->init();
	memset(&imreq, 0, sizeof(struct ip_mreq));
	if (bind(_sockFD, (struct sockaddr *)&_saddr, sizeof(_saddr))) {
		std::cerr << "Could not bind server socket with: \""
			<< _addr << ":" << _port << "\"" << std::endl;
		close(_sockFD);
		return;
	}
	imreq.imr_multiaddr.s_addr = inet_addr(_addr.c_str());
	imreq.imr_interface.s_addr = INADDR_ANY;
	setsockopt(_sockFD, IPPROTO_IP, IP_ADD_MEMBERSHIP, &imreq,
		   sizeof(struct ip_mreq));
}

void WarpServer::init()
{
	int value = 1;

	setsockopt(_sockFD, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));
	memset(&_saddr, 0, sizeof(struct sockaddr_in));
	_saddr.sin_family = AF_INET;
	_saddr.sin_port = htons(_port);
	_saddr.sin_addr.s_addr = inet_addr(_addr.c_str());
}

WarpServer::~WarpServer()
{
	close(_sockFD);
}

void WarpServer::setTimeout(const unsigned int ms)
{
	struct timeval tout;

	if (ms == 0) {
		tout.tv_sec = 0;
		tout.tv_usec = 0;
	} else {
		tout.tv_sec = ms / 1000;
		tout.tv_usec = (ms % 1000) * 1000;
	}
	setsockopt(_sockFD, SOL_SOCKET, SO_RCVTIMEO, &tout, sizeof(tout));
}

void WarpServer::sendAddr() const
{
	struct sockaddr_in saddr;
	int sockFD;
	memset(&saddr, 0, sizeof(struct sockaddr_in));
	if ((sockFD = socket(AF_INET, SOCK_DGRAM, 0)) < 1) {
		std::cerr << "Could not create addrListener" << std::endl;
		return;
	}
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(0);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sockFD, (struct sockaddr *)&saddr, sizeof(saddr)) == -1) {
		std::cerr << "Could not bind addrListener" << std::endl;
		close(sockFD);
		return;
	}
	saddr.sin_port = htons(4221);
	saddr.sin_addr.s_addr = inet_addr("239.42.42.42");
	sendto(sockFD, _addr.c_str(), _addr.size(), 0,
	       (struct sockaddr *)&saddr, sizeof(saddr));
	close(sockFD);
}

std::string WarpServer::receiveMessage()
{
	int max_size = 65507;
	char buff[max_size];
	int size = sizeof(struct sockaddr_in);

	memset(buff, 0, max_size);
	recvfrom(_sockFD, buff, max_size - 1, 0,
		 (struct sockaddr *)&_saddr, (socklen_t *)&size);
	std::string ret(buff);
	return (ret);
}
