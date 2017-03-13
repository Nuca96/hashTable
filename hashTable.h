#ifndef DECLARE_HASH_H_INCLUDED
#define DECLARE_HASH_H_INCLUDED
#include "list.h"

struct hashTable
{
        int dimension;
        node *first;
};

int create(hashTable hashT, int dim);
int delete_hash(hashTable hashT);



#endif // DECLARE_HASH_H_INCLUDED
