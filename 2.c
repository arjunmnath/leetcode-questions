/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} Node;

void forwardTraversal(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("[%d, %p] -> ", ptr->val, ptr->next);
        ptr = (Node *)ptr->next;
    }
    printf("NULL\n");
}

void addNode(Node **head, Node **prev, int val)
{
    if (NULL == *head)
    {
        *head = malloc(sizeof(Node));
        (*head)->val = val;
        (*head)->next = NULL;
        *prev = *head;
    }
    else
    {
        Node *tmp = malloc(sizeof(Node));
        tmp->val = val;
        tmp->next = NULL;
        (*prev)->next = tmp;
        *prev = tmp;
    }
}



int main()
{
    Node *l1 = NULL, *l2 = NULL, *l1prev, *l2prev, *l3;
    addNode(&l1, &l1prev, 2);
    addNode(&l1, &l1prev, 4);
    addNode(&l1, &l1prev, 3);
    addNode(&l2, &l2prev, 5);
    addNode(&l2, &l2prev, 6);
    addNode(&l2, &l2prev, 4);
    forwardTraversal(l1);
    forwardTraversal(l2);
    l3 = addTwoNumbers(l1, l2);
    forwardTraversal(l3);
}