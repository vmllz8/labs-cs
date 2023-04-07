#include<iostream>
using namespace std;
class Shape
{
protected:
	double x_coord, y_coord;
public:
	Shape(double x, double y)
	{
		x_coord = x;
		y_coord = y;
	}
	virtual void print()
	{
		cout << "x_coord = " << x_coord << endl;
		cout << "y_coord = " << y_coord << endl;
	}
	virtual double getArea() = 0;
};
class Square :public Shape
{
private:
	double side;
public:
	Square(double x, double y, double Side) : Shape(x, y)
	{
		side = Side;
	}
	void print()
	{
		Shape::print();
		cout << "Side = " << side << endl;
	}
	double getArea()
	{
		return side * side;
	}
};
class Circle :public Shape
{
private:
	double radius;
public:
	Circle(double x, double y, double Radius) : Shape(x, y)
	{
		radius = Radius;
	}
	void print()
	{
		Shape::print();
		cout << "Radius = " << radius << endl;
	}
	double getArea()
	{
		return 3.14159265 * radius * radius;
	}
};