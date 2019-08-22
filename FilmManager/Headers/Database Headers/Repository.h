#pragma once
#include <vector>
#include <string>
#include "../Model Headers/Category.h"
#include "../Model Headers/Actor.h"
#include "../Model Headers/Film.h"
#include "../Model Headers/CurrentStatistics.h"
#include "../Database Headers/ConnectionString.h"

using namespace MySql::Data::MySqlClient;

public class Repository {
public:

	std::string connectionString = "datasource=localhost;port=3306;username=root;password=root";
	ConnectionString cstring;

public:

	Repository();
	Repository(ConnectionString con);

	MySqlConnection^ openConnection(std::string serverName, std::string port, std::string username, std::string password);

	//Getting data from db
	std::vector<Actor> getAllActors();
	std::vector<Category> getAllCategories();
	std::vector<Film> getAllFilms();
	std::vector<Film> getAllFilms_Actor(std::string id);
	std::vector<Film> getAllFilms_Category(std::string id);

	Film getFilmById(std::string id);
	CurrentStatistics getCurrentStats();

	//Insert
	void insertFilm(Film film);

	//Update
	void updateFilm(Film f);

	//Delete
	void deleteActor(std::string id);
	void deleteFilm(std::string id);

	//nisu implementirane
	void insertActor(Actor actor);
	void insertCategory(Category cat);

	void updateActor(Actor actor);
	void updateCategory(Category category);
};