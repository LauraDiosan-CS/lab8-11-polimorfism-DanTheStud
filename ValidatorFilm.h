#pragma once

#include "ValidatorFestival.h"
#include "ValidationException.h"
#include "Film.h"

class ValidatorFilm : public ValidatorFestival
{
public:
	ValidatorFilm();
	~ValidatorFilm();

	void validate(Festival* festival);
};