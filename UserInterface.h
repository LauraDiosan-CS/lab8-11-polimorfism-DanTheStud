#pragma once

#include "Service.h"
#include "Service_Users.h"

class UI
{
private:
	Service service;

	void display_manu();
	void display_user_manu();
	void choose_file_type();

	void add_film();
	void add_artist();

	void modify_festival();

	void delete_festival();

	void show();

	void print_festival(vector<Festival*> festivale);

	void login(string& username, string& password);
	void add_new_user();
	void modify_user(string& username, string& password);
	void del_user(Users user_to_del);

	void cumpara_bilet();
	void cauta_eveniment_dupa_zi();

public:
	UI();
	~UI();
	void run_UI();
};