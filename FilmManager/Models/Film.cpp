#include "../stdafx.h"
#include "../Headers/Model Headers/Film.h"

Film::Film(int id, std::string title, std::string releaseYear, std::string description, std::string length)
{
	this->id = id;
	this->title = title;
	this->releaseYear = releaseYear;
	this->description = description;
	this->length = length;
}

//konstruktor za insert filma bez id-a
Film::Film(std::string title, std::string releaseYear, std::string description, std::string length)
{
	this->title = title;
	this->releaseYear = releaseYear;
	this->description = description;
	this->length = length;
}