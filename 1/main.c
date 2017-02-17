//
//  Created by Максим Шилов on 17.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char* array = malloc(180 * sizeof(char));
    int j = 0, k;
    for(int i = 10; i < 100; i++)
    {
        array[j] = (char) ((i / 10) % 10 + (int)'0');
        array[j + 1] = (char)(i % 10 + (int)'0');
        j += 2;
    }
    printf("Последовательность:");
    for (int i = 0; i < 180; i++)
        printf("%c", array[i]);
    printf("\nВведите k: \n");
    scanf("%i", &k);
    while(k < 1 || k > 180)
    {
        rewind(stdin);
        printf("Введите k, которая находится в пределах размера последовательности: \n");
        scanf("%i", &k);
    }
    printf("%d-ая цифра последовательности: %c\n", k, array[k - 1]);
    return 0;
}
