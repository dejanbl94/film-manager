#include "../stdafx.h"
#include "../Headers/Database Headers/ConnectionString.h"

ConnectionString::ConnectionString()
{
}

ConnectionString::ConnectionString(std::string server, std::string port, std::string username, std::string password)
{
	this->server = server;
	this->port = port;
	this->username = username;
	this->password = password;
}