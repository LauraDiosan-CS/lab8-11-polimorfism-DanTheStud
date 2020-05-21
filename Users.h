#pragma once
#include <iostream>

using namespace std;

class Users
{
private:
	string username;
	string password;
public:
	Users();
	Users(string username, string password);
	Users(const Users& user);
	~Users();

	string get_username();
	string get_password();

	void set_username(string new_username);
	void set_password(string new_password);

	Users& operator=(const Users& user);
	bool operator==(const Users& user);
	friend ostream& operator<<(ostream& os, const Users& user);
	friend istream& operator>>(istream& is, Users& user);
	string toString(string delim);
};