/*
* Author: DobroAlex (https://github.com/DobroAlex)
*
* Created on 10 июня 2017 г., 19:06
*/
#include "stdafx.h"	//для совместимости с Visual Studdio 
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
*
*/
template <class T > class Arr { //шаблонный класс
	T* ptr; //указатель на тип, собственно сам массив
	int size; //явный размер
public:
	Arr() { // конструктор по умолчанию
		ptr = new T[size];

	}
	Arr(int s) { //  конструктор с параметрами , создает массив размера s тип Т
		size = s;
		ptr = new T[s];
		for (int i = 0; i <size; i++) {
			ptr[i] = i;
		}
	}
	Arr(const Arr & a) { // конструктор копирования 
		if (ptr) {		/* можно обойтись без этого */
			delete[] ptr;
		}
		size = a.size;
		ptr = new T[size]; /*захватываем память*/
		for (int i = 0; i< size; i++) { /*копируем элементы*/
			ptr[i] = a.ptr[i];
		}
	}
	~Arr() { //деструктор
		if (ptr) {	//если деструктор до этого не вызывался и ptr != null
			delete[] ptr;	//удаляем ptr
		}
		ptr = nullptr; /*ставим указатель на NULL -- избавляемся от возможных ошибок в будущем */
	}
	T  &  operator [] (int i) { //перегрузка оператора взятия эл-та
		try {
			if (i < 0) { //если индекс меньше 0 ...
				throw string("Out of index");	// ... бросаем исключение ...
			}
			return this->ptr[i];
		}
		catch (string msg) { //... ловим исключение
			cout << msg << endl;
			exit(-100); // выходим из программы с return -100;
		}
	}
	T & operator = (const Arr &ar) { //оператор присванивания поэлементно
		try {
			if (size != ar.size) { //размеры должны совпадать
				throw string("Mismatch!");
			}
			for (int i = 0; i< size; i++) {
				ptr[i] = ar[i];
			}
			return *this;
		}
		catch (string msg) {
			cout << msg;
			exit(-77);
		}
	}
	void show(void) { //вместо перегрузки << 
		for (int i = 0; i<size; i++) {
			cout << ptr[i] << "   ";
		}
		cout << endl;
	}
	int getSize(void) { //геттер - публичная функция, возвращающая приватный член 
		return this->size;
	}
};
int main(int argc, char** argv) {
	Arr<int> jopa(100);
	jopa.show();
	Arr <string> bep(888);
	bep.show();
	Arr <  long double> ebin(1001);
	ebin.show();
	getchar();
	return 0;

}

