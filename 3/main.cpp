//
//  Created by Максим Шилов on 17.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void showArray(double** a, int n);
void sumAll(double** array, int n);
void swapLeftAndRight(double** a, int n);
void swapTopAndBottom(double** a, int n);

int main(void) {
    int n;
    printf("Введите n: \n");
    scanf("%d", &n);
//    printf("Введите элементы массива: \n");
    double** array = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++){
        array[i] = (double*)malloc(n * sizeof(double*));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
//            scanf("%lf", &array[i][j]);
            array[i][j] = rand() % 10;
        }
    }
    showArray(array, n);
    printf("\n");
    sumAll(array, n);
    printf("\n");
    swapLeftAndRight(array, n);
    swapTopAndBottom(array, n);
    showArray(array, n);
    printf("\n");
    sumAll(array, n);
    printf("\n");
    return 0;
}

void showArray(double** a, int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%lf\t", a[i][j]);
        }
        printf("\n");
    }
}

double sumLeft(double** a, int n){
    double sum = 0;
    for (int i = 1; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if(i + j < n - 1 && i != j){
                sum += a[i][j];
            }
            else
                break;
        }
    }
    return sum;
}

double sumRight(double** a, int n){
    double sum = 0;
    for (int i = 1; i < n - 1; i++){
        for (int j = n - 1; j > 0; j--){
            if(i + j > n - 1 && i != j){
                sum += a[i][j];
            }
            else
                break;
        }
    }
    return sum;
}

double sumTop(double** a, int n){
    double sum = 0;
    for (int i = 0; i < n / 2; i++){
        for (int j = 1; j < n - 1; j++){
            if(j > i && i + j < n - 1){
                sum += a[i][j];
            }
        }
    }
    return sum;
}

double sumBottom(double** a, int n){
    double sum = 0;
    for (int i = n/2 ; i < n; i++){
        for (int j = 1; j < n - 1; j++){

            if(j < i && i + j > n -1){
                sum += a[i][j];
            }
        }
    }
    return sum;
}

void sumAll(double** array, int n){
    printf("Сумма элементов левой четверти: %lf\n", sumLeft(array, n));
    printf("Сумма элементов правой четверти: %lf\n", sumRight(array, n));
    printf("Сумма элементов верхней четверти: %lf\n", sumTop(array, n));
    printf("Сумма элементов нижней четверти: %lf\n", sumBottom(array, n));
}

void swap(double* a, double* b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swapLeftAndRight(double** a, int n){
    for (int i = 1; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            if(i + j < n - 1 && i != j){
                swap(&a[i][j], &a[i][n - j - 1]);
            }
            else
                break;
        }
    }
}

void swapTopAndBottom(double** a, int n){
    for (int i = 0; i < n / 2; i++){
        for (int j = 1; j < n - 1; j++){
            if(j > i && i + j < n - 1){
                swap(&a[i][j], &a[n - 1 - i][j]);
            }
        }
    }
}
