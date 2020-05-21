#include "Film.h"

Film::Film() : Festival()
{
}

Film::Film(string titlu, string actori, string data, string loc, int numar_locuri_disponibile, int numar_locuri_vandute)
{
	this->titlu = titlu;
	this->actori = actori;
	this->data = data;
	this->loc = loc;
	this->numar_locuri_dosponibile = numar_locuri_disponibile;
	this->numar_locuri_vandute = numar_locuri_vandute;
}

Film::Film(const Film& film)
{
	this->titlu = film.titlu;
	this->actori = film.actori;
	this->data = film.data;
	this->loc = film.loc;
	this->numar_locuri_dosponibile = film.numar_locuri_dosponibile;
	this->numar_locuri_vandute = film.numar_locuri_vandute;
}

Film::~Film()
{
}

Film* Film::clone()
{
	return new Film(this->titlu, this->actori, this->data, this->loc, this->numar_locuri_dosponibile, this->numar_locuri_vandute);
}

string Film::get_titlu()
{
	return this->titlu;
}

string Film::get_actori()
{
	return this->actori;
}

void Film::set_titlu_film(string new_titlu)
{
	this->titlu = new_titlu;
}

void Film::set_actori_film(string new_actori)
{
	this->actori = new_actori;
}

Film& Film::operator=(const Film& film)
{
	Festival::operator=(film);
	this->titlu = film.titlu;
	this->actori = film.actori;
	return *this;
}

bool Film::operator==(const Film& film)
{
	return Festival::operator==(film) && this->titlu == film.titlu && this->actori == film.actori;
}

string Film::toString(string delim)
{
	return "FI" + delim + this->titlu + delim + this->actori + delim + Festival::toString(delim);
}
