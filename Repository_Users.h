#pragma once

#include "Users.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Repository_Users
{
protected:
	vector<Users> users;
	string file_name;
public:
	Repository_Users();
	Repository_Users(string file_name);
	Repository_Users(const Repository_Users& u);
	~Repository_Users();
	Repository_Users& operator=(const Repository_Users& u);


	void set_filename(string new_filename);

	vector<Users>get_all();
	void add(Users user);
	void del(Users user);
	void update(Users old_user, Users new_user);

	int get_size();
	void clear();
	Users get_users(int pos);

	void load_to_file();
	void save_to_file();
};