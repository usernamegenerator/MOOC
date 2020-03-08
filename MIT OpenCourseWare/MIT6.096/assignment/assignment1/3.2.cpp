#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc,char** argv)
{
	int n = atoi(argv[1]);
	int array[n];
	int i = 0;
	int num = n;
	while(num>0)
	{
		array[i] = atoi(argv[i+2]);
		i++;
		num--;
	}
	int sum = 0;
	for(i=0;i<n;i++)
	{
		//cout << array[i] << " ";
		sum += array[i];
	}
	int min = array[0];
	int max = array[0];
	for(i=1;i<n;i++)
	{
		if(array[i] < min)
			min = array[i];
		if(array[i] > max)
			max = array[i];
	}

	double mean = sum/n;

	cout << "Mean: " << mean << endl;
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	cout << "Min: " << max - min << endl;

	return 0;
}