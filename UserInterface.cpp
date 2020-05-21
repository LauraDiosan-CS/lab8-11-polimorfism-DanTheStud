#include <iostream>
#include <fstream>
#include "UserInterface.h"
#include "Repository_CSV.h"
#include "Repository_TXT.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"
#include "Exceptions.h"
#include "Artist.h"
#include "Film.h"
#include "RepositoryException.h"
#include "Util.h"

void UI::display_manu()
{
	cout << "1. Afiseaza toate evenimentele.\n";
	cout << "2. Cautare evenimente dupa zi.\n";
	cout << "3. Cumpara bilete la un eveniment.\n";
	cout << "4. Adaugare eveniment cu artisti.\n";
	cout << "5. Adaugare evenimente cu filme.\n";
	cout << "6. Sterge eveniment.\n";
	cout << "7. Modifica eveniment.\n";
	cout << "0. Exit\n";
}

void UI::display_user_manu()
{
	cout << "1. Login\n";
	cout << "2. Sign up\n";
	cout << "0. Exit\n";
}

void UI::choose_file_type()
{
	int option = 0;
	cout << "Alegeti tipul de fisier dorit: 1 - .CSV || 2 - .TXT\noptiunea alease: ";
	cin >> option;
	while (option != 1 && option != 2)
	{
		cout << "Optiunea aleasa trebuie sa fie: 1 - .CSV SAU 2 - .TXT! Mai incercati!\noptiune aleasa: ";
		cin >> option;
	}
	if (option == 1)
	{
		this->service.set_repository(new Repository_CSV("File_CSV.csv"));
	}
	else
	{
		this->service.set_repository(new Repository_TXT("File_TXT.txt"));
	}
}

