// C++ String Handing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

typedef std::string String;

int _tmain(int argc, _TCHAR* argv[])
{
	// Literals (double-quoted text) denote C strings, but std::string
    // instances can be initialized from such literals.
    String foo = "fighters";
    String bar = "stool";

    // The operator != compares string contents for inequality. This is different
    // from != on char pointers to C strings, where != would compare the memory
    // addresses of the strings rather than their contents.
    if (foo != bar) {
		 std::cout << "The strings are different." << std::endl;
    }

    // Prints "stool fighters". The + operator denotes string concatenation.
    std::cout << (bar + " " + foo) << std::endl;

    return 0;
}

