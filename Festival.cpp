#include <iostream>
#include "Festival.h"
#include "Util.h"

Festival::Festival()
{
	this->numar_locuri_dosponibile = 0;
	this->numar_locuri_vandute = 0;
}

Festival::Festival(string data, string loc, int numar_locuri_disponibile, int numar_locuri_vandute)
{
	this->data = data;
	this->loc = loc;
	this->numar_locuri_dosponibile = numar_locuri_disponibile;
	this->numar_locuri_vandute = numar_locuri_vandute;
}

Festival::Festival(const Festival& festival)
{
	this->data = festival.data;
	this->loc = festival.loc;
	this->numar_locuri_dosponibile = festival.numar_locuri_dosponibile;
	this->numar_locuri_vandute = festival.numar_locuri_vandute;
}

Festival::~Festival()
{
}

Festival* Festival::clone()
{
	return new Festival(this->data, this->loc, this->numar_locuri_dosponibile, this->numar_locuri_vandute);
}

string Festival::get_data()
{
	return this->data;
}

string Festival::get_loc()
{
	return this->loc;
}

int Festival::get_numar_locuri_disponibile()
{
	return this->numar_locuri_dosponibile;
}

int Festival::get_numar_locuri_vandute()
{
	return this->numar_locuri_vandute;
}

void Festival::set_data(string new_data)
{
	this->data = new_data;
}

void Festival::set_loc(string new_loc)
{
	this->loc = new_loc;
}

void Festival::set_numar_locuri_disponibile(int new_numar_locuri_disponibile)
{
	this->numar_locuri_dosponibile = new_numar_locuri_disponibile;
}

void Festival::set_numar_locuri_vandute(int new_numar_locuri_vandute)
{
	this->numar_locuri_vandute = new_numar_locuri_vandute;
}

Festival& Festival::operator=(const Festival& festival)
{
	this->data = festival.data;
	this->loc = festival.loc;
	this->numar_locuri_dosponibile = festival.numar_locuri_dosponibile;
	this->numar_locuri_vandute = festival.numar_locuri_vandute;
	return *this;
}

bool Festival::operator==(const Festival& festival)
{
	return this->data == festival.data && this->loc == festival.loc && this->numar_locuri_dosponibile == festival.numar_locuri_dosponibile && this->numar_locuri_vandute == festival.numar_locuri_vandute;
}

string Festival::toString(string delim)
{
	return this->data + delim + loc + delim + to_string(numar_locuri_dosponibile) + delim + to_string(numar_locuri_vandute);
}
