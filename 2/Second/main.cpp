//
//  main.cpp
//  Second
//
//  Created by Максим Шилов on 17.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//

#include <stdio.h>
#include <math.h>

double fact(int n);
double func(double x, int n);

int main(void) {
    double x, sinValue, rightValue, e;
    int n;
    printf("Введите x: \n");
    scanf("%lf", &x);
    printf("Введите точность E: \n");
    scanf("%lf", &e);
    e = fabs(e);
    sinValue = sin(x);
    rightValue = 0;
    n = 0;
    for (int i = 1; i < 10000; i++){
        rightValue = func(x, i);
        if (fabs(sinValue - rightValue) < e){
            n = i;
            break;
        }
    }
    printf("sin(x) = %lf, правая часть = %lf ", sinValue, rightValue);
    printf("\nТочность E была достигнута при n = %d\n", n);
    return 0;
}

double func(double x, int n){
    double res = 0;
    for (int i = 1; i <= n; i++){
        res += pow((-1), i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
    }
    return res;
}

double fact(int n){
    double res = 1;
    for (int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}
