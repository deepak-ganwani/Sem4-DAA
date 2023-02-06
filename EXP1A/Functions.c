#include<stdio.h>
#include<math.h>

double function1(int);
double function2(int);
double function3(int);
double function4(int);
double function5(int);
double function6(int);
double function7(int);
double function8(int);
double function9(int);
double function10(int);

int main(){
    printf("\tn\t2^n\tn^3\tlog(n)\tln(n)\tlog(log(n))\t2^log(n)\t2^2^n\tnlogn\te^n\n");
    for (int i = 0; i < 101; i++)
    {
        double a1=function1(i);
        double a2=function2(i);
        double a3=function3(i);
        double a4=function4(i);
        double a5=function5(i);
        double a6=function6(i);
        double a7=function7(i);
        double a8=function8(i);
        double a9=function9(i);
        double a10=function10(i);

        printf("%d\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",i,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
        // printf("%d\t%f\t%f\t%f\t%f\t%f\n",i,a1,a2,a3,a4,a5);
    }  

    return 0;
}

double function1(int n){ // function: n
    return n;
}

double function2(int n){ // function: 2^n
    return pow(2,n);
}

double function3(int n){ // function: n^3
    return n*n*n;
}

double function4(int n){ // function: log2(n)
    return log2(n);
}

double function5(int n){ // function: ln(n)
    return log(n);
}

double function6(int n){ // function: log2(log2(n))
    return log2(log2(n));
}

double function7(int n){ // function: 2^(log2(n))
    return pow(2,log2(n));
}

double function8(int n){ // function: 2^(2^n)
    return pow(2,pow(2,n));
}

double function9(int n){ // function: nlogn
    return n*log2(n);
}

double function10(int n){ // function: e^n
    return exp(n);
}
