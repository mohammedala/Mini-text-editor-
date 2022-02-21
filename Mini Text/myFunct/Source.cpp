#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ArrList.h"
#include <thread>
#include <Windows.h>
using namespace std;

string openFile(ArrList & arr) 
{
	fstream file;
	string fileName;
	bool flag = true;
	string temp;
	while (flag) 
	{
		cout << "enter file name\n";
		cin >> fileName;
		cin.ignore();
		fileName = fileName + ".txt";
		file.open(fileName);
		if (file.is_open()) {
			flag = false;
		}
		else cout << "enter a valid file name\n";
	}
	while (!file.eof()) {
		getline(file, temp);
		arr.Append(temp);
	}
	file.close();
	cout << "\n\n";
	system("CLS");
	return fileName;
}
void SaveFile(ArrList & arr, string fileName) {
	fstream newFile(fileName, ios::out | ios::trunc);

	for (int i = 0; i < arr.Length(); i++) {
		if (i == arr.Length()-1)
			newFile << arr.At(i);
		else
			newFile << arr.At(i) << endl;
	}
	newFile.close();
	system("CLS");
	cout << "File is saved\n\n\n";
	this_thread::sleep_for(1000ms);
	system("CLS");
}
void addLine(ArrList & arr) {
	string temp;
	cout << "Write the new line:\n";
	cin.ignore();
	getline(cin,temp);
	arr.Append(temp);
	system("CLS");
	cout<<"line is added\n\n\n";
	this_thread::sleep_for(1000ms);
	system("CLS");
}
void Update(ArrList & arr)
{
	bool integer1 = true;
	int tempnum;
	string index;
	string temp;
	cout << "please enter the number you want to update\n";
    retry:
	cin >> index;
	for (int i = 0; i < index.length(); i++)
		if (isdigit(index[i]) == false)
			integer1 = false;
		else
			integer1 = true;
	if (integer1== false)
	{
		cout << " not a number\n";
		goto retry;
	}
	else
	{
		tempnum = stoi(index);
		if (tempnum > arr.Length() || tempnum <= 0)
		{
			cout << "Enter a valid number. " << endl;
			goto retry;
		}
		else
		{
			cout << " please enter the updateded line\n";
			cin.ignore();
			getline(cin, temp);
			arr.Update(tempnum - 1, temp);
			system("CLS");
			cout << "line is updated\n\n\n";
			this_thread::sleep_for(500ms);
			system("CLS");
		}
	}
}
void FindAll(ArrList & arr) {
	string x;
	bool exist = false;
	cout << "enter the word in search\n";
	cin >> x;

	for (int i = 0; i < arr.Length(); i++) {
		if (strstr(arr.At(i).c_str(), x.c_str()))
		{
			exist = true;
			cout << "line no: " << i + 1 << endl;
		}
	}
	if (exist == false)
	{
		cout << " Word Does not exist\n";
		this_thread::sleep_for(2000ms);
	}
	else
	{
		this_thread::sleep_for(2000ms);
	}
	cout << "\n\n\n";
	system("CLS");
}
void GetLine(ArrList & arr) {
	bool integer1 = true;
	int tempnum;
	string index;
	cout << "Enter line's number\n";
    retry:
	cin >> index;
	for (int i = 0; i < index.length(); i++)
		if (isdigit(index[i]) == false)
			integer1 = false;
		else
			integer1 = true;
	if (integer1 == false)
	{
		cout << " not a number\n";
		goto retry;
	}
	else
	{

		tempnum = stoi(index);
		if (tempnum > arr.Length() || tempnum <= 0)
		{
			cout << "NOT A VALID NUMBER! " << endl;
			goto retry;
		}
		else {
			cout << arr.At(tempnum - 1) << endl;
			cout << "\n\n\n";
			this_thread::sleep_for(2000ms);
			system("CLS");
		}
	}
}
void Delete(ArrList & arr) 
{
	bool integer1 = true;
	int tempnum;
	string index;
	cout << "Enter line's number\n";
    retry:
	cin >> index;
	for (int i = 0; i < index.length(); i++)
		if (isdigit(index[i]) == false)
			integer1 = false;
		else
			integer1 = true;
	if (integer1 == false)
	{
		cout << " not a number\n";
		goto retry;
	}
	else
	{
		tempnum = stoi(index);
		if (tempnum > arr.Length() || tempnum <= 0)
		{
			cout << "Insert a valid line number. " << endl;
			goto retry;
		}
		else
		{
			arr.deleteAt(tempnum - 1);
			system("CLS");
			cout << "line is deleted\n\n\n";
			this_thread::sleep_for(1000ms);
			system("CLS");
		}
	}
}
void Display(ArrList & arr) {
	cout << "\n\n<< ";
	for (int i = 0; i < arr.Length(); i++) 
	{
		if (i == (arr.Length() - 1))
			cout << arr.At(i) << " >>\n\n\n";
		else cout << arr.At(i)<<endl;
	}
}
void insert(ArrList & arr) {
	bool integer1 = true;
	int tempnum;
	string index;
	string temp;
	cout << "please enter number of the line you want to insert\n";
    retry:
	cin >> index;
	for (int i = 0; i < index.length(); i++)
		if (isdigit(index[i]) == false)
			integer1 = false;
		else
			integer1 = true;
	if (integer1 == false)
	{
		cout << " not a number\n";
		goto retry;
	}
	else
	{
		tempnum = stoi(index);
		if (tempnum > arr.Length() || tempnum <= 0)
		{
			cout << " please enter a valid number" << endl;
			goto retry;

		}
		else {
			cout << " please enter the updateded line\n";
			cin.ignore();
			getline(cin, temp);
			arr.insertAt(tempnum - 1, temp);
			cout << "line is updated\n\n\n";
			this_thread::sleep_for(1000ms);
			system("CLS");
		}
	}
}
void FindReplace(ArrList & arr) {
	bool exist = false;
	string y;
	string z;
	string temp;
	int counter = 0;
	int pos = 0;
	int index;
	cout << "Enter the word you want to change\n";
	cin >> y;
		cout << "Enter the subsituted word\n";
		cin >> z;
		for (int i = 0; i < arr.Length(); i++)
		{
			while ((index = arr.At(i).find(y, pos)) != string::npos) {
				temp = arr.At(i);
				counter++;
				pos = index + 1;
				temp.replace(index, y.length(), z);
				arr.Update(i, temp);
				exist = true;
			}
			pos = counter = 0;
		}
	if (exist == false)
	{
		cout << "Word not found\n";
		this_thread::sleep_for(1000ms);
	}
	else
	{
		cout << " word replaced\n";
		this_thread::sleep_for(2000ms);
	}
	system("CLS");
}
int main() {
	ArrList arr;
	char choice;
	bool flag = true;
	bool flag2 = true;
	string fName;
	fstream newFile;

	while (flag) {
		char sure;
		cout << "                   Mini Text Editor\n";
		cout << "Open an existing text file : 1\nMake a new text file : 2\nExit : 3\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			fName = openFile(arr);
		    menu:
			flag2 = true;
			while (flag2)
			{
				cout << "Add a new line : 1\nInsert in a line : 2\nGet line : 3\nDelete line : 4\n";
				cout << "Update line : 5\nFind all : 6\nFind and replace : 7\nDisplay Text : 8\n";
				cout << "Exit & Save : 9\nExit without Saving : 0\n";
				cin >> choice;
				if (choice < '0' || choice > '9')
				{
					cout << "Invalid entry, please enter a number between 1 and 9 " << endl;
					this_thread::sleep_for(200ms);
					system("CLS");
					goto menu;
				}
				else
				{
					switch (choice)
					{
					case '0':
						system("CLS");
						cout << "Are you sure you want to Exit witout saving\n Choose Y for Yes\n";
						cin >> sure;
						if (sure == 'y' || sure == 'Y')
						{
							flag2 = false;
							arr.Clear();
							break;
						}
						else
							goto menu;
					case '1':
						system("CLS");
						addLine(arr);
						break;
					case '2':
						system("CLS");
						insert(arr);
						break;
					case '3':
						system("CLS");
						GetLine(arr);
						break;
					case '4':
						system("CLS");
						cout << "Are you sure you want to Delete a line\n Choose Y for Yes\n";
						cin >> sure;
						if (sure == 'y' || sure == 'Y')
						{
							Delete(arr);
							break;
						}
						else
							goto menu;
						break;
					case '5':
						system("CLS");
						Update(arr);
						break;

					case '6':
						system("CLS");
						FindAll(arr);
						break;
					case '7':
						system("CLS");
						FindReplace(arr);
						break;
					case '8':
						system("CLS");
						Display(arr);
						break;
					case '9':
						system("CLS");
						cout << "Are you sure you want to Save and exit\n Type Y for yes\n";
						cin >> sure;
						if (sure == 'y' || sure == 'Y')
						{
							SaveFile(arr, fName);
							flag2 = false;
							arr.Clear();
							break;
						}
						else
						{
							goto menu;
						}
					default:
						system("CLS");
					}
				}
			}
			break;
		case '2':
			system("CLS");
			cout << "Enter file's name\n";
			cin >> fName;
			newFile.open(fName + ".txt", ios::out);
			newFile.close();
			cout << "A file is made\n\n";
			fName.clear();
			break;
		case '3':
			flag = false;
			break;
		default:
			system("CLS");
		}

	}
}