//
//  Created by Максим Шилов on 17.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int findNumber(char* string);
int main(void) {
    int N = INT32_MAX, countOfRaws = 0;
    char *buffer = (char*) malloc(sizeof(char) * N);
    FILE *fp;
    fp = fopen("file.txt", "r+");
    if (!fp) exit(1);
    while (fgets(buffer, N, fp) != NULL)
        countOfRaws++;
    char** text = (char**)malloc(sizeof(char*) * countOfRaws);
    char** newText = (char**)malloc(sizeof(char*) * countOfRaws);
    for (int i = 0; i < countOfRaws; i++){
        text[i] = (char*)malloc(sizeof(char*) * 40);
        newText[i] = (char*)malloc(sizeof(char*) * 40);
    }
    int i = 0;
    fseek(fp, 0, SEEK_SET);
    while (fgets(buffer, N, fp) != NULL){
        strcpy(text[i], buffer);
        i++;
    }
    printf("Текст в файле: \n");
    for (int i = 0; i < countOfRaws; i++){
        printf("%s", text[i]);
    }
    for (int i = 0; i < countOfRaws; i++){
        int j = findNumber(text[i]) - 1;
        if(newText[j] == NULL){
            printf("\nОшибка в файле\nЗавершение программы...\n\n");
            exit(1);
        }
        strcpy(newText[j], text[i]);
    }
    fseek(fp, 0, SEEK_SET);
    printf("\nИзменённый текст в файле: \n");
    for (int i = 0; i < countOfRaws; i++){
        fprintf(fp, "%s", &newText[i] [ '\0']);
        printf("%s", newText[i]);
    }
    
    fclose(fp);
    return 0;
}

int findNumber(char* string){
    int number = 0, count = 0, position = 0;
    for (int i = 0; i < 8; i++){
        if(string[32 + i] >= '0' && string[32 + i] <= '9'){
            count++;
            position = i;
        }
        else if(count != 0)
            break;
    }
    for (int i = 0; i < count; i++){
        number +=  (string[32 + position - count + i + 1] - '0') * pow(10, count - i - 1);
    }
    return number;
}
