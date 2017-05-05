//
//  Created by Максим Шилов on 17.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void showMatrix(char** matrix, int n);
void enterMatrix(char** matrix, int n);
char* reverse(char* array);

int main(void)
{
    int n, k;
    puts("Введите n (количество матриц): ");
    scanf("%d", &n);
    rewind(stdin);
    for (int i = 0; i < n; i++) {
        puts("Введите количество строк в матрице: ");
        scanf("%d", &k);
        rewind(stdin);
        char** array = (char**)malloc(sizeof(char*) * k);
        for (int i = 0; i < k; i++) {
            array[i] = (char*)malloc(sizeof(char*) * 256);
        }
        printf("Введите слова матрицы: \n");
        enterMatrix(array, k);
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (int j = 0; j < 255; j++) {
                if (array[i][j] != '\n') {
                    sum += (int)array[i][j];
                } else {
                    break;
                }
            }
            if (sum % 2 == 0)
                array[i] = reverse(array[i]);
        }
        printf("Полученная матрица: \n");
        showMatrix(array, k);
        printf("\n");
    }
    return 0;
}

void enterMatrix(char** matrix, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 255; j++) {
            if ((matrix[i][j] = getchar()) == '\n') {
                rewind(stdin);
                break;
            }
        }
    }
}

void showMatrix(char** matrix, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 255; j++) {
            if (matrix[i][j] != '\n') {
                printf("%c", (char)matrix[i][j]);
            } else {
                break;
            }
        }
        printf("\n");
    }
}

char* reverse(char* array)
{
    int position = 0;
    for (int i = 0; i < 256; i++) {
        if (array[i] == '\n') {
            position = i;
            break;
        }
    }
    char* temp = (char*)malloc(sizeof(char*) * position + 2);
    for (int i = 0; i < position; i++) {
        temp[i] = array[position - 1 - i];
    }
    temp[position] = '\n';
    return temp;
}
