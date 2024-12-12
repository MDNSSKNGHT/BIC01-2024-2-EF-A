#include <iostream>

using namespace std;

int suma_en_A(int A[], int n, int ind)
{
	if (ind < n - 1) {
		return A[ind] + suma_en_A(A, n, ind + 1);
	}
	return A[ind];
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "La suma desde el índice 2 es: " << suma_en_A(arr, n, 2) << endl;

	return 0;
}
