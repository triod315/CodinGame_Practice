// CodinGame_Chuk_Norris.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
using namespace std;

string CharToBinary(char c)//convert one char(it`s ASCII code) to binary 7-bit code
{ 
	string Code = "";//temporary variable for converting to binary code
	string BinaryCode = "";//Variable for output bianry code
	int number = (int)c;//ASCII code of char

	while (number > 1)
	{
		Code += (number % 2);
		number /= 2;
	}
	Code += number;
	for (int i = Code.length() - 1; i >= 0; i--)
	{
		BinaryCode += Code[i];
	}
	if (BinaryCode.length() % 7 != 0)//chek for 7-bit format of output code
		for (int i = 0; i < BinaryCode.length() % 7; i++) BinaryCode = (char)0 + BinaryCode;
	return BinaryCode;
}

int main()
{
	string MESSAGE;//input text
	getline(cin, MESSAGE);
	string code = "";//output text(bianry code)
	for (int i = 0; i < MESSAGE.length(); i++)
	{
		code += CharToBinary(MESSAGE[i]);//converting from char to binary code for all char`s
	}
	int current_bit = 2;
	for (int i = 0; i < code.length(); i++)
	{
		if ((int)code[i] == current_bit) cout << '0';//chek if current bit equal previous bit
		else
		{
			if ((int)code[i] == 1)
			{
				cout << " 0 0";
			}
			else
			{
				cout << " 00 0";
			}
		}
		current_bit = (int)code[i];
	}
	return 0;
}

