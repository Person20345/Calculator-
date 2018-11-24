#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int fcInt_HowManyNumbers(string str_StringWithNumbers) {
	int int_HowManyNumbers = 0, int_Position = 0;
	for (int i = 0; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (ch_Symbol == '0' || ch_Symbol == '1' || ch_Symbol == '2' || ch_Symbol == '3' || ch_Symbol == '4' || ch_Symbol == '5' || ch_Symbol == '6' || ch_Symbol == '7' || ch_Symbol == '8' || ch_Symbol == '9' || ch_Symbol == '.') {
			if (int_Position == 0) {
				int_Position = 1;
				int_HowManyNumbers++;
			}
		}
		else {
			if (int_Position == 1) {
				int_Position = 0;
			}
		}
	}
	return int_HowManyNumbers;
}

string fcStr_RootAndPower(string str_StringWithNumbers) {
	string str_BeforeAll, str_BeforeFirstNumber, str_FirstNumber, str_BetweenNumbers, str_SecondNumber, str_Answer, str_AfterNumbers;
	int int_WhereIsStringBeforeFirstNumber = 0, int_WhatAction = 0;
	bool bl_EndTheCycle = 0;
	stringstream strstr_FirstNumber, strstr_SecondNumber;
	float fl_FirstNumber, fl_SecondNumber, fl_Answer;
	for (int i = 0; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (ch_Symbol == 'r' || ch_Symbol == 'p') {
			if (ch_Symbol == 'r') {
				int_WhatAction = 1;
			} else if (ch_Symbol == 'p') {
				int_WhatAction = 2;
			}
			int int_Position = 0;
			int j = i;
			for (; j >= 0; j = j - 1) {
				char ch_Symbol_0 = str_StringWithNumbers[j];
				if (ch_Symbol_0 == '0' || ch_Symbol_0 == '1' || ch_Symbol_0 == '2' || ch_Symbol_0 == '3' || ch_Symbol_0 == '4' || ch_Symbol_0 == '5' || ch_Symbol_0 == '6' || ch_Symbol_0 == '7' || ch_Symbol_0 == '8' || ch_Symbol_0 == '9' || ch_Symbol_0 == '.') {
					if (int_Position == 0) {
						int_Position = 1;
					} else if (int_Position == 2) {
						int_WhereIsStringBeforeFirstNumber = j + 1;
						bl_EndTheCycle = 1;
						break;
					}
				} else {
					if (int_Position == 1) {
						int_Position = 2;
					}
				}
			}
			if (bl_EndTheCycle == 0) {
				int_WhereIsStringBeforeFirstNumber = j + 1;
			}
			break;
		}
	}
	int int_Position = 0;
	for (int i = int_WhereIsStringBeforeFirstNumber; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (ch_Symbol == '0' || ch_Symbol == '1' || ch_Symbol == '2' || ch_Symbol == '3' || ch_Symbol == '4' || ch_Symbol == '5' || ch_Symbol == '6' || ch_Symbol == '7' || ch_Symbol == '8' || ch_Symbol == '9' || ch_Symbol == '.') {
			if (int_Position == 0) {
				int_Position = 1;
				str_FirstNumber += ch_Symbol;
			} else if (int_Position == 1) {
				str_FirstNumber += ch_Symbol;
			} else if (int_Position == 2) {
				int_Position = 3;
				str_SecondNumber += ch_Symbol;
			} else if (int_Position == 3) {
				str_SecondNumber += ch_Symbol;
			} else if (int_Position == 4) {
				str_AfterNumbers += ch_Symbol;
			}
		} else {
			if (int_Position == 0) {
				str_BeforeFirstNumber += ch_Symbol;
			} else if (int_Position == 1) {
				int_Position = 2;
				str_BetweenNumbers += ch_Symbol;
			} else if (int_Position == 2) {
				str_BetweenNumbers += ch_Symbol;
			} else if (int_Position == 3) {
				int_Position = 4;
				str_AfterNumbers += ch_Symbol;
			} else if (int_Position == 4) {
				str_AfterNumbers += ch_Symbol;
			}
		}
	}
	int int_NumberOfMinus_1 = 0;
	for (int i = 0; i < str_BetweenNumbers.length(); i++) {
		char ch_Symbol = str_BetweenNumbers[i];
		if (ch_Symbol == '-') {
			int_NumberOfMinus_1++;
		}
	}
	for (int i = 0; i <= int_WhereIsStringBeforeFirstNumber - 1; i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		str_BeforeAll += ch_Symbol;
	}
	if (int_NumberOfMinus_1 % 2 == 1) {
		str_SecondNumber = '-' + str_SecondNumber;
	}
	int int_NumberOfMinus_0 = 0;
	for (int i = 0; i < str_BeforeFirstNumber.length(); i++) {
		char ch_Symbol = str_BeforeFirstNumber[i];
		if (ch_Symbol == '-') {
			int_NumberOfMinus_0++;
			str_BeforeFirstNumber[i] = ' ';
		}
	}
	if (int_NumberOfMinus_0 % 2 == 1) {
		str_FirstNumber = '-' + str_FirstNumber;
	}
	strstr_FirstNumber << str_FirstNumber;
	strstr_FirstNumber >> fl_FirstNumber;
	strstr_SecondNumber << str_SecondNumber;
	strstr_SecondNumber >> fl_SecondNumber;
	if (int_WhatAction == 1) {
		fl_Answer = pow(fl_FirstNumber, 1/fl_SecondNumber);
	} else if (int_WhatAction == 2) {
		fl_Answer = pow(fl_FirstNumber, fl_SecondNumber);
	}
	str_Answer = to_string(fl_Answer);
	if (bl_EndTheCycle == 0) {
		str_StringWithNumbers = str_Answer + str_AfterNumbers;
	} else if (bl_EndTheCycle == 1) {
		str_StringWithNumbers = str_BeforeAll + str_BeforeFirstNumber + str_Answer + str_AfterNumbers;
	}
	int int_HowManyNumbers = 0;
	int_HowManyNumbers = fcInt_HowManyNumbers(str_StringWithNumbers);
	size_t sz_FindInString_0 = str_StringWithNumbers.find('r');
	size_t sz_FindInString_1 = str_StringWithNumbers.find('p');
	if ((sz_FindInString_0 != string::npos || sz_FindInString_1 != string::npos) && int_HowManyNumbers != 1 && int_HowManyNumbers != 0) {
		str_StringWithNumbers = fcStr_RootAndPower(str_StringWithNumbers);
	}
	return str_StringWithNumbers;
}

