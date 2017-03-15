#ifndef MYHASH_H_
#define MYHASH_H_
#include "hashTable.h"

struct hashTable H;

int create(int dim);
int add(char *word);
void remove_word(char *word);
void find(char *word, char *where);
void print_bucket(int i, char *where);
void resize_double();
void resize_halve();
void print(char *where);



#endif // MYHASH_H_INCLUDED
