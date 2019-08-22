#pragma once
#include<string>
public class ConnectionString
{
public:

	std::string server;
	std::string port;
	std::string username;
	std::string password;

	ConnectionString();
	ConnectionString(std::string server, std::string port, std::string username, std::string password);
};