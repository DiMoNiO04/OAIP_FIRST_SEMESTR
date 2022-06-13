#include<iostream>
#include<ctime>
#include<algorithm>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int m, n, i = 0, j = 0;
	cout << "������� ���������� ����� ������� : "; cin >> m;
	cout << "������� ���������� �������� ������� : "; cin >> n;

	if (m > 0 && n > 0) {

		double** a = new double* [m];

		for (i; i < m; i++) a[i] = new double[n];

		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << "matrix [" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}

		cout << "�������������� ������� : \n";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++) 
			{
				cout << setw(5) << a[i][j] << " ";
			}
			cout << endl;
		}

		double* b = new double[m];

		double max;
		for (i = 0; i < m; i++) 
		{
			max = a[i][0];
			for (j = 1; j < n; j++)
			{
				if (a[i][j] > max)
				{
					max = a[i][j];
				}
			}
			b[i] = max;
		}

		cout << endl << endl;
		for (i = 0; i < m; i++) {
			cout <<"������������ ������� � "<<i<<" ������ " << b[i] << endl;
		}

		for (int i = 0; i < m - 1; i++)
		{
			for (int j = i + 1; j < m; j++)
			{
				if (b[j] < b[i])
				{
					swap(b[i], b[j]);
					swap(a[i], a[j]);
				}
			}
		}

		cout << "\n\n ��������������� ������ : \n";
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++) cout << a[i][j] << " ";
			cout << endl;
		}

		delete[] b;

		for (i; i < m; i++) delete[] a[i];
		delete[] a;
	}

	else cout << "������� ������������ ������� ������� , ������ �� ����� ���� ������";
}