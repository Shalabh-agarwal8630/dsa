#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void circularlisttraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct node *insertafternode(struct node *head,struct node* prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 7;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = head;

    circularlisttraversal(head);
    head = insertafternode(head,second, 54);
    printf("after inserting\n");
    circularlisttraversal(head);
    return 0;
}