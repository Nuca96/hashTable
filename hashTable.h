#ifndef DECLARE_HASH_H_INCLUDED
#define DECLARE_HASH_H_INCLUDED
#include "list.h"

struct hashTable
{
        int dimension;
        struct node *first;
};

int h_create(struct hashTable hashT, int dim);
int h_clear(struct hashTable hashT);
int h_add (struct hashTable hashT, char *word);
_Bool h_find (struct hashTable hashT, char *word);
int h_remove(struct hashTable hashT, char *word);
struct hashTable h_resize_halve(struct hashTable hashT);
struct hashTable h_resize_double(struct hashTable hashT);
int print_word(char *word, char*where);
int h_print_bucket (struct hashTable hashT, int i, char *where);
int h_print (struct hashTable hashT, char *where);



#endif // DECLARE_HASH_H_INCLUDED
