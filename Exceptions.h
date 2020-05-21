#pragma once

#include <iostream>
using namespace std;

class MyException : runtime_error
{
private:
	string message;
public:
	MyException(string msg) : runtime_error(msg), message(msg)
	{

	};
	const string what()
	{
		return message;
	}
};

