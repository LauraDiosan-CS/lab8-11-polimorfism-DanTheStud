#include <fstream>
#include "Repository_TXT.h"
#include "ReadFromFileException.h"
#include "Artist.h"
#include "Film.h"

Repository_TXT::Repository_TXT()
{
}

Repository_TXT::Repository_TXT(string file_name) : Repository(file_name)
{
	this->load_from_file();
}

Repository_TXT::~Repository_TXT()
{
}

void Repository_TXT::load_from_file() throw(ReadFromFileException)
{
	ifstream f(this->file_name);
	if (f.is_open())
	{
		this->empty_repository();
		string linie;
		string delim = " ";
		try
		{
			while (getline(f, linie))
			{
				if (linie.substr(0, 2) == "AR")
				{
					linie = linie.erase(0, 3);

					int pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string data = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string locatie = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int nr_loc_disponibil = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int nr_loc_vandute = stoi(linie.substr(0, pos));

					Artist* artist = new Artist(nume, data, locatie, nr_loc_disponibil, nr_loc_vandute);
					this->validator_artist.validate(artist);
					this->festivale.push_back(artist);
				}
				else if (linie.substr(0, 2) == "FI")
				{
					linie = linie.erase(0, 3);

					int pos = linie.find(delim);
					string titlu = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string actori = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string data = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string locatie = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int nr_loc_disponibil = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int nr_loc_vandute = stoi(linie.substr(0, pos));

					Film* film = new Film(titlu, actori, data, locatie, nr_loc_disponibil, nr_loc_vandute);
					this->validator_film.validate(film);
					this->festivale.push_back(film);
				}
			}
		}
		catch (...)
		{
			throw ReadFromFileException("Formatul datelor din fisier este invalid!");
		}
	}
	else
	{
		throw ReadFromFileException("Fisierul nu exista!");
	}
}

void Repository_TXT::save_to_file()
{
	ofstream f(this->file_name);
	if (f.is_open())
	{
		for (Festival* elem : this->festivale)
		{
			f << elem->toString(" ") << endl;
		}
	}
}
