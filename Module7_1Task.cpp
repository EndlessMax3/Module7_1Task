﻿#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Line.h"
#include "Scene.h"

int main()
{
    //динамически создаем объекты
    Point* pp1 = new Point(10, 20, "Green");
    Point* pp2 = new Point(20, 30, "Yellow");
    Line* lp1 = new Line(0, 0, 30, 40, "Red");
    Line* lp2 = new Line(5, 10, 15, 20, "Pink");
    Circle* cp1 = new Circle(30, 30, 30, "White");
    Circle* cp2 = new Circle(50, 50, 25, "Blue");
    //создаем указатели типа Shape на объекты
    Shape* s1 = pp1;
    Shape* s2 = pp2;
    Shape* s3 = lp1;
    Shape* s4 = lp2;
    Shape* s5 = cp1;
    Shape* s6 = cp2;
    //вызываем метод draw для каждого типа объекта
    s1->draw();
    s2->draw();
    s3->draw();
    s4->draw();
    s5->draw();
    s6->draw();
    //вызываем различные методы для изменения объектов
    pp1->moveBy(5, 6);
    pp2->moveBy(7, 8);
    lp1->scale(2.5);
    lp2->scale(3.5);
    cp1->scale(1.5);
    cp2->scale(4.5);
    //создаем сцену
    Scene* sc1 = new Scene;
    //добавляем объекты в сцену
    sc1->add(pp1);
    sc1->add(pp2);
    sc1->add(lp1);
    sc1->add(lp2);
    sc1->add(cp1);
    sc1->add(cp2);
    //рисуем сцену
    sc1->draw();

    //очищаем память выделенную  под сцену
    delete sc1;


}

