#pragma once
#include <string>

public class Category {
public:
	int id;
	std::string name;
	int film_id;

	Category(int id, int film_id, std::string name);
};