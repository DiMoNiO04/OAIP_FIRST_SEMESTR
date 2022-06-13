#include <iostream>
using namespace std;

int NODrecursia(int numberFirst, int numberSecond)
{
    if (numberSecond == 0) return numberFirst;
    else return NODrecursia(numberSecond, numberFirst % numberSecond);
}

int NOD(int numberFirst, int numberSecond) {

    while (numberSecond != numberFirst) {
        if (numberSecond > numberFirst)  numberSecond = numberSecond - numberFirst;
        else numberFirst = numberFirst - numberSecond;
    }
    return numberSecond;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int numberFirst, numberSecond;
    cout << "������� ������ ����� : "; cin >> numberFirst;
    cout << "������� ������ ����� : "; cin >> numberSecond;

    if (numberFirst == 0 || numberSecond == 0) cout << "��� ����� ����� �� ����������\n";
    else {
        numberFirst = fabs(numberFirst);
        numberSecond = fabs(numberSecond);

        cout <<endl<< "��� �����  ����� ����������� ������� = " << NODrecursia(numberFirst, numberSecond);
        cout << endl << "��� ����� ����� ������� ������� " << NOD(numberFirst, numberSecond);

        if (NODrecursia(numberFirst, numberSecond) == NOD(numberFirst, numberSecond))
            cout << "\n\n����������� � ������� ������� �����\n";
        else cout << endl << "�� �����";
    }  
    system("pause");
}
