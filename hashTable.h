#ifndef DECLARE_HASH_H_INCLUDED
#define DECLARE_HASH_H_INCLUDED
#include "list.h"

struct hashTable
{
        int dimension;
        node *first;
};

int h_create(hashTable hashT, int dim);
int h_clear(hashTable hashT);
int h_add (hashTable hashT, char *word);
bool h_find (hashTable hashT, char *word);
int h_remove(hashTable hashT, char *word);
hashTable h_resize_halve(hashTable hashT);
hashTable h_resize_double(hashTable hashT);
int print_word(char *word, char*where);
int h_print_bucket (hashTable hashT, int i, char *where);
int h_print (hashTable hashT, char *where);



#endif // DECLARE_HASH_H_INCLUDED
