#pragma once
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include <iostream>
using std::cout;
using std::endl;

#include "Shape.h"
//класс-наследник Circle
class Circle : public Shape {

protected:
	int x, y, r;

public:
	//конструктор по-умолчанию
	Circle(int _x = 0, int _y = 0, int _r = 0, const char* _color = DEFAULT_COLOR) : Shape(_color), x(_x), y(_y), r(_r)
	{
		cout << "Circle(int,int,int)" << endl;
	}

	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetR() const { return r; }

	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	void SetR(int _r) { r = _r; }

	//вывод круга в консоль
	void draw() const override
	{
		cout << "Circle(" << GetX() << ", " << GetY() << ", " << GetR() << ") " << GetColor() << endl;
	}

	//увеличить круг на factor
	void scale(double factor)
	{
		r = r * factor;
	}

	//сместить круг на dx, dy
	void moveBy(int dx, int dy)
	{
		x += dx;
		y += dy;
	}

	//деструктор круга
	~Circle()
	{
		cout << "~Circle()" << endl;
	}
};

#endif // !_CIRCLE_H_

