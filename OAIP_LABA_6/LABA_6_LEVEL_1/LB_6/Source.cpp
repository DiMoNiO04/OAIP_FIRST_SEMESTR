#include<iostream>
#include<string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	string str,strNew;
	cout << "������� ������ ��������� �� ������ ����� : "; cin >> str;

	size_t found = str.find_first_not_of("1234567890");
	if (found != string::npos) cout << "E��� ������ ��-�� �������� ������ �� ������� ����� ����� ";
	else {
		int n = str.length();

		bool w = true;
		for (int i = 0; i < n / 2; i++)
			if (str[i] != str[n - 1 - i]) w = false;

		if (w) cout << "����� �����������\n";
		else cout << "����� �� �����������\n";

		if (n < 3) cout << "������ ������� ����� ��� �� 3 ��������" << endl;
		else {
			strNew = str.substr(n - 3, 3);
			cout << "" << strNew << endl;
		}
	}
		
}