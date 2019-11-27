// 12191706 ±Ë¡§¡¯

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Shape {
public:
	explicit Shape(const string& n, double w, double h) {
		name = n; width = w; height = h;
	}

	virtual double CalculateArea() const = 0;

	string getName() const{
		return name;
	}

	~Shape() {};

protected:
	string name;
	double width;
	double height;
};

class Rect : public Shape {
public:
	explicit Rect(const string& n, double w, double h)
	: Shape(n,w,h){	}

	virtual double CalculateArea() const override {
		return width * height;
	}

    ~Rect() {};
};

class Triangle : public Shape {
public:
	explicit Triangle(const string& n, double w, double h)
		: Shape(n, w, h) {	}

	virtual double CalculateArea() const override {
		return (width * height)/ 2;
	}

	~Triangle() {};
};

void swap(int& a, int& b) {
	int c;
	int& ref = c;
	ref = a;
	a = b;
	b = ref;
	return;
}

int main() {
	ofstream Test("Test.txt", ios::out);
	{
	vector<Shape*>shapes{
		new Rect("≥Î∆Æ∫œ", 40, 25),
		new Triangle("≈‰Ω∫∆Æ", 20, 12)
	};

	if (!Test) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	for (Shape* shapePtr : shapes) {
		string namesave = shapePtr->getName();
		double areasave = shapePtr->CalculateArea();
		Test << namesave << " ¿« ≥–¿Ã¥¬ " << showpoint << areasave << endl;

	}
	}
	int a = 10; int b = 20;
	Test << setw(17) << "ø¯∑° a, b¥¬ " << a << " " << b << endl;
	swap(a, b);
	Test << setw(17) << "πŸ≤Ô a, b¥¬ " << a << " " << b << endl;
}