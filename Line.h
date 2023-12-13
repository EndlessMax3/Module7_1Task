#pragma once
#ifndef _LINE_H_
#define _LINE_H_
#include <iostream>
using std::cout;
using std::endl;

#include "Shape.h"

//класс-наследник Line
class Line : public Shape {

protected:
	int x1, y1, x2, y2;

public:
	//конструктор класса Line
	Line(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, const char* _color = DEFAULT_COLOR) : Shape(_color), x1(_x1), y1(_y1), x2(_x2), y2(_y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}

	int GetX1() const { return x1; }
	int GetY1() const { return y1; }
	int GetX2() const { return x2; }
	int GetY2() const { return y2; }

	Line* SetX1(int _x) { x1 = _x; return this; }
	Line* SetY1(int _y) { y1 = _y; return this; }
	Line* SetX2(int _x) { x2 = _x; return this; }
	Line* SetY2(int _y) { y2 = _y; return this; }

	//отобразить линию в консоли
	void draw() const override
	{
		//this->Shape::draw(); вызов метода родителя
		cout << "Line(" << GetX1() << ", " << GetY1() << ") "<< '(' << GetX2() << ", " << GetY2() << ") " << GetColor() << endl;
	}

	//сместить линию на dx1, dy1, dx2, dy2
	void moveBy(int dx = 0, int dy = 0)
	{
		x1 += dx;
		y1 += dy;
		x2 += dx;
		y2 += dy;
	}

	//увеличить линию на factor
	void scale(double factor)
	{
		x2 = (x2 - x1) * factor + x1;
		y2 = (y2 - y1) * factor + y1;
	}

	//деструктор линии
	~Line()
	{
		cout << "~Line()" << endl;
	}
};

#endif // !_LINE_H_

