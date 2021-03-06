#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include "classTasker.h"
#include "functions.h"
#include "classArray.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char address[] = "tasks.txt";
	int menuMainResult = 1;
	Array <Tasker> Obj(address);
	while (menuMainResult > 0) {
		menuMainResult = menuMain();
		switch (menuMainResult) {
		// Отображение задач
		case 1: {
			if (Obj.taskOutOnScreen()) {
				Obj.taskSave(address);
			}
			else {
				cout << "\n\tВСЕ ЗАДАЧИ УДАЛЕНЫ!" << endl;
			}
			break;
		}
		// Удаление задачи
		case 2: {
			Obj.taskOutOnScreen();
			int taskDeleteNum;
			cout << "Введите номер удаляемой задачи: ";
			cin >> taskDeleteNum;
			if (Obj.taskDelete(taskDeleteNum)) {
				system("cls");
				cout << "\n\tЗАДАЧА УДАЛЕНА!" << endl;
				Obj.taskSave(address);
			}
			else {
				system("cls");
				cout << "\n\tЗАДАЧА НЕ НАЙДЕНА!" << endl;

			}
			break;
		}
		// Изменение задачи
		case 3: {
			Obj.taskOutOnScreen();
			int taskEditNum;
			cout << "Введите номер редактируемой задачи: ";
			cin >> taskEditNum;
			if (Obj.taskEdit(taskEditNum)) {
				Obj.taskSave(address);
			}
			else {
				system("cls");
				cout << "\n\tЗАДАЧА НЕ НАЙДЕНА!" << endl;
			}
			break;
		}
		// Добавление задач
		case 4: {
			system("cls");
			cout << "Введите количество задач, которые вы хотите добавить: ";
			int taskAddNum;
			cin >> taskAddNum;
			if (Obj.taskAdd(taskAddNum)) {
				Obj.taskSave(address);
			}
			else {
				system("cls");
				cout << "\n\tСЛИШКОМ МНОГО ЗАДАЧ!" << endl;
			}
			break;
		}
		case 5: {
			system("cls");
			int categoryMenuResult;
			cout << "Выберите категорию, которую нужно показать на экране: " << endl;
			categoryMenuResult = categoryMenu();
			system("cls");
			if (categoryMenuResult > 0 && categoryMenuResult < 5) {
				if (Obj.taskCategoryOut(categoryMenuResult)) {
				}
				else {
					system("cls");
					cout << "\n\tЗАДАЧИ ДАННОЙ КАТЕГОРИИ НЕ НАЙДЕНЫ!" << endl;
				}
			}
			else {
				system("cls");
				cout << "\n\tКАТЕГОРИЯ НЕ НАЙДЕНА!" << endl;
			} 
			break;
		}
		// Выход из программы
		case 0: {
			Obj.taskSave(address);
			system("cls");
			exit();
			break;
		}
		// Неверная команда
		default: {
			Obj.taskSave(address);
			system("cls");
			cout << "\n\tНЕВЕРНАЯ КОМАНДА!" << endl;
		}
		}
	}
	return 0;
}
