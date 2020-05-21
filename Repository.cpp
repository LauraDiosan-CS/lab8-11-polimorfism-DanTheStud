#include <typeinfo>
#include "Repository.h"
#include "Artist.h"
#include "Film.h"
#include "RepositoryException.h"
#include "ValidationException.h"

Repository::Repository()
{
}

Repository::Repository(string file_name)
{
	this->file_name = file_name;
}

Repository::~Repository()
{
	this->empty_repository();
}

void Repository::set_file_name(string new_file_name)
{
	this->file_name = new_file_name;
}

Repository& Repository::operator=(const Repository& repository)
{
	this->file_name = repository.file_name;
	return *this;
}

vector<Festival*> Repository::get_all()
{
	return this->festivale;
}

int Repository::get_size()
{
	return this->festivale.size();
}

Festival* Repository::get_festival(int pos) throw(ValidationException, RepositoryException)
{
	if (pos >= 0 && pos < this->get_size())
	{
		return this->festivale[pos]->clone();
	}
	throw RepositoryException("Indexul este invalid!");
}

int Repository::find_festival(Festival* festival)
{
	for (int i = 0; i < this->festivale.size(); i++)
	{
		if (this->festivale[i]->get_data() == festival->get_data() && this->festivale[i]->get_loc() == festival->get_loc())
		{
			return i;
		}
	}
	return -1;
}

void Repository::add_festival(Festival* festival) throw(ValidationException, RepositoryException)
{
	if (typeid(*festival) == typeid(Artist))
	{
		this->validator_artist.validate(festival);
	}
	if (typeid(*festival) == typeid(Film))
	{
		this->validator_film.validate(festival);
	}
	if (this->find_festival(festival) >= 0)
	{
		throw RepositoryException("Exista deja un festival cu aceasi data si locatie!");
	}
	this->festivale.push_back(festival->clone());
	this->save_to_file();
}

void Repository::update_festival(Festival* old_festival, Festival* new_festival)
{
	if (typeid(new_festival) == typeid(Artist))
	{
		this->validator_artist.validate(new_festival);
	}
	if (typeid(new_festival) == typeid(Film))
	{
		this->validator_film.validate(new_festival);
	}
	if (this->find_festival(old_festival) < 0)
	{
		throw RepositoryException("Nu exista!");
	}
	for (int i = 0; i < this->festivale.size(); i++)
	{
		if (this->get_festival(i)->get_data() == old_festival->get_data() && this->get_festival(i)->get_loc() == old_festival->get_loc())
		{
			delete this->festivale[i];
			this->festivale[i] = new_festival->clone();
			this->save_to_file();
			return;
		}
	}
}

void Repository::delete_festival(Festival* festival)
{
	for (int i = 0; i < this->festivale.size(); i++)
	{
		if (this->festivale[i]->get_data() == festival->get_data() && this->festivale[i]->get_loc() == festival->get_loc())
		{
			delete this->festivale[i];
			this->festivale.erase(this->festivale.begin() + i);
			this->save_to_file();
			return;
		}
	}
}

void Repository::empty_repository()
{
	for (int i = 0; i < this->get_size(); i++)
	{
		delete this->festivale[i];
	}
	this->festivale.clear();
}
