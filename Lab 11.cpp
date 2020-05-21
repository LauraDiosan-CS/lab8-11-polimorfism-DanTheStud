// Lab 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Repository.h"
#include "Repository_CSV.h"
#include "Repository_TXT.h"
#include "UserInterface.h"
#include "Test_Festival.h"
#include "Test_Artist.h"
#include "Test_Film.h"
#include "Test_Repository.h"
#include "Test_Users.h"
#include "Test_Service.h"

using namespace std;

int main()
{
	TestFestival tf;
	TestArtist ta;
	TestFilm tfi;
	TestRepository tr;
	Test_Users tu;
	TestService ts;
	tf.test_all();
	ta.test_all();
	tfi.test_all();
	tr.test_all();
	tu.test_all();
	ts.test_all();

	UI ui;
	ui.run_UI();

	cout << "Tu trabaho para mi amigo, tu esta mui muerta, asta la vista";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
