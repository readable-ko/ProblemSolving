#include <bits/stdc++.h>
#define INTMAX 0x3f3f3f3f
using namespace std ;

typedef struct node
{
    int number ;
    node* left ;
    node* right ;
}Node ;

void PostFixPrinter(node* curr)
{
    if(curr == NULL) return ;

    if(curr->left != NULL) PostFixPrinter(curr->left) ;
    if(curr->right != NULL) PostFixPrinter(curr->right) ;
    printf("%d\n", curr->number) ;
}


int main()
{
    int num ;
    node* head = NULL ;
    while(scanf("%d", &num) == 1)
    {
        node** curr = &head ;
        node* now = new node;
        now->number = num ;
        now->left = NULL ;
        now->right = NULL ;

        while(1)
        {
            if((*curr) == NULL)
            {
                *curr = now ; 
                break ;
            }
            else if((*curr)->number > num)
            {
                curr = &(*curr)->left ;
            }
            else if((*curr)->number < num)
            {
                curr = &(*curr)->right ;
            }
        }
    }

    PostFixPrinter(head) ;
}