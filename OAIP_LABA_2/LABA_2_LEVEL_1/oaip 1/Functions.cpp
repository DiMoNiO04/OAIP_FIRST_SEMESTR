
#include <iostream>
#include <string>
#include <fstream>
#include <locale> /* ��� �������� ����� */
using namespace std;

/*C������ ��������� ��� ������ ���������*/
struct autorizationnn {
	int number = 0;
	string login;
	string password;
	string who;
};

/*������� ��������� ��� ������ ���������*/
struct dataPatients {
	string surname;
	string name;
	string patronymic;
	string gender;
	string dateOfBirth;
	string town;
	string phoneNumber;
	string diagnosis;
};

/*���������*/
void switchCaseMain(autorizationnn* usersAndAdmins, int countUsersAndAdmins);
void  workWithFailUsers();
int entranceRegisterBack();
void entrance(autorizationnn* usersAndAdmins, int countUsersAndAdmins);
void exit(autorizationnn* usersAndAdmins, int countUsersAndAdmins);
autorizationnn* readExamFromFile(string fileName, int& countUsersAndAdmins);
autorizationnn* resizeArray(int& oldSize, int newSize, autorizationnn* usersAndAdmins);
void workWithFailPatients();
dataPatients* readExamFromFilePatients(string fileName, int& countPatients);
dataPatients* resizeArrayPatients(int& oldSizePatients, int newSizePatients, dataPatients* patients);


//���������� ��������� ���� �����
enum entranceRegisteExit {
	ENTRANCE = 1,
	REGISTE = 2,
	EXIT = 3
};

enum noYes {
	yes = 1,
	no = 2
};



int main() {
	setlocale(LC_ALL, "RUSSIA");
	workWithFailUsers();
	cout << endl << endl;
	system("pause");
}

/*������ � ������ ������������� ������*/
void workWithFailUsers() {
	int countUsersAndAdmins = 1;
	autorizationnn* usersAndAdmins = readExamFromFile("autorization.txt", countUsersAndAdmins);
	fstream file("autorization.txt");

	file.close();
	switchCaseMain(usersAndAdmins, countUsersAndAdmins);
}

autorizationnn* readExamFromFile(string fileName, int& countUsersAndAdmins) {
	ifstream file(fileName);
	if (!file.is_open())
	{
		return nullptr;
	}
	countUsersAndAdmins <= 0 ? countUsersAndAdmins = 10 : countUsersAndAdmins = countUsersAndAdmins;

	autorizationnn* usersAndAdmins = new autorizationnn[countUsersAndAdmins];
	int numberOfLines = 0;
	while (!file.eof()) {
		if (numberOfLines == countUsersAndAdmins) {
			usersAndAdmins = resizeArray(countUsersAndAdmins, countUsersAndAdmins + 1, usersAndAdmins);
		}

		file >> usersAndAdmins[numberOfLines].number;
		file >> usersAndAdmins[numberOfLines].login;
		file >> usersAndAdmins[numberOfLines].password;
		file >> usersAndAdmins[numberOfLines].who;
		numberOfLines++;
	}


	usersAndAdmins = resizeArray(countUsersAndAdmins, numberOfLines, usersAndAdmins);
	file.close();
	return  usersAndAdmins;
}

