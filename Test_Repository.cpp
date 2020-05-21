#include <assert.h>
#include "Test_Repository.h"
#include "Repository_CSV.h"
#include "Repository_TXT.h"
#include "Film.h"
#include "Artist.h"
#include "ReadFromFileException.h"
#include "RepositoryException.h"

void TestRepository::test_get_size()
{
	Repository* repo = new Repository_TXT();
	assert(repo->get_size() == 0);
	repo->add_festival(new Artist("Dan", "21.12.2020", "Oradea", 120, 80));
	assert(repo->get_size() == 1);
}

void TestRepository::test_get_all()
{
	Repository* repo = new Repository_TXT();
	Artist* artist = new Artist("Dan", "21.12.2020", "Oradea", 120, 80);
	Artist* sec_artist = new Artist("Andrada", "99.22.3300", "Canada", 120, 80);
	repo->add_festival(artist);
	repo->add_festival(sec_artist);
	vector<Festival*> festivale = repo->get_all();
	assert(*festivale[0] == *artist);
	assert(*festivale[1] == *sec_artist);
}

void TestRepository::test_get_festival()
{
	Repository* repo = new Repository_TXT();
	Artist* artist = new Artist("Dan", "21.12.2020", "Oradea", 120, 80);
	repo->add_festival(artist);
	try
	{
		assert(*repo->get_festival(0) == *artist);
	}
	catch (...)
	{
		assert(false);
	}
	try
	{
		*(repo)->get_festival(-1);
	}
	catch (RepositoryException & e)
	{
	}
	catch (...)
	{
		assert(false);
	}
	try
	{
		*(repo)->get_festival(1);
	}
	catch (RepositoryException & e)
	{
	}
	catch (...)
	{
		assert(false);
	}
}

void TestRepository::test_add_festival()
{
	Repository* repo = new Repository_TXT();
	Artist* artist = new Artist("Dan", "21.12.2020", "Oradea", 120, 80);
	try
	{
		repo->add_festival(artist);
	}
	catch (...)
	{
		assert(false);
	}
	assert(repo->get_size() == 1);
	assert(*repo->get_festival(0) == *artist);

	Film* film = new Film("ACDC", "Da", "21.12.2000", "NuStiu", 10, 10);
	try
	{
		repo->add_festival(film);
	}
	catch (...)
	{
		assert(false);
	}
	assert(repo->get_size() == 2);
	assert(*repo->get_festival(1) == *film);
}

void TestRepository::test_update_festival()
{
	Repository* repo = new Repository_TXT();
	Artist* artist = new Artist("Dan", "21.12.2020", "Oradea", 120, 80);
	Artist* artist2 = new Artist("ACDC", "21.12.2000", "NuStiu", 10, 10);
	repo->add_festival(artist);
	try
	{
		repo->update_festival(artist, artist2);
	}
	catch (RepositoryException& e)
	{
	}
	catch (...)
	{
		assert(false);
	}
	assert(*repo->get_festival(0) == *artist2);
}

void TestRepository::test_delete_festival()
{
	Repository* repo = new Repository_TXT();
	Artist* artist = new Artist("Dan", "21.12.2020", "Oradea", 120, 80);
	Artist* sec_artist = new Artist("Alex", "12.20.3000", "Korea", 12, 23);
	repo->add_festival(artist);
	try
	{
		repo->delete_festival(sec_artist);
	}
	catch (RepositoryException& e)
	{
	}
	catch (...)
	{
		assert(false);
	}
	assert(repo->get_size() == 1);
	assert(*repo->get_festival(0) == *artist);
	try
	{
		repo->delete_festival(artist);
	}
	catch (...)
	{
		assert(false);
	}
	assert(repo->get_size() == 0);
}

