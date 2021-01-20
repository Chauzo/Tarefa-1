/*
 *Programa em C para busca em profundidade
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int a;
    struct node *left;
    struct node *right;
};
 
void generate(struct node **, int);
void DFS(struct node *);
void delete(struct node **);
 
int main()
{
    struct node *head = NULL;
    int choice = 0, num, flag = 0, key;
 
    do
    {
        printf("\nEscolher:\n1. Inserir\n2. Fzer busca em profundidade\n3. sair\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1: 
            printf("Insira um elemento: ");
            scanf("%d", &num);
            generate(&head, num);
            break;
        case 2: 
            DFS(head);
            break;
        case 3: 
            delete(&head);
            printf("Memoria limpa\nPROGRAM TERMINATED\n");
            break;
        default: 
            printf("Entrada invalida, tente de novo\n");
        }
    } while (choice != 3);
    return 0;
}
 
void generate(struct node **head, int num)
{
    struct node *temp = *head, *prev = *head;
 
    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->a = num;
        (*head)->left = (*head)->right = NULL;
    }
    else
    {
        while (temp != NULL)
        {
            if (num > temp->a)
            {
                prev = temp;
                temp = temp->right;
            }
            else
            {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (struct node *)malloc(sizeof(struct node));
        temp->a = num;
        if (num >= prev->a)
        {
            prev->right = temp;
        }
        else
        {
            prev->left = temp;
        }
    }
}
 
void DFS(struct node *head)
{
    if (head)
    {
        if (head->left)
        {
            DFS(head->left);
        }
        if (head->right)
        {
            DFS(head->right);
        }
        printf("%d  ", head->a);
    }
}
 
void delete(struct node **head)
{
    if (*head != NULL)
    {
        if ((*head)->left)
        {
            delete(&(*head)->left);
        }
        if ((*head)->right)
        {
            delete(&(*head)->right);
        }
        free(*head);
    }
}
