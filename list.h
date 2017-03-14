#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct node {
        char *info;
        struct node *next;
};

int l_insert (char *word, node *this_node);
int l_remove (char *word, node *this_node);
int l_free_node (node *this_node);
int l_delete_all (node *this_node);
bool l_search (char *word, node *this_node);

#endif // LIST_H_INCLUDED
