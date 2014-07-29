// RailFence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <memory>
#include "RailFenceCipher.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    int rails;
    string message;
    cout << "Enter number of rails" << endl;
    cin >> rails;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter message" << endl;
    std::getline(cin, message);
    RailFenceCipher cipher;
    cipher.SetPlainText(message);
    cipher.SetNumRails(rails);
    string cipherText = cipher.GetCipherText();
    cout << cipherText << endl;
	return 0;
}

