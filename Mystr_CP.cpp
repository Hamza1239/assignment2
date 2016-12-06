#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class Mystr
{
public:

	Mystr()           // Default Constructor of class Mystr
	{
		length = 0;
		string = NULL;
	}

	//Contructor to create a Copy
	Mystr(const Mystr& str)         // Parameterized Constructor
	{
		length = str.length;
		string = new char[length];
		//strcpy_s(string, length, str.string);
		strcpy(string, str.string);
	}


    Mystr(const char* str)           // Parameterized Constructor
	{
		length = strlen(str);
		string = new char[length];
		//strcpy_s(string, length, str);
		strcpy(string, str);
	}

	void print(char* str)               // Function for Printing
	{		for (int i = 0; i < strlen(str); i++)

		{
			cout << str[i];
		}
		cout << endl;
	}

    char charAt(int index) const
	{
		return string[index];
	}


	void newChar(int charLength)
	{
		char* temp = new char[length];
		//strcpy_s(temp, length,string);
		strcpy(temp, string);


		string = new char[length + charLength];
		//strcpy_s(string, length+charLength, temp);
		strcpy(string, temp);
		length += charLength;
	}

	void append(char addChar)
	{
		newChar(1);
		string[length - 1] = addChar;
		string[length] = '\0';
	}


	void print()
	{
		for (int i = 0; i < length; i++)
		{
			cout << string[i];
		}
		cout << endl;
	}

	~Mystr()
	{
		if (string != NULL)
		{
			cout << "Mystr class Destrcuted!" << endl;
			delete[] string;
			string = NULL;

		}
	}

private:

	int length;
	char* string;
};


int main()
{
	Mystr string("This is my String");
	Mystr string2(string);
	cout << "Following is the Original String:- " << endl;;
	string.print();
	cout << "Following is the copy of the String:-" << endl;
	string2.append('a');
	string2.print();
	cout << "Char at 3 index: " << string2.charAt(3) << endl;
	cout << "Char at 5 index: " << string2.charAt(5) << endl;
    cout << "Char at 8 index: " << string2.charAt(8) << endl;
	return 0;
}
