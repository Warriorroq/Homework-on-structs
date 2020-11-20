#include <iostream>

using namespace std;

struct Vector3 {
public:
	double x;
	double y;
	double z;
	Vector3(double x = 0, double y = 0, double z = 0, double scale = 0, string name = "") : x(x),y(y),z(z) {

	}

};

int main()
{
    std::cout << "Hello World!\n";
}
