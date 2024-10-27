#include<iostream> 
#include<Windows.h> 
using namespace std;

class Student
{
	char* name;
	int age;
public:
	////  prototype  
	Student();
	Student(const char*, int); // construct by 2 param 
	void Output();
	Student& operator=(Student& obj);
	~Student();

};
Student::Student()
{
	name = nullptr;
	age = 0;
}
Student::Student(const char* Name, int Age)
{
	name = new char[strlen(Name) + 1];
	strcpy_s(name, strlen(Name) + 1, Name);
	age = Age;
}
void Student::Output()
{
	cout << "Name: " << name << endl
		<< "Age: " << age << endl << endl;
}
Student& Student::operator=(Student& obj)
{
	// 1. a=a 
	if (this == &obj)
	{
		return *this;
	}

	if (name != nullptr)
	{
		delete[] name;
	}
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	age = obj.age;

	return *this;
}
Student::~Student()
{
	if (name != nullptr)
	{
		delete[] name;
	}
	cout << "Destruct\n";
	Sleep(1000);
}

int main()
{
	Student obj1("Oleg", 21);
	obj1.Output();
	Student obj = obj1;
	Student mas[2]{ {"Alena",20 }, {"Maksim", 22} };
	for (int i = 0; i < 2; i++)
	{
		mas[i].Output();
	}
	system("pause");
}