#include <iostream>
#include "math.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double h;
    int i;
    double a[5],b[5],c[5],d[5],y[5],xi[5];
    a[0]=b[0]=c[0]=d[0]=c[4]=0;
    for (i=0;i<5;i++)
    {
        cin>>y[i];
    }
    for (i=0;i<5;i++)
    {
        xi[i]=i*0.9;
        cout<<" "<<xi[i]<<endl;;
    }
    cout <<"\nEnter to h ->";
    cin>>h;
    double k1,k2,k3;
    k1=3*(y[4]-2*y[3]+y[2])/(h*h);
    k2=3*(y[3]-2*y[2]+y[1])/(h*h);
    k3=3*(y[2]-2*y[1]+y[0])/(h*h);
    c[3]=(15*k1-4*k2+k3)/56;
    c[2]=k1-4*c[3];
    c[1]=15*c[3]-4*k1+k2;
    for (i=1;i<5;i++)
    {
        a[i]=y[i];
        d[i]=(c[i]-c[i-1])/(3*h);
        b[i]=(a[i]-a[i-1])/h + (2*c[i] + c[i-1])*h/3;
    }
    double x;
    double res=0;
    cin>>x;
    int m=1;
    if (x<=0.9 && x>=0)
    {
        res=a[m] + b[m]*(x-xi[m]) + c[m]*(x-xi[m])*(x-xi[m]) + d[m]*(x-xi[m])*(x-xi[m])*(x-xi[m]);
    }
    m+=1;
    if (x<=1.8 && x>=0.9)
    {
        res=a[m] + b[m]*(x-xi[m]) + c[m]*(x-xi[m])*(x-xi[m]) + d[m]*(x-xi[m])*(x-xi[m])*(x-xi[m]);
    }
    m+=1;
    if (x<=2.7 && x>=1.8)
    {
        res=a[m] + b[m]*(x-xi[m]) + c[m]*(x-xi[m])*(x-xi[m]) + d[m]*(x-xi[m])*(x-xi[m])*(x-xi[m]);
    }
    m+=1;
    if (x<=3.6 && x>=2.7)
    {
        res=a[m] + b[m]*(x-xi[m]) + c[m]*(x-xi[m])*(x-xi[m]) + d[m]*(x-xi[m])*(x-xi[m])*(x-xi[m]);
    }
    if (x==1.8)
    {
	double derivation1= b[2] + 2*c[2]*(x-xi[2]) + 3*d[2]*(x-xi[2])*(x-xi[2]);
	double derivation2= b[3] + 2*c[3]*(x-xi[3]) + 3*d[3]*(x-xi[3])*(x-xi[3]);
	cout<<"\nder DOP ZAD: \nDER1 -> "<<derivation1<<endl<< "DER2 - > "<<derivation2<<endl;
    }
    if (x==2.7){
	double derivation3= b[4] + 2*c[4]*(x-xi[4]) + 3*d[4]*(x-xi[4])*(x-xi[4]);
	double derivation4= b[3] + 2*c[3]*(x-xi[3]) + 3*d[3]*(x-xi[3])*(x-xi[3]);
	cout<<"\nder DOP ZAD: \nDER3 -> "<<derivation3<<endl<< "DER4 - > "<<derivation4<<endl;
	}


//Считаешь обе производные в точке 1.8 Они должны быть равны

    cout<<res<<endl;

    for(int i=1;i<=4;i++){
    cout<<"\nСтепень при 0 : "<<a[i]<<endl;
    cout<<"Степень при 1 : "<<b[i]<<endl;
    cout<<"Степень при 2 : "<<c[i]<<endl;
    cout<<"Степень при 3 : "<<d[i]<<endl;
    }
    return 0;
}
