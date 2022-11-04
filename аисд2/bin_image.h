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
#include "error.h"
/*����� �������� ����������� ������������� �������.
��� �������, ������������:
� ����������� � �����������: ������� �����������;
� �������� () ��� ������/������ �������� �� ��������� ��������;
� ��������� ��������� * (������������ �Ȼ) � �������� + (������������ ���Ȼ) �����������;
� ��������� ��������� * (������������ �Ȼ) � �������� + (������������ ���Ȼ) ����������� � ���������� ��������� bool (���������� ���������������);
� �������� ! ��� �������������� �������� �����������;
� ���������� ������������ ���������� �����������;
� ������������� �������� ������ ������ �������� ����������� �������, ��������, ��� ����������� false ������������ ������ ����� . ��� �������  , ��� true � �����-������ ������ (��������, 1):
....|.....
.111|111..
.111|111..
....|.....

������:
��������� ���� � ������������ ������ x,y � �������� r.
*/
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
	bool** data;
	int length, width;
public:
	int get_length() const;
	int get_width() const;
	bin_image(int length = 10, int width = 10);
	bool& operator ()(int str_index, int col_index) const;
	bin_image& operator !();
	double fill_factor() const;
	~bin_image();
	bin_image(const bin_image& a);
};
