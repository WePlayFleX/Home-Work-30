#include <iostream>
#include <cstring>

using namespace std;

struct Car
{
	struct Wheel
	{
		int D = 15;
		int width = 185;
		int prof = 65;
	};
	Wheel wheels[4];

	struct Engine
	{
		double volume = 1.3;
		int power = 75;
	};
	Engine pow_vol;

	struct BodyCar
	{
		string type = "sedan";
		string color = "black";
	};
	BodyCar body;

	struct Interior
	{
		string seat = "textile";
	};
	Interior inter;
};

void car_complect(Car &myCar)
{
	cout << "Choose complet car which you wish: " << endl;
	cout << "Engine: Volume, Power: " << endl;
	double volume = 0.0;
	cin >> volume;
	int power = 0;
	cin >> power;
	myCar.pow_vol.volume = volume;
	myCar.pow_vol.power = power;

	cout << "Choose body's type: sedan, hb, cabriolete: " << endl;
	string type;
	cin >> type;
	myCar.body.type = type;

	cout << "Choose body's color: black, white, red, blue: " << endl;
	string color;
	cin >> color;
	myCar.body.color = color;

	cout << "Choose interior: textile, leather: " << endl;
	string seat;
	cin >> seat;
	myCar.inter.seat = seat;

	cout << "Chose wheels: diametr, wight, profil: " << endl;
	int d = 0;
	int w = 0;
	int p = 0;

	cin >> d >> w >> p;

	for (size_t i = 0; i < 4; i++)
	{
		myCar.wheels[i] = { d, w, p };
	}

}

void output_car(Car &myCar) {
	cout << "Your car: " << endl;
	cout << "Engine: Volume - " << myCar.pow_vol.volume << "; Power - " << myCar.pow_vol.power << endl;
	cout << "Body car: Type - " << myCar.body.type << "; Color - " << myCar.body.color << endl;
	cout << "Interio: Seat - " << myCar.inter.seat << endl;
	cout << "Wheels: Diametr(inch) - " << myCar.wheels->D
		<< "; Width - " << myCar.wheels->width
		<< "; Profile - " << myCar.wheels->prof << endl;
}

int main()
{
	int size = 3;

	string cars[3] = { "ZIL", "Lada", "ZAZ" };

	Car *myCars = new Car[size];

	for (size_t i = 0; i < size; i++)
	{
		car_complect(myCars[i]);
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << cars[i] << " : " << endl;
		output_car(myCars[i]);
	}

	system("pause");
	return 0;

	delete[] myCars;
}