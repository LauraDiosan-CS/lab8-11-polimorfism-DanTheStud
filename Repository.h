#pragma once

#include "Festival.h"
#include <vector>
#include "ValidatorArtist.h"
#include "ValidatorFilm.h"

using namespace std;

class Repository
{
protected:
	vector < Festival*> festivale;
	string file_name;
	ValidatorArtist validator_artist;
	ValidatorFilm validator_film;

public:
	Repository();
	Repository(string file_name);
	~Repository();

	void set_file_name(string new_file_name);

	Repository& operator=(const Repository& repository);

	vector < Festival*> get_all();
	int get_size();

	Festival* get_festival(int pos);

	int find_festival(Festival* festival);

	void add_festival(Festival* festival);
	void update_festival(Festival* old_vestival, Festival* new_festival);
	void delete_festival(Festival* festival);

	void empty_repository();

	virtual void load_from_file() = 0;
	virtual void save_to_file() = 0;
};