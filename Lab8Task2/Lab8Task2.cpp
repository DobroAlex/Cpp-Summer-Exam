
/* Author:DobroAlex
Created on 12 июня 2017 г., 19:31
*/
/*Создать класс - данные - абстрактный базовый класс.
*  Создать производные классы - данные типа сигнал,
* данные типа результат обработки и вспомогательные данные.
*  Все данные имеют функции отображения, сохранения и обработки. */
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#define LEN 10
using namespace std;
class Data {	//виртуальный базовый класс -- нет инстансов (экземпляров ), есть хотя бы одна чисто виртуальная функция 
public:
	Data() {
		cout << "Constructing DATA (aka abstract basic class)\n";
	}

	virtual char * Process(void) = 0;	 //чисто виртуальная функция 
	virtual void Show(void) = 0;		//чисто виртуальная функция
	virtual void Save(char * dest) = 0;//чисто виртуальная функция
	virtual  ~Data() {				  //чисто виртуальная функция
		cout << "Destroying Data\n"; //чисто виртуальная функция
	}
};
class Sig : public Data {
private:
	int ID;
	char * txt;
public:
	Sig() {
		txt = new char[LEN];
		for (int i = 0; i < LEN; i++) {
			txt[i] = '\0';
		}
		ID = 0;
	}
	Sig(int i) {
		txt = new char[LEN];
		for (int i = 0; i < LEN; i++) {
			txt[i] = '\0';
		}
		ID = i;
	}
	Sig(int i, char * str) {
		txt = new char[LEN];
		for (int i = 0; i < LEN; i++) {
			txt[i] = '\0';
		}
		strcpy(txt, str);
		ID = 0;
	}
	~Sig() {
		if (txt) {
			delete txt;
		}
		txt = NULL;
	}
	char * Process(void) {
		return txt;
	}
	void Show(void) {
		cout << "ID " << ID;
		for (int i = 0; i < strlen(txt); i++) {
			cout << txt[i];
		}
		cout << endl;
	}
	void Save(char * dest) {
		strcpy(dest, txt);
	}
};
class ProcRes : public Data {
private:
	char * txt;
public:
	ProcRes() {
		txt = new char[LEN];
		for (int i = 0; i < LEN; i++) {
			txt[i] = '\0';
		}
	}
	ProcRes(char * t) {
		txt = new char[LEN];
		for (int i = 0; i < LEN; i++) {
			txt[i] = '\0';
		}
		strcpy(txt, t);
	}
	~ProcRes() {
		if (txt) {
			delete txt;
		}
		txt = nullptr;
	}
	char * Process(void) {
		return txt;
	}
	void Show(void) {
		cout << "In processing:";
		for (int i = 0; i< strlen(txt); i++) {
			cout << txt[i] << endl;
		}
		cout << endl;
	}
	void Save(char * dest) {
		strcpy(dest, txt);
	}
};
class Dop : public Data {
private:
	int timestamp;
public:
	Dop() {
		timestamp = -0;
	}
	Dop(int t) {
		timestamp = t;
	}
	~Dop() {
		timestamp = -LEN;
		cout << "Bye,Dop\n";
	}
	void Show(void) {
		cout << "Timestamp" << timestamp << endl;
	}
	void Save(char * d) {
		char * tmp = new char[1];
		tmp[0] = (char)timestamp;
		strcpy(d, tmp);
		delete tmp;
		tmp = nullptr;
	}
	char * Process(void) {
		cout << "U can't process Dop,retard" << endl;
		return nullptr;
	}

};
int main(int argc, char** argv) {
	Data * ar[5];
	ar[1] = new Sig;
	ar[1]->Show();
	ar[2] = new Dop(333);
	ar[2]->Show();
	delete ar[2];       //равноценные вызвовы деструктора 
						//ar[2]->~Data();   //
	getchar();
	return 0;
}
