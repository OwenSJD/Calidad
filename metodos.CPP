
#include<stdio.h>
using namespace std;
double cor[10000];
doble f (doble x, doble y) // función de reescritura
{
    return x+y;
}
 double correctf (double x) // función de solución exacta
{
    return -x-1+2*exp(x);
}
 nulo Euler (doble h, doble l, doble r, doble * a, doble * b, doble tol) // Método de Euler
{
    double sum=0;
    for(int i=1; i<=tol; i++)
    {
        b[i]=b[i-1]+h*f(a[i-1],b[i-1]);
        sum+=fabs(b[i]-cor[i])/cor[i];
    }
    for(int i=1; i<=tol; i++)
                 printf ("Cuando x =% lf, la solución aproximada es:% lf, la solución exacta es:% lf \ n", a [i], b [i], cor [i]);
         printf ("Precisión:% lf \ n \ n", sum / tol);
}
 vacío mejoradoEuler (doble h, doble l, doble r, doble * a, doble * b, doble tol) // Método Euler mejorado
{
    double b1,sum=0;
    for(int i=1; i<=tol; i++)
    {
        b1=b[i-1]+h*f(a[i-1],b[i-1]);
        b[i]=b[i-1]+h/2*(f(a[i-1],b[i-1])+f(a[i],b1));
    }
    for(int i=1; i<=tol; i++)
                 printf ("Cuando x =% lf, la solución aproximada es:% lf, la solución exacta es:% lf \ n", a [i], b [i], cor [i]);
         printf ("Precisión:% lf \ n \ n", sum / tol);
}
 vacío RungeKutta (doble h, doble l, doble r, doble * a, doble * b, doble tol) // RungeKutta de cuarto orden
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
                 printf ("Cuando x =% lf, la solución aproximada es:% lf, la solución exacta es:% lf \ n", a [i], b [i], cor [i]);
         printf ("Precisión:% lf \ n \ n", sum / tol);
}
int main()
{
    double h,a[10000],b[10000],l,r;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(cor,0,sizeof(cor));
         printf ("Ingrese el tamaño del paso:");
    scanf("%lf",&h);
         printf ("Ingrese el límite inferior del intervalo:");
    scanf("%lf",&l);
         printf ("Ingrese el límite superior del intervalo:");
    scanf("%lf",&r);
         printf ("Por favor asigne un valor inicial:");
    scanf("%lf",&b[0]);
    double tol=(r-l)/h;
    for(int i=0; i<=tol; i++)
        a[i]=l+i*h;
    for(int i=1; i<=tol; i++)
        cor[i]=correctf(a[i]);
         printf ("El siguiente es el resultado de la solución de Euler: \ n");
    Euler(h,l,r,a,b,tol);
         printf ("El siguiente es el resultado del método Euler mejorado: \ n");
    improvedEuler(h,l,r,a,b,tol);
         printf ("Resultados del método Runge-Kutta de cuarto orden: \ n");
    RungeKutta(h,l,r,a,b,tol);
    return 0;
}
