#include "errors.h"

errors::errors(const char* message)
{
	this->message = _strdup(message);
}

errors::errors(const errors& e)
{
	this->message = _strdup(e.message);
}

errors::~errors()
{
	free(message);
}

const char* errors::get_message() { return message; }

void errors::print() { std::cout << message; }