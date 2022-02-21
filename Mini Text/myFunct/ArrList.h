#pragma once
#include <string>
using namespace std;

class ArrList
{
	string * arr;
	int size, count;
public:
	ArrList();
	int Length();
	void Append(string);
	void Expand();
	string At(int);
	void insertAt(int, string);
	void deleteAt(int);
	~ArrList(void);
	void Update(int , string);
	void Clear();
};

