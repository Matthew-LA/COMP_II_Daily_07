//
//  daily7.c
//  COMP1020
//
//  Created by Matthew Lorette Anaya on 4/22/20.
//  Copyright © 2020 Matthew Lorette Anaya. All rights reserved.
//
/***********************************************************
Author: Matthew Lorette Anaya
Date: 02/16/2020
Effort: 30mins
Purpose: Familiarizing with linked lists
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

void* reverse_node(Node** hHead);

int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;

    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++){
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL){
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    //call your function to reverse the list (should work for any list given the head node).
    reverse_node(&head);

    //print the reversed list.
    temp = head;
    while (temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}
void* reverse_node(Node** hHead)
{
    Node* prev = NULL;
    Node* curr = *hHead;
    Node* next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *hHead = prev;
}

