#include "bin_image.h"

template<typename type>
int bin_image<type>::get_length() const
{
	return length;
}

template<typename type>
int bin_image<type>::get_width() const
{
	return width;
}

template<typename type>
bin_image<type>::bin_image(int length, int width) : length(length), width(width)
{
	if (length < 1 || width < 1) { throw error("Incorrect length and width calculations"); }
	data = new bool* [length];
	for (int i = 0; i < length; i++) {
		data[i] = new bool[width];
	}
}

template<typename type>
type& bin_image<type>::operator ()(int str_index, int col_index) const {
	if (str_index < 0 || str_index >= length) { throw error("Invalid str_index"); }
	if (col_index < 0 || col_index >= width) { throw error("Invalid col_index"); }
	bool& a = data[str_index][col_index];
	return a;
}

template<typename type>
bin_image<type> operator+(const bin_image<type>& image_1, const bin_image<type>& image_2)//сложение изображений bool
{
	if (image_1.length != image_2.length || image_1.width != image_2.width) { throw error("Addition error"); }
	bin_image<type> image(image_1.length, image_1.width);
	for (int i = 0; i < image_1.length; i++) {
		for (int j = 0; j < image_1.width; j++) {
			image.data[i][j] = (image_1.data[i][j] || image_2.data[i][j]);
		}
	}
	return image;
}

template<typename type>
bin_image<type> operator*(const bin_image<type>& image_1, const bin_image<type>& image_2)//умножение изображений bool
{
	if (image_1.length != image_2.length || image_1.width != image_2.width) { throw error("Multiplication error"); }
	bin_image<type> image(image_1.length, image_1.width);
	for (int i = 0; i < image_1.length; i++) {
		for (int j = 0; j < image_1.width; j++) {
			image.data[i][j] = (image_1.data[i][j] && image_2.data[i][j]);
		}
	}
	return image;
}

template<typename type>
bin_image<type> operator*(const bin_image<type>& image, bool a)
{
	bin_image<type> tmp(image.length, image.width);
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			tmp.data[i][j] = (image.data[i][j] && a);
		}
	}
	return tmp;
}

template<typename type>
bin_image<type> operator+(const bin_image<type>& image, bool a)
{
	bin_image<type> tmp(image.length, image.width);
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			tmp.data[i][j] = (image.data[i][j] || a);
		}
	}
	return tmp;
}

template<typename type>
bin_image<type> operator*(bool a, const bin_image<type>& image)
{
	bin_image<type> tmp(image.length, image.width);
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			tmp.data[i][j] = (image.data[i][j] && a);
		}
	}
	return tmp;
}

template<typename type>
bin_image<type> operator+(bool a, const bin_image<type>& image)
{
	bin_image<type> tmp(image.length, image.width);
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			tmp.data[i][j] = (image.data[i][j] || a);
		}
	}
	return tmp;
}

template<typename type>
bin_image<type>& bin_image<type>:: operator !() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (data[i][j] == 0) {
				data[i][j] = 1;
			}
			else {
				data[i][j] = 0;
			}
		}
	}
	return *this;
}

template<typename type>
double bin_image<type>::fill_factor() const {
	double count_0 = 0;
	double count_1 = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (data[i][j] == false) { count_0 += 1; }
			if (data[i][j] == true) { count_1 += 1; }
		}
	}
	return (double)(count_1) / (count_0 + count_1);
}

template<typename type>
bin_image<type>::~bin_image() {
	for (int i = 0; i < length; i++) {
		delete[]data[i];
	}
	delete[]data;
	length = 0;
	width = 0;
}

template<typename type>
bin_image<type>::bin_image(const bin_image& a) {
	length = a.length;
	width = a.width;
	data = new bool* [length];
	for (int i = 0; i < length; i++) {
		data[i] = new bool[width];
		for (int j = 0; j < width; j++) {
			data[i][j] = a.data[i][j];
		}
	}
}

template<typename type>
std::ostream& operator <<(std::ostream& s, const bin_image<type>& image)
{
	for (int i = 0; i < image.length; i++) {
		for (int j = 0; j < image.width; j++) {
			if (image.data[i][j] == false) { s << " ."; }
			if (image.data[i][j] == true) { s << " 1"; }
		}
		s << "\n";
	}
	return s;
}

