#pragma once
#include <vector>
#include "Category.h"
#include "Actor.h"

public class Film {
public:

	int id;
	std::string title;
	std::string releaseYear;
	std::string description;
	std::string length;

	Film(int film_id, std::string title, std::string releaseYear, std::string description, std::string length);
	Film(std::string title, std::string releaseYear, std::string description, std::string length);

	bool operator<(const Film& rhs) const { return title < rhs.title; } //overload operatora < , ReloadDataGrid() metod u filmmain form, sortiranje po title
};