#pragma once

#include "Festival.h"

class Artist : public Festival
{
private:
	string nume;

public:
	Artist();
	Artist(string nume, string data, string loc, int numar_locuri_disponibile, int numar_locuri_vandute);
	Artist(const Artist& artist);
	~Artist();

	Artist* clone();

	string get_nume_artist();

	void set_nume_artist(string new_name);

	Artist& operator=(const Artist& artist);
	bool operator==(const Artist& artist);
	string toString(string delim);
};