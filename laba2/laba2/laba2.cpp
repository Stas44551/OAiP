#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Car {
	string marka;
	string markGasoline;
	double vGasoline, vCistern, gasolineNow, vOils;
	bool wash;
	Car* next;
};
//typedef Car* PCar;
struct Washing
{
	string lastName;
	int group;
	Washing* next;
} *t;

typedef Student* PStudent;

void addStudent(PStudent& startStudent, PStudent& endStudent);
void delStudent(PStudent& startStudent, PStudent& endStudent);
void sortingStudents(PStudent& startStudent);
//void changeStudent(PStudent& startStudent, PStudent& endStudent);
void seeStudents(PStudent startStudent);



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	PStudent startStudent = NULL, endStudent = NULL;
	while (1) {
		cout << "Операции:" << endl;
		cout << "1. Добавить информацию об студенте" << endl;
		cout << "2. Вывод информации о студенте:" << endl;
		cout << "3. Удаление студента:" << endl;
		cout << "4. Сортировка по фамилиям/группам:" << endl;
		cout << "5. Редактирование информации" << endl;
		cout << "0. Закончить:" << endl;
		switch (_getch())
		{
		case '1':
			addStudent(startStudent, endStudent);
			break;
		case '2':
			seeStudents(startStudent);
			break;
		case '3':
			delStudent(startStudent, endStudent);
			break;
		case '4':
			sortingStudents(startStudent);
			break;
		case '5':
			//changeStudent(startStudent, endStudent);
			break;
		case '0':
			return 0;
		}
	}

	return 0;
}

void addStudent(PStudent& startStudent, PStudent& endStudent) {
	system("cls");
	cout << endl << "Добавление студента" << endl;
	PStudent adding = new Student;
	PGrade grade=NULL, gradeSave;
	if (!adding) {
		cout << "Нет свободной памяти" << endl;
		return;
	}
	int i = 0;
	adding->next = 0;
	cout << "	Введите фамилию студента: ";
	cin >> adding->lastName;
	cout << "	Введите группу студента: ";
	cin >> adding->group;
	cout << "	Введите оценки студента(вводить новую оценку через ентер): ";
	do {
		gradeSave = grade;
		grade = new Grade;
		cin >> grade->mark;
		grade->next = gradeSave;
		cout << "Закончить?(0-продолжить/1-закончить)";
		switch (_getch())
		{
		case '1':
			i = -212;
			adding->grade = grade;
			break;
		case '0':
		default:
			cout << "Пишите оценку";
			break;
		}
	} while (i != -212);

	if (!startStudent) {
		startStudent = endStudent = adding;
	}
	else {
		endStudent->next = adding;
		endStudent = adding;
	}
}

void seeStudents(PStudent startStudent) {
	system("cls");
	cout << "Вывод содержимого очереди" << endl;
	PStudent listStudents = startStudent;
	PGrade seeMarks;
	if (!listStudents) {
		cout << "Очередь пуста" << endl;
		return;
	}
	for (int i = 1; listStudents != NULL; i++) {
		cout << "Студент №" << i << endl;
		cout << "	Фамилия: " << listStudents->lastName << endl;
		cout << "	Группа: " << listStudents->group << endl;
		cout << "	Оценки: ";
		seeMarks = listStudents->grade;
		while (seeMarks) {
			cout << seeMarks->mark << ' ';
			seeMarks = seeMarks->next;
		}
		cout << endl;
		listStudents = listStudents->next;
	}
}

void delStudent(PStudent& startStudent, PStudent& endStudent) {
	system("cls");
	cout << "Удаление неуспевающих студентов" << endl;
	PStudent newListStudents;
	PStudent save;
	PGrade gradeCheck=NULL;
	PStudent checkStudents = startStudent;
	int numBadMarks = 0;
	if (!checkStudents) {
		cout << "Очередь пуста" << endl;
		return;
	}


	startStudent = endStudent = NULL;

	if (startStudent != endStudent != NULL) {
		cout << "ERORR" << endl;
		return;
	}


	do {
		numBadMarks = 0;
		gradeCheck = checkStudents->grade;
		while (gradeCheck)
		{
			if (gradeCheck->mark < 4) {
				numBadMarks++;
			}
			gradeCheck = gradeCheck->next;
		}
		if (numBadMarks < 3) {

			newListStudents = new Student;
			newListStudents->next = 0;
			newListStudents->lastName = checkStudents->lastName;
			newListStudents->group = checkStudents->group;
			newListStudents->grade = checkStudents->grade;

			if (!startStudent) {
				startStudent = endStudent = newListStudents;

			}
			else {
				endStudent->next = newListStudents;
				endStudent = newListStudents;

			}

		}
		checkStudents = checkStudents->next;
	} while (checkStudents != NULL);

}

