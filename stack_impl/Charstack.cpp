#pragma once
#include "Charstack.h"

CharStack& CharStack::operator=(CharStack& rhs)
{
	if (this != &rhs)
	{
		delete[] this->array;
		this->CopyInternalData(rhs);
	}
		return *this;
}

void CharStack::CopyInternalData(const CharStack& chstk)
{
	this->count = chstk.count;
	this->capacity = chstk.capacity;
	this->array = new char[this->capacity]{ 0 };
	for (int i = 0; i < this->count; i++)
	{
		this->array[i] = chstk.array[i];
	}
}

int CharStack::Size()
{
	return count;
}

bool CharStack::IsEmpty() const
{
	return count==0;
}

void CharStack::Push(char ch)
{
	if (count == capacity)
	{
		ExpandCapacity();
	}
	array[count++] = ch;
	}

const char CharStack::Pop()
{
	if (IsEmpty())
	{
		return 0;
	}
	else
	{
		return array[--count];
	}
}

const char CharStack::Peek() const
{
	if (IsEmpty())
	{
		return 0;
	}
	else
	{
		return array[count - 1];
	}
}

void CharStack::Print()
{
	for (int i = 0 ; i < count; i++)
	{
		_putch(array[i]);
	}
}

void CharStack::Clear()
{
	delete[] array;
	array = new char[INITIAL_CAPACITY]{ 0 };
	capacity = INITIAL_CAPACITY;
	count = 0;
}

int CharStack::GetCapacity()
{
	return capacity;
}

int CharStack::GetCount()
{
	return count;
}

void CharStack::ExpandCapacity()
{
	char* array_old = array;
	
	capacity += INITIAL_CAPACITY;
	array = new char[capacity]{ 0 };

	for (int i = 0; i < count; i++)
	{
		array[i] = array_old[i];
	}

	delete[] array_old;
}
