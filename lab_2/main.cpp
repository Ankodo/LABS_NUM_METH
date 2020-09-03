#include <iostream>

using namespace std;


/*double ddr(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double right_der=((y3-y2)/(x3-x2)-(y2-y1)/(x2-x1))/(x3-x2);
    cout<< "right_der: " << right_der<<endl;
    return right_der;

}*/

double TDR(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double a[10]={x0,y0,x1,y1,x2,y2,x3,y3,x4,y4};
    int p;
    for (int i=0; i<8; i+=2){
    double right_der=(a[i+3]-a[i+1])/(a[i+2]-a[i]);
    p=i/2;
    cout<<"point "<<p<<" -> Derivation right: "<< right_der<< endl;
    }

    return 0;
}

double RightSecDer (double x1, double y1, double x2, double y2, double x3, double y3,double x4,double y4)
{
    double sec_der=((y4-y3)/(x4-x3) - (y3-y2)/(x3-x2))/((x3-x2));
    return sec_der;
}

double central_derivation(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double central_der=((y3-y2)/(x3-x2) + (y2-y1)/(x2-x1))/2;
    return central_der;
}
double SecDer (double x1, double y1, double x2, double y2, double x3, double y3)
{
    double sec_der=((y3-y2)/(x3-x2) - (y2-y1)/(x2-x1))/((x2-x1));
    return sec_der;
}

double left_derivation(double x1, double y1, double x2, double y2)
{
    double left_der=(y2-y1)/(x2-x1);
    return left_der;
}

double right_derivation(double x2, double y2, double x3, double y3)
{
    double right_der=(y3-y2)/(x3-x2);
    return right_der;

}

int main()
{
    double x0,x1,x2,y0,y1,y2,x3,y3,x4,y4;
    //x0 = 0.1; y0 = 1.1052; x1 = 0.2; y1 = 1.2214; x2=0.3; y2 = 1.3499;
    x0 = 0.0; y0=1.0; x1=0.1; y1=1.1052; x2=0.2; y2=1.2214; x3=0.3; y3=1.3499; x4=0.4; y4=1.4918;
    //cin>>x0>>y0>>x1>>y1>>x2>>y2;
    double res1=left_derivation(x1,y1,x2,y2);
    double res2=right_derivation(x2,y2,x3,y3);
    double rsd=RightSecDer(x1,y1,x2,y2,x3,y3,x4,y4);
    double res3=central_derivation(x1,y1,x2,y2,x3,y3);
    double tdr=TDR(x0,y0,x1,y1,x2,y2,x3,y3,x4,y4);
    cout<<"\nleftDer: "<<res1<<endl<<"rightDer: "<<res2<<endl<<"\ncentralDer: "<<res3<<endl;
    cout<<"Central second derivation: "<< SecDer(x1,y1,x2,y2,x3,y3)<<endl;
    cout<<"Right second derivation: in point 2 -> "<< rsd<<endl;
    return 0;
}
