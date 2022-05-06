#include "Deque.h"
#include <iostream>


bool Deque::isEmpty(void)
{
	return (length > 0) ? false : true;
}
void Deque::show(std::ostream& out)
{
	for (node* currentPtr = first; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		out << currentPtr->value << "  ";
	}
	out << std::endl;
}
void Deque::clear(void)
{
	while (!isEmpty())
		this->popBack();
}

void Deque::init(void)
{
	length = 0;
	node* tmp = new node;
	tmp->prev = nullptr;
	tmp->next = nullptr;
	first = last = tmp;
}

void Deque::pushBack(float value)
{

	if (length > 0)
	{
		node* tmp = new node;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = nullptr;
		last = tmp;
	}
	last->value = value;
	length++;
}
void Deque::pushFront(float value)
{
	if (length > 0)
	{
		node* tmp = new node;
		first->prev = tmp;
		tmp->next = first;
		tmp->prev = nullptr;
		first = tmp;
	}
	first->value = value;
	length++;
}
float Deque::popFront(void)
{
	float returnValue = first->value;
	if (first->next != nullptr)
	{
		first = first->next;
		delete(first->prev);
		first->prev = nullptr;
	}
	length--;
	return returnValue;
}
float Deque::popBack(void)
{
	float returnValue = last->value;
	if (last->prev != nullptr)
	{
		last = last->prev;
		delete(last->next);
		last->next = nullptr;
	}
	length--;
	return returnValue;
}

Deque& Deque::operator=(const Deque& rightValue)
{
	if (this == &rightValue)
		return *this;
	while (!isEmpty())
	{
		popBack();
	}
	if (rightValue.length > 0)
	{
		node* currentPtr = rightValue.first;
		this->pushBack(currentPtr->value);
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
			this->pushBack(currentPtr->value);
		}
	}
	return *this;
}
Deque& Deque::operator!()
{
	
	for (node* currentPtr=first;currentPtr!=nullptr; currentPtr=currentPtr->next)
	{
		currentPtr->value *= -1;
	}
	return *this;
}
Deque& Deque::operator++()
{
	for (node* currentPtr = first; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		currentPtr->value +=0.5f;
	}
	return *this;
}
Deque& Deque::operator--()
{
	for (node* currentPtr = first; currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		currentPtr->value -= 1.0f;
	}
	return *this;
}
Deque& operator++(Deque& value, int )
{
	system("cls");
	std::cout << "Введите помещаемое значение:";
	float tmp;
	std::cin >> tmp;
	while (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Введенно некоректное значение. Попробуйте ещё:";
		std::cin >> tmp;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	value.pushBack(tmp);
	return value;
}
Deque& operator--(Deque& value, int)
{
	if(!value.isEmpty())
		value.popFront();
	return value;
}


Deque::Deque()
{
	init();
}
Deque::Deque(int length)
{
	init();
	for (size_t i = 0; i < length ; i++)
	{
		system("cls");
		std::cout << "Введите значение помещаемое в " << i << " элемент :";
		float tmp;
		std::cin >> tmp;
		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Введенно некоректное значение. Попробуйте ещё:";
			std::cin >> tmp;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		this->pushBack(tmp);
	}
}
Deque::Deque(const Deque& original)
{
	init();
	if (original.length > 0)
	{
		node* currentPtr = original.first;
		this->pushBack(currentPtr->value);
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
			this->pushBack(currentPtr->value);
		}
	}
}

Deque::~Deque()
{
	node* currentPtr = first;
	while (currentPtr->next != nullptr)
	{
		if (currentPtr->prev != nullptr)
		{
			delete currentPtr->prev;
		}
		currentPtr = currentPtr->next;
	}
	delete currentPtr;
}


