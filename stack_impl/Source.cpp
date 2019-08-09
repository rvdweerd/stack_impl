#pragma once
//#include <iostream>
//#include <conio.h>
#include "Charstack.h"
#include "CRog.h"



void MenuChoice(char& ch)
{
	CRog::print("\n(a)dd (r)elease (p)eek (c)lear or (q)uit \n");
	ch = '0';
	while (ch != 'a' && ch != 'r' && ch != 'p' && ch != 'c' && ch != 'q')
	{
		ch = _getch();
	}
}

void RunMenu(CharStack* charstack)
{
	char choice;
	MenuChoice(choice);
	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a':
		{
			CRog::print("Enter element to add: ");
			char in = 0;
			while (in == 0)
			{
				in = _getch();
				_putch(in);
			}
			charstack->Push(in);
			break;
		}
		case 'p':
		{
			char ch[2] = { 0 };
			ch[0] = charstack->Peek();
			CRog::print(ch);
			break;
		}
		case 'r':
		{
			char ch[2] = { charstack->Pop(), 0 };
			CRog::print(ch);
			break;
		}
		case 'c':
		{
			charstack->Clear();
			//delete charstack;
			//charstack = new CharStack();
			break;
		}
		}
		char buf1[3] = { 0 }; CRog::int2str(charstack->getCapacity(), buf1, 3);
		char buf2[3] = { 0 }; CRog::int2str(charstack->getCount(), buf2, 3);
		CRog::print("\n\nStack: "); CRog::print(buf2); CRog::print("/"); CRog::print(buf1); CRog::print(" | "); charstack->Print();
		MenuChoice(choice);
	}

}

int main()
{
	CharStack charstack;// = new CharStack();

	//RunMenu(charstack);

	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		charstack.Push(ch);
	}
	while (!charstack.IsEmpty())
	{
		char ch[2] = { charstack.Pop() , 0 };
		CRog::print(ch);
	}



	while (!_kbhit());
	return 0;
}