string fcStr_StringWishMultiplication(string str_StringWithNumbers) {
	string str_BeforeAll, str_BeforeFirstNumber, str_FirstNumber, str_BetweenNumbers, str_SecondNumber, str_Answer, str_AfterNumbers;
	int int_WhereIsStringBeforeFirstNumber = 0, int_WhatAction = 0;
	bool bl_EndTheCycle = 0;
	stringstream strstr_FirstNumber, strstr_SecondNumber;
	float fl_FirstNumber, fl_SecondNumber, fl_Answer;
	for (int i = 0; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (ch_Symbol == '*' || ch_Symbol == '/' || ch_Symbol == ':') {
			if (ch_Symbol == '/' || ch_Symbol == ':') {
				int_WhatAction = 1;
			} else if (ch_Symbol == '*') {
				int_WhatAction = 2;
			}
			int int_Position = 0;
			int j = i;
			for (; j >= 0; j = j - 1) {
				char ch_Symbol_0 = str_StringWithNumbers[j];
				if (ch_Symbol_0 == '0' || ch_Symbol_0 == '1' || ch_Symbol_0 == '2' || ch_Symbol_0 == '3' || ch_Symbol_0 == '4' || ch_Symbol_0 == '5' || ch_Symbol_0 == '6' || ch_Symbol_0 == '7' || ch_Symbol_0 == '8' || ch_Symbol_0 == '9' || ch_Symbol_0 == '.') {
					if (int_Position == 0) {
						int_Position = 1;
					} else if (int_Position == 2) {
						int_WhereIsStringBeforeFirstNumber = j + 1;
						bl_EndTheCycle = 1;
						break;
					} 
				} else {
					if (int_Position == 1) {
						int_Position = 2;
					}
				}
			}
			if (bl_EndTheCycle == 0) {
				int_WhereIsStringBeforeFirstNumber = j + 1;
			}
			break;
		}
	}
	int int_Position = 0;
	for (int i = int_WhereIsStringBeforeFirstNumber; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (ch_Symbol == '0' || ch_Symbol == '1' || ch_Symbol == '2' || ch_Symbol == '3' || ch_Symbol == '4' || ch_Symbol == '5' || ch_Symbol == '6' || ch_Symbol == '7' || ch_Symbol == '8' || ch_Symbol == '9' || ch_Symbol == '.') {
			if (int_Position == 0) {
				int_Position = 1;
				str_FirstNumber += ch_Symbol;
			} else if (int_Position == 1) {
				str_FirstNumber += ch_Symbol;
			} else if (int_Position == 2) {
				int_Position = 3;
				str_SecondNumber += ch_Symbol;
			} else if (int_Position == 3) {
				str_SecondNumber += ch_Symbol;
			} else if (int_Position == 4) {
				str_AfterNumbers += ch_Symbol;
			}
		} else {
			if (int_Position == 0) {
				str_BeforeFirstNumber += ch_Symbol;
			} else if (int_Position == 1) {
				int_Position = 2;
				str_BetweenNumbers += ch_Symbol;
			} else if (int_Position == 2) {
				str_BetweenNumbers += ch_Symbol;
			} else if (int_Position == 3) {
				int_Position = 4;
				str_AfterNumbers += ch_Symbol;
			} else if (int_Position == 4) {
				str_AfterNumbers += ch_Symbol;
			}
		}
	}
	int int_NumberOfMinus_1 = 0;
	for (int i = 0; i < str_BetweenNumbers.length(); i++) {
		char ch_Symbol = str_BetweenNumbers[i];
		if (ch_Symbol == '-') {
			int_NumberOfMinus_1++;
		}
	}
	for (int i = 0; i <= int_WhereIsStringBeforeFirstNumber - 1; i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		str_BeforeAll += ch_Symbol;
	}
	if (int_NumberOfMinus_1 % 2 == 1) {
		str_SecondNumber = '-' + str_SecondNumber;
	}
	if (bl_EndTheCycle == 0) {
		int int_NumberOfMinus_0 = 0;
		for (int i = 0; i < str_BeforeFirstNumber.length(); i++) {
			char ch_Symbol = str_BeforeFirstNumber[i];
			if (ch_Symbol == '-') {
				int_NumberOfMinus_0++;
			}
		}
		if (int_NumberOfMinus_0 % 2 == 1) {
			str_FirstNumber = '-' + str_FirstNumber;
		}
	}
	strstr_FirstNumber << str_FirstNumber;
	strstr_FirstNumber >> fl_FirstNumber;
	strstr_SecondNumber << str_SecondNumber;
	strstr_SecondNumber >> fl_SecondNumber;
	if (int_WhatAction == 1) {
		fl_Answer = fl_FirstNumber / fl_SecondNumber;
	} else if (int_WhatAction == 2) {
		fl_Answer = fl_FirstNumber * fl_SecondNumber;
	}
	str_Answer = to_string(fl_Answer);
	if (bl_EndTheCycle == 0) {
		str_StringWithNumbers = str_Answer + str_AfterNumbers;
	} else if (bl_EndTheCycle == 1) {
		str_StringWithNumbers = str_BeforeAll + str_BeforeFirstNumber + str_Answer + str_AfterNumbers;
	}
	int int_HowManyNumbers = 0;
	int_HowManyNumbers = fcInt_HowManyNumbers(str_StringWithNumbers);
	size_t sz_FindInString_0 = str_StringWithNumbers.find('*');
	size_t sz_FindInString_1 = str_StringWithNumbers.find('/');
	size_t sz_FindInString_2 = str_StringWithNumbers.find(':');
	if ((sz_FindInString_0 != string::npos || sz_FindInString_1 != string::npos || sz_FindInString_2 != string::npos) && int_HowManyNumbers != 1 && int_HowManyNumbers != 0) {
		str_StringWithNumbers = fcStr_StringWishMultiplication(str_StringWithNumbers);
	}
	return str_StringWithNumbers;
}

