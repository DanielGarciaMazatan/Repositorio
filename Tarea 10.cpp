#include <iostream>
using namespace std;
/*
Programa en C++ que dibuje un el perímetro de un rectángulo con asteriscos 
con base b y altura a dados por el usuario.
*/

int main() {

	int base;
	int altura;
	int cont1 = -1;
	int cont2;

	cout << "Base:" << endl;
	cin >> base;

	cout << "Altura:" << endl;
	cin >> altura;

	int area = base * altura;

	int perimetro = 2 * (base + (altura - 2));

	int resta = area - perimetro;

	for (int i = 0; i < area; i++) {
		
		if (i % base == 0) {
			cout << "\n";
			cont2 = cont1;	
		}

		if (i < base || i % base == 0 || i - cont2 == base || i > (altura - 1) * base) {
			cout << "* ";
		}
		else {
			cout << "  ";
		}

		cont1 = cont1 + 1;

	}

	cout << endl << endl;

	system("pause");
}






