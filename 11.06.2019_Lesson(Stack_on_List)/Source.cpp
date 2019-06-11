#include<list>
#include<vector>
#include<stack>
using namespace std;

int main() {

	stack<list<int>, int> s; //на без листа, т.е. будут вызываться методы для листа и память будет распределяться как в листе
	stack<vector<int>, int> s1;// на базе вектора
	stack<deque<int>, int> s2;//на базе двусторонней очереди

	system("pause");
	return 0;
}