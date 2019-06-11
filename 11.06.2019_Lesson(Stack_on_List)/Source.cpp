#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include"Book.h"
using namespace std;

class setBook{
public:
	bool operator()(const Book& obj1, const Book& obj2) const {//predicator
		return(obj1.getTitle() < obj2.getTitle());//по алфавиту
	}
};

int main() {

	//stack<list<int>, int> s; //на без листа, т.е. будут вызываться методы для листа и память будет распределяться как в листе
	//stack<vector<int>, int> s1;// на базе вектора
	//stack<deque<int>, int> s2;//на базе двусторонней очереди


	//priority_queue<int> q1;//по возрастанию будут располагаться элементы, извлекаются с конца, т.е. с максимального значения 
	//т.е. сортировка идет и извлекается сначала наибольшее - в основном для задач для аукционов
	//q1.push(10);
	//q1.push(15);
	//q1.push(12);
	//q1.push(12);
	//q1.push(5);

	//ассоциированный контейнер - у которого есть ключ
	map<string, string> m1; // 1 string -type of key (use simple data type), 2 string type of value

	//ключи в мэп добаляются по типу бинарного дерева, т.е. автоматически сортируется по возрастанию/по алфавиту
	m1["banana"] = "yellow";//banana is a key
	m1["apple"] = "red";
	m1["apple"] = "green";//through operator[] rewrote value "red" to "green"

	m1.insert(pair<string, string>("banana", "green"));//если через insert под новый ключ добавится значение, а под старый проигнорит, ничего не перезапишет в отличие от []
	m1.insert(pair<string, string>("kiwi", "green"));

	for (/*map<string, string>::iterator*/auto it = m1.begin(); it != m1.end(); it++)//
		cout << it->first/*key*/ << " " << it->second/*value*/ << endl;



	setlocale(LC_ALL, "");
	ifstream in_file("in.txt");


	priority_queue<Book> q1;
	//чтобы сет помещал элменты не по ценам, а по названиям книг без повторящихся книг, в сете нельзя использовать предикатор, только функтор с оператором круглых скобок! т.е. класс нужен
	set<Book, setBook>s1;//в сете данные отсортированы как и в прайорити_кью, но данные все уникальны! нет повторений

	string title;
	double price;

	while (!in_file.eof()) {
		getline(in_file, title, '#');
		in_file >> price;
		in_file.ignore();//to ignore "\n"
		q1.push(Book(title, price));
	}

	while (!q1.empty()) {
		//cout << q1.top() << endl;
		s1.insert(q1.top());
		q1.pop();
	}

	for (auto it = s1.begin(); it != s1.end(); it++)
		cout << *it << endl;
	//auto это оператор для автоматчиеского определения типа итератора - int, book и тд (set<int>::iterator it)

	system("pause");
	return 0;
}