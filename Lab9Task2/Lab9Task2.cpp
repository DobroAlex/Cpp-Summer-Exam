
/*
* Author: DobroAlex
*
* Created on 13 июня 2017 г., 14:31
*/
/*Создать иерархию типов -
* транспорт, корабль, пассажирский транспорт и пассажирский корабль.
*  Использовать виртуальные базовые классы.*/
#define _CRT_SECURE_NO_WARNINGS 
#include "stdafx.h" //совместимость с VS 
#include <cstdlib>
#include <iostream>
#include <cstring>
#define LEN 150
using namespace std;
//будем использовать виртуальное наследование от базовых классов
class Trans {
private:
	int pass;
public:
	Trans() { //конструктор по умолчанию
		cout << "Creating Trans default\n";
		pass = 0;
	}
	Trans(int p) { // с параметрами 
		cout << "Creating Trans\n";
		pass = p;
	}
	Trans(const Trans & t) { // копирования
		cout << "Creating Trans\n";
		pass = t.pass;
	}
	virtual ~Trans() { // виртуальный деструктор,можно переопределить у наследников
		cout << "Bye,Trans\n";
		pass = -1;
	}
	int GetPass(void) const { // геттер -- получает значение
		return pass;
	}
	void SetPass(int p) { // сеттер -- устанавливает значение, можно будет получить доступ к private членам родителя у  наследника
		pass = p;
	}
	friend ostream & operator << (ostream & out, const Trans &t) {	//дружественные перегрузки НЕ наследуются 
		out << "Pass num :" << t.GetPass() << endl;
		return out;
	}
};
class Ship : virtual public Trans { // виртуальное наследование,хотя в нем нет необходимости,Virtual можно убрать тут
private:
	int draught; //водоизмещение
public:
	Ship() {//конструктор по умолчанию
		cout << "Creating Ship\n";
		draught = 0;
	}
	Ship(int d, int p) : Trans(p) {	// с параметрами , ОБЯЗАТЕЛЬНО явно вызываем конструктор родителя 
		cout << "Creating Ship\n";
		draught = d;
	}
	Ship(const Ship& s, const Trans & t) : Trans(t) {	// копирования, ОБЯЗАТЕЛЬНО явно вызываем конструктор родителя 
		cout << "Creating Ship\n";
		this->draught = s.draught;
	}
	virtual ~Ship() {	 // виртуальный деструктор,можно переопределить у наследников
		cout << "Bye,ship\n";
		draught = -01;
	}
	int GetDraught(void)const {	 // геттер -- получает значение
		return draught;
	}
	void SetDraught(int d) {	// сеттер -- устанавливает значение, можно будет получить доступ к private членам родителя у  наследника
		draught = d;
	}
	friend ostream & operator << (ostream & out, const Ship &t) {
		out << "Pass num :" << t.GetPass() << " Draught : " << t.GetDraught() << endl;
		return out;
	}
};
class PasTran : virtual public Trans {	//пассажирский транспорт
										// виртуальное наследование,хотя в нем нет необходимости,Virtual можно убрать тут
private:
	int speed;
public:
	PasTran() {//конструктор по умолчанию
		cout << "Creating PasTran\n";
		speed = 0;
	}
	PasTran(int s, int p) : ::Trans(p) {// с параметрами , ОБЯЗАТЕЛЬНО явно вызываем конструктор родителя 
		cout << "Creating PasTran\n";
		speed = s;
	}
	PasTran(const PasTran & p, const Trans & t) : Trans(t) {// копирования, ОБЯЗАТЕЛЬНО явно вызываем конструктор родителя 
		cout << "Creating PasTran\n";
		speed = p.speed;
	}
	virtual ~PasTran() { // виртуальный деструктор,можно переопределить у наследников
		cout << "Bye PasTran\n";
		speed = -1;
	}
	int GetSpeed(void)const { // геттер -- получает значение
		return this->speed;
	}
	void SetSpeed(int s) { // сеттер -- устанавливает значение, можно будет получить доступ к private членам родителя у  наследника
		this->speed = s;
	}
	friend ostream & operator << (ostream & out, const PasTran &t) {
		out << "Pass num :" << t.GetPass() << " Speed: " << t.GetSpeed() << endl;
		return out;
	}
};
class PasShip : virtual public ::Ship, virtual public ::PasTran { // обязательно виртуально наследуем, иначе в private секции будет два pass
private:
	char * name;
public:
	PasShip() { //конструктор по умолчанию
		name = new char[LEN];
		cout << "Creating PasShip\n";
	}
	PasShip(char * n, int d, int p, int a) : Ship(d, a), PasTran(p, a), ::Trans(a) {//необходимо явно вызвать конструктор суперкалсса, иначе родители PasShip будут вызывать конструкторы по умолчанию вместо нужных конструкторов с параметрами 
		cout << "Creating PasShip\n";
		name = new char[LEN];
		strcpy(name, n);
	}
	PasShip(const PasShip &p, const Ship &s, const PasTran &pt, const Trans& t) : Ship(s, t), PasTran(pt, t) {//необходимо явно вызвать конструктор суперкалсса, иначе родители PasShip будут вызывать конструкторы по умолчанию вместо нужных конструкторов с параметрами 
		cout << "Creating PasShip\n";
		name = new char[LEN];
		strcpy(name, p.name);
	}
	char * GetName(void)const { //имя как указатель на строку
		return name;
	}
	void SetName(char * n) {
		strcpy(name, n); //копирование строк
	}
	virtual ~PasShip() {// виртуальный деструктор,можно переопределить у наследников,но их не будет
		if (name) {
			delete name;
		}
		name = nullptr; //на всякий случай ставим как указатель на NULL чтоб избежать возможных ошибок при  возможном повторном вызвове
		cout << "Bye, PasShip\n";
	}
	friend ostream & operator << (ostream & out, const PasShip& t) {
		out << "Pass num :" << t.GetPass() << " Draught : " << t.GetDraught() << " Speed :" << t.GetSpeed() << " Name is :" << t.GetName() << endl;
		return out;
	}
};
int main(int argc, char** argv) {
	Trans a(100);
	Ship b(200, 300);
	PasTran c(300, 400);
	PasShip d("Adolf", 500, 600, 700);
	cout << a << b << c << d;
	Trans * ar[3];
	ar[0] = new Ship(2000, 3000);
	ar[1] = new PasTran(3000, 4000);
	ar[2] = new PasShip("LushnikovIsLOVE", 5000, 6000, 7000);
	for (int i = 0; i < 3; i++) {
		cout << ar[i];

		delete ar[i];

	}
	return 0;
}

