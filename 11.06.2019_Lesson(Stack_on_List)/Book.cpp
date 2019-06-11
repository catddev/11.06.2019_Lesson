#include "Book.h"

Book::Book()
{
	title = "";
	price = 0;
}

Book::Book(string title, double price)
{
	this->title = title;
	this->price = price;
}

bool Book::operator<(const Book & obj) const
{
	return(this->price > obj.price);//> не ошибка, а чтобы сет выводил по наименьшей цене
}

string Book::getTitle() const
{
	return title;
}

ostream & operator<<(ostream & os, Book obj)
{
	os << obj.title << " " << obj.price;
	return os;
}
