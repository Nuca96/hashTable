#include "list.h"
#include "hash.h"

int create(hashTable hashT, int dim)
{
        //returns:
        //0 -> success
        //-1 -> fail
        int i;
        if (delete_hash(hashT) == -1)
        {
                return -1;
        }
        hastT.dimension=dim;
        hashT.first = (node*) malloc(dim*sizeof(node));
        for (i=0; i<dim; i++)
        {
                hashT.first[i].next=NULL;
                hashT.first[i].word=NULL;
        }
        return 0;
}

int delete_hash(hashTable hashT)
{
        int i;
        for (i=0; i<hashT.dim; i++)
        {
                list::delete_all(hashT.first[i].next);
        }
        free(first);
}

//unsigned int hash(const char *str, unsigned int hash_length)

int insert (hashTable hashT, char *word)
{
        int number;
        number = hash(word, hashT.dimension);
        if (list::insert(word, hashT.first[number].next) == -1)
        {
                return -1;
        }
        return 0;
}

bool find (hashTable hashT, char *word)
{
        if (word==NULL)
        {
                return false;
        }
        int number = hash(word, hashT.dimension);
        return list::search(word, hash.first[number].next);
}
