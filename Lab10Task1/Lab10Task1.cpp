/*
* Author: DobroAlex
* Created on 10 июня 2017 г., 18:02
*/
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#define SHITLOAD 20
#define SHIT SHITLOAD
#define SL SHIT
using namespace std;

/*
*
*/
class Vector { //описываю double - вектор, если это не_понятно, то см. классы и перегрузку операторов
private:
	double * ptr;
	int size;
public:
	Vector() {
		size = 0;
		ptr = new double[size];
		for (int i = 0; i<size; i++) {
			ptr[i] = 0;
		}
	}
	Vector(int i) {
		size = i;
		ptr = new double[size];
		for (int i = 0; i<size; i++) {
			ptr[i] = 0;
		}
	}
	Vector(int i, double j) {
		size = i;
		ptr = new double[size];
		for (int i = 0; i<size; i++) {
			ptr[i] = j;
		}
	}
	Vector(const Vector &v) {
		size = v.size;
		ptr = new double[size];
		for (int i = 0; i<size; i++) {
			ptr[i] = v.ptr[i];
		}
	}
	~Vector() {
		if (ptr) {
			delete[] ptr;
		}
		ptr = NULL;
	}
	double & operator [] (int i) const {
		try {
			if (i < 0 || i > size - 1) {
				throw - 1;
			}
			return this->ptr[i];
		}
		catch (string i) {
			cout << i << endl;
			exit(-1);
		}
	}
	Vector & operator  = (const Vector &v) {
		try {
			if (size != v.size) {
				throw string("Size mismatch");
			}
			for (int i = 0; i<size; i++) {
				ptr[i] = v[i];
			}
			return *this;
		}
		catch (string i) {
			cout << i << endl;
			exit(-1);
		}

	}
	Vector operator += (Vector &v) {
		try {
			if (this->size != v.size) {
				throw string("Size mismatch");
			}
			for (int i = 0; i<v.size; i++) {
				(*this)[i] += v[i];
			}
			return *this;
		}
		catch (string i) {
			cout << i << endl;
			exit(-1);
		}
	}
	Vector operator -= (Vector &v) {
		try {
			if (this->size != v.size) {
				throw string("Size mismatch");
			}
			for (int i = 0; i<v.size; i++) {
				(*this)[i] -= v[i];
			}
			return *this;
		}
		catch (string i) {
			cout << i << endl;
			exit(-1);
		}
	}
	Vector operator *= (double j) {
		for (int i = 0; i<size; i++) {
			(*this)[i] *= j;
		}
		return *this;
	}
	friend bool operator == (const Vector &v1, const Vector &v2);
	friend Vector  operator + (const Vector &v1, const Vector &v2);
	friend Vector  operator - (const Vector &v1, const Vector &v2);
	friend double   operator * (const Vector &v1, const Vector v2);
	friend ostream & operator << (ostream & out, const Vector  & v) {
		cout << "[   ";
		for (int i = 0; i<v.size; i++) {
			out << v[i] << "   ";
		}
		out << ']' << endl;
		return out;
	}
};
Vector  operator + (const Vector &v1, const Vector &v2) {
	try {
		if (v1.size != v2.size) {
			throw string("Size mismatch!");
		}
		Vector ans(v1.size);
		for (int i = 0; i<v1.size; i++) {
			ans[i] = v1[i] + v2[i];
		}
		return ans;
	}
	catch (string i) {
		cout << i << endl;
		exit(-1);
	}
}
Vector  operator - (const Vector &v1, const Vector &v2) {
	try {
		if (v1.size != v2.size) {
			throw - 50;
		}
		Vector ans(v1.size);
		for (int i = 0; i<v1.size; i++) {
			ans[i] = v1[i] - v2[i];
		}
		return ans;
	}
	catch (string i) {
		cout << i << endl;
		exit(-1);
	}
}
double   operator * (const Vector &v1, const Vector v2) {
	try {
		if (v1.size != v2.size) {
			throw string("Size mismatch");
		}
		double ret = 0;
		for (int i = 0; i<v1.size; i++) {
			ret += v1[i] * v2[i];
		}
		return ret;
	}
	catch (string i) {
		cout << i << endl;
		exit(-1);
	}
}
bool operator == (const Vector &v1, const Vector &v2) {
	if (v1.size != v2.size) {
		return false;
	}
	for (int i = 0; i<v1.size; i++) {
		if (v1[i] != v2[i]) {
			return false;
		}

	}
	return true;
}
template <class T> int getByKey(T* arr, T key, int size) { // шаблонный метод взятия по индексу  : указатель типа T (сам массив), Ключ типа Т (значение элемента, который ищем), размер массива (у динамических нельзя определить через sizeof)
	try {
		if (size < 0 || arr == nullptr) { //если размер массива пытаются установить <0 или если массив удален / еще не создан
			throw string("BULLSHIT"); //бросаем ошибку
		}

		for (int i = 0; i<size; i++) {
			if (arr[i] == key) {
				return i;
			}
		}
		return -1; // если не нашли, то возвращем такое значение (может быть быдло-решением, т.к не будет работать для unsigned и структур)
	}
	catch (string msg) { //ловим ошибку
		cout << msg;
		exit (-100); //выходим аварийно из программы
	}
}
int main(int argc, char** argv) {
	int arr[SHITLOAD];
	for (int i = 0; i < SL; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << endl;
	}
	Vector ar[SL];
	for (int i = 0; i<SL; i++) {
		cout << ar[i];
	}
	cout << endl << getByKey(arr, 4, -12);
	cout << endl << getByKey(ar, ar[2], SL);
	long double ar1[SL];
	for (int i = 0; i<SL; i++) {
		ar1[i] = rand() % 1000000;
		cout << ar1[i] << endl;
	}
	cout << getByKey(ar1, (long double)18456, SL);
	getchar();
	return 0;
}

