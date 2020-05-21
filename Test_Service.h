#pragma once
class TestService {
private:
    void test_get_all();
    void test_get_festival_at_position();
    void test_add_artist();
    void test_add_film();
    void test_update_artist();
    void test_update_film();
    void test_delete_festival();

public:
    TestService();
    ~TestService();
    void test_all();
};