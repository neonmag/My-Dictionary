#include <iostream>
#include "Classes.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	Dictionary obj;
	obj.Input();
	system("CLS");
	obj.Output();
	/*cout << "\nEnter word: ";
	string temp;
	cin >> temp;
	if (obj.FindWord(temp) != -1)
	{
		cout << "\nIndex = " << obj.FindWord(temp) << "\n";
	}
	string tempRus, tempEng;
	cout << "\nEnter russian word: ";
	cin >> tempRus;
	cout << "\nEnter english word: ";
	cin >> tempEng;
	int index;
	cout << "\nEnter index: ";
	cin >> index;
	obj.Change(tempRus, tempEng, index);
	obj.Deleting("English");
	cout << "\nEnter index: ";
	cin >> index;
	obj.Editing(index);*/

	system("CLS");
	obj.Sorting();
	obj.Output();
}