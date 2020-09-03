#include <iostream>
#include <math.h>

using namespace std;


double my_exp(double arg)
{
    double eps=0.000001;
    int n=1;
    double sum=0;
    double current=1;
    while (fabs(current)>eps)
    {
        sum+=current;
        current*=arg/n;
        n++;
    }
    return sum;
}


double Lagrange(double x0, double x1, double x2,  double x3, double x)
{
    double L0,L1,L2,L3,res0,res1,res2,res3,mainres;

    L0=(x-x1)*(x-x2)*(x-x3)/((x0-x1)*(x0-x2)*(x0-x3));
    L1=(x-x0)*(x-x2)*(x-x3)/((x1-x0)*(x1-x2)*(x1-x3));
    L2=(x-x0)*(x-x1)*(x-x3)/((x2-x0)*(x2-x1)*(x2-x3));
    L3=(x-x0)*(x-x1)*(x-x2)/((x3-x0)*(x3-x1)*(x3-x2));
    res0=my_exp(x0);
    res1=my_exp(x1);
    res2=my_exp(x2);
    res3=my_exp(x3);
    mainres=res0*L0+res1*L1+res2*L2+res3*L3;
    return mainres;
}

double Newton(double x0, double x1, double x2,  double x3, double x)
{
    double P0,P1,P2,P3,res0,res1,res2,res3,mainres,mainres1,derivation,dx,i;
    res0=my_exp(x0);
    res1=my_exp(x1);
    res2=my_exp(x2);
    res3=my_exp(x3);
    dx=0.01;
    P0=res0;
    P1=(res0-res1)/(x0-x1);
    P2=(res1-res2)/(x1-x2);
    P3=(res2-res3)/(x2-x3);
    //mainres=P0+(x-x0)*P1 + (x-x0)*(x-x1)*(P1-P2)/(x0-x2) + (x-x0)*(x-x1)*(x-x2)*((P1-P2)/(x0-x2) - (P2-P3)/(x1-x3))/(x0-x3);
    //mainres1=P0+(x+dx-x0)*P1 + (x+dx-x0)*(x+dx-x1)*(P1-P2)/(x0-x2) + (x+dx-x0)*(x+dx-x1)*(x+dx-x2)*((P1-P2)/(x0-x2) - (P2-P3)/(x1-x3))/(x0-x3);
    //derivation=(mainres1-mainres)/dx;

    for (i=x0; i<=x3; i++){
        mainres=P0+(i-x0)*P1 + (i-x0)*(i-x1)*(P1-P2)/(x0-x2) + (i-x0)*(i-x1)*(i-x2)*((P1-P2)/(x0-x2) - (P2-P3)/(x1-x3))/(x0-x3);
        mainres1=P0+(i+dx-x0)*P1 + (i+dx-x0)*(i+dx-x1)*(P1-P2)/(x0-x2) + (i+dx-x0)*(i+dx-x1)*(i+dx-x2)*((P1-P2)/(x0-x2) - (P2-P3)/(x1-x3))/(x0-x3);
        derivation=(mainres1-mainres)/dx;
        cout<<"point -> "<<i<<endl;
        cout<<"derivation: "<<derivation<<endl;
        cout<<"Diff: "<<derivation-exp(i)<<endl<<endl;

    }
    mainres=P0+(x-x0)*P1 + (x-x0)*(x-x1)*(P1-P2)/(x0-x2) + (x-x0)*(x-x1)*(x-x2)*((P1-P2)/(x0-x2) - (P2-P3)/(x1-x3))/(x0-x3);
    mainres1=P0+(x+dx-x0)*P1 + (x+dx-x0)*(x+dx-x1)*(P1-P2)/(x0-x2) + (x+dx-x0)*(x+dx-x1)*(x+dx-x2)*((P1-P2)/(x0-x2) - (P2-P3)/(x1-x3))/(x0-x3);
    derivation=(mainres1-mainres)/dx;
    cout<<"point -> "<<x<<endl;
    cout<<"derivation: "<<derivation<<endl;
    cout<<"Diff: "<<derivation-exp(-0.5)<<endl<<endl;
    return mainres;
}

/*double deriv(double x0, double x1, double x2,  double x3, double x) {
    double P0,P1,P2,P3,res0,res1,res2,res3, B, B1, res, mainres, a, b, c;
        res0=my_exp(x0);
        res1=my_exp(x1);
        res2=my_exp(x2);
        res3=my_exp(x3);
        P0=res0;
        P1=(res0-res1)/(x0-x1);
        P2=(res1-res2)/(x1-x2);
        P3=(res2-res3)/(x2-x3);
        B = ((P1-P2)/(x0-x2) - (P2-P3)/(x1-x3))/(x0-x3);
        B1 =  (P1-P2)/(x0-x2);
        res=P0+(x-x0)*P1 + (x-x0)*(x-x1)*B1 + (x-x0)*(x-x1)*(x-x2)*B;
        a = 3*x*x;
        b = 2*x;
        c = 1;
        mainres = a*B - b*(B1+(-x0*B-x1*B-x2*B))-c*((-x0*P1-x0*B1-x1*B1)+(x1*x2+x0*x2+x0*x1)*B);
        cout<<"deriv: "<<mainres<<endl;
        return mainres;
}
/*double defer(double x)
    double p1, p2, res;
    p1=(my_exp(0)-my_exp(-1))/2;
    p2=(Lagrange(0)-Lagrange(-1))/2;
    res=p1-p2;
    return res;
*/

int main()
{
    double x0,x1,x2,x3,x;
    //double pi=3.14159265;
    cin>>x0>>x1>>x2>>x3>>x;
    double reslangr=Lagrange(x0,x1,x2,x3,x);
    double resnewton=Newton(x0,x1,x2,x3,x);
    double resexp = my_exp(x);

    cout<<endl<<"Lagrange: "<<reslangr<<endl<< "Newton: " <<resnewton<<endl<<"EXP: " <<resexp<<endl;;
    return 0;
}
