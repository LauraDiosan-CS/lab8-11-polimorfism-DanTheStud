#pragma once
class TestFestival 
{
private:
	void test_implicit_constructor();
	void test_constructor_with_parameters();
	void test_copy_constructor();
	void test_clone();
	void test_get_data();
	void test_get_locatie();
	void test_get_nr_locuri_valabile();
	void test_get_nr_locuri_vandute();
	void test_set_data();
	void test_set_locatie();
	void test_set_nr_locuri_valabile();
	void test_set_nr_locuri_vandute();
	void test_assignment_operator();
	void test_equality_operator();
	void test_to_string();
public:
	void test_all();
};