string fcStr_StringWishAdd(string str_StringWithNumbers) {
	int int_Position = 0;
	string str_FirstNumber, str_SecondNumber, str_BeforeNumbers, str_BetweenNumbers, str_AfterNumbers, str_Answer;
	stringstream strstr_FirstNumber, strstr_SecondNumber;
	float fl_FirstNumber, fl_SecondNumber, fl_Answer;
	for (int i = 0; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (ch_Symbol == '0' || ch_Symbol == '1' || ch_Symbol == '2' || ch_Symbol == '3' || ch_Symbol == '4' || ch_Symbol == '5' || ch_Symbol == '6' || ch_Symbol == '7' || ch_Symbol == '8' || ch_Symbol == '9' || ch_Symbol == '.') {
			if (int_Position == 0) {
				int_Position = 1;
				str_FirstNumber += ch_Symbol;
			} else if (int_Position == 1) {
				str_FirstNumber += ch_Symbol;
			} else if (int_Position == 2) {
				int_Position = 3;
				str_SecondNumber += ch_Symbol;
			} else if (int_Position == 3) {
				str_SecondNumber += ch_Symbol;
			} else if (int_Position == 4) {
				str_AfterNumbers += ch_Symbol;
			}
		} else {
			if (int_Position == 0) {
				str_BeforeNumbers += ch_Symbol;
			} else if (int_Position == 1) {
				int_Position = 2;
				str_BetweenNumbers += ch_Symbol;
			} else if (int_Position == 2) {
				str_BetweenNumbers += ch_Symbol;
			} else if (int_Position == 3) {
				int_Position = 4;
				str_AfterNumbers += ch_Symbol;
			} else if (int_Position == 4) {
				str_AfterNumbers += ch_Symbol;
			}
		}
	}
	size_t sz_FindMinus = str_BeforeNumbers.find('-');
	if (sz_FindMinus != string::npos) {
		str_FirstNumber = '-' + str_FirstNumber;
	}
	int int_NumberOfMinus = 0;
	for (int i = 0; i < str_BetweenNumbers.length(); i++) {
		char ch_Symbol = str_BetweenNumbers[i];
		if (ch_Symbol == '-') {
			int_NumberOfMinus++;
		}
	}
	size_t sz_FindPlus = str_BetweenNumbers.find('+');
	strstr_FirstNumber << str_FirstNumber;
	strstr_FirstNumber >> fl_FirstNumber;
	strstr_SecondNumber << str_SecondNumber;
	strstr_SecondNumber >> fl_SecondNumber;
	if (int_NumberOfMinus % 2 == 1) {
		fl_Answer = fl_FirstNumber - fl_SecondNumber;
	} else if (int_NumberOfMinus % 2 == 0 || (int_NumberOfMinus == 0 && sz_FindPlus != string::npos)) {
		fl_Answer = fl_FirstNumber + fl_SecondNumber;
	}
	str_Answer = to_string(fl_Answer);
	str_StringWithNumbers = str_Answer + str_AfterNumbers;
	int int_HowManyNumbers = 0;
	int_HowManyNumbers = fcInt_HowManyNumbers(str_StringWithNumbers);
	size_t sz_FindInString_3 = str_StringWithNumbers.find('+');
	size_t sz_FindInString_4 = str_StringWithNumbers.find('-');
	if ((sz_FindInString_3 != string::npos || sz_FindInString_4 != string::npos) && int_HowManyNumbers != 1 && int_HowManyNumbers != 0) {
		str_StringWithNumbers = fcStr_StringWishAdd(str_StringWithNumbers);
	}
	return str_StringWithNumbers;
}

