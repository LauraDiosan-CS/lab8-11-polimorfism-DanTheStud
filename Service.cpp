#include "Service.h"
#include <algorithm>
#include "Artist.h"
#include "Film.h"
#include "RepositoryException.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"

using namespace std;

Service::Service()
{
	this->repository = NULL;
}

Service::Service(Repository* repository)
{
	this->repository = repository;
}

Service::~Service()
{
	if (this->repository != NULL)
	{
		delete this->repository;
	}
}

vector<Festival*> Service::get_all()
{
	return this->repository->get_all();
}

Festival* Service::get_festival_at_position(int pos) throw(RepositoryException)
{
	return this->repository->get_festival(pos);
}

void Service::add_artist(string nume, string data, string locatie, int numar_locuri_valabile, int numar_locuri_vandute) throw(ValidationException, RepositoryException)
{
	Artist* artist = new Artist(nume, data, locatie, numar_locuri_valabile, numar_locuri_vandute);
	this->repository->add_festival(artist);
}

void Service::add_film(string titlu, string actori, string data, string locatie, int numar_locuri_valabile, int numar_locuri_vandute) throw(ValidationException, RepositoryException)
{
	Film* film = new Film(titlu, actori, data, locatie, numar_locuri_valabile, numar_locuri_vandute);
	this->repository->add_festival(film);
}

void Service::update_artist(string old_data, string old_locatie, string new_nume, string new_data, string new_locatie, int new_numar_locuri_valabile, int new_numar_locuri_vandute) throw(ValidationException, RepositoryException)
{
	Artist* artist_vechi = new Artist("", old_data, old_locatie, 0, 0);
	Artist* artist_new = new Artist(new_nume, new_data, new_locatie, new_numar_locuri_valabile, new_numar_locuri_vandute);

	this->repository->update_festival(artist_vechi, artist_new);
}

void Service::update_film(string old_data, string old_locatie, string new_titlu, string new_actori, string new_data, string new_locatie, int new_numar_locuri_valabile, int new_numar_locuri_vandute) throw(ValidationException, RepositoryException)
{
	Film* film_vechi = new Film("", "", old_data, old_locatie, 0, 0);
	Film* film_new = new Film(new_titlu, new_actori, new_data, new_locatie, new_numar_locuri_valabile, new_numar_locuri_vandute);

	this->repository->update_festival(film_vechi, film_new);
}

void Service::delete_festival(string data, string locatie, int numar_locuri_disponibile, int numar_locuri_vandute)
{
	Festival* festival = new Festival(data, locatie, numar_locuri_disponibile, numar_locuri_vandute);
	this->repository->delete_festival(festival);
}

void Service::load_from_file()
{
	this->repository->load_from_file();
}

void Service::save_to_file()
{
	this->repository->save_to_file();
}

void Service::set_file_name(string new_file_name)
{
	this->repository->set_file_name(new_file_name);
}

void Service::set_repository(Repository* repository)
{
	this->repository = repository;
}
