#pragma once
#include<string>
public class Actor
{
public:

	int id;
	int film_id;
	std::string name;
	std::string lastName;

	Actor::Actor(int id, int film_id, std::string name, std::string lastName);
};