string fcStr_EquationInNumber(string str_StringWithNumbers) {
	int int_Position = 0, int_HowManyNumbers = 0;
	string str_FirstNumber;
	for (int i = 0; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (ch_Symbol == '0' || ch_Symbol == '1' || ch_Symbol == '2' || ch_Symbol == '3' || ch_Symbol == '4' || ch_Symbol == '5' || ch_Symbol == '6' || ch_Symbol == '7' || ch_Symbol == '8' || ch_Symbol == '9' || ch_Symbol == '.') {
			if (int_Position == 0) {
				int_Position = 1;
				int_HowManyNumbers++;
				if (int_HowManyNumbers == 1) {
					str_FirstNumber += ch_Symbol;
				}
			} else if (int_Position == 1) {
				if (int_HowManyNumbers == 1) {
					str_FirstNumber += ch_Symbol;
				}
			}
		} else {
			if (int_Position == 1) {
				int_Position = 0;
			}
		}
	}
	if (int_HowManyNumbers == 1) {
		int int_HowManyMinus = 0;
		for (int i = 0; i < str_StringWithNumbers.length(); i++) {
			char ch_Symbol = str_StringWithNumbers[i];
			if (ch_Symbol == '-') {
				int_HowManyMinus++;
			}
		}
		if (int_HowManyMinus % 2 == 1) {
			str_StringWithNumbers = '-' + str_FirstNumber;
		} else {
			str_StringWithNumbers = str_FirstNumber;
		}
	} else {
		int int_HowManyNumbers = 0;
		int_HowManyNumbers = fcInt_HowManyNumbers(str_StringWithNumbers);
		size_t sz_FindInString_0 = str_StringWithNumbers.find('r');
		size_t sz_FindInString_1 = str_StringWithNumbers.find('p');
		if ((sz_FindInString_0 != string::npos || sz_FindInString_1 != string::npos) && int_HowManyNumbers != 1 && int_HowManyNumbers != 0) {
			str_StringWithNumbers = fcStr_RootAndPower(str_StringWithNumbers);
		}
		int_HowManyNumbers = fcInt_HowManyNumbers(str_StringWithNumbers);
		size_t sz_FindInString_2 = str_StringWithNumbers.find('*');
		size_t sz_FindInString_3 = str_StringWithNumbers.find('/');
		size_t sz_FindInString_4 = str_StringWithNumbers.find(':');
		if ((sz_FindInString_2 != string::npos || sz_FindInString_3 != string::npos || sz_FindInString_4 != string::npos) && int_HowManyNumbers != 1 && int_HowManyNumbers != 0) {
			str_StringWithNumbers = fcStr_StringWishMultiplication(str_StringWithNumbers);
		}
		int_HowManyNumbers = fcInt_HowManyNumbers(str_StringWithNumbers);
		size_t sz_FindInString_5 = str_StringWithNumbers.find('+');
		size_t sz_FindInString_6 = str_StringWithNumbers.find('-');
		if ((sz_FindInString_5 != string::npos || sz_FindInString_6 != string::npos) && int_HowManyNumbers != 1 && int_HowManyNumbers != 0) {
			str_StringWithNumbers = fcStr_StringWishAdd(str_StringWithNumbers);
		}
	}
	return str_StringWithNumbers;
}

