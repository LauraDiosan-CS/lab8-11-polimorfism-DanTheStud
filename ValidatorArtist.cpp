#include "ValidatorArtist.h"
#include "Artist.h"
#include "ValidationException.h"

ValidatorArtist::ValidatorArtist()
{
}

ValidatorArtist::~ValidatorArtist()
{
}

void ValidatorArtist::validate(Festival* festival)
{
	ValidatorFestival::validate(festival);
	Artist* artist = (Artist*)festival;

	if (artist->get_nume_artist().empty())
	{
		throw ValidationException("Numele artistului nu poate fi gol!");
	}
}