autorizationnn* resizeArray(int& oldSize, int newSize, autorizationnn* usersAndAdmins) {
	if (oldSize == newSize) {
		return  usersAndAdmins;
	}

	autorizationnn* newArray = new autorizationnn[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;

	for (int i = 0; i < oldSize; i++) {
		newArray[i] = usersAndAdmins[i];
	}

	oldSize = newSize;
	delete[]  usersAndAdmins;
	return newArray;
}
/*������ � ������ ������������� �����*/

/*������� �������� ���� ������*/
void switchCaseMain(autorizationnn* usersAndAdmins, int countUsersAndAdmins) {
	switch (entranceRegisterBack()) {
	case ENTRANCE:
		system("cls");
		entrance(usersAndAdmins, countUsersAndAdmins);
		break;
	case REGISTE:
		system("cls");
		cout << "�����������";

		break;
	case EXIT:
		system("cls");
		exit(usersAndAdmins, countUsersAndAdmins);
		return;
	default:
		while (true) {
			system("cls");
			cout << "�������� �������� ����. ��������� �������.\n";
			switchCaseMain(usersAndAdmins, countUsersAndAdmins);
			break;
		}
	}
}

int entranceRegisterBack() {
	cout << "����� ����� � �������, ������� ��� ����� � ������  ��� �����������������\n";
	cout << "1.�����\n";
	cout << "2.���������������� ����� �������\n";
	cout << "3.����� �� ���������\n";
	int choiceUserAdmin;
	cout << "<< "; cin >> choiceUserAdmin;
	return choiceUserAdmin;
}

void exit(autorizationnn* usersAndAdmins, int countUsersAndAdmins) {
	cout << "�� ������� ��� ������ ����� �� ���������?\n";
	cout << "1.��\n";
	cout << "2.���, ��������� �����\n";
	int yesNo;
	cout << "<< ";  cin >> yesNo;
	switch (yesNo) {
	case yes:
		system("cls");
		cout << "�� ����� �� �������.\n����� �������!";
		break;
	case no:
		system("cls");
		switchCaseMain(usersAndAdmins, countUsersAndAdmins);
		break;
	default:
		while (true) {
			system("cls");
			cout << "�������� �������� ����. ��������� �������.\n";
			exit(usersAndAdmins, countUsersAndAdmins);
			break;
		}
	}
}
/*������� �������� ���� �����*/

/*������� ����� ������*/
void entrance(autorizationnn* usersAndAdmins, int countUsersAndAdmins) {
	int peoples = 0;
	string pas;
	string log;
	string USER = "user";
	string ADMIN = "admin";

	cout << "��� ����, ����� ����� � ������� ���� ������� '0' '0'\n";
	cout << "������� ����� � ������:\n";
	cout << "\n�����:  << "; cin >> log;
	cout << "������: << "; cin >> pas;

	while (peoples != countUsersAndAdmins) {
		if (log == usersAndAdmins[peoples].login && pas == usersAndAdmins[peoples].password) {
			system("cls");
			break;
		}
		peoples++;
	}
	if (log == usersAndAdmins[peoples].login && pas == usersAndAdmins[peoples].password && usersAndAdmins[peoples].who == USER) {
		system("cls");
		cout << "�� ����� � ������� ��� ������������";
		workWithFailPatients();
	}
	else if (log == usersAndAdmins[peoples].login && pas == usersAndAdmins[peoples].password && usersAndAdmins[peoples].who == ADMIN) {
		cout << "�� ����� � ������� ��� �������������";
	}
	else if (log == "0" && pas == "0") {
		system("cls");
		switchCaseMain(usersAndAdmins, countUsersAndAdmins);
	}
	else {
		system("cls");
		cout << "������� ����� ����� ��� ������!!!" << endl;
		cout << "��������� ����" << endl;
		entrance(usersAndAdmins, countUsersAndAdmins);
	}
}
/*������� ����� �����*/



/*������ � ������ ��������� ������*/
void workWithFailPatients() {
	setlocale(LC_CTYPE, "Russian");
	int countPatients = 1;
	dataPatients* patients = readExamFromFilePatients("patients.txt", countPatients);
	fstream file("patients.txt");

	file.close();
}

dataPatients* readExamFromFilePatients(string fileName, int& countPatients) {

	ifstream file(fileName);
	if (!file.is_open())
	{
		return nullptr;
	}
	countPatients <= 0 ? countPatients = 10 : countPatients = countPatients;

	dataPatients* patients = new  dataPatients[countPatients];
	int numberOfPatients = 0;
	while (!file.eof()) {
		if (numberOfPatients == countPatients) {
			patients = resizeArrayPatients(countPatients, countPatients + 1, patients);
		}

		file >> patients[numberOfPatients].surname;
		file >> patients[numberOfPatients].name;
		file >> patients[numberOfPatients].patronymic;
		file >> patients[numberOfPatients].gender;
		file >> patients[numberOfPatients].dateOfBirth;
		file >> patients[numberOfPatients].town;
		file >> patients[numberOfPatients].phoneNumber;
		file >> patients[numberOfPatients].diagnosis;
		numberOfPatients++;
	}
	cout << endl;
	for (int i = 0; i < numberOfPatients; i++) {
		cout << patients[i].surname << "  ";
		cout << patients[i].name << "  ";
		cout << patients[i].patronymic << "  ";
		cout << patients[i].gender << "  ";
		cout << patients[i].dateOfBirth << "  ";
		cout << patients[i].town << "  ";
		cout << patients[i].phoneNumber << "  ";
		cout << patients[i].diagnosis << "  ";
		cout << endl;
	}

	patients = resizeArrayPatients(countPatients, numberOfPatients, patients);
	file.close();
	return  patients;
}

dataPatients* resizeArrayPatients(int& oldSizePatients, int newSizePatients, dataPatients* patients) {
	if (oldSizePatients == newSizePatients) {
		return  patients;
	}

	dataPatients* newArrayPatients = new  dataPatients[newSizePatients];
	oldSizePatients = newSizePatients < oldSizePatients ? newSizePatients : oldSizePatients;

	for (int i = 0; i < oldSizePatients; i++) {
		newArrayPatients[i] = patients[i];
	}

	oldSizePatients = newSizePatients;
	delete[]  patients;
	return newArrayPatients;
}
/*������ � ������ ��������� �����*/