void TestRepository::test_load_from_file_TXT()
{
	Repository* repo = new Repository_TXT(this->file_name_in_TXT);
	try
	{
		repo->load_from_file();
	}
	catch (...)
	{
		assert(false);
	}
	assert(repo->get_size() == this->festivale_in.size());
	//assert(*repo->get_festival(0) == (*this->festivale_in[0]));
	//assert(*repo->get_festival(1) == (*this->festivale_in[1]));

	repo->set_file_name("AUTIREAWOtnaowrjhwoat.txt");
	try
	{
		repo->load_from_file();
	}
	catch (ReadFromFileException & e)
	{

	}
	catch (...)
	{
		assert(false);
	}

	repo->set_file_name(this->file_name_in_TXT);
	try
	{
		repo->load_from_file();
	}
	catch (ReadFromFileException& e)
	{

	}
	catch (...)
	{
		assert(false);
	}
}

void TestRepository::test_load_from_file_CSV()
{
	Repository* repo = new Repository_CSV(this->file_name_in_CSV);
	try
	{
		repo->load_from_file();
	}
	catch (...)
	{
		assert(false);
	}
	assert(repo->get_size() == this->festivale_in.size());
	//assert(*repo->get_festival(0) == (*this->festivale_in[0]));
	//assert(*repo->get_festival(1) == (*this->festivale_in[1]));

	repo->set_file_name("AUTIREAWOtnaowrjhwoat.csv");
	try
	{
		repo->load_from_file();
	}
	catch (ReadFromFileException& e)
	{

	}
	catch (...)
	{
		assert(false);
	}

	repo->set_file_name(this->file_name_in_CSV);
	try
	{
		repo->load_from_file();
	}
	catch (ReadFromFileException& e)
	{

	}
	catch (...)
	{
		assert(false);
	}
}

void TestRepository::test_save_to_file_TXT()
{
	Repository* repo = new Repository_TXT(this->file_name_in_TXT);
	repo->load_from_file();
	repo->set_file_name(this->file_name_out_TXT);
	Artist* new_artist = new Artist("Ana", "12.22.3122", "are", 120, 43);
	repo->add_festival(new_artist);
	repo->save_to_file();
	repo->load_from_file();
	assert(repo->get_size() == this->festivale_in.size() + 1);
	vector<Festival*> festivale = repo->get_all();
	for (int i = 0; i < repo->get_size() - 1; i++)
	{
		//assert(*festivale[i] == *this->festivale_in[i]);
	}
	assert(*festivale[festivale.size() - 1] == *new_artist);
}
void TestRepository::test_save_To_file_CSV()
{
	Repository* repo = new Repository_CSV(this->file_name_in_CSV);
	repo->load_from_file();
	repo->set_file_name(this->file_name_out_TXT);
	Artist* new_artist = new Artist("Ana", "12.22.3122", "are", 120, 43);
	repo->add_festival(new_artist);
	repo->save_to_file();
	repo->load_from_file();
	assert(repo->get_size() == this->festivale_in.size() + 1);
	vector<Festival*> festivale = repo->get_all();
	for (int i = 0; i < repo->get_size() - 1; i++)
	{
		//assert(*festivale[i] == *this->festivale_in[i]);
	}
	assert(*festivale[festivale.size() - 1] == *new_artist);
}

TestRepository::TestRepository()
{
	Artist* artist = new Artist("Dan", "12.12.2000", "Oradea", 14, 23);
	Film* film = new Film("Guacamole", "Guacalico", "12.23.2432", "Oradea", 24, 31);
	this->festivale_in.push_back(artist);
	this->festivale_in.push_back(film);
}

TestRepository::~TestRepository()
{
}

void TestRepository::test_all()
{
	this->test_get_size();
	this->test_get_all();
	this->test_get_festival();
	this->test_add_festival();
	this->test_update_festival();
	this->test_delete_festival();
	this->test_load_from_file_TXT();
	this->test_load_from_file_CSV();
	this->test_save_to_file_TXT();
	this->test_save_To_file_CSV();
}

