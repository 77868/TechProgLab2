// TechProgLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//• Задание 1. Унарная операция
//  Создать объект "Дэк".
//  Размер и значения дэка вводятся с клавиатуры пользователем.
// 
// необходимо перегрузить следующие операторы : 
// 1)оператор !как метод для получения дэка с отрицательными значениями; 
// 2)оператор префиксного декрементирования как метод для уменьшения значения всех элементов дэка на единицу; 
// 3)оператор префиксного инкрементирования как метод для увеличения всех элементов на 0, 5; 
// 4)оператор постфиксного декрементирования как дружественную функцию для извлечения из дэка;
// 5)оператор постфиксного инкрементирования как дружественная функция для добавления элемента(пользовательское число) в дэк.
// 
// 
//• Задание 2. Бинарная операция
//  Создать класс “Целое число”.
// 
// Необходимо перегрузить следующие операторы :
// 1)оператор сложения, вычитания, умножения и деления как для работы с другими экземплярами класса, так и с пользовательскими числами;
// 2)оператор преобразования в int. 
// Необходимо учитывать то, что пользовательское число и объект класса могут находится и слева и справа от оператора.
// На усмотрение студента остается решение какой оператор какой перегрузки требует(метод или дружественная функция)

#include <iostream>
#include <locale>
#include "integer.h"
#include "deque.h"

void demonstrateInteger();
void demonstrateDeque();
int choiseMode();
int getInt();

void main()
{
	setlocale(LC_ALL,"Russian");
	std::cout << "Выберите класс для взаимодействия:\n 1 - Deque\n 2 - Integer" << std::endl;
	int choise = 0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}

	while (choise < 1 || choise > 2)
	{
		system("cls");
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	switch (choise)
	{
	case 1:
		demonstrateDeque();
		break;
	case 2:
		demonstrateInteger();
		break;
	}
	return;
}
void demonstrateInteger()
{
	system("cls");
	std::cout << "Введите значение" << std::endl;
	int val = 0;
	std::cin >> val;
	while (!std::cin.good())
	{
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> val;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Integer integer(val);
	
	while (true)
	{
		system("cls");
		std::cout << "Integer = " <<(int)integer<< std::endl;
		std::cout << "Выберите действие:\n 1 - сложение  \n 2 - вычитание \n 3 - умножение  \n 4 - деление \n 5 - выйти" << std::endl;
		int choise = 0;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		while (choise < 1 || choise > 5)
		{

			std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
			std::cin >> choise;
			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore();
			}
		}
		int val = getInt();
		Integer tmp(val);
		switch (choise)
		{
		case 1://+
			switch (choiseMode())
			{
			case 1:
				integer = integer + val;
				break;
			case 2:
				integer = integer + tmp;
				break;
			case 3:
				integer = val + integer;
				break;
			}
			break;
		case 2://-
			switch (choiseMode())
			{
			case 1:
				integer = integer - val;
				break;
			case 2:
				integer = integer - tmp;
				break;
			case 3:
				integer = val - integer;
				break;
			}
			break;
		case 3://*
			switch (choiseMode())
			{
			case 1:
				integer = val * integer;
				break;
			case 2:
				integer = integer * tmp;
				break;
			case 3:
				integer = integer * val;
				break;
			}
			break;
		case 4://  /
			switch (choiseMode())
			{
			case 1:
				integer =val / integer;
				break;
			case 2:
				integer = integer / tmp;
				break;
			case 3:
				integer = integer/val;
				break;
			}
			break;
		case 5:
			return;
		}
	}
}
void demonstrateDeque()
{
	system("cls");
	std::cout << "Введите длину Дэка" << std::endl;
	int len = -1;
	std::cin >> len;
	
	while (len < 0 || !std::cin.good())
	{
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> len;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Deque deque(len);
	while (true)
	{
		system("cls");
		deque.show(std::cout);
		std::cout << "Выберите действие:\n 1 - оператор отрицания \n 2 - оператор префиксного инкрементирования \n 3 - оператор префиксного декрементирования \n 4 - оператор постфиксного инкрементирования\n 5 - оператор постфиксного декрементирования\n 6 - выйти" << std::endl;
		int choise = 0;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		while (choise < 1 || choise > 6)
		{

			std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
			std::cin >> choise;
			if (!std::cin.good())
			{
				std::cin.clear();
				std::cin.ignore();
			}
		}
		switch (choise)
		{
		case 1:
			!deque;
			break;
		case 2:
			++deque;
			break;
		case 3:
			--deque;
			break;
		case 4:
			deque++;
			break;
		case 5:
			deque--;
			break;
		case 6:
			return;
		}
	}
}

int choiseMode()
{
	system("cls");
	std::cout << "Выберите тип действия:\n 1 - integer int \n 2 - integer integer \n 3 - int integer"<< std::endl;
	int choise = 0;
	std::cin >> choise;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
	}
	while (choise < 1 || choise > 3)
	{

		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin >> choise;
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
		}
	}
	return choise;
}

int getInt()
{
	system("cls");
	std::cout << "Введите значение" << std::endl;
	int val = 0;
	std::cin >> val;
	while (!std::cin.good())
	{
		std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> val;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return val;
}
