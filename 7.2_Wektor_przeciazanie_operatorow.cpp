// Przeciazanie operatorów - l. zespolone 
#include <iostream> 
using namespace std;

class vec {
public:
	// dane 
	float x;
	float y;

	// konstruktor 
	vec(float f1, float f2) {
		x = f1; y = f2;
	}

	// konstruktor 
	vec() { };

	vec operator+(const vec& v1); // operator dodawanie 
	vec operator-(const vec& v1); // operator odejmowania 
	bool operator== (vec v1); // operator porownania 
	vec operator= (vec& v1); // operator przypisania
};

vec vec::operator+(const vec & v1) // Tak wyglada dodawanie 
{
	vec result;
	result.x = this->x + v1.x;
	result.y = this->y + v1.y;
	return result;
};

// Tu dopisaæ kod 


ostream& operator<< (ostream& stream, vec v) {
	cout << "(" << v.x << "," << v.y << ")";
	return stream;
};


int main() {
	vec v1(3, 6);
	vec v2(2, -2);
	vec v3 = v1 + v2;
	vec v4 = v1 - v2;

	cout << "v3 =" << v3 << endl;
	cout << "v4 =" << v4 << endl;

	if (v1 == v2) {
		cout << "v1 == v2" << endl;
	}
	else {
		cout << "v1 != v2" << endl;
	}

	v4 = v1;

	cout << "v4 =" << v4 << endl;
}