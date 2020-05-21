#include "ValidatorFilm.h"

ValidatorFilm::ValidatorFilm()
{
}

ValidatorFilm::~ValidatorFilm()
{
}

void ValidatorFilm::validate(Festival* festival)
{
	ValidatorFestival::validate(festival);
	Film* film = (Film*)festival;

	if (film->get_titlu().empty())
	{
		throw ValidationException("Titltul filmului nu poate fi gol!");
	}
	if (film->get_actori().empty())
	{
		throw ValidationException("Lista de actori participanti ai filmului nu poate fi goala!");
	}
}
