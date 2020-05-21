#include <assert.h>
#include "Test_Festival.h"
#include "Festival.h"
#include "Util.h"

void TestFestival::test_implicit_constructor()
{
	Festival festival;
	assert(festival.get_data().empty());
	assert(festival.get_loc().empty());
	assert(festival.get_numar_locuri_disponibile() == 0);
	assert(festival.get_numar_locuri_vandute() == 0);
}

void TestFestival::test_constructor_with_parameters()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	assert(festival.get_data() == "21.12.2020");
	assert(festival.get_loc() == "Oradea");
	assert(festival.get_numar_locuri_disponibile() == 120);
	assert(festival.get_numar_locuri_vandute() == 80);

}

void TestFestival::test_copy_constructor()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	Festival sec_festival(festival);
	assert(festival.get_data() == sec_festival.get_data());
	assert(festival.get_loc() == sec_festival.get_loc());
	assert(festival.get_numar_locuri_disponibile() == sec_festival.get_numar_locuri_disponibile());
	assert(festival.get_numar_locuri_vandute() == sec_festival.get_numar_locuri_vandute());
}

void TestFestival::test_clone()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	Festival* clone_festival = festival.clone();
	assert(festival == *clone_festival);
	assert(&festival != clone_festival);
}

void TestFestival::test_get_data()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	assert(festival.get_data() == "21.12.2020");
}

void TestFestival::test_get_locatie()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	assert(festival.get_loc() == "Oradea");
}

void TestFestival::test_get_nr_locuri_valabile()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	assert(festival.get_numar_locuri_disponibile() == 120);
}

void TestFestival::test_get_nr_locuri_vandute()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	assert(festival.get_numar_locuri_vandute() == 80);
}

void TestFestival::test_set_data()
{
	Festival festival;
	festival.set_data("21.12.2020");
	assert(festival.get_data() == "21.12.2020");
}

void TestFestival::test_set_locatie()
{
	Festival festival;
	festival.set_loc("Oradea");
	assert(festival.get_loc() == "Oradea");
}

void TestFestival::test_set_nr_locuri_valabile()
{
	Festival festival;
	festival.set_numar_locuri_disponibile(120);
	assert(festival.get_numar_locuri_disponibile() == 120);

}

void TestFestival::test_set_nr_locuri_vandute()
{
	Festival festival;
	festival.set_numar_locuri_vandute(80);
	assert(festival.get_numar_locuri_vandute() == 80);
}

void TestFestival::test_assignment_operator()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	Festival sec_festival;
	sec_festival = festival;
	assert(festival.get_data() == sec_festival.get_data());
	assert(festival.get_loc() == sec_festival.get_loc());
	assert(festival.get_numar_locuri_disponibile() == sec_festival.get_numar_locuri_disponibile());
	assert(festival.get_numar_locuri_vandute() == sec_festival.get_numar_locuri_vandute());

}

void TestFestival::test_equality_operator()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	Festival sec_festival = festival;
	assert(festival == sec_festival);
}

void TestFestival::test_to_string()
{
	Festival festival("21.12.2020", "Oradea", 120, 80);
	assert(festival.toString(" ") == "21.12.2020 Oradea 120 80");
	assert(festival.toString(",") == "21.12.2020,Oradea,120,80");
}

void TestFestival::test_all()
{
	this->test_implicit_constructor();
	this->test_constructor_with_parameters();
	this->test_copy_constructor();
	this->test_clone();
	this->test_get_data();
	this->test_get_locatie();
	this->test_get_nr_locuri_valabile();
	this->test_get_nr_locuri_vandute();
	this->test_set_data();
	this->test_set_locatie();
	this->test_set_nr_locuri_valabile();
	this->test_set_nr_locuri_vandute();
	this->test_assignment_operator();
	this->test_equality_operator();
	this->test_to_string();
}
