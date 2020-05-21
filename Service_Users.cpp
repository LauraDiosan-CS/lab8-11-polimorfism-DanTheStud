#include "Service_Users.h"
#include "Exceptions.h"

Service_Users::Service_Users()
{

}

Service_Users::Service_Users(Repository_Users& repo_users)
{
	this->repo_users = repo_users;
}

Service_Users::Service_Users(const Service_Users& s)
{
	this->repo_users = s.repo_users;
}

Service_Users::~Service_Users()
{

}

void Service_Users::add_user(string username, string password)
{
	Users u(username, password);
	this->repo_users.add(u);
}

vector<Users> Service_Users::show_users()
{
	return this->repo_users.get_all();
}

void Service_Users::update_user(Users old_user, Users new_user)
{
	vector<Users> users = this->repo_users.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (old_user.get_username() == users[i].get_username() && old_user.get_password() == users[i].get_password())
		{
			this->repo_users.update(old_user, new_user);
		}
	}
}

void Service_Users::delete_user(Users user)
{
	this->repo_users.del(user);
}

int Service_Users::verify_username(string username)
{
	vector<Users> users = this->repo_users.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_username() == username)
			return 1;
	}
	return 0;
}

int Service_Users::verify_password(string password)
{

	vector<Users> users = this->repo_users.get_all();
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].get_password() == password)
			return 1;
	}
	return 0;
}