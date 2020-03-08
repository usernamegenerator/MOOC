#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

double simulatePi(int n){

    double pi;
    double a;
    srand(time(NULL));
    //5.2
    int dartsIn = 0;
    for(int i =0;i<n;i++){
        //5.1

        double x = rand() / (double)RAND_MAX;
        double y = rand() / (double)RAND_MAX;

        if(sqrt(x*x+y*y)<1){
            dartsIn++;
        }
    }
    cout << dartsIn << endl;
    a = 4.0*dartsIn/(double)n;
    pi = a/1; //a/r^2;

    return pi;
}


int main()
{

    cout << simulatePi(500000) << endl;


}
