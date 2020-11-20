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

	virtual void operator +=(Vector3 & vec) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}

	virtual void operator -=(Vector3 & vec) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}	

	virtual void operator *=(double vec) {
		x *= vec;
		y *= vec;
		z *= vec;
	}

	virtual void operator /=(double vec) {
		x /= vec;
		y /= vec;
		z /= vec;
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

	void PrintInfo() {
		cout << "Name : " << name << endl;
		cout << "Vector :" <<"(" << x << "," << y << "," << z << ")" << endl;
		cout << "Lenght : " << Length() << endl;

	}

private: 
	string name;
	void SetRandomName() {
		this->name = "vector " + to_string(rand() % 15);
	}
};

int main()
{
	Vector3 * vecs = (Vector3 *)malloc(sizeof(Vector3) * 100);
	for (int i = 0; i < 100; i++)
		vecs[i] = Vector3(rand() % 10, rand() % 5, rand() % 18);

	while (true){
		int a = 0;
		cin >> a;
		if (a >= 0)
			if(a < 100)
				vecs[a].PrintInfo();
		else
			return false;
	}

	return 0;
}