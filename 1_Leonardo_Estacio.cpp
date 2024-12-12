#include <iostream>

using namespace std;

int A[5] = {10, 1, 17, 11, 5};
int n = sizeof(A) / sizeof(A[0]);

int objetivo_en_A(int S)
{
	int obj = 0;

	/* 
	 * Caso donde n = 5
	 *
	 * Tomamos el número `i` en su representación binaria como una combinación de
	 * índices cuyos elementos asociados en el arreglo serán sumados dependiendo si
	 * el bit en el orden `j + 1` del número es un 0 o un 1.
	 *
	 * 0 0 0 0 0 
	 * .
	 * .
	 * .
	 * 0 1 1 1 1 1
	 * 1 0 0 0 0 0 <- 1 << 5
	 */
	for (int i = 0; i < (1 << n); i++) {

		int sum = 0;

		for (int j = 0; j < n; j++) {

			/*
			 * Digamos que el orden y el valor del número `i`, respectivamente, es
			 *
			 * Orden: 
			 * 5 4 3 2 1
			 *
			 * Número:
			 * 1 1 0 1 0
			 *
			 * Con lo cual aquí nos indica que los elementos en los índices 4 (5 - 1),
			 * 3 (4 - 1) y 1 (2 - 1) serán sumados.
			 *
			 * Y para saber si se debe o no sumar el índice `j` usamos un bitwise AND
			 * tal que
			 *
			 * 1 1 0 1 0 <- `i`
			 * 0 1 0 0 0 <- 1 << j (para j = 3)
			 * ---------
			 * 0 1 0 0 0
			 *
			 * Si el resultado es diferente a 0 significa que usaremos el elemento en el índice
			 * `j` para evaluar la suma.
			 */
			if ((i & (1 << j)) != 0) {

				sum += A[j];

			}

		}

		if (sum <= S) {

			obj = max(obj, sum);

		}

	}

	return obj;
}

int main()
{
	int S;

	cout << "Para A[6] = [";

	for (int i = 0; i < n; i++) {
		cout << A[i] << (i != n - 1 ? " " : "");
	}

	cout << "] y S = ";

	cin >> S;

	cout << "La suma máxima que no supera a " << S << " es " << objetivo_en_A(S) << endl;


	return 0;
}
