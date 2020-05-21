#include <assert.h>
#include "Test_Artist.h"
#include "Artist.h"
#include "Util.h"

void TestArtist::test_implicit_constructor()
{
	Artist artist;
	assert(artist.get_nume_artist().empty());
}

void TestArtist::test_constructor_with_parameters()
{
	Artist artist("Dan", "21.12.2020", "Oradea", 120, 80);
	assert(artist.get_nume_artist() == "Dan");
}

void TestArtist::test_copy_constructor()
{
	Artist artist("Dan", "21.12.2020", "Oradea", 120, 80);
	Artist sec_artist(artist);
	assert(artist.get_nume_artist() == sec_artist.get_nume_artist());
}

void TestArtist::test_clone()
{
	Artist artist("Dan", "21.12.2020", "Oradea", 120, 80);
	Artist* clone_artist = artist.clone();
	assert(artist == *clone_artist);
	assert(&artist != clone_artist);
}

void TestArtist::test_get_nume()
{
	Artist artist("Dan", "21.12.2020", "Oradea", 120, 80);
	assert(artist.get_nume_artist() == "Dan");
}

void TestArtist::test_set_nume()
{
	Artist artist;
	artist.set_nume_artist("Dan");
	assert(artist.get_nume_artist() == "Dan");
}

void TestArtist::test_assignment_operator()
{
	Artist artist("Dan", "21.12.2020", "Oradea", 120, 80);
	Artist sec_artist;
	artist = sec_artist;
	assert(artist.get_nume_artist() == sec_artist.get_nume_artist());
}

void TestArtist::test_equality_operator()
{
	Artist artist("Dan", "21.12.2020", "Oradea", 120, 80);
	Artist sec_artist = artist;
	assert(sec_artist == artist);
}

void TestArtist::test_to_string()
{
	Artist artist("Dan", "21.12.2020", "Oradea", 120, 80);
	assert(artist.toString(" ") == "AR Dan 21.12.2020 Oradea 120 80");
	assert(artist.toString(",") == "AR,Dan,21.12.2020,Oradea,120,80");
}

void TestArtist::test_all()
{
	this->test_implicit_constructor();
	this->test_constructor_with_parameters();
	this->test_copy_constructor();
	this->test_clone();
	this->test_get_nume();
	this->test_set_nume();
	this->test_assignment_operator();
	this->test_equality_operator();
	this->test_to_string();
}
