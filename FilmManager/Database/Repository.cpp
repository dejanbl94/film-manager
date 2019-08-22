#include "../stdafx.h"
#include "../Headers/Database Headers/Repository.h"
#include "../Headers/Model Headers/Actor.h"
#include "../Headers/Model Headers/Film.h"
#include "../Headers/Model Headers/Category.h"
#include "../Headers/Model Headers/CurrentStatistics.h"
#include <msclr\marshal_cppstd.h>

using namespace System::Data;

Repository::Repository()
{
}

Repository::Repository(ConnectionString con)
{
	cstring = con;
}

MySqlConnection^ Repository::openConnection(std::string serverName, std::string port, std::string username, std::string password)
{
	System::String^ query = gcnew System::String(("datasource='" + serverName + "';port='" + port + "';username='" + username + "';password='" + password + "'").c_str());

	MySqlConnection^ connection = gcnew MySqlConnection(query);
	connection->Open();

	return connection;
}

std::vector<Actor> Repository::getAllActors()
{
	std::vector<Actor>* actVector = new std::vector<Actor>();

	System::String^ firstName;
	System::String^ lastName;
	int id, film_id;

	MySqlCommand^ command = gcnew MySqlCommand("select * from sakila.actor a inner join sakila.film_actor act on a.actor_id = act.actor_id group by a.actor_id", openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	MySqlDataReader^ myReader = command->ExecuteReader();

	while (myReader->Read())
	{
		firstName = (myReader->GetString("first_name"));
		lastName = (myReader->GetString("last_name"));
		id = (myReader->GetInt32("actor_id"));
		film_id = (myReader->GetInt32("film_id"));

		std::string unmanagedFName = msclr::interop::marshal_as<std::string>(firstName);
		std::string unmanagedLName = msclr::interop::marshal_as<std::string>(lastName);

		Actor* ac = new Actor(id, film_id, unmanagedFName, unmanagedLName);
		actVector->push_back(*ac);
	}

	return *actVector;
}

std::vector<Film> Repository::getAllFilms()
{
	std::vector<Film>* filmVector = new std::vector<Film>();//declare a vector  put * to keep native class member in CLR class. This is not allowed directly as well, but you can keep pointer to native class as a member

	int filmId;
	System::String^ title;
	System::String^ releaseYear;
	System::String^ description;
	System::String^ length;

	MySqlCommand^ command = gcnew MySqlCommand("SELECT film_id,title,release_year,length,description FROM sakila.film", openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	MySqlDataReader^ myReader = command->ExecuteReader();

	while (myReader->Read())

	{
		filmId = (myReader->GetInt32("film_id"));
		title = (myReader->GetString("title"));
		releaseYear = (myReader->GetString("release_year"));
		description = (myReader->GetString("description"));
		length = (myReader->GetString("length"));

		std::string unmanagedTitle = msclr::interop::marshal_as<std::string>(title);
		std::string unmanagedRelease = msclr::interop::marshal_as<std::string>(releaseYear);//posto je konstruktor klase actor sa unmanaged stringovima std::string a mi imamo String^ moramo ovo konvertovati u std::string
		std::string unmanagedDesc = msclr::interop::marshal_as<std::string>(description);
		std::string unmanagedLength = msclr::interop::marshal_as<std::string>(length);//posto je konstruktor klase actor sa unmanaged stringovima std::string a mi imamo String^ moramo ovo konvertovati u std::string

		Film* f = new Film(filmId, unmanagedTitle, unmanagedRelease, unmanagedDesc, unmanagedLength);
		filmVector->push_back(*f);
	}

	return *filmVector;
}

std::vector<Category> Repository::getAllCategories()
{
	System::String^ name;
	int id, film_id;

	std::vector<Category> catVector;

	System::String^ query = "select * from sakila.category a inner join sakila.film_category act on a.category_id = act.category_id group by a.category_id"; //kreiran view po zahtjevu iz zadatka, sada ne prikazujemo cijelu tabelu vec samo odredjene kolone
	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));
	MySqlDataReader^ myReader = command->ExecuteReader();

	while (myReader->Read())

	{
		name = (myReader->GetString("name"));
		id = (myReader->GetInt32("category_id"));
		film_id = (myReader->GetInt32("film_id"));

		std::string unmanagedName = msclr::interop::marshal_as<std::string>(name);

		Category* cat = new Category(id, film_id, unmanagedName);
		catVector.push_back(*cat);
	}

	return catVector;
}

//Vraca vektor sastavljen od svih filmova za izabranog glumca (id uzimamo iz current row sa forme)
std::vector<Film> Repository::getAllFilms_Actor(std::string id)
{
	std::vector<Film> filmVector;

	int filmId;
	System::String^ title;
	System::String^ releaseYear;
	System::String^ description;
	System::String^ length;

	System::String^ query = gcnew System::String(("select * from sakila.film_actor a inner join sakila.film f on f.film_id = a.film_id where a.actor_id = '" + id + "';").c_str());
	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	MySqlDataReader^ myReader = command->ExecuteReader();

	while (myReader->Read())
	{
		filmId = (myReader->GetInt32("film_id"));
		title = (myReader->GetString("title"));
		releaseYear = (myReader->GetString("release_year"));
		description = (myReader->GetString("description"));
		length = (myReader->GetString("length"));

		std::string unmanagedTitle = msclr::interop::marshal_as<std::string>(title);
		std::string unmanagedRelease = msclr::interop::marshal_as<std::string>(releaseYear);//posto je konstruktor klase actor sa unmanaged stringovima std::string a mi imamo String^ moramo ovo konvertovati u std::string
		std::string unmanagedDesc = msclr::interop::marshal_as<std::string>(description);
		std::string unmanagedLength = msclr::interop::marshal_as<std::string>(length);//posto je konstruktor klase actor sa unmanaged stringovima std::string a mi imamo String^ moramo ovo konvertovati u std::string

		Film* f = new Film(filmId, unmanagedTitle, unmanagedRelease, unmanagedDesc, unmanagedLength);
		filmVector.push_back(*f);
	}

	return filmVector;
}

