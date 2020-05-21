#include "Repository_Users.h"
#include <string>
#include <fstream>

using namespace std;

Repository_Users::Repository_Users()
{

}

Repository_Users::Repository_Users(string filename)
{
	this->file_name = filename;
	this->load_to_file();
}

Repository_Users::Repository_Users(const Repository_Users& u)
{
	//this->load_to_file();
	this->file_name = u.file_name;
}

Repository_Users::~Repository_Users()
{

}

Repository_Users& Repository_Users::operator=(const Repository_Users& u)
{
	this->load_to_file();
	this->file_name = u.file_name;
	return *this;
}

void Repository_Users::set_filename(string new_filename)
{
	this->file_name = new_filename;
	this->load_to_file();
}

vector<Users> Repository_Users::get_all()
{
	return this->users;
}

void Repository_Users::add(Users users)
{
	this->users.push_back(users);
	this->save_to_file();
}

void Repository_Users::del(Users user)
{
}

void Repository_Users::update(Users old_users, Users new_users)
{
	typename vector <Users>::iterator it;
	it = find(this->users.begin(), this->users.end(), old_users);
	if (!(it == this->users.end()))
	{
		*it = new_users;
	}
	this->save_to_file();
}

int Repository_Users::get_size()
{
	return this->users.size();
}

void Repository_Users::clear()
{
	this->users.clear();
}

Users Repository_Users::get_users(int pos)
{
	return this->users[pos - 1];
}

void Repository_Users::load_to_file()
{
	if (this->file_name != " ")
	{
		string line;
		ifstream f("Users.txt");
		string delimitator = " ";
		while (getline(f, line))
		{
			int pos = line.find(delimitator);
			string username = line.substr(0, pos);
			line = line.erase(0, pos + 1);
			pos = line.find(delimitator);
			string password = line.substr(0, pos);
			Users user(username, password);
			this->users.push_back(user);
		}
		f.close();
	}
}

void Repository_Users::save_to_file()
{
	ofstream f(this->file_name);
	if (f.is_open())
	{
		int n = get_size();
		for (int i = 0; i < n; i++)
			f << users[i].toString(" ") << endl;
	}
}