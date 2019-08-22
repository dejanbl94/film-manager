#include "../stdafx.h"
#include "../Headers/Model Headers/Category.h"

#pragma once

Category::Category(int id, int film_id, std::string name) {
	this->id = id;
	this->film_id = film_id;
	this->name = name;
}