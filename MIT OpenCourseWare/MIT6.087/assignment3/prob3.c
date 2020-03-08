//(a)

int factorial(int n){
    int i=2;
    int ret=1;
    while(i<=n)
    {
        ret*=i;
        i=i+1;
    }
    return ret;
}

//(b)
int sample_geometric_rv(double p)
{
    double q;
    int n = 0;
    q = rand_double();
    n++;

    while(q>=p)
    {
        q = rand_double();
        n++;
    }
}
