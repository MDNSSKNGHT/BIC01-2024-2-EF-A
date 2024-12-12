#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
	srand(time(0));

	int grado = rand() % 10 + 1;
	double x, vn = 0;

	vector<int> coefs(grado);

	cout << "Arreglo generado (" << grado << " elementos):";

	for (auto &coef : coefs) {
		coef = rand() % 2;
		cout << " " << coef;
	}

	cout << "\nIngrese el valor de x: ";
	cin >> x;

	cout << "Polinomio:";

	for (int i = 0; i < grado; i++) {

		bool ceros = true;

		for (int j = i + 1; j < grado; j++)
			ceros &= coefs[j] == 0;

		if (coefs[i] != 0) {

			cout << "x^" << i;

			if (i == grado - 1) {
				cout << "";
			} else if (ceros) {
				cout << "";
			} else {
				cout << " + ";
			}

			vn += pow(x, i);
		}

	}

	cout << "\nResultado de reemplazar x por " << x << ": " << vn << endl;

	return 0;
}
