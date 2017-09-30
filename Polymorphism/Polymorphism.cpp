// Polymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Polygon {
protected:
	int width, height;
public:
	void set_values(int a, int b)
	{
		width = a; height = b;
	}
	virtual int area()
	{
		return 0;
	}
};

class Rectangle : public Polygon {
public:
	int area()
	{
		return width*height;
	}
};

class Triangle : public Polygon {
public:
	int area()
	{
		return width*height / 2;
	}
};


int main()
{
	Rectangle rect;
	Triangle trgl;

	//This following part of test is to use pointer of derived class to access functions and attributes in 
	//base class
	Polygon * ppoly1 = &rect;
	Polygon * ppoly2 = &trgl;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	//in this case if I do not use virtual function, then ppoly1->area() give a result of 
	//0, because it calls the area function from base class, instead of from derived class
	cout << "result from base class:" << ppoly1->area() << '\n';
	cout << "result from rect class" << rect.area() << '\n';
	cout << "result from triangle class" << trgl.area() << '\n';

	//Let's test using pointers of base class to access functions and attributes in derived class, both work
	Polygon poly;
	Rectangle* pRect = (Rectangle*)&poly;
	pRect->set_values(4, 5);
	cout << "the result from Rectangle class:" << pRect->area() << '\n';
	cout << "the result from polygon class:" << poly.area() << '\n';

    return 0;
}

