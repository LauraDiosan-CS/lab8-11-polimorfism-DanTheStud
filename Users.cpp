#include "Users.h"
#include <iostream>
#include <string>
#include "vector"
#include <sstream>
using namespace std;

Users::Users()
{

}

Users::Users(string username, string password)
{
	this->username = username;
	this->password = password;
}

Users::Users(const Users& user)
{
	this->username = user.username;
	this->password = user.password;
}

Users::~Users()
{

}

string Users::get_username()
{
	return this->username;
}


string Users::get_password()
{
	return this->password;
}

void Users::set_username(string username)
{
	this->username = username;
}

void Users::set_password(string password)
{
	this->password = password;
}

Users& Users::operator=(const Users& user)
{
	this->username = user.username;
	this->password = user.password;
	return *this;
}

bool Users::operator==(const Users& user)
{
	return this->username == user.username && this->password == user.password;
}

string Users::toString(string delim)
{
		return this->username + delim + this->password;
}

istream& operator>>(istream& is, Users& user)
{
	is >> user.username >> user.password;
	return is;
}

ostream& operator<<(ostream& os, const Users& user)
{
	os << user.username << " -> " << user.password << endl;
	return os;
}