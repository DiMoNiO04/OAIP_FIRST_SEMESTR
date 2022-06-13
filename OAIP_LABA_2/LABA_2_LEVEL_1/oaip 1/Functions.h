#pragma once
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

