#pragma once

#include "Repository_Users.h"
#include "Users.h"
using namespace std;

class Service_Users
{
private:
	Repository_Users repo_users;
public:
	Service_Users();
	Service_Users(Repository_Users& repo_users);
	Service_Users(const Service_Users& s);
	~Service_Users();

	void add_user(string username, string password);
	vector<Users> show_users();
	void update_user(Users old_user, Users new_user);
	void delete_user(Users user);

	int verify_username(string username);
	int verify_password(string password);
};