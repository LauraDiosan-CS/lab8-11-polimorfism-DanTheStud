#pragma once
#include "ValidatorFestival.h"

class ValidatorArtist : public ValidatorFestival
{
public:
	ValidatorArtist();
	~ValidatorArtist();

	void validate(Festival* festival);
};