void sortingStudents(PStudent& startStudent) {
	system("cls");
	PStudent t = NULL, t1= startStudent;
	int r;
	PGrade rrr = NULL;
	string rr;
	if (!t1) {
		cout << "Очередь пуста" << endl;
		return;
	}

	cout << "Выберите сортировку(1-по фамилии; 2-по группе)" << endl;
	switch (_getch())
	{
	case '1':
		do {
			for (t1 = startStudent; t1->next != t; t1 = t1->next)
				if (t1->lastName > t1->next->lastName) {
					r = t1->group;
					rr = t1->lastName;
					rrr = t1->grade;
					t1->group = t1->next->group;
					t1->lastName = t1->next->lastName;
					t1->grade = t1->next->grade;
					t1->next->group = r;
					t1->next->lastName = rr;
					t1->next->grade = rrr;
				}
			t = t1;
		} while (startStudent->next != t);
		break;

	case '2':
		do {
			for (t1 = startStudent; t1->next != t; t1 = t1->next)
				if (t1->group > t1->next->group) {
					r = t1->group;
					rr = t1->lastName;
					rrr = t1->grade;
					t1->group = t1->next->group;
					t1->lastName = t1->next->lastName;
					t1->grade = t1->next->grade;
					t1->next->group = r;
					t1->next->lastName = rr;
					t1->next->grade = rrr;
				}
			t = t1;
		} while (startStudent->next != t);
		break;

	default:
		break;
	}
	cout << "Сортировка завершена" << endl;
}

void changeStudent(PStudent& startStudent, PStudent& endStudent) {
	seeStudents(startStudent);
	int numStudent, i = 0;
	PStudent saveList = startStudent;
	PStudent changeSt = startStudent;
	PGrade grade = NULL, gradeSave;
	PStudent updateList;
	cout << "У какого студента вы хотите подредактировать информацию?(Введите номер) ";
	cin >> numStudent;
	cout << "Что вы хотите поменять?(1-фамилия 2-группа 3-оценки)";
	for (int i = 0; i != numStudent - 1; i++) {
		changeSt = changeSt->next;
	}
	switch (_getch())
	{
	case '1':
		cout << endl << "Введите фамилию" << endl;
		cin >> changeSt->lastName;
		break;
	case '2':
		cout << endl << "Введите группу" << endl;
		cin >> changeSt->group;
		break;
	case '3':
		cout << endl << "Введите оценки(вводить оценку через ентер. После окончания y):" << endl;
		do {
			gradeSave = grade;
			grade = new Grade;
			cin >> grade->mark;
			grade->next = gradeSave;
			cout << "Закончить?(0-продолжить/1-закончить)";
			switch (_getch())
			{
			case '1':
				i = -212;
				changeSt->grade = grade;
				break;
			case '0':
			default:
				cout << "Пишите оценку";
				break;
			}
		} while (i != -212);
		break;
	default:
		break;
	}
	startStudent = endStudent = NULL;
	for (int i = 0; saveList != NULL; i++) {
		updateList = new Student;
		updateList->next = 0;
		if (i == numStudent - 1) {
			updateList->lastName = changeSt->lastName;
			updateList->group = changeSt->group;
			updateList->grade = changeSt->grade;
			if (!startStudent) {
				startStudent = endStudent = updateList;
			}
			else {
				endStudent->next = updateList;
				endStudent = updateList;
			}
		}
		else {
			updateList->lastName = saveList->lastName;
			updateList->group = saveList->group;
			updateList->grade = saveList->grade;
			if (!startStudent) {
				startStudent = endStudent = saveList;
			}
			else {
				endStudent->next = saveList;
				endStudent = saveList;
			}
		}
		saveList = saveList->next;
	}
}