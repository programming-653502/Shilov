//
//  Created by Максим Шилов on 16.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//

#include <stdio.h>

char* version = (char*)"1.0.0";
char* author = (char*)"Максим Шилов";

void getVersion();
void showMenu(int n);
void getInverse(int n);
void numberToBase(int n, int base);
void nToBase(int n);
void enterN(int *n);
void enterBase(int *base);

int main(void) {
    int n = 0;
    printf("Введите n:\n");
    enterN(&n);
    while(1){
        showMenu(n);
        int choise;
        scanf("%d", &choise);
        switch (choise) {
            case 1:
                printf("Введите новое значение n: \n");
                enterN(&n);
                break;
            case 2:
                printf("Десятичная форма: %d\n", n);
                printf("Восьмеричная форма: ");
                numberToBase(n, 8);
                printf("\nШестнадцатеричная форма: ");
                numberToBase(n, 16);
                printf("\n");
                
                break;
            case 3:
                getInverse(n);
                break;
            case 4:
                nToBase(n);
                break;
            case 5:
                getVersion();
                break;
            case 6:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}

void showMenu(int n){
    printf("--------------------------------------\n");
    printf("Ваше число - %d\n\
1. Ввод нового натурального числа\n\
2. Вывод значения числа в десятичной, восьмеричной и шестнадцатеричной форме.\n\
3. Вывод обратного к нему числа в десятичной форме.\n\
4. Перевод числа в систему счисления, с основанием n [2..16].\n\
5. Информация о версии и авторепрограммы.\n\
6. Выход из программы.\n", n);
    printf("--------------------------------------\n");
}

void getVersion(){
    printf("Версия: %s\n", version);
    printf("Автор: %s\n", author);
}

void getInverse(int n){
    double inverse = 1.0 / n;
    printf("Обратное число: %f\n", inverse);
}

char getSymb(int a, int base){
    char b = NULL;
    switch(a % base){
        case 0: b = '0';
            break;
        case 1: b = '1';
            break;
        case 2: b = '2';
            break;
        case 3: b = '3';
            break;
        case 4: b = '4';
            break;
        case 5: b = '5';
            break;
        case 6: b = '6';
            break;
        case 7: b = '7';
            break;
        case 8: b = '8';
            break;
        case 9: b = '9';
            break;
        case 10: b = 'A';
            break;
        case 11: b = 'B';
            break;
        case 12: b = 'C';
            break;
        case 13: b = 'D';
            break;
        case 14: b = 'E';
            break;
        case 15: b = 'F';
    }
    return b;
}

void nToBase(int n){
    int base;
    printf("Введите основание системы счисления для перевода (от 2 до 16): \n");
    enterBase(&base);
    printf("Число %d в системе счисления с основанием %d: ", n, base);
    numberToBase(n, base);
    printf("\n");
}

void numberToBase(int n, int base){
    int temp = n, countAr = 1;
    while(temp >= base){
        temp /= base;
        countAr++;
    }
    char* ch = new char[countAr];
    int count = 0;
    do{
        ch[count] = getSymb(n, base);
        count++;
        n /= base;
    }
    while(n >= base);
    ch[count] = getSymb(n, base);
    int begin = 1;
    for (int i = count; i >= 0; i--){
        if(begin && ch[i] == '0')
            continue;
        else{
            begin = 0;
            printf("%c", ch[i]);
        }
    }
}

void enterN(int *n){
    scanf("%i", n);
    rewind(stdin);
    while(*n < 1){
        rewind(stdin);
        printf("Ошибка. Введите натуральное число: \n");
        scanf("%i", n);
    }
}

void enterBase(int *base){
    scanf("%i", base);
    rewind(stdin);
    while(*base < 2 || *base > 16){
        rewind(stdin);
        printf("Ошибка. Введите основание системы счисления от 2 до 16: \n");
        scanf("%i", base);
    }
}
