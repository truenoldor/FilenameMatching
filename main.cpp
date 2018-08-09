// Filename matching.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>

bool testName(const char * name);
void fixBackSlash(char * path);
bool isHard(char * temp);
bool testElement(char * text, char * templ);

enum ResultType
{
	eGoodResult = 0,			// template == filename
	eBadResult = 1,				// template != filename
	eInvalidParameters = 2			// error in params
};

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "invalid parameters";
        return eInvalidParameters;			 // invalid size of arguments
    }

	char * name= argv[1];
	char * templ = argv[2];

	fixBackSlash(name);
	fixBackSlash(templ);

    if (!testName(name))
    {
        std::cout << "Invalid parameters";
        return eInvalidParameters;			 // unresolved character
    }

    if (!testElement(name, templ))
    {
        std::cout << "File name does not match pattern";
        return eBadResult;				 // template != filename
    }

    std::cout << "The file name matches the pattern";
	return eGoodResult;
}

bool testElement(char * text, char * templ)
{
	bool result = false;

	switch (*templ)
	{
	case '?':
		result = (*text) && (*text) != '/' && testElement(text + 1, templ + 1);
		break;

	case '*':

		if (isHard(templ + 1))
		{
			if (((*text) && (*text) == '/'))
			{
				result = false;
				break;
			}
			result = testElement(text, templ + 1) || *text && testElement(text + 1, templ);
		}
		else
			result = testElement(text, templ + 2) || *text && testElement(text + 1, templ);
		break;

	case '\0':
		result = !(*text);
		break;

	default:
		result = (templ[0] == text[0] && testElement(text + 1, templ + 1));
	}

	return result;
}

bool isHard(char * temp)
{
	return !(*temp) || *temp != '*';
}

bool testName(const char * name)
{
	const char * symbols = "*? ";
	while (*symbols != '\0')
	{
		if (strchr(name, symbols[0]))
			return false;

		++symbols;
	}

	return true;
}

void fixBackSlash(char * path)
{
	while (*path != '\0')
	{
		if (*path == '\\')
			*path = '/';

		++path;
	}
}


