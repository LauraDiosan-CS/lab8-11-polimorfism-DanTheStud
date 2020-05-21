#pragma once

#include "Repository.h"

class Repository_TXT : public Repository
{
public:
	Repository_TXT();
	Repository_TXT(string file_name);
	~Repository_TXT();

	void load_from_file();
	void save_to_file();
};