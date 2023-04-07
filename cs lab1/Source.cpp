#include<string>
#include<iostream>
using namespace std;
class Employee
{
public:
	Employee()
	{
		eID = 0;
		eName = "unknown";
		eExperience = 0;
	}
	void setID(int id)
	{
		eID = id;
	}
	void setName(string n)
	{
		eName = n;
	}
	void setEx(int e)
	{
		eExperience = e;
	}
	int getID()
	{
		return eID;
	}
	string getName()
	{
		return eName;
	}
	int getEx()
	{
		return eExperience;
	}
protected:
	int eID, eExperience;
	string eName;
};
class Engineer :public Employee
{
public:
	void setSalary(double s)
	{
		salary = s;
	}
	void setdept(string d)
	{
		department = d;
	}
	double getSalary()
	{
		return salary;
	}
	string getdept()
	{
		return department;
	}
	void calculateSalary()
	{
		salary = (eExperience >= 10) ? salary * 1.25 : salary * 1.1;
	}
private:
	double salary;
	string department;
};
int main()
{
	Engineer eng;
	int id, exp;
	string name, dept;
	double salary;
	// read all engineer information
	cout << "Name: ";
	cin >> name;
	cout << "ID: ";
	cin >> id;
	cout << "Dept.: ";
	cin >> dept;
	cout << "Experience: ";
	cin >> exp;
	cout << "Salary: ";
	cin >> salary;
	eng.setID(id);
	eng.setdept(dept);
	eng.setEx(exp);
	eng.setName(name);
	eng.setSalary(salary);
	cout << "Engineer's Information\n";
	cout << "Name: " << eng.getName() << endl;
	cout << "ID: " << eng.getID() << endl;
	cout << "Department: " << eng.getdept() << endl;
	cout << "Experience: " << eng.getEx() << endl;
	cout << "Salary (before update): " << eng.getSalary() << endl;
	eng.calculateSalary();
	cout << "Salary (after update): " << eng.getSalary() << endl;
	system("pause");
}