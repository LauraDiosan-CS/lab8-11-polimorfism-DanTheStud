#pragma once

#include <string>
#include "Festival.h"

using namespace std;

class ValidatorFestival
{
public:
	ValidatorFestival();
	~ValidatorFestival();

	virtual void validate(Festival* festival);
};