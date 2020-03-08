#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char**argv)
{
	int n = atoi(argv[1]);
	int numOfPrimes = 0;
	for(int i=2;i;i++)
	{
		bool prime=true;
		for(int j=2;j<i-1;j++)
		{
			if(i%j==0)
			{
				prime=false;
				break;
			}
		}
		if(prime)
		{
			numOfPrimes++;
			cout << i << endl;
		}
		if(numOfPrimes==n)
		{
			break;
		}
	}

	return 0;
}