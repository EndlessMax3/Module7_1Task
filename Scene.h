#pragma once
#include "Shape.h"
#include <iostream>

const int MAX_SCENE_SIZE = 100; //максмальный размер динамического массива
//класс сцена
class Scene {

private:
	Shape** objects; //массив объектов Shape
	int size; //размер массива

public:
	Scene() : size(0) { objects = new Shape * [MAX_SCENE_SIZE]; } //выделить память под массив размера MAX_SCENE_SIZE
	//деструктор массива, очищает память выделенную под массив
	~Scene()
	{
		clear();
		delete[] objects; 
	}

	//нарисовать фигуры из массива Scene
	void draw()
	{
		cout << "************ Drawing Scene ************" << endl;
		for (int i = 0; i < size; i++)
		{
			objects[i]->draw();
		}
		cout << "***************************************" << endl;
	}

	//добавить фигуру в массив Scene
	void add(Shape* s) 
	{
		if (size < MAX_SCENE_SIZE)
			objects[size++] = s;
		else
			std::cerr << "Array size is too big" << endl; //вывод ошибки при добавлении более 100 фигур
	}

	//очистка памяти выделенной под массив
	void clear()
	{
		for (int i = 0; i < size; i++)
		{
			delete objects[i];
		}
		size = 0;
	}

};
