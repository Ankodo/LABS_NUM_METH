#include <iostream>
#include "math.h"

using namespace std;

int main()
{
    double x[6], y[6];
    int i;
    for (i=0; i<6; i++)
    {
        cin>>x[i]>>y[i];
    }
    double k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10;
    k0=k1=k2=k3=k4=k5=k6=k7=k8=k9=k10=0;
    k0=6;
    for (i=0; i<6; i++)
    {
        k1+=x[i];
        k2+=pow(x[i],2);
        k3+=pow(x[i],3);
        k4+=pow(x[i],4);
        k5+=pow(x[i],5);
        k6+=pow(x[i],6);
        k7+=y[i];
        k8+=x[i]*y[i];
        k9+=pow(x[i],2)*y[i];
        k10+=pow(x[i],3)*y[i];
    }
    double a,b,c,d;
    a=(k0*k8-k1*k7)/(k2*k0-k1*k1);
    b=(k7-k1*a)/k0;
    cout<<"linear_polinom = "<<a<<"*x + "<<b<<endl;
    double sum1=0;
    for (i=0;i<6;i++)
    {
        sum1+=pow(y[i]-(a*x[i]+b),2);
    }
    a=b=0;
    a=((k2*k9-k8*k3)*(k1*k2-k0*k3)-(k9*k1-k7*k3)*(k2*k2-k1*k3))/((k4*k2-k3*k3)*(k1*k2-k0*k3)-(k1*k4-k2*k3)*(k2*k2-k1*k3));
    c=(a*(k3*k3-k4*k2)+k2*k9-k8*k3)/(k2*k2-k1*k3);
    b=(k7-k0*c-k2*a)/k1;
    cout<<"quadratic_polinom = "<<a<<"*x^2 + "<<b<<"*x + "<<c<<endl;
    double sum2=0;
    for (i=0;i<6;i++)
    {
        sum2+=pow(y[i]-(a*x[i]*x[i]+b*x[i]+c),2);
    }
    a=b=c=0;
    double res1,res2,res3,res4,res5,res6;
    res1=(k6*k2-k5*k3)*(k2*k0-k1*k1)-(k4*k0-k3*k1)*(k4*k2-k3*k3);
    res2=(k5*k2-k4*k3)*(k2*k0-k1*k1)-(k3*k0-k2*k1)*(k4*k2-k3*k3);
    res3=(k10*k2-k9*k3)*(k2*k0-k1*k1)-(k8*k0-k7*k1)*(k4*k2-k3*k3);
    res4=(k5*k0-k3*k2)*(k4*k1-k2*k3)-(k6*k1-k4*k3)*(k3*k0-k1*k2);
    res5=(k4*k0-k2*k2)*(k4*k1-k2*k3)-(k5*k1-k3*k3)*(k3*k0-k1*k2);
    res6=(k9*k0-k7*k2)*(k4*k1-k2*k3)-(k10*k1-k8*k3)*(k3*k0-k1*k2);
    a=(res3*res5-res6*res2)/(res1*res5-res2*res4);
    b=(res6-a*res4)/res5;
    c=((k9*k0-k7*k2)-a*(k5*k0-k3*k2)-b*(k4*k0-k2*k2))/(k3*k0-k1*k2);
    d=(k10-k4*c-k5*b-k6*a)/k3;
    cout<<"cubic_polinom = "<<a<<"*x^3 + "<<b<<"*x^2 + "<<c<<"*x + "<<d<<endl;
    double sum3=0;
    for (i=0;i<6;i++)
    {
        sum3+=pow(y[i]-(a*x[i]*x[i]*x[i]+b*x[i]*x[i]+c*x[i]+d),2);
    }
    cout<<sum1<<endl<<sum2<<endl<<sum3<<endl;
    return 0;
}
