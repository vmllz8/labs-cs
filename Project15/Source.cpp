#include <iostream>
using namespace std;
class Point {

	friend std::ostream& operator<<(std::ostream& output, const Point& p);

private: // Private data members
	int x;
	int y;
public:
	// Default Constructor
	Point() : x(0), y(0) { }
	Point(int x, int y) : x(x), y(y) { }

	// Getters
	int getX() const { return x; }
	int getY() const { return y; }
	// Setters
	void setX(int X) { x = X; }
	void setY(int Y) { y = Y; }


	// Member function overloading operators
	// Overload ++Prefix, increase x, y by 1
	Point operator ++()
	{
		return Point(++x, ++y);
	}
	// Overload Postfix++, increase x, y by 1
	Point operator ++(int)
	{
		Point old;
		old.x = x;
		old.y = y;
		x++;
		y++;
		return old;
	}
	// Overload Point + int. Return a new Point by value
	Point operator +(int value) const
	{
		return Point(x + value, y + value);
	}
	// Overload Point + Point. Return a new Point by value
	Point operator +(Point Obj1) const
	{
		return Point(x + Obj1.x, y + Obj1.y);
	}
	// Overload Point += int. Increase x, y by value
	Point operator +=(int value)
	{
		x += value;
		y += value;
		return Point(x, y);
	}
	// Overload Point += Point. Increase x, y by rhs
	Point operator +=(Point Obj2)
	{
		x += Obj2.x;
		y += Obj2.y;
		return Point(x, y);
	}
	// Overload comparison operator point == point. Same x value and y value or not
		bool operator == (Point Obj3) const
	{
		if (x == Obj3.x && y == Obj3.y)
			return true;
		else
			return false;
	}
	// Overload comparison operator point < point. 
	bool operator < (Point Obj4) const
	{
		if (x < Obj4.x && y < Obj4.y)
			return true;
		else
			return false;
	}
};
std::ostream& operator<<(std::ostream& output, const Point& p)
{
	output << "(" << p.getX() << "," << p.getY() << ")";
	return output;
}
int main()
{
	Point p1(1, 2);
	cout << "p1= " << p1 << endl; // (1,2)
	Point p2(3, 4);
	cout << "p2= " << p2 << endl;
	cout << "p1+p2= " << p1 + p2 << endl; // (4,6)
	cout << "p1+10= " << p1 + 10 << endl; // (11,12)

	p1 += p2;
	cout << "p1+=p2: " << p1 << endl; // (4,6)
	p1 += 3;
	cout << "p1+=3: " << p1 << endl; // (7,9)
	Point p3; // (0,0)
	cout << "p3= " << p3 << endl; // (0,0)
	cout << "p3++: " << p3++ << endl; // (0,0)
	cout << "p3: " << p3 << endl; // (1,1)
	cout << "++p3: " << ++p3 << endl; // (2,2)
	Point p4(2, 2);
	cout << "p4= " << p4 << endl; // (0,0)
	if (p3 == p4)
		cout << "p3 == p4" << endl; // True
	if (p2 < p1)
		cout << "p2 < p1" << endl; // True
};