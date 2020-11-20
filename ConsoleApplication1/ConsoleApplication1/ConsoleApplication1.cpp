#include <iostream>
#include "Math.h"
#include <string>


using namespace std;

struct Vector3 {
public:

	double x;
	double y;
	double z;
	Vector3(double x = 0, double y = 0, double z = 0, string name = "") : x(x),y(y),z(z),name(name) {
		if (name.length() == 0)
			SetRandomName();
	}

	double Length() {
		return sqrt(x*x + y*y + z*z);
	}

	void Normalize(){
		x /=  Length();
		y /= Length();
		z /= Length();
	}

	string GetName() {
		return name;
	}

	void SetName(string name) {
		this->name = name;
	}
private: 
	string name;
	void SetRandomName() {
		this->name = "vector " + to_string(rand() % 15);
	}
};

int main()
{
	Vector3 vec(1, 1, 1);
    cout << "Hello World! " << vec.GetName() << endl;
	return 0;
}