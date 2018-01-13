/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Warp client: sends presents
*/

#ifndef WARPCLIENT_HPP_
	#define WARPCLIENT_HPP_

	#include <vector>
	#include <iostream>

	#include <netdb.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <sys/socket.h>
	#include <netinet/in.h>

	#include "WarpServer.hpp"

class WarpClient
{
public:
	WarpClient();
	~WarpClient();

	void receiveAddr();

	int sendMessage(const std::string &message);

protected:

private:
	std::vector<std::string> _addrList;
	std::string _listenerAddr;
	int _listenerPort;
	WarpServer *_addrListener;

	int _sockFD;
	struct sockaddr_in _saddr;
};

#endif /* !WARPCLIENT_HPP_ */
