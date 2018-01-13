/*
** EPITECH PROJECT, 2018
** cpp_rush2
** File description:
** Client implementation
*/

#include "WarpClient.hpp"

WarpClient::WarpClient()
	: _listenerAddr("239.42.42.42"), _listenerPort(4221),
	_addrListener(new WarpServer(_listenerAddr, _listenerPort))
{
	memset(&_saddr, 0, sizeof(struct sockaddr_in));
	_sockFD = socket(AF_INET, SOCK_DGRAM, 0);
	if (_sockFD < 1) {
		std::cerr << "Could not create client socket" << std::endl;
		return;
	}
	_saddr.sin_family = AF_INET;
	_saddr.sin_port = htons(0);
	_saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(_sockFD, (struct sockaddr *)&_saddr, sizeof(_saddr))) {
		std::cerr << "Could not bind client socket with interfaces";
		std::cerr << std::endl;
		close(_sockFD);
	}
}

WarpClient::~WarpClient()
{
	delete _addrListener;
	close(_sockFD);
}

void WarpClient::receiveAddr()
{
	_addrListener->setTimeout(50);
	std::string ret;
	while ((ret = _addrListener->receiveMessage()) != "") {
		std::vector<std::string>::iterator it;
		for (it = _addrList.begin(); it != _addrList.end(); it++) {
			if (*it == ret)
				return;
		}
		_addrList.push_back(ret);
	}
	_addrListener->setTimeout();
}

int WarpClient::sendMessage(const std::string &message)
{
	_saddr.sin_family = AF_INET;
	_saddr.sin_port = htons(4242);

	std::vector<std::string>::iterator it;
	for (it = _addrList.begin(); it != _addrList.end(); it++) {
		_saddr.sin_addr.s_addr = inet_addr((*it).c_str());
		if (sendto(_sockFD, message.c_str(), message.size(), 0,
			   (struct sockaddr *)&_saddr, sizeof(_saddr)) == -1)
			return (-1);
	}
	return (1);
}
