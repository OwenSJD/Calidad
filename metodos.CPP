
#include<stdio.h>
using namespace std;
double cor[10000];
doble f (doble x, doble y) // funci�n de reescritura
{
    return x+y;
}
 double correctf (double x) // funci�n de soluci�n exacta
{
    return -x-1+2*exp(x);
}
 nulo Euler (doble h, doble l, doble r, doble * a, doble * b, doble tol) // M�todo de Euler
{
    double sum=0;
    for(int i=1; i<=tol; i++)
    {
        b[i]=b[i-1]+h*f(a[i-1],b[i-1]);
        sum+=fabs(b[i]-cor[i])/cor[i];
    }
    for(int i=1; i<=tol; i++)
                 printf ("Cuando x =% lf, la soluci�n aproximada es:% lf, la soluci�n exacta es:% lf \ n", a [i], b [i], cor [i]);
         printf ("Precisi�n:% lf \ n \ n", sum / tol);
}
 vac�o mejoradoEuler (doble h, doble l, doble r, doble * a, doble * b, doble tol) // M�todo Euler mejorado
{
    double b1,sum=0;
    for(int i=1; i<=tol; i++)
    {
        b1=b[i-1]+h*f(a[i-1],b[i-1]);
        b[i]=b[i-1]+h/2*(f(a[i-1],b[i-1])+f(a[i],b1));
    }
    for(int i=1; i<=tol; i++)
                 printf ("Cuando x =% lf, la soluci�n aproximada es:% lf, la soluci�n exacta es:% lf \ n", a [i], b [i], cor [i]);
         printf ("Precisi�n:% lf \ n \ n", sum / tol);
}
 vac�o RungeKutta (doble h, doble l, doble r, doble * a, doble * b, doble tol) // RungeKutta de cuarto orden
{
    double k1,k2,k3,k4,sum=0;
    for(int i=1; i<=tol; i++)
    {
        k1=f(a[i-1],b[i-1]);
        k2=f(a[i-1]+h/2,b[i-1]+h/2*k1);
        k3=f(a[i-1]+h/2,b[i-1]+h/2*k2);
        k4=f(a[i-1]+h,b[i-1]+h*k3);
        b[i]=b[i-1]+h/6*(k1+2*k2+2*k3+k4);
    }
    for(int i=1; i<=tol; i++)
                 printf ("Cuando x =% lf, la soluci�n aproximada es:% lf, la soluci�n exacta es:% lf \ n", a [i], b [i], cor [i]);
         printf ("Precisi�n:% lf \ n \ n", sum / tol);
}
int main()
{
    double h,a[10000],b[10000],l,r;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(cor,0,sizeof(cor));
         printf ("Ingrese el tama�o del paso:");
    scanf("%lf",&h);
         printf ("Ingrese el l�mite inferior del intervalo:");
    scanf("%lf",&l);
         printf ("Ingrese el l�mite superior del intervalo:");
    scanf("%lf",&r);
         printf ("Por favor asigne un valor inicial:");
    scanf("%lf",&b[0]);
    double tol=(r-l)/h;
    for(int i=0; i<=tol; i++)
        a[i]=l+i*h;
    for(int i=1; i<=tol; i++)
        cor[i]=correctf(a[i]);
         printf ("El siguiente es el resultado de la soluci�n de Euler: \ n");
    Euler(h,l,r,a,b,tol);
         printf ("El siguiente es el resultado del m�todo Euler mejorado: \ n");
    improvedEuler(h,l,r,a,b,tol);
         printf ("Resultados del m�todo Runge-Kutta de cuarto orden: \ n");
    RungeKutta(h,l,r,a,b,tol);
    return 0;
}
