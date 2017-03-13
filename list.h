#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct node {
        char *info;
        struct node *next;
};

int insert (char *word, node *this_node);
int remove (char *word, node *this_node);
int free_node (node *this_node);
int delete_all (node *this_node);
bool search (char *word, node *this_node);

#endif // LIST_H_INCLUDED
