#include <stdio.h>

double parallel_max(double *p1, double *p2)
{
    int pivot = (p2-p1)/2; // nas srednji indeks
    double *srednji = p1+pivot; 
    if(p2-p1 == 1) return *p1; //znaci da pokazuju na susjede
    else {
        double x = parallel_max(p1,srednji);
        double y = parallel_max(srednji,p2);
        if(x > y) return x; //vrati vecu vrijednost
        return y;
    }
}

int main()
{
    double niz[] = {4.3, 15.1, 2.2, -3.4, 20.1, 1.1, 3.0};
    printf("%g", parallel_max(niz, niz+7));
    return 0;
}
