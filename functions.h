#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
using namespace std;
// Приветствие
void welcome() {
	cout << "====================================================================" << endl;
	cout << "\t\t\tДОБРО ПОЖАЛОВАТЬ!" << endl;
	cout << "====================================================================" << endl;
}
// Прощание
void exit() {
	cout << "===================================================================" << endl;
	cout << "\t\t\tДО СВИДАНИЯ!" << endl;
	cout << "===================================================================" << endl;
}
// Основное меню
int menuMain() {
	int menuMainResult;
	cout << "\nДоступные действия: " << endl;
	cout << "[1] Показать задачи;\n" <<
		"[2] Удалить выполненную задачу;\n" <<
		"[3] Редактировать задачу;\n" <<
		"[4] Добавить новые задачи;\n" <<
		"[5] Показать задачи определенной категории;\n" <<
		"[0] Выход из программы.\n\n" <<
		"Введите номер желаемого действия: ";
	cin >> menuMainResult;
	return menuMainResult;
}
// Меню категорий
int categoryMenu() {
	int categoryMenuResult;
	cout << "[1] Личные;\n" <<
		"[2] Рабочие;\n" <<
		"[3] Покупки;\n" <<
		"[4] Другие.\n\n" <<
		"Введите номер желаемого действия: ";
	cin >> categoryMenuResult;
	return categoryMenuResult;
}
#endif
