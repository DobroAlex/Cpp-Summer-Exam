/* Author: DobroAlex
*
* Created on 12 июня 2017 г., 21:10
*/
/*Задание 1 .
Создать иерархию типов - корабль, пассажирский транспорт и пассажирский корабль.
*  Классы должны конструкторы, включая конструктор копирования, виртуальные деструкторы,
*  перегруженные функции вывода в поток и ввода в поток. */
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
using namespace std;
class Ship {  
private:
	int draught;//водоизмещение
public:
	Ship() { // конструктор по умолчанию
		draught = 0;
	}
	Ship(int d) { // конструктор с параметром 
		draught = d;
	}
	Ship(const Ship&s) { // конструктор копирования
		draught = s.draught;
	}
	virtual  ~Ship() { // виртуальный деструктор, может быть переопределен наследниками 
		cout << "Bye, Ship" << endl;
		draught = 0;
	}
	friend ostream& operator << (ostream & out, const Ship& s);
	friend istream& operator >> (istream & out, Ship& s);
};
ostream& operator << (ostream & out, const Ship& s) {
	out << "Draught is " << s.draught << endl;
	return out;
}
istream& operator >> (istream & out, Ship& s) {
	cin >> s.draught;
	return out;
}
class Transp {
private:
	int pass; //число пассажиров
public:
	Transp() {  // конструктор по умолчанию
		pass = 0;
	}
	Transp(int p) {// конструктор с параметром 
		pass = p;
	}
	Transp(const Transp & t) {// конструктор копирования
		pass = t.pass;
	}
	virtual  ~Transp() {// виртуальный деструктор, может быть переопределен наследниками 
		cout << "bye,transp" << endl;
		pass = 0;
	}
	friend ostream& operator << (ostream & out, const Transp& s);
	friend istream& operator >> (istream & out, Transp& s);
};
ostream& operator << (ostream & out, const Transp& s) {
	out << "Num of passengers : " << s.pass << endl;
	return out;
}
istream& operator >> (istream & out, Transp& s) {
	out >> s.pass;
	return out;
}
class PasShip : virtual   public Ship, virtual     public Transp { // виртуальное наследование гарантирует отсутствие повторяющихся полей (ТУТ  НЕТ НЕОБХОДИМОСТИ ИСПОЛЬЗОВАТЬ)
	int num; //номер корабля
public:
	PasShip() {
		num = 0;
	}
	PasShip(int n, int d, int p) : Ship(d), Transp(p) { //передача параметров конструкторам родителй с явным вызовом
		num = n;
	}
	PasShip(const PasShip &p, const Ship & s, const Transp& t) : Ship(s), Transp(t) {  //передача параметров конструкторам копирования  родителй с явным вызовом
		num = p.num;
	}
	~PasShip() { //деструктор. Не виртуален, т.к не предпологается переопределение 
		cout << "Bye, pasship\n";
		num = 0;
	}
	friend ostream& operator << (ostream & out, const PasShip& s);
	friend istream& operator >> (istream & out, PasShip& s);
};
ostream& operator << (ostream & out, const PasShip& s) {
	cout << "Num" << s.num << endl;
	return out;
}
istream& operator >> (istream & out, PasShip& s) {
	out >> s.num;
	return out;
}
int main(int argc, char** argv) {
	Ship A(100);
	cout << A;
	Transp B(200);
	cout << B;
	PasShip C(300, 400, 500);
	return 0;
}