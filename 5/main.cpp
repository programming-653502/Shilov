//
//  Created by Максим Шилов on 17.02.17.
//  Copyright © 2017 Максим Шилов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void reverse(struct node** headRef)
{
    struct node* prev = NULL;
    struct node* current = *headRef;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

void push(struct node** headRef, int newData)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main(void)
{
    struct node* head = NULL;
    int n;
    printf("Введите количество элементов в списке: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        push(&head, rand() % 100);
    }
    printf("Исходный список:\n");
    printList(head);
    reverse(&head);
    printf("\nПеревёрнутый список:\n");
    printList(head);
    printf("\n");
    return 0;
}
