#pragma once

#include "Repository.h"

class Service
{
private:
	Repository* repository;

public:
	Service();
	Service(Repository* repository);
	~Service();

	vector < Festival*> get_all();

	Festival* get_festival_at_position(int pos);

	void add_artist(string nume, string data, string locatie, int numar_locuri_valabile, int numar_locuri_vandute);
	void add_film(string titlu, string actori, string data, string locatie, int numar_locuri_valabile, int numar_locuri_vandute);

	void update_artist(string old_data, string old_locatie, string new_nume, string new_data, string new_locatie, int new_numar_locuri_valabile, int new_numar_locuri_vandute);
	void update_film(string old_data, string old_locatie, string new_titlu, string new_actori, string new_data, string new_locatie, int new_numar_locuri_valabile, int new_numar_locuri_vandute);

	void delete_festival(string data, string locatie, int numar_locuri_disponibile, int numar_locuri_vandute);

	void load_from_file();
	void save_to_file();
	void set_file_name(string new_file_name);
	void set_repository(Repository* repository);
};