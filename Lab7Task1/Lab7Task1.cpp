/* Author: DobroAlex
* Created on 11 июня 2017 г., 20:48
	Создать класс животное, имеющий классификацию (указатель на строку),
* число конечностей, число потомков. Определить конструкторы, деструктор и функцию печати.
*  Создать public-производный класс - домашнее животное, имеющий кличку.
* Определить конструкторы по умолчанию и с разным числом параметров, деструкторы, функцию печати.
* Определить функции переназначения названия клички и числа потомков.*/
#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#define KLASSLEN 20
#define KL KLASSLEN
using namespace std;
class Animal { //жЫвотное
private:
	char * klass; //классификатор
	int  limbs; //конечности
	int kids;// деточки
public:
	Animal() {
		klass = new char[KL];
		limbs = 4;
		kids = 88;
	}
	Animal(char *_klass) {
		klass = new char[KL];
		strcpy(klass, _klass);
		limbs = 4;
		kids = 88;
	}
	Animal(char *_klass, int l, int k) {
		klass = new char[KL];
		strcpy(klass, _klass);
		limbs = l;
		kids = k;
	}
	Animal(int l, int k) {
		klass = new char[KL];
		limbs = l;
		kids = k;
	}
	Animal(const Animal & a) {
		klass = new char[KL];
		strcpy(klass, a.klass);
		limbs = a.limbs;
		kids = a.kids;
	}
	~Animal() {
		if (klass) { //если был создан и ещё не удален
			delete  klass;
		}
		klass = nullptr; // для наджености теперь указывает на NULL 
	}
	void setKids(int k) {  //публичный сеттер привтаного члена 
		kids = k;
	}
	int getKids(void) const {
		return this->kids; // геттер с защитой от модификации 
	}
	char * getKlass(void) const {
		return this->klass;
	}

	friend ostream  & operator << (ostream & out, const Animal& a);
};
ostream  & operator << (ostream & out, const Animal& a) {
	out << "Classification: ";
	for (int i = 0; i< strlen(a.klass); i++) { //стрлен -- длина строки 
		out << a.klass[i];
	}
	out << " limbs " << a.limbs << " kids " << a.kids << endl;
	return out;
}
class HAnimal : public Animal {
	char  * name; //кличка
public:
	HAnimal(char * n, char * c, int l, int k) : Animal(c, l, k) { //передаем данные конструктору-роидтелю
		name = new char[KL];
		strcpy(name, n);
	}
	void changeName(char * n) { // передача константных строк вида "строка" в функцию, принимающую неконстантые строки, - быдлокод и undefined behaviour 
		strcpy(name, n);
	}
	void changeName(const char * n) { 
		strcpy(name, n);
	}
	friend ostream  & operator << (ostream & out, const HAnimal& a) {
		out << "Name : ";
		for (int i = 0; i < strlen(a.name); i++) {
			out << a.name[i];
		}
		out << ' ';
		out << a.getKids();
			out <<' ' <<  a.getKlass() << endl;
		return out;
	}
};
int main(int argc, char** argv) {
	Animal a("LolKek");
	cout << a;
	HAnimal b("BARYGA", "baryga", 3, 3);
	cout << b;
	getchar();
	return 0;
}

