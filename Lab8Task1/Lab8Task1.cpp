
/* Author: DobroAlex
* Created on 12 июня 2017 г., 16:47
*/
/*Задание 1 .
Создать абстрактный базовый класс с виртуальной функцией - площадь.
*  Создать производные классы: прямоугольник, круг, прямоугольный треугольник, трапеция со своими функциями площади.
*  Для проверки определить массив ссылок на абстрактный класс, которым присваиваются адреса различных объектов.
* Площадь трапеции:S=(a+b)h/2
*/


#include <cmath>
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#define M_PI 	3.14159265358979323846	//если ваш компилятор ретард и не умеет в cmath
using namespace std;

class ABS { //абстрактный класс. Все методы виртуальны, не будет иметь экземпляров
public:
	virtual  float  Space(void) = 0;
	virtual void Show(void) = 0;

};
class Rect : public ABS {
private:
	int x, y;
public:
	Rect(int xx, int yy) {
		x = xx;
		y = yy;
	}
	float Space(void) {
		return (float)x*y;
	}
	void Show(void) {
		cout << "X:" << x << " Y:" << y << " Space" << this->Space() << endl;
	}
	~Rect() {
		cout << "Bye,Rect" << endl;
	}
};
class Circle : public ABS {
private:
	int rad;
public:
	Circle(int r) {
		rad = r;
	}
	float Space(void) {
		return(float)(M_PI * (rad*rad));
	}
	void Show(void) {
		cout << "Rad " << rad << " Space " << this->Space() << endl;
	}
	~Circle() {
		cout << "Bye, circle" << endl;
	}
};
class Trian : public ABS {
private:
	int a, b, c; //катеты и гипотенуза
public:
	Trian(int aa = 3, int bb = 4, int cc = 5) {
		a = aa;
		b = bb;
		c = cc;
	}
	float Space(void) {
		return (float)((1 / 2.0)*a*b);
	}
	void Show(void) {
		cout << "A:" << a << " B: " << b << " C: " << c << " Space " << this->Space() << endl;
	}
	~Trian() {
		cout << "Bye, trian" << endl;
	}
};
class Trap : public ABS {
private:
	int a, b, h;//основания и высота
public:
	Trap(int A, int B, int H) {
		a = A;
		b = B;
		h = H;
	}
	float Space(void) {
		return (float)((a + b)*h) / 2.0;
	}
	void Show(void) {
		cout<<endl << "A:" << a << " B:" << b << " H:" << h << " Space: " << Space() << endl;
	}
	~Trap() {
		cout << "Bye, Trap" << endl;
	}
};
//указатель на базовый класс может быть использован для обращения к любому класс-наследнику 
int main(int argc, char** argv) {
	Rect RRR(3, 4);
	ABS* ar[5];//массив ссылок на абстрактный класс
	ar[0] = new Rect(3, 4);  // создание нового объекта-наследника, не как требует задание 
	ar[0]->Show();
	ar[1] = new Circle(8);
	ar[1]->Show();
	ar[2] = new Trian();
	ar[2]->Show();
	ar[3] = new Trap(3, 4, 5);
	ar[3]->Show();
	ar[4] = &  RRR; //присванивание адреса объекта , как и требует задание 
	ar[4]->Show();
	getchar();
	return 0;
}