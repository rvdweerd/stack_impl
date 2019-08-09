#pragma once
#include <conio.h>
#include <cmath>

namespace CRog
{
	void print(const char* s)
	{
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
	}

	void printFixedWidth(const char* s, const int width)
	{
		int count = 0;
		for (; (*s != 0) && (count < width); s++)
		{
			_putch(*s);
			count++;
		}
		for (; count < width; count++)
		{
			_putch(' ');
		}
	}

	void read(char* buff, int maxSize)
	{
		const char* const pEnd = buff + maxSize;
		for (char c = _getch(); (c != 13) && (buff < pEnd - 1); c = _getch(), buff++)
		{
			*buff = c;
			_putch(c);
		}
		*buff = 0;
	}

	void strcpy(const char* pSource, char* pTarget, int maxBufferSize)
	{
		int n = 0;
		for (; *pSource != 0 && (n + 1 < maxBufferSize); pSource++, pTarget++, n++)
		{
			*pTarget = *pSource;
		}
		*pTarget = 0;
	}

	int str2int(const char* const ch)
	{
		// set r pointer 
		const char* r = ch;
		for (; *r >= '0' && *r <= '9'; r++);
		r--;
		// convert factored values and accumulate
		int total = 0;
		int factor = 1;
		for (; r >= ch; r--)
		{
			total += (*r - '0') * factor;
			factor *= 10;
		}
		return total;

	}

	void strrev(char* pl)
	{
		char* pr = pl;
		for (; *(pr + 1) != 0; pr++);

		for (; pl < pr; pl++, pr--)
		{
			//std::swap(*str, *pr);
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void int2str(int n, char* buff, int size)
	{

		char* const pStart = buff;
		char* const pEnd = buff + size;
		if (n == 0)
		{
			*buff = '0';
			buff++;
		}
		for (; n > 0 && (buff + 1 < pEnd); n /= 10, buff++)
		{
			*buff = n % 10 + '0';
		}
		*buff = 0;
		strrev(pStart);
	}
}
