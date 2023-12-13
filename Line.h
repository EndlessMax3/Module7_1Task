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

	void SetX1(int _x) { x1 = _x; }
	void SetY1(int _y) { y1 = _y; }
	void SetX2(int _x) { x2 = _x; }
	void SetY2(int _y) { y2 = _y; }

	//отобразить линию в консоли
	void draw() const override
	{
		//this->Shape::draw(); вызов метода родителя
		cout << "Line(" << GetX1() << ", " << GetY1() << ") "<< '(' << GetX2() << ", " << GetY2() << ") " << GetColor() << endl;
	}

	//сместить линию на dx1, dy1, dx2, dy2
	void moveBy(int dx1 = 0, int dy1 = 0, int dx2 = 0, int dy2 = 0)
	{
		x1 += dx1;
		y1 += dy1;
		x2 += dx2;
		y2 += dy2;
	}

	//увеличить линию на factor
	void scale(double factor)
	{
		x2 = x2 * factor;
		y2 = y2 * factor;
	}

	//деструктор линии
	~Line()
	{
		cout << "~Line()" << endl;
	}
};

#endif // !_LINE_H_

