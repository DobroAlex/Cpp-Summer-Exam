/* Author: DobroAlex
* Created on 12 июня 2017 г., 14:05
/*Создать иерархию классов студент и студент дипломник.
* Переопределить вывод в поток и ввод из потока, конструктор копирования,
* оператор присваивания через соответствующие функции базового класса. */
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Stud {
private:
	int kurs;
public:
	Stud() {	//конструктор по умолчанию 
		kurs = 1;
	}
	Stud(int y) {// с параметрами
		kurs = y;
	}
	Stud(const Stud& s) {//копирования 
		kurs = s.kurs;
	}
	void SetKurs(int k) {//сеттер - доступ к приватному члену
		kurs = k;
	}
	int GetKurs(void) const {// геттер -- получение приватного члена 
		return kurs;
	}
	~Stud() {//деструктор 

	}
	Stud & operator = (const Stud& s) { //оператор присваивания 
		kurs = s.kurs;
		return *this;
	}
	friend ostream & operator << (ostream &out, const Stud & s) { //перегрузка оператора вывода 
		out << "Kurs :" << s.kurs << endl;
		return out;
	}
};
class DStud : public Stud { // публичный наследник 
private:
	int dipl;//год получения диплома
public:
	DStud() {
		dipl = 0;
	}
	DStud(int d, int k = 5) : Stud(k) { // явный вызов конструктора класса-родителя, иначе будет вызван конструктор родителя по умолчанию
		dipl = d;
	}
	~DStud() {

	}
	friend ostream& operator  << (ostream & out, const DStud &d) {
		out << "Year " << d.dipl << " Kurs " << d.GetKurs() << endl;
		return out;
	}
	DStud & operator = (const DStud & d) {
		dipl = d.dipl;
		Stud(d.GetKurs());
		return *this;
	}
	int getBeniz(void) {	//пример функции, которая есть в наследнике, но нет в родителе 
		return (int)88;
	}
};
int main(int argc, char** argv) {
	Stud a(8), b = a;
	cout << a << b;
	DStud c(2007), d = c;
	DStud f(88, 77);
	cout << c << d;
	Stud * F = &f; 
	cout << F->GetKurs() << ' ' << ((DStud*)F)->getBeniz(); // указатель на родительский класс может быть использован для доступа к членам наследника, если они есть в родителе, иначе необходимо произвести преобразование к указателю на класс - наслденик  
	getchar();
	return 0;
}

