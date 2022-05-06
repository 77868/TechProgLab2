#ifndef INTEGER_H
#define INTEGER_H
class Integer
{
public:
	Integer();
	Integer(const int& number);
	Integer(const Integer& number);

	int getValue();

	operator int();

	Integer& operator = (Integer rightValue);
	Integer& operator = (int rightValue);
	
	Integer operator + (Integer rightValue);
	Integer operator + (int rightValue);
	friend Integer operator+(int leftValue, Integer rightValue);

	Integer operator- (Integer rightValue);
	Integer operator - (int rightValue);
	friend Integer operator-(int leftValue, Integer rightValue);

	Integer operator* (Integer rightValue);
	Integer operator* (int rightValue);
	friend Integer operator*(int leftValue, Integer rightValue);

	Integer operator/ (Integer rightValue);
	Integer operator/ (int rightValue);
	friend Integer operator/ (int leftValue, Integer rightValue);



private:
	int value;
};
#endif