#include <iostream>
#include <math.h>

using namespace std;

double my_exp(double x)
{
    double current=1;
    double sum=1;
    int n=1;
    int i=0;
    double eps=0.000001;
    while (fabs(current)>eps)
    {
        current*=x/n;
        n+=1;
        i++;
        sum+=current;
    }
    cout<< "countEXP: " << i<< endl;
    return sum;
}

double my_log(double x)
{
    double current=x;
    double sum=x;
    int n=1;
    int i=0;
    double eps=0.000001;
    while (fabs(current)>eps)
    {
        current*=(-1)*x*n/(n+1);
        n+=1;
        i++;
        sum+=current;
    }
    cout<< "countLOG: " << i<<endl;
    return sum;

}

void micos(const double x, double *my_cos, int*val_cos)
{
    double current=1;
    int n=1;
    int i=0;
    double eps=0.000001;
    while (fabs(current)>eps)
    {
        current*=(-1)*x*x/(n*(n+1));
        n+=2;
        i+=1;
        (*my_cos)+=current;
    }
    (*val_cos) = i;
}

int main()
{
    double x;
    double ln10 = 2.3025851;
    cout << "Enter to x -> " ;


    cin>>x;
    int valcos;
    double mycos = 1;
    micos(x, &mycos, &valcos);

    double resexp = my_exp(x);
    double reslog;

    if (x<=0){
    cout <<"\nValue ->LOG<- less than ZeR0"<<endl;
    }
    else
    {
        x=x-1;
        int m=0;
        double x1=1+x;
        while ((x1)>=1)
        {
            x1=x1/10;
            m+=1;
        }
        x1=x1-1;
        reslog = (my_log(x1)+m*ln10)/ln10;

        cout<< "LOG: " <<reslog;
    }
    cout<<fixed;
    cout.precision(6);
    cout<<"\nCOS: "<<mycos<<endl<<"\nCountCOS: "<<valcos<<endl<< "EXP: " <<resexp<<endl;
    return 0;
}
