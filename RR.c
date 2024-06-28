#include <stdio.h>
#include <stdlib.h>

void read ( int *x, int n ) {
    for ( int *p = x; p < x + n; ++p ) {
        printf(" bt[%ld] = ", p - x + 1);
        scanf("%d", p);
    }
}

void display ( int *b, int *w, int *t, int n ) {
    printf(" bt wt tt\n");
    for( int *p = b, *q = w, *d = t; p < b + n; ++p, ++q, ++d )
        printf(" %02d %02d %02d\n", *p, *q, *d);
}

void tozero ( int *x, int n ) {
    for ( int *p = x; p < x + n; ++p )
        *p = 0;
}

void copy ( int *a, int *b, int n ) {
    for ( int *p = a, *q = b; p < a + n; ++p, ++q )
        *p = *q;
}

void calc ( int *b, int *w, int *t, int n, int qntm ) {
    int stop = 1, B[10], q, i = 0;
    copy(B, b, n);
    while( stop ) {
        if ( i >= n ) i = 0;
        stop = n;
        q = qntm;
        while( q && B[i] ) {
            for ( int j = 0; j < n; ++j )
                if ( (j != i) && B[j] )
                    w[j]++;
                
            B[i]--;
            q--;
        }
        for ( int *j = B; j < B + n; ++j )
            if ( *j == 0 )
                stop--;
        i++;
    }

    for (int j = 0; j < n; ++j)
        t[j] = w[j] + b[j];
}

double avrg ( int *x, int n ) {
    double avr = 0;
    for ( int *p = x; p < x + n; ++p )
        avr += *p;
    return avr / n;
}

int main()
{
    int wt[10], bt[10], tt[10], n = 10, qntm = 5;
    tozero(wt, n);tozero(bt, n);tozero(tt, n);
    
    printf(" Enter number of processes: ");
    scanf("%d", &n);
    printf(" Enter burst time (execution time): \n");
    read(bt, n);
    calc(bt, wt, tt, n, qntm);
    display(bt, wt, tt, n);
    printf("\n aw = %lf", avrg(wt, n));
    printf("\n at = %lf", avrg(tt, n));
    return 0;
}
