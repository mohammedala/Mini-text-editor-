#include "ArrList.h"
#include <iostream>

 ArrList ::ArrList()
{
	size = 5;
	arr = new string[size];
	count = 0;
}

int ArrList ::Length()
{
	return count;
}

void ArrList::Append(string val) {
	if (count == size)
		Expand();
	arr[count] = val;
	count++;
}

void ArrList::Expand()
{
	size *= 2;
	string* tmp = new string[size];
	for (int i = 0; i < count; i++)
		tmp[i] = arr[i];
	delete [] arr;
	arr = tmp;
}

string ArrList::At(int pos)
{
	if(pos < count && pos >= 0)
	return arr[pos];
}

void ArrList::insertAt(int pos, string val)
{
	if (pos < count&& pos >= 0) {
		if (count == size)
			Expand();
		for (int i = count; i > pos; i--)
			arr[i] = arr[i - 1];
		arr[pos] = val;
		count++;
	}
}

void ArrList::deleteAt(int pos)
{
	if (pos < count && pos >= 0) {
		for (int i = pos; i < count - 1; i++)
			arr[i] = arr[i + 1];
		count--;
	}
}

ArrList::~ArrList(void)
{
	delete[] arr;
	count = 0;
}

void ArrList :: Update(int pos , string value) {

	if (pos < count && pos >= 0) {
		arr[pos] = value;
	}
}
void ArrList::Clear()
{
		count = 0;
}
