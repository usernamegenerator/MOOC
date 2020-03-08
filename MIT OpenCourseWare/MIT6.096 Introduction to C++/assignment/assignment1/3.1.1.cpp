#include <iostream>

using namespace std;

int main()
{
	int arg1;
	arg1 = -1;
	int x,y,z;
	char myDouble = '5';
	char arg1 = 'A';
	cout << arg1 << "\n";
	return 0;
}

/*
3.1.cpp: In function ‘int main()’:
3.1.cpp:11:7: error: conflicting declaration ‘char arg1’
  char arg1 = 'A';
       ^
3.1.cpp:7:6: note: previous declaration as ‘int arg1’
  int arg1;
*/