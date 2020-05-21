#include <assert.h>
#include "Test_Film.h"
#include "Film.h"
#include "Util.h"

void TestFilm::test_implicit_constructor()
{
	Film film;
	assert(film.get_titlu().empty());
	assert(film.get_actori().empty());
}

void TestFilm::test_constructor_with_parameters()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	assert(film.get_titlu() == "MoaraVeche");
	assert(film.get_actori() == "JoanHuan");
}

void TestFilm::test_copy_constructor()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	Film sec_film(film);
	assert(film.get_titlu() == sec_film.get_titlu());
	assert(film.get_actori() == sec_film.get_actori());
}

void TestFilm::test_clone()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	Film* clone_film = film.clone();
	assert(film == *clone_film);
	assert(&film != clone_film);
}

void TestFilm::test_get_titlu()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	assert(film.get_titlu() == "MoaraVeche");
}

void TestFilm::test_get_actori()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	assert(film.get_actori() == "JoanHuan");
}

void TestFilm::test_set_titlu()
{
	Film film;
	film.set_titlu_film("MoaraVeche");
	assert(film.get_titlu() == "MoaraVeche");
}

void TestFilm::test_set_actori()
{
	Film film;
	film.set_actori_film("JoanHuan");
	assert(film.get_actori() == "JoanHuan");
}

void TestFilm::test_assignment_operator()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	Film sec_film;
	sec_film = film;
	assert(film.get_titlu() == sec_film.get_titlu());
	assert(film.get_actori() == sec_film.get_actori());
}

void TestFilm::test_equality_operator()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	Film sec_film = film;
	assert(sec_film == film);
}

void TestFilm::test_to_string()
{
	Film film("MoaraVeche", "JoanHuan", "21.12.2020", "Oradea", 120, 80);
	assert(film.toString(" ") == "FI MoaraVeche JoanHuan 21.12.2020 Oradea 120 80");
	assert(film.toString(",") == "FI,MoaraVeche,JoanHuan,21.12.2020,Oradea,120,80");

}

void TestFilm::test_all()
{
	this->test_implicit_constructor();
	this->test_constructor_with_parameters();
	this->test_copy_constructor();
	this->test_clone();
	this->test_get_titlu();
	this->test_get_actori();
	this->test_set_titlu();
	this->test_set_actori();
	this->test_assignment_operator();
	this->test_equality_operator();
	this->test_to_string();
}