std::vector<Film> Repository::getAllFilms_Category(std::string id)
{
	std::vector<Film> filmVector;

	System::String^ query = gcnew System::String(("select * from sakila.film f inner join sakila.film_category cat on f.film_id = cat.film_id where cat.category_id = '" + id + "';").c_str());
	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	int filmId;
	System::String^ title;
	System::String^ releaseYear;
	System::String^ description;
	System::String^ length;

	MySqlDataReader^ myReader = command->ExecuteReader();

	while (myReader->Read())
	{
		filmId = (myReader->GetInt32("film_id"));
		title = (myReader->GetString("title"));
		releaseYear = (myReader->GetString("release_year"));
		description = (myReader->GetString("description"));
		length = (myReader->GetString("length"));

		std::string unmanagedTitle = msclr::interop::marshal_as<std::string>(title);
		std::string unmanagedRelease = msclr::interop::marshal_as<std::string>(releaseYear);//posto je konstruktor klase actor sa unmanaged stringovima std::string a mi imamo String^ moramo ovo konvertovati u std::string
		std::string unmanagedDesc = msclr::interop::marshal_as<std::string>(description);
		std::string unmanagedLength = msclr::interop::marshal_as<std::string>(length);//posto je konstruktor klase actor sa unmanaged stringovima std::string a mi imamo String^ moramo ovo konvertovati u std::string

		Film* f = new Film(filmId, unmanagedTitle, unmanagedRelease, unmanagedDesc, unmanagedLength);
		filmVector.push_back(*f);
	}

	return filmVector;
}

Film Repository::getFilmById(std::string id)
{
	System::String^ query = gcnew System::String(("SELECT title,release_year,length,description,film_id FROM sakila.film where film_id = " + id + ";").c_str());
	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	MySqlDataReader^ myReader = command->ExecuteReader();
	myReader->Read();

	int film_id = (myReader->GetInt32("film_id"));
	System::String^ release_year = (myReader->GetString("release_year"));
	System::String^ length = (myReader->GetString("length"));
	System::String^ description = (myReader->GetString("description"));
	System::String^ title = (myReader->GetString("title"));

	std::string unmanagedTitle = msclr::interop::marshal_as<std::string>(title);
	std::string unmanagedRelease = msclr::interop::marshal_as<std::string>(release_year);//posto je konstruktor klase actor sa unmanaged stringovima std::string a mi imamo String^ moramo ovo konvertovati u std::string
	std::string unmanagedDesc = msclr::interop::marshal_as<std::string>(description);
	std::string unmanagedLength = msclr::interop::marshal_as<std::string>(length);//posto je konstruktor kl

	return Film(film_id, unmanagedTitle, unmanagedRelease, unmanagedDesc, unmanagedLength);
}

void Repository::updateFilm(Film f)
{
	int id = f.id; std::string idString = std::to_string(id);

	System::String^ query = gcnew System::String(("UPDATE sakila.film SET title = '" + f.title + "',release_year =" + f.releaseYear + ",length = " + f.length + ",description = '" + f.description + "' WHERE film_id = " + idString + ";").c_str());
	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	MySqlDataReader^ myReader = command->ExecuteReader();
}

CurrentStatistics Repository::getCurrentStats()
{
	std::vector<CurrentStatistics>* filmVector = new std::vector<CurrentStatistics>();

	MySqlCommand^ command = gcnew MySqlCommand("SELECT * FROM sakila.currentStats_view", openConnection(cstring.server, cstring.port, cstring.username, cstring.password));/*napravio view jer ne moze dve komande odvojeno da radi na jedan event*/

	MySqlDataReader^ myReader = command->ExecuteReader();
	myReader->Read();

	int brojFilmova = (myReader->GetInt32("brojFilmova"));
	int brojPonavljanja = (myReader->GetInt32("brojPonavljanja"));
	System::String^ name = (myReader->GetString("name"));

	std::string unmanagedName = msclr::interop::marshal_as<std::string>(name);

	//Pravimo pokazivac na objekat
	CurrentStatistics* stats = new CurrentStatistics(brojFilmova, brojPonavljanja, unmanagedName);

	return *stats;
}

void Repository::deleteActor(std::string id)
{
	System::String^ query = gcnew System::String(("DELETE FROM sakila.actor WHERE actor_id ='" + id + "';").c_str());

	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));
}

void Repository::deleteFilm(std::string id)
{
	System::String^ query = gcnew System::String(("DELETE FROM sakila.film WHERE film_id ='" + id + "';").c_str());
	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	MySqlDataReader^ myReader = command->ExecuteReader();
}

void Repository::insertFilm(Film film)
{
	System::String^ query = gcnew System::String(("INSERT INTO sakila.film (title,length,release_year,description) values('" + film.title + "','" + film.length + "','" + film.releaseYear + "','" + film.description + "');").c_str());
	MySqlCommand^ command = gcnew MySqlCommand(query, openConnection(cstring.server, cstring.port, cstring.username, cstring.password));

	MySqlDataReader^ myReader = command->ExecuteReader();
}

void Repository::insertActor(Actor actor)
{
	throw gcnew System::NotImplementedException();
}

void Repository::insertCategory(Category cat)
{
	throw gcnew System::NotImplementedException();
}

void Repository::updateActor(Actor actor)
{
	throw gcnew System::NotImplementedException();
}

void Repository::updateCategory(Category category)
{
	throw gcnew System::NotImplementedException();
}