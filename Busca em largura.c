/*
 * Programa em C  para mostrar os nos de uma arvore  Usando Busca em largura (BFS) Traversal 
 *              
 */
#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{ 
    int value; 
    struct btnode *left, *right; 
}; 
typedef struct btnode node;
 
/* declarando as funcoes */
void insert(node *, node *);
void bfs_traverse(node *);
 
/*declaracoes globais */
node *root = NULL;
int val, front = 0, rear = -1, i;
int queue[20];
 
void main() 
{ 
    node *new = NULL ; 
    int num = 1; 
    printf("Digite o elemento da arvore(clica 0 para SAIR)\n"); 
    while (1) 
    {     
        scanf("%d",  &num); 
        if (num  ==  0) 
            break; 
        new = malloc(sizeof(node)); 
        new->left = new->right = NULL; 
        new->value = num; 
        if (root == NULL) 
            root = new; 
        else 
        { 
            insert(new, root); 
        } 
    }
    printf("elementos nao ordenados da arvore sao:\n"); 
    queue[++rear] = root->value;
    bfs_traverse(root);
    for (i = 0;i <= rear;i++)
        printf("%d -> ", queue[i]);
    printf("%d\n", root->right->right->right->value);
}
 
/* inserting nodes of a tree */
void insert(node * new , node *root) 
{ 
    if (new->value>root->value) 
    {     
        if (root->right == NULL) 
            root->right = new; 
        else 
            insert (new, root->right); 
    } 
    if (new->value < root->value) 
    {     
        if (root->left  ==  NULL) 
            root->left = new; 
        else 
            insert (new, root->left); 
    }     
}
 
/* displaying elements using BFS traversal */
void bfs_traverse(node *root)
{
    val = root->value;
    if ((front <= rear)&&(root->value == queue[front]))
    {
        if (root->left != NULL)
            queue[++rear] = root->left->value;
        if (root->right != NULL || root->right  ==  NULL)
            queue[++rear] = root->right->value;
        front++;
    }
    if (root->left != NULL)
    {
        bfs_traverse(root->left);
    }
    if (root->right != NULL)
    {
        bfs_traverse(root->right);
    }
}
