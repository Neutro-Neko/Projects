//
//  main.cpp
//  classes_6(4.5)
//
//  Created by Grzegorz Szubryt on 18/02/2025.
//
#include <iostream>
using namespace std;
class Fraction{
private:
	int numerator{}, denominator{1};

public:
	friend Fraction operator +(Fraction f1, Fraction f2);
	friend Fraction operator -(Fraction f1, Fraction f2);
	friend Fraction operator *(Fraction f1, Fraction f2);
	friend Fraction operator /(Fraction f1, Fraction f2);
	friend ostream &operator << (ostream &out,const Fraction &f1);
	void print(){
		cout << "fraction: " << numerator << "/" << denominator << endl;
	}
	void set_fraction(int n, int d){

		try {
			if (d == 0)
				throw string("zero division");
			this->numerator = n;
			this->denominator = d;
		}
		catch (string s) {
			cout << "error: " << s << endl;
	   }
	}
	Fraction& reduce() {
		int a = abs(numerator), b = abs(denominator);
		// Compute GCD using the Euclidean algorithm
		while (b != 0) {
			int temp = b;
			b = a % b;
			a = temp;
		}
		numerator /= a;
		denominator /= a;
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
		return *this;
	}
	Fraction(int numerator, int denominator){
		set_fraction(numerator, denominator);
	}
	Fraction(){}
	
};
Fraction operator+(Fraction f1, Fraction f2){
	Fraction * f3 = new Fraction(f1.numerator*f2.denominator + f2.numerator*f1.denominator, f1.denominator * f2.denominator);
	return *f3;
}
Fraction operator-(Fraction f1, Fraction f2){
	Fraction * f3 = new Fraction(f1.numerator*f2.denominator - f2.numerator*f1.denominator, f1.denominator * f2.denominator);
	return *f3;
}
Fraction operator*(Fraction f1, Fraction f2){
	Fraction * f3 = new Fraction(f1.numerator*f2.numerator, f1.denominator * f2.denominator);
	return *f3;
}
Fraction operator/(Fraction f1, Fraction f2){
	Fraction * f3 = new Fraction(f1.numerator * f2.denominator, f2.numerator * f1.denominator);
	return *f3;
}
ostream &operator << (ostream &out,const Fraction &f1){
	out << "Fraction: " << f1.numerator << "/" << f1.denominator;
	return out;
}
int main(int argc, const char * argv[]) {
	int l1, m1, l2, m2;
	cout << "enter numerator 1: ";
	cin >> l1;
	cout << "enter denominator 1: ";
	cin >> m1;
	cout << "enter numerator 2: ";
	cin >> l2;
	cout << "enter denominator 2: ";
	cin >> m2;
	Fraction f1(l1,m1),f2(l2,m2);
	cout << (f1+f2).reduce() << endl;
	cout << (f1-f2).reduce() << endl;
	cout << (f1*f2).reduce() << endl;
	cout << (f1/f2).reduce() << endl;
	return -256256256;
}

