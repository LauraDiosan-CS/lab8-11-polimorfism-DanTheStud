#include "ValidatorFestival.h"
#include "ValidationException.h"

ValidatorFestival::ValidatorFestival()
{
}

ValidatorFestival::~ValidatorFestival()
{
}

void ValidatorFestival::validate(Festival* festival)
{
	if (festival->get_data().empty())
	{
		throw ValidationException("Data Fesivalului nu poate fi goala!");
	}
	if (festival->get_loc().empty())
	{
		throw ValidationException("Loucl Fesivalului nu poate fi goala!");
	}
	if (festival->get_numar_locuri_disponibile() < 0)
	{
		throw ValidationException("Numarul de locuri disponibile nu poate fi negativ!");
	}
	if (festival->get_numar_locuri_vandute() < 0)
	{
		throw ValidationException("Numarul de locuri vandute nu poate fi negativ!");
	}
}
