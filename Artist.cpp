#include "Artist.h"

Artist::Artist() : Festival()
{
}

Artist::Artist(string nume, string data, string loc, int numar_locuri_disponibile, int numar_locuri_vandute)
{
	this->nume = nume;
	this->data = data;
	this->loc = loc;
	this->numar_locuri_dosponibile = numar_locuri_disponibile;
	this->numar_locuri_vandute = numar_locuri_vandute;
}

Artist::Artist(const Artist& artist) : Festival(artist)
{
	this->nume = artist.nume;
	this->data = artist.data;
	this->loc = artist.loc;
	this->numar_locuri_dosponibile = artist.numar_locuri_dosponibile;
	this->numar_locuri_vandute = artist.numar_locuri_vandute;
}

Artist::~Artist()
{
}

Artist* Artist::clone()
{
	return new Artist(this->nume, this->data, this->loc, this->numar_locuri_dosponibile, this->numar_locuri_vandute);
}

string Artist::get_nume_artist()
{
	return this->nume;
}

void Artist::set_nume_artist(string new_name)
{
	this->nume = new_name;
}

Artist& Artist::operator=(const Artist& artist)
{
	Festival::operator=(artist);
	this->nume = artist.nume;
	return *this;
}

bool Artist::operator==(const Artist& artist)
{
	return Festival::operator==(artist) && this->nume == artist.nume;
}

string Artist::toString(string delim)
{
	return "AR" + delim + this->nume + delim + Festival::toString(delim);
}
