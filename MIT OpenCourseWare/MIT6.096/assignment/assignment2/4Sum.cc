#include <iostream>

using namespace std;


//4.1
int sum(const int a, const int b)
{
    return a+b;
}

double sum(const double a, const double b)
{
    return a+b;
}
//4.1 end


//4.3
/*
int sum(const int a, const int b, const int c)
{
    return a+b+c;
}


int sum(const int a, const int b, const int c, const int d)
{
    return a+b+c+d;
}
*/
//4.3 end


//4.4
int sum(const int a, const int b, const int c, const int d = 0)
{
    return a+b+c+d;
}

//4.4 end


//4.5
/*
int sum(const int numofnum, const int* numArray)
{
    int sum = 0;
    for(int i = 0 ; i < numofnum; i++)
    {
        sum += numArray[i];
    }
    return sum;
}
*/
//4.5 end



//4.6
int sumvalue = 0;
int sum(const int numofnum, const int* numArray)
{
    /*
    //solution #1
    if(numofnum == 0){
        return 0;
    }
    else{
        return numArray[0] + sum(numofnum-1,numArray+1);
    }
    */
    //solution #2
    if(numofnum == 1){
        sumvalue = numArray[0];
        return sumvalue;
    }
    else{
        return numArray[0] + sum(numofnum-1,numArray+1);
    }

}
//4.6 end


int main()
{
    //4.2
    //call of overloaded 'sum(int, double)' is ambiguous|
    //cout << sum(1,10.0) << endl;
    //4.2 end


    //4.4
    //cout << sum(3,5,7) << endl;
    //4.4 end

    //4.5 test
    //int numArray[] = {3,5,7};
    //cout << sum(3,numArray) << endl;
    //4.5 test end

    //4.6 test
    int numArray[] = {3,5,7};
    cout << sum(3,numArray) << endl;
    //4.6 test
}
