// TestOne.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include <fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout<<"Hello, world!"<<std::showpoint;
	printf("Hello, world!\n");

	std::ofstream file("file.txt");
    file << "Hello, world!" << std::endl;

	return 0;
}

	