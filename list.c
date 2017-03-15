#include<string.h>
#include "list.h"

int l_insert(char *word, struct node *this_node)
{
        //returns:
        //1 -> successful insertion
        //2 -> the word was already a member of the list
        //-1 -> error
        if (word==NULL)
        {
                return -1;
        }
        if ( this_node == NULL )
        {
                this_node = (node*) malloc (sizeof(node));
                this_node->info = (char*) malloc (strlen(word) + 1);
                strcpy(this_node->info, word);
                this_node->next = NULL;
                return 1;
        }
        if ( strcmp(this_node->info, word)==0)
        {
                return 2;
        }
        return l_insert(word, this_node->next);
}

int l_free_node(struct node *this_node)
{
        if(this_node !=NULL)
        {
                free(this_node->word);
                free(this_node);
                return 0;
        }
        return -1;
}

int l_remove(char *word, struct node *this_node)
{
        //returns:
        //1 -> successfull deleting
        //2 -> word not found
        //-1 -> error
        if (word==NULL)
        {
                return -1;
        }
        if (this_node==NULL)
        {
                return 2;
        }
        if (this_node->next==NULL)
        {
                if (strcmp(this_node->info, word)==0)
                {
                        l_free_node(this_node);
                        return 1;
                }
        }
        if (strcmp(word, this_node->next->info) == 0)
        {
                struct node *aux;
                aux=this_node->next;
                this_node->next=this_node->next->next;
                l_free_node(aux);
                return 1;
        }
        return l_remove(word, this_node->next);
}

bool l_search(char *word, struct node *this_node)
{
        if (word==NULL)
        {
                return false;
        }
        if (this_node==NULL)
        {
                return false;
        }
        if (strcmp(this_node->info, word) ==0)
        {
                return true;
        }
        return l_search(word, this_node->next);
}

int l_delete_all (struct node *this_node)
{
        //returns the number of elements deleted
        if (this_node==NULL) {
                return 0;
        }
        node *next;
        next=this_node->next;
        l_free_node(this_node);
        return 1+l_delete_all(next);
}
