#include "../stdafx.h"
#include "../Headers/Model Headers/Actor.h"

Actor::Actor(int id, int film_id, std::string name, std::string lastName) {
	this->id = id;
	this->film_id = film_id;
	this->name = name;
	this->lastName = lastName;
}