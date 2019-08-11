#pragma once
#include <conio.h>

class CharStack
{
public:
	CharStack()
		:
		array(new char[INITIAL_CAPACITY] { 0 }),
		capacity(INITIAL_CAPACITY),
		count(0)
	{
	}
	CharStack(const CharStack& chstk)
	{
		CopyInternalData(chstk);
	}
	CharStack& operator=(CharStack& rhs);
	~CharStack()
	{
		delete[] array;
	}
	void CopyInternalData(const CharStack& chstk);
	int Size();
	bool IsEmpty() const;
	void Push(char ch);
	const char Pop();
	const char Peek() const;
	void Print();
	void Clear();
	int GetCapacity();
	int GetCount();
private:
	void ExpandCapacity();
private:
	char* array = nullptr;
	int capacity;
	int count;
	static constexpr int INITIAL_CAPACITY = 10;
};