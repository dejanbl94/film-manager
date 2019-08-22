#pragma once
#include <string>
public class CurrentStatistics
{
public:

	int brojFilmova, brojPonavljanja;
	std::string name;

	CurrentStatistics(int brojFilmova, int brojPonavljanja, std::string name);
};