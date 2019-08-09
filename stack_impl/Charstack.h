#pragma once
#include <conio.h>

class CharStack
{
public:
	CharStack()
		:
		array(new char[INITIAL_CAPACITY]{ 0 }),
		capacity(INITIAL_CAPACITY),
		count (0)
	{
	}
	~CharStack()
	{
		delete[] array;
	}
	int Size();
	bool IsEmpty() const;
	void Push(char ch);
	const char Pop();
	const char Peek() const;
	void Print();
	void Clear();
	int getCapacity();
	int getCount();
private:
	void ExpandCapacity();
private:
	char* array = nullptr;
	int capacity;
	int count;
	static constexpr int INITIAL_CAPACITY = 10;
};