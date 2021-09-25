#pragma once

#include<string>
#include <vector>
#include <algorithm>
using namespace std;

class Pair
{
	mutable string rus;
	mutable string eng;
public:
	Pair();
	Pair(string r, string e);

	void Input();
	void Print();

	string GetRus()const;
	string GetEng()const;
	void SetRus(string r);
	void SetEng(string e);
};

Pair::Pair()
{
	this->rus = { 0 };
	this->eng = { 0 };
}

inline Pair::Pair(string r, string e)
{
	this->rus = r;
	this->eng = e;
}

inline void Pair::Input()
{
	setlocale(LC_ALL, "RUS");
	cout << "\nEnter russian word: ";
	cin >> this->rus;
	cout << "\nEnter english word: ";
	cin >> this->eng;
	cout << endl;
}

inline void Pair::Print()
{
	setlocale(LC_ALL, "RUS");
	cout << this->rus << "\t" << this->eng << endl;
}

inline string Pair::GetRus() const
{
	return this->rus;
}

inline string Pair::GetEng() const
{
	return this->eng;
}

inline void Pair::SetRus(string r)
{
	this->rus = r;
}

inline void Pair::SetEng(string e)
{
	this->eng = e;
}

class Dictionary
{
	Pair* arr;
	int size;
public:
	Dictionary();
	Dictionary(int s);
	Dictionary(const Dictionary& s);
	Dictionary& operator =(const Dictionary& s)
	{
		this->arr = new Pair[s.size];
		this->size = s.size;
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = s.arr[i];
		}
	}
	~Dictionary();
	void Input();
	void Output();
	int FindWord(string s)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i].GetEng() == s || this->arr[i].GetRus() == s)
			{
				return i;
			}
		}
		return -1;
	}
	void Change(string rus, string eng, int index)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (i == index)
			{
				this->arr[i].SetEng(eng);
				this->arr[i].SetRus(rus);
			}
		}
	}
	void Deleting(string s)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (s == arr[i].GetEng())
			{
				arr[i].SetEng(0);
			}
			else if (s == arr[i].GetRus())
			{
				arr[i].SetRus(0);
			}
		}
	}
	void Editing(int index)
	{
		setlocale(LC_ALL, "RUS");
		string tempRus, tempEng;
		cout << "\nEnter russian word: ";
		cin >> tempRus;
		cout << "\nEnter english word: ";
		cin >> tempEng;
		cout << endl;
		for (int i = 0; i < this->size; i++)
		{
			if (i == index)
			{
				arr[i].SetEng(tempEng);
				arr[i].SetRus(tempRus);
			}
		}
	}
	void Sorting()
	{
		string* temp = new string[this->size];
		string* tempRus = new string[this->size];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->arr[i].GetEng();
			tempRus[i] = this->arr[i].GetRus();
		}
		sort(temp, temp + this->size);
		sort(tempRus, tempRus + this->size);
		Pair* ptrWord = new Pair[this->size];
		for (int i = 0; i < this->size; i++)
		{
			ptrWord[i] = this->arr[this->FindWord(temp[i])];
			ptrWord[i] = this->arr[this->FindWord(tempRus[i])];
		}
		delete[] this->arr;
		this->arr = ptrWord;
	}
};

Dictionary::Dictionary()
{
	this->arr = nullptr;
	this->size = 0;
}

inline Dictionary::Dictionary(int s)
{
	this->size = s;
	this->arr = nullptr;
}

inline Dictionary::Dictionary(const Dictionary& s)
{
	this->arr = new Pair[s.size];
	this->size = s.size;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = s.arr[i];
	}
}

inline Dictionary::~Dictionary()
{
	delete[]this->arr;
	this->arr = nullptr;
}

inline void Dictionary::Input()
{
	cout << "\nEnter size: ";
	cin >> this->size;
	this->arr = new Pair[this->size];
	for (int i = 0; i < this->size; i++)
	{
		cout << "\nEnter russian and english words: ";
		this->arr[i].Input();
		cout << endl;
	}
}

inline void Dictionary::Output()
{
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i].Print();
	}
}
