#pragma once
#include<string>
#include<iostream>
using namespace std;

class Book {
	string title;
	double price;
public:
	Book();
	Book(string title, double price);
	bool operator<(const Book& obj) const;//по этому оператору priority_queue сам будет автоматически сравнивать
	string getTitle()const;

	friend ostream& operator<<(ostream& os, Book obj);
};