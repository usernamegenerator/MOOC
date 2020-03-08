#include <iostream>

using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		(n>=0&&(n%5==0))?(cout<<n/5 << endl):(cout<<-1<<endl);
	}
	return 0;
}