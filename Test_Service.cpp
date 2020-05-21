#include <assert.h>
#include <vector>
#include "Test_Service.h"
#include "Service.h"
#include "Repository_TXT.h"
#include "Artist.h"
#include "Film.h"
#include "RepositoryException.h"

void TestService::test_get_all()
{
    Service serv;
    Repository* repo = new Repository_TXT();
    serv.set_repository(repo);
    Film* f = new Film("Ana", "areMere", "12.23.3123", "Locatie", 123, 3);
    Artist* a = new Artist("Joni", "23.13.2423", "TotUndeva", 32, 4);
    serv.add_film(f->get_titlu(), f->get_actori(), f->get_data(), f->get_loc(), f->get_numar_locuri_disponibile(), f->get_numar_locuri_vandute());
    serv.add_artist(a->get_nume_artist(), a->get_data(), a->get_loc(), a->get_numar_locuri_disponibile(), a->get_numar_locuri_vandute());
    vector<Festival*> festivale = serv.get_all();
    assert(*festivale[0] == *f);
    assert(*festivale[1] == *a);
}

void TestService::test_get_festival_at_position()
{
    Service serv;
    Repository* repo = new Repository_TXT();
    serv.set_repository(repo);
    Film* f = new Film("Ana", "areMere", "12.23.3123", "Locatie", 123, 3);
    serv.add_film(f->get_titlu(), f->get_actori(), f->get_data(), f->get_loc(), f->get_numar_locuri_disponibile(), f->get_numar_locuri_vandute());
    try {
        assert(*serv.get_festival_at_position(0) == *f);
    }
    catch (...) {
        assert(false);
    }
    try {
        *serv.get_festival_at_position(-1);
    }
    catch (RepositoryException& e) {
    }
    catch (...) {
        assert(false);
    }
    try {
        *serv.get_festival_at_position(1);
    }
    catch (RepositoryException& e) {
    }
    catch (...) {
        assert(false);
    }
}

void TestService::test_add_artist()
{
    Service serv;
    Repository* repo = new Repository_TXT();
    serv.set_repository(repo);
    Artist* a = new Artist("Joni", "23.13.2423", "TotUndeva", 32, 4);
    try {
        serv.add_artist(a->get_nume_artist(), a->get_data(), a->get_loc(), a->get_numar_locuri_disponibile(), a->get_numar_locuri_vandute());
    }
    catch (RepositoryException& e) {
    }
    catch (...) {
        assert(false);
    }
    assert(*serv.get_festival_at_position(0) == *a);
}

void TestService::test_add_film()
{
    Service serv;
    Repository* repo = new Repository_TXT();
    serv.set_repository(repo);
    Film* f = new Film("Ana", "areMere", "12.23.3123", "Locatie", 123, 3);
    serv.add_film(f->get_titlu(), f->get_actori(), f->get_data(), f->get_loc(), f->get_numar_locuri_disponibile(), f->get_numar_locuri_vandute());
    try {
        serv.add_film(f->get_titlu(), f->get_actori(), f->get_data(), f->get_loc(), f->get_numar_locuri_disponibile(), f->get_numar_locuri_vandute());
    }
    catch (RepositoryException& e)
    {
    }
    catch (...) {
        assert(false);
    }
    assert(*serv.get_festival_at_position(0) == *f);
}

void TestService::test_update_artist()
{
    Service serv;
    Repository* repo = new Repository_TXT();
    serv.set_repository(repo);
    Artist* a = new Artist("Joni", "23.13.2423", "TotUndeva", 32, 4);
    serv.add_artist(a->get_nume_artist(), a->get_data(), a->get_loc(), a->get_numar_locuri_disponibile(), a->get_numar_locuri_vandute());
    Artist* sa = new Artist("Jnu", "43.03.1123", "TotUva", 342, 24);
    Artist* ta = new Artist("Jwaerni", "13.13.3323", "Tota", 132, 234);
    try
    {
        serv.update_artist(ta->get_data(), ta->get_loc(), sa->get_nume_artist(), sa->get_data(), sa->get_loc(), sa->get_numar_locuri_disponibile(), sa->get_numar_locuri_vandute());
        assert(false);
    }
    catch (RepositoryException& e) {
    }
    catch (...) {
        assert(false);
    }
    assert(*serv.get_festival_at_position(0) == *a);
    try
    {
        serv.update_artist(a->get_data(), a->get_loc(), sa->get_nume_artist(), sa->get_data(), sa->get_loc(), sa->get_numar_locuri_disponibile(), sa->get_numar_locuri_vandute());
    }
    catch (...)
    {
        assert(false);
    }
    assert(*serv.get_festival_at_position(0) == *sa);
}

void TestService::test_update_film()
{
    Service serv;
    Repository* repo = new Repository_TXT();
    serv.set_repository(repo);
    Film* f = new Film("Ana", "areMere", "12.23.3123", "Locatie", 123, 3);
    serv.add_film(f->get_titlu(), f->get_actori(), f->get_data(), f->get_loc(), f->get_numar_locuri_disponibile(), f->get_numar_locuri_vandute());
    Film* sf = new Film("nuAna", "NuAreMere", "32.32.2322", "Gata", 23, 32);
    Film* tf = new Film("DEJANUMAISTIU", "SERIOSACUMA", "12.32.4232", "GATASERIOS", 32, 34);
    try
    {
        serv.update_film(tf->get_data(), tf->get_loc(), sf->get_titlu(), sf->get_actori(), sf->get_data(), sf->get_loc(), sf->get_numar_locuri_disponibile(), sf->get_numar_locuri_vandute());
        assert(false);
    }
    catch (RepositoryException& e) {
    }
    catch (...) {
        assert(false);
    }
    assert(*serv.get_festival_at_position(0) == *f);
    try
    {
        serv.update_film(f->get_data(), f->get_loc(), sf->get_titlu(), sf->get_actori(), sf->get_data(), sf->get_loc(), sf->get_numar_locuri_disponibile(), sf->get_numar_locuri_vandute());
    }
    catch (...)
    {
        assert(false);
    }
    assert(*serv.get_festival_at_position(0) == *sf);
}

void TestService::test_delete_festival()
{
    Service serv;
    Repository* repo = new Repository_TXT();
    serv.set_repository(repo);
    Film* f = new Film("Ana", "areMere", "12.23.3123", "Locatie", 123, 3);
    serv.add_film(f->get_titlu(), f->get_actori(), f->get_data(), f->get_loc(), f->get_numar_locuri_disponibile(), f->get_numar_locuri_vandute());
    try
    {
        serv.delete_festival(f->get_data(), f->get_loc(), f->get_numar_locuri_disponibile(), f->get_numar_locuri_vandute());
    }
    catch (RepositoryException& e)
    {
    }
    catch (...)
    {
        assert(false);
    }

}

TestService::TestService()
{
}

TestService::~TestService()
{
}

void TestService::test_all()
{
    this->test_get_all();
    this->test_get_festival_at_position();
    this->test_add_artist();
    this->test_add_film();
    this->test_update_artist();
    this->test_update_film();
    this->test_delete_festival();
}