string fcStr_BracketInNumber(string str_StringWithNumbers) {
	string str_InBracket, str_WordsBeforeBracket, str_WordsLaterBracket, str_LastBracketNumber;
	int int_Position=0;
	for (int i = 0; i < str_StringWithNumbers.length(); i++) {
		char ch_Symbol = str_StringWithNumbers[i];
		if (int_Position == 0) {
			if (ch_Symbol == '(') {
				int_Position = 1;
			} else {
				str_WordsBeforeBracket += ch_Symbol;
			}
		} else if (int_Position == 1) {
			if (ch_Symbol == '0' || ch_Symbol == '1' || ch_Symbol == '2' || ch_Symbol == '3' || ch_Symbol == '4' || ch_Symbol == '5' || ch_Symbol == '6' || ch_Symbol == '7' || ch_Symbol == '8' || ch_Symbol == '9' || ch_Symbol == '*' || ch_Symbol == ':' || ch_Symbol == '/' || ch_Symbol == '-' || ch_Symbol == '+' || ch_Symbol == 'p' || ch_Symbol == 'r' || ch_Symbol == '.') {
				str_InBracket += ch_Symbol;
			} else if (ch_Symbol == ')') {
				int_Position = 2;
			} 
		} else if (int_Position == 2) {
			str_WordsLaterBracket += ch_Symbol;
		}
	}
	size_t sz_BracketFind_0_0 = str_InBracket.find('(');
	size_t sz_BracketFind_0_1 = str_InBracket.find(')');
	size_t sz_BracketFind_1_0 = str_WordsLaterBracket.find('(');
	size_t sz_BracketFind_1_1 = str_WordsLaterBracket.find(')');
	if (sz_BracketFind_0_0 != string::npos && sz_BracketFind_0_1 != string::npos) {
		str_InBracket = fcStr_BracketInNumber(str_InBracket);
	}
	if (sz_BracketFind_1_0 != string::npos && sz_BracketFind_1_1 != string::npos) {
		str_WordsLaterBracket = fcStr_BracketInNumber(str_WordsLaterBracket);
	}
	str_LastBracketNumber = fcStr_EquationInNumber(str_InBracket);
	str_StringWithNumbers = str_WordsBeforeBracket + str_LastBracketNumber + str_WordsLaterBracket;
	return str_StringWithNumbers;
}

