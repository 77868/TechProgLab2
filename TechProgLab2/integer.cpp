#include "integer.h"
Integer::Integer()
{
	value = 0;
}
Integer::Integer(const int& rightValue)
{
	value = rightValue;
}
Integer::Integer(const Integer& rightValue)
{
	value = rightValue.value;
}

int Integer::getValue()
{
	return this->value;
}

Integer& Integer::operator =(Integer rightValue)
{
	if (this==&rightValue)
		return *this;
	value = rightValue.value;
	return *this;
}
Integer& Integer::operator = (int rightValue)
{
	value = rightValue;
	return *this;
}

Integer Integer::operator + (Integer rightValue)
{
	Integer result(value + rightValue.value);
	return result;
}
Integer Integer::operator + (int rightValue)
{
	Integer result(value + rightValue);
	return result;
}
Integer operator+(int leftValue, Integer rightValue)
{
	Integer result(leftValue + rightValue.value);
	return result;
}

Integer Integer::operator- (Integer rightValue)
{
	Integer result(value - rightValue.value);
	return result;
}
Integer Integer::operator - (int rightValue)
{
	Integer result(value - rightValue);
	return result;
}
Integer operator-(int leftValue, Integer rightValue)
{
	Integer result(leftValue - rightValue.value);
	return result;
}

Integer Integer::operator* (Integer rightValue)
{
	Integer result(value * rightValue.value);
	return result;
}
Integer Integer::operator* (int rightValue)
{
	Integer result(value * rightValue);
	return result;
}
Integer operator*(int leftValue, Integer rightValue)
{
	Integer result(leftValue * rightValue.value);
	return result;
}

Integer Integer::operator/ (Integer rightValue)
{
	Integer result(value / rightValue.value);
	return result;
}
Integer Integer::operator/ (int rightValue)
{
	Integer result(value / rightValue);
	return result;
}
Integer operator/ (int leftValue, Integer rightValue)
{
	Integer result(leftValue / rightValue.value);
	return result;
}

Integer::operator int()
{
	return value;
}

