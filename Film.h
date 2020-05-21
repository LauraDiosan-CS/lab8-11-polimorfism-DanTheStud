#pragma once

#include "Festival.h"

class Film : public Festival
{
private:
	string titlu;
	string actori;

public:
	Film();
	Film(string titlu, string actori, string data, string loc, int numar_locuri_disponibile, int numar_locuri_vandute);
	Film(const Film& film);
	~Film();

	Film* clone();

	string get_titlu();
	string get_actori();

	void set_titlu_film(string new_titlu);
	void set_actori_film(string new_actori);

	Film& operator=(const Film& film);
	bool operator==(const Film& film);
	string toString(string delim);
};