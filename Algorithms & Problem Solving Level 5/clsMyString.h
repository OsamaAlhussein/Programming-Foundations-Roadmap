#pragma once
#include<iostream>
using namespace std;
class claMyString
{
private:
	string _Value;

public:

	void setValue(string Value)
	{
		_Value = Value;
	}

	string getValue()
	{
		return _Value;
	}

	

};
