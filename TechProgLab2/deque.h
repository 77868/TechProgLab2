#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
#include <iostream>

class Deque
{
public:
	bool isEmpty(void);
	void show(std::ostream & out);
	void clear();

	void pushBack(float value);
	void pushFront(float value);
	float popBack(void);
	float popFront(void);

	Deque& operator!();
	Deque& operator++();
	Deque& operator--();
	friend Deque& operator++(Deque& value,int );
	friend Deque& operator--(Deque& value, int);
	Deque& operator=(const Deque& rightValue);

	Deque();
	Deque(int length);
	Deque(const Deque& Deque);
	
	~Deque();
private:
	void init(void);
	node* first;
	node* last;
	int length;
};
#endif