int main() {
	while (true) {
		float fl_LastAnswer;
		string str_UsersWords;
		stringstream strstr_UsersWords;
		cout << "Write equation, you can write help:" << endl;
		getline(cin, str_UsersWords);
		str_UsersWords = ' ' + str_UsersWords + ' ';
		size_t sz_FindHelp = str_UsersWords.find(" help ");
		if (sz_FindHelp != string::npos) {
			cout << "You can use calculator wish power(p), root(r), +, -, /, *." << endl << "To use power wish numbers write '_number_ 'p' _power_', to use root wish numbers write '_number_ 'r' _root_'." << endl;
		}
		size_t sz_NumberFind_0 = str_UsersWords.find('0');
		size_t sz_NumberFind_1 = str_UsersWords.find('1');
		size_t sz_NumberFind_2 = str_UsersWords.find('2');
		size_t sz_NumberFind_3 = str_UsersWords.find('3');
		size_t sz_NumberFind_4 = str_UsersWords.find('4');
		size_t sz_NumberFind_5 = str_UsersWords.find('5');
		size_t sz_NumberFind_6 = str_UsersWords.find('6');
		size_t sz_NumberFind_7 = str_UsersWords.find('7');
		size_t sz_NumberFind_8 = str_UsersWords.find('8');
		size_t sz_NumberFind_9 = str_UsersWords.find('9');
		if (sz_NumberFind_0 != string::npos || sz_NumberFind_1 != string::npos || sz_NumberFind_2 != string::npos || sz_NumberFind_3 != string::npos || sz_NumberFind_4 != string::npos || sz_NumberFind_5 != string::npos || sz_NumberFind_6 != string::npos || sz_NumberFind_7 != string::npos || sz_NumberFind_8 != string::npos || sz_NumberFind_9 != string::npos) {
			size_t sz_BracketFind_0 = str_UsersWords.find('(');
			size_t sz_BracketFind_1 = str_UsersWords.find(')');
			if (sz_BracketFind_0 != string::npos && sz_BracketFind_1 != string::npos) {
				str_UsersWords = fcStr_BracketInNumber(str_UsersWords);
			}
			str_UsersWords = fcStr_EquationInNumber(str_UsersWords);
			strstr_UsersWords << str_UsersWords;
			strstr_UsersWords >> fl_LastAnswer;
			cout << "Answer: " << fl_LastAnswer << endl;
		}
    }
    return 0;
}