void UI::add_film()
{
	string titlu, actori, data, locatie;
	int nr_locuri_disponibile, nr_locuri_vandute;

	cout << " Titlul filumui: "; cin >> titlu;
	cout << " Actorii filmului: "; cin >> actori;
	cout << " Data la care va avea loc filmul: "; cin >> data;
	cout << " Locatia unde se va difuza filmul: "; cin >> locatie;
	cout << " Numarul locurilor disponibile: "; cin >> nr_locuri_disponibile;
	cout << " Numarul locurilor vandute: "; cin >> nr_locuri_vandute;

	try
	{
		this->service.add_film(titlu, actori, data, locatie, nr_locuri_disponibile, nr_locuri_vandute);
		this->service.save_to_file();
	}
	catch (ValidationException& e)
	{
		cout << e.what() << endl;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::add_artist()
{
	string nume, data, locatie;
	int nr_locuri_disponibile, nr_locuri_vandute;

	cout << " Numle artistului: "; 
	getline(cin, nume);
	cout << " Data la care va avea loc evenimentul: "; 
	getline(cin, data);
	cout << " Locatia unde se va difuza evenimentul: "; 
	getline(cin, locatie);
	cout << " Numarul locurilor disponibile: "; 
	cin >> nr_locuri_disponibile;
	cout << " Numarul locurilor vandute: "; 
	cin >> nr_locuri_vandute;

	try
	{
		this->service.add_artist(nume, data, locatie, nr_locuri_disponibile, nr_locuri_vandute);
		this->service.save_to_file();
	}
	catch (ValidationException& e)
	{
		cout << e.what() << endl;
	}
	catch (RepositoryException& e)
	{
		cout << e.what() << endl;
	}
}

void UI::modify_festival()
{
	vector<Festival*> festivale = service.get_all();
	string data, locatie;
	int raspuns;
	cout << "Ce doriti sa modificati? 1 - Film || 2 - Artist.\n raspuns: ";
	cin >> raspuns;
	if (raspuns == 1)
	{
		string titlu, actori, data_new, locatie_new;
		int nr_loc_val, nr_loc_vand;
		cout << "Data evenimentului care doriti sa il modificati: ";
		cin >> data;
		cout << "Locatia evenimentului care doriti sa il modificati: ";
		cin >> locatie;
		cout << "titlu noua: ";
		cin >> titlu;
		cout << "actori noua: ";
		cin >> actori;
		cout << "data noua: ";
		cin >> data_new;
		cout << "locatie noua: ";
		cin >> locatie_new;
		cout << "numar locuri valabile noua: ";
		cin >> nr_loc_val;
		cout << "numar locuri vandute noua: ";
		cin >> nr_loc_vand;
		service.update_film(data, locatie, titlu, actori, data_new, locatie_new, nr_loc_val, nr_loc_vand);
	}
	else if (raspuns == 2)
	{
		string nume, data_new, locatie_new;
		int nr_loc_val, nr_loc_vand;
		cout << "Data evenimentului care doriti sa il modificati: ";
		cin >> data;
		cout << "Locatia evenimentului care doriti sa il modificati: ";
		cin >> locatie;
		cout << "nume noua: ";
		cin >> nume;
		cout << "data noua: ";
		cin >> data_new;
		cout << "locatie noua: ";
		cin >> locatie_new;
		cout << "numar locuri valabile noua: ";
		cin >> nr_loc_val;
		cout << "numar locuri vandute noua: ";
		cin >> nr_loc_vand;
		service.update_artist(data, locatie, nume, data_new, locatie_new, nr_loc_val, nr_loc_vand);
	}
	else
	{
		cout << "Nu ati ales o optiune buna, mai incercati.\n";
	}



}

void UI::delete_festival()
{
	string data, locatie;
	cout << "Data evenimentului care doriti sa il stergeti: ";
	cin >> data;
	cout << "Locatia evenimentului care doriti sa il stergeti: ";
	cin >> locatie;
	vector<Festival*> festivale = service.get_all();
	for (int i = 0; i < festivale.size(); i++)
	{
		if (festivale[i]->get_data() == data && festivale[i]->get_loc() == locatie)
		{
			service.delete_festival(festivale[i]->get_data(), festivale[i]->get_loc(), festivale[i]->get_numar_locuri_disponibile(), festivale[i]->get_numar_locuri_vandute());
		}
	}
}

void UI::show()
{
	this->print_festival(this->service.get_all());
}

void UI::print_festival(vector<Festival*> festivale)
{
	for (Festival* festival : festivale)
	{
		cout << festival->toString(" ").erase(0, 3) << endl;
	}
}

void UI::login(string& username, string& password)
{
	Repository_Users repository_users("Users.txt");
	Service_Users service_users(repository_users);
	try
	{
		while (true)
		{
			string username;
			cout << "USERNAME: ", cin >> username;
			if (service_users.verify_username(username) == 1)
			{
				string password;
				cout << "PASSWORD: ", cin >> password;
				if (service_users.verify_password(password) == 1)
				{
					cout << "Login successful!" << "\n";
					break;
				}
				else
				{
					cout << "Username sau password gresit!\n";
				}
			}
			else
			{
				cout << "Username gresit, mai incearca.\n";
			}
		}
	}
	catch (MyException e)
	{
		cout << "ERROR: " << e.what() << endl;
	}
}

void UI::add_new_user()
{
	Repository_Users repository_users("Users.txt");
	Service_Users service_users(repository_users);
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	service_users.add_user(username, password);
}

void UI::modify_user(string& username, string& password)
{
	Repository_Users repository_users("Users.txt");
	Service_Users service_users(repository_users);
	int raspuns;
	string old_username = username;
	string old_password = password;
	cout << "Doriti sa modificati username-ul? 1 - Da -- 2 - Nu.\nraspuns: ";
	cin >> raspuns;
	if (raspuns == 1)
	{
		cout << "noul username: ";
		cin >> username;
	}
	cout << "Doriti sa modificati password-ul? 1 - Da -- 2 - Nu.\nraspuns: ";
	cin >> raspuns;
	if (raspuns == 1)
	{
		cout << "noul password: ";
		cin >> password;
	}
	Users old_user(old_username, old_password);
	Users new_user(username, password);
	service_users.update_user(old_user, new_user);
}

void UI::del_user(Users user_to_del)
{
	Repository_Users repository_users("Users.txt");
	Service_Users service_users(repository_users);
	try
	{
		service_users.delete_user(user_to_del);
	}
	catch (MyException e)
	{
		cout << "ERROR: " << e.what() << endl;
	}
}

void UI::cumpara_bilet()
{
	string data, locatie;
	int raspuns;
	vector<Festival*> festivale = service.get_all();
	cout << "Data si locatia evenimentului pentru care doriti sa cumparati bilete:\n";
	cout << "data: ";
	cin >> data;
	cout << "locatie: ";
	cin >> locatie;
	cout << "Cate bilete doriti sa cumparati?\nraspuns: ";
	cin >> raspuns;
	for (int i = 0; i < festivale.size(); i++)
	{
		if (festivale[i]->get_data() == data && festivale[i]->get_loc() == locatie)
		{
			if (festivale[i]->get_numar_locuri_disponibile() >= raspuns)
			{
				festivale[i]->set_numar_locuri_disponibile(festivale[i]->get_numar_locuri_disponibile() - raspuns);
				festivale[i]->set_numar_locuri_vandute(festivale[i]->get_numar_locuri_vandute() + raspuns);
				break;
			}
			else
			{
				cout << "Nu sunt destule locuri disponibile!\n";
			}
		}
	}

}

void UI::cauta_eveniment_dupa_zi()
{
	string zi;
	vector<Festival*> festivale = service.get_all();
	cout << "Ziua cautata: ";
	cin >> zi;
	for (int i = 0; i < festivale.size(); i++)
	{
		if (festivale[i]->get_data()[0] == zi[0] && festivale[i]->get_data()[1] == zi[1])
		{
			cout << festivale[i]->toString(" ") << "\n";
		}
	}


}

UI::UI()
{
}

UI::~UI()
{
}

void UI::run_UI()
{
	bool logged_in = false, ok = true;
	int option;
	string usename_loged, password_loged;
	while (!logged_in)
	{
		this->display_user_manu();
		cout << "Optiunea aleasa: ";
		cin >> option;
		if (option == 1)
		{
			try
			{
				this->login(usename_loged, password_loged);
				logged_in = true;
			}
			catch (MyException e)
			{
				cout << "ERROR: " << e.what() << endl;
			}
		}
		else if (option == 2)
		{
			try
			{
				this->add_new_user();
			}
			catch (MyException e)
			{
				cout << "ERROR: " << e.what() << endl;
			}


		}
		else if (option == 0)
		{
			ok = false;
			break;
		}
		else
		{
			cout << "Alege o optiune corecta!";
		}
	}
	if (ok == true)
	{
		this->choose_file_type();
		bool running = true;
		this->show();
		while (running)
		{
			this->display_manu();
			cout << "\noption: \n";
			cin >> option;
			cin.ignore();
			if (option == 1)
			{
				this->show();
			}
			if (option == 2)
			{
				this->cauta_eveniment_dupa_zi();
			}
			if (option == 3)
			{
				this->cumpara_bilet();
				this->service.save_to_file();
			}
			if (option == 4)				
			{
				this->add_artist();
			}
			if (option == 5)
			{
				this->add_film();
			}
			if (option == 6)
			{
				this->delete_festival();
			}
			if (option == 7)
			{
				this->modify_festival();
			}
			if (option == 0)
			{
				running = false;
			}
		}
	}
}
