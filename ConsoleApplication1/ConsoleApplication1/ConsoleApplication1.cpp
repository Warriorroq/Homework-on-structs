﻿#include <iostream>
#include "Math.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

using namespace std;

namespace myfuck {
	struct Vector3 {
	public:
		double x;
		double y;
		double z;
		Vector3(double x = 0, double y = 0, double z = 0, string name = "") : x(x), y(y), z(z), name(name) {
			if (name.length() == 0)
				SetRandomName();
		}

		virtual void operator +=(Vector3 vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
		}

		virtual void operator -=(Vector3 vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
		}

		virtual bool operator ==(Vector3 vec) {
			return (x == vec.x && y == vec.y && z == vec.z);
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
			return sqrt(x*x + y * y + z * z);
		}

		void Normalize() {
			double l = Length();
			x /= l;
			y /= l;
			z /= l;
		}

		string GetName() {
			return name;
		}

		void SetName(string name) {
			this->name = name;
		}

		void PrintInfo() {
			cout << "Name : " << name << endl;
			cout << "Vector :" << "(" << x << "," << y << "," << z << ")" << endl;
			cout << "Lenght : " << Length() << endl;

		}

	private:
		string name;
		void SetRandomName() {
			this->name = "vector " + to_string(rand() % 15);
		}
	};
}

int main()
{
	const float FPS = 75.0f;
	float frameTime = 1.0f / FPS;
	bool draw = true;

	myfuck::Vector3 pos(0,0);
	myfuck::Vector3 velocity(0,0);
	myfuck::Vector3 radius(10);
	myfuck::Vector3 color(255,255,255);

	float power = -1;
	float angle = 100;
	float startPos = -1;
	float gravity = 9.8f;
	while (power < 0) {
		cout << "power: (>0)";
		cin >> power;
	}

	while (!(angle >= 0 && angle <= 90)) {
		cout << "angle: (0<x<90)";
		cin >> angle;

		velocity.x = power * sinf(angle);
		velocity.y = -power * cosf(angle);
	}



	while (!(startPos >= 0 && startPos <= 380)) {
		cout << "start Y: (>0 & <380)";
		cin >> startPos;
		pos.y = 380 - startPos;
	}
	velocity.PrintInfo();
	RenderWindow window(VideoMode(800, 400, 32), "Hello");
	Clock clock;
	Event ev;

	CircleShape circle(radius.x);

	circle.setPosition(pos.x, pos.y);

	circle.setFillColor(Color(color.x, color.y, color.z));

	while (window.isOpen())
	{
		if (clock.getElapsedTime().asSeconds() >= frameTime){
			draw = true;
			pos += velocity;			
			velocity.y += gravity * frameTime;
			circle.setPosition(pos.x, pos.y);
			clock.restart();
		}
		else{
			Time sleepTime = seconds((frameTime) - clock.getElapsedTime().asSeconds());
			sleep(sleepTime);
		}
		while (window.pollEvent(ev)){
			if (ev.type == Event::Closed) window.close();
		}
		if (draw){
			draw = false;
			window.clear(Color::Black);
			window.draw(circle);
			window.display();
		}
	}

	return 0;
}

