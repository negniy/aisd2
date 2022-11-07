#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include "errors.h"
/*
Сделать тип пикселя шаблонным параметром.Обеспечить работоспособность шаблонного класса как минимум со следующими типами :
bool;
char;
short;
float.
*/

template<typename type>
class bin_image
{
	friend std::ostream& operator <<(std::ostream& s, const bin_image& image);
	friend bin_image operator *(const bin_image& image_1, const bin_image& image_2);
	friend bin_image operator +(const bin_image& image_1, const bin_image& image_2);
	friend bin_image operator *(const bin_image& image, bool a);
	friend bin_image operator +(const bin_image& image, bool a);
	friend bin_image operator *(bool a, const bin_image& image);
	friend bin_image operator +(bool a, const bin_image& image);
private:
	type** data;
	int length, width;
public:
	int get_length() const;
	int get_width() const;
	bin_image(int length = 10, int width = 10);
	type& operator ()(int str_index, int col_index) const;
	bin_image& operator !();
	double fill_factor() const;
	~bin_image();
	bin_image(const bin_image& a);
};
template class bin_image<short>;
template class bin_image<float>;
template class bin_image<bool>;
template class bin_image<char>;
