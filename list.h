#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct node {
        char *info;
        struct node *next;
};

int l_insert (char *word, struct node *this_node);
int l_remove (char *word, struct node *this_node);
int l_free_node (struct node* this_node);
int l_delete_all (struct node* this_node);
_Bool l_search (char *word, struct node *this_node);

#endif // LIST_H_INCLUDED
