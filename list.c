#include<string.h>

int insert(char *word, node *this_node)
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
        return insert(word, this_node->next);
}

int free_node(node *this_node)
{
        if(this_node !=NULL)
        {
                free(this_node->word);
                free(this_node);
                return 0;
        }
        return -1;
}

int remove(char *word, node *this_node)
{
        //returns:
        //1 -> successfull deleting
        //2 -> word not found
        //-1 -> error
        if (word=NULL)
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
                        free_node(this_node);
                        return 1;
                }
        }
        if (strcmp(word, this_node->next->info) == 0)
        {
                struct node *aux;
                aux=this_node->next;
                this_node->next=this_node->next->next;
                free_node(aux);
                return 1;
        }
        return remove(word, this_node->next);
}

bool search(char *word, node *this_node)
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
        return search(word, this_node->next);
}

int delete_all (node *this_node)
{
        //returns the number of elements deleted
        if (this_node==NULL) {
                return 0;
        }
        node *next;
        next=this_node->next;
        free_node(this_node);
        return 1+delete_all(next);
}
