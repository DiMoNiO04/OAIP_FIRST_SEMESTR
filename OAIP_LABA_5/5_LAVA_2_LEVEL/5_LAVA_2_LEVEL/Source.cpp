#include<iostream>
#include<ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int rows, cols;
	cout << "������� ���������� ����� ������������� �������: "; cin >> rows;
	cout << "������� ���������� �������� ������������ �������:"; cin >> cols;
	if (rows <= 0 || cols <= 0) cout << "�������������� �������\n";
	else {
		int** matrix = new int* [rows];

		for (int i = 0; i < rows; i++) {
			matrix[i] = new int[cols];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << "matrix[" << i << "][" << j << "] = ";
				cin >> matrix[i][j];
			}
			cout << endl;
		}

		cout << "Matrix: \n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << matrix[i][j]<<" ";
			}
			cout << endl;
		}

		int specialElement = 0;
		for (int j = 0; j < cols; j++) {
			int max = 0;
			int summa = 0;
			for (int i = 0; i < rows; i++) {
				if (matrix[i][j] > max) {
					max = matrix[i][j];
				}
				summa = summa + matrix[i][j];

			}
			if (summa - max < max) 
				specialElement++;
		}

		if (specialElement >= 1)
			cout << endl << "������ ��������� ������� , ������� ������ ����� ���� ��������� � �������  = " << specialElement << endl;
		else cout << "\n������� �� �������� ������ ���������\n";
	}
}