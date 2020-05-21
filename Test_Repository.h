#pragma once
#include "Repository.h"

class TestRepository {
private:
    const string file_name_in_TXT = "Test_festivale_in.txt";
    const string file_name_out_TXT = "Test_festivale_out.txt";
    const string file_name_in_CSV = "Test_festivale_in.csv";
    const string file_name_out_CSV = "Test_festivale_out.csv";

    //folosit pt. a testa lucrul cu fisiere
    vector<Festival*> festivale_in;

    void test_get_size();
    void test_get_all();
    void test_get_festival();
    void test_add_festival();
    void test_update_festival();
    void test_delete_festival();

    void test_load_from_file_TXT();
    void test_load_from_file_CSV();
    void test_save_to_file_TXT();
    void test_save_To_file_CSV();
public:
    TestRepository();
    ~TestRepository();
    void test_all();
};