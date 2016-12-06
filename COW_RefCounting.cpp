#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Mystr
{
public:

	Mystr()          // Default Constructor of class Mystr
	{
		length = 0;
		string = NULL;
		refcount = 1; //initialiizng reference Count to 1 for first pointer
	}

    Mystr(const Mystr& str)      // Parameterized Constructor
	{
		length = str.length;
		string = new char[length];
		refcount += 1; //increments reference count by 1

		strcpy(string, str.string);
	}


	Mystr(const char* str)        // Parameterized Constructor
	{
		length = strlen(str);
		string = new char[length];
		refcount = 1;

		strcpy(string, str);
	}

	//Constructor to create a Copy

	void reserve(int charL)        // Function for reserving integer
	{
		char* temp = new char[length];
		strcpy(temp, string);

		string = new char[length + charL];
		strcpy(string, temp);
		length += charL;
	}


	void print(char* str)        // Function for Printing
	{
		for (int i = 0; i < strlen(str); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}

	void print()                 // Function for Printing
	{
		for (int i = 0; i < length; i++)
		{
			cout << string[i];
		}
		cout << endl;
	}



	void append(char newC)         // Function for Printing
	{
		reserve(1);
		string[length - 1] = newC;
		string[length] = '\0';
	}

	char charAt(int index) const     // Character at specific index
	{
		return string[index];
	}

	~Mystr()                        // Destructor
	{
		refcount -= 1; // decrementing refcount by -1
		// Checks if refcount = 0 then deletes the pointer
		if (refcount == 0)
		{
			if (string != NULL)
			{
				cout << "Mystr class Destructed!" << endl;
				delete[] string;
				string = NULL;
			}
		}
	}

private:

	int length;
	static int refcount;
	char* string;
};

int Mystr:: refcount = 0;

int main(int argc, char *argv[])
{
	Mystr string("This is my String."); //Original String
	Mystr string2(string);	//Copy of String
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

