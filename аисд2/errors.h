#pragma once
class errors
{
};

#include "bin_image.h"
#include "stdio.h"
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>

class errors
{
private:
	char* message;
public:
	errors(const char* message);
	errors(const errors& e);
	~errors();
	const char* get_message();
	void print();
};

