#pragma once

#include "Repository.h"

class Repository_CSV : public Repository
{
public:
	Repository_CSV();
	Repository_CSV(string file_name);
	~Repository_CSV();

	void load_from_file();
	void save_to_file();
};