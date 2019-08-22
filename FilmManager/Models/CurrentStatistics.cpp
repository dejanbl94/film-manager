#include "../stdafx.h"
#include "../Headers/Model Headers/CurrentStatistics.h"

CurrentStatistics::CurrentStatistics(int brojFilmova, int brojPonavljanja, std::string name)
{
	this->brojFilmova = brojFilmova;
	this->brojPonavljanja = brojPonavljanja;
	this->name = name;
}