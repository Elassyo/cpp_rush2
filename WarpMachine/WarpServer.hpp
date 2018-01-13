/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Warp server: receives presents
*/

#ifndef WARPSERVER_HPP_
	#define WARPSERVER_HPP_

	#include <iostream>

	#include <netdb.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <sys/socket.h>
	#include <netinet/in.h>

class WarpServer
{
public:
	WarpServer(const std::string &addr, int port);
	void init();
	~WarpServer();

	void sendAddr() const;
	int sendMessage(const std::string &message);

	std::string receiveMessage();
	void setTimeout(const unsigned int ms = 0);

protected:

private:
	int _sockFD;
	std::string _addr;
	int _port;
	struct sockaddr_in _saddr;
};

#endif /* !WARPSERVER_HPP_ */
