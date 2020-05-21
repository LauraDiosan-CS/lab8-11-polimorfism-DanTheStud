#pragma once

#include <string>

using namespace std;

class Festival
{
protected:
	string data;
	string loc;
	int numar_locuri_dosponibile;
	int numar_locuri_vandute;

public:
	Festival();
	Festival(string data, string loc, int numar_locuri_disponibile, int numar_locuri_vandute);
	Festival(const Festival& festival);
	~Festival();

	virtual Festival* clone();

	string get_data();
	string get_loc();
	int get_numar_locuri_disponibile();
	int get_numar_locuri_vandute();

	void set_data(string new_data);
	void set_loc(string new_loc);
	void set_numar_locuri_disponibile(int new_numar_locuri_disponibile);
	void set_numar_locuri_vandute(int new_numar_locuri_vandute);

	Festival& operator=(const Festival& festival);
	bool operator==(const Festival& festival);
	friend istream& operator>>(istream& is, Festival& festival);
	virtual string toString(string delim);
};