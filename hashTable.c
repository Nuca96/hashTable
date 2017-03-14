#include "list.h"
#include "hash.h"
#include <string.h>

int h_create(hashTable hashT, int dim)
{
        //returns:
        //0 -> success
        //-1 -> fail
        int i;
        if (h_clear(hashT) == -1)
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

int h_clear(hashTable hashT)
{
        int i;
        for (i=0; i<hashT.dim; i++)
        {
                l_delete_all(hashT.first[i].next);
        }
        free(first);
}

//unsigned int hash(const char *str, unsigned int hash_length)

int h_add (hashTable hashT, char *word)
{
        int number;
        number = hash(word, hashT.dimension);
        if (l_insert(word, hashT.first[number].next) == -1)
        {
                return -1;
        }
        return 0;
}

bool h_find (hashTable hashT, char *word)
{
        if (word==NULL)
        {
                return false;
        }
        int number = hash(word, hashT.dimension);
        return l_search(word, hash.first[number].next);
}

int h_remove(hashTable hashT, char *word)
{
        if (word==NULL)
        {
                return 0;
        }
        int number = hash(word, hashT.dimension);
        return l_remove(word, hashT.first[number].next);
}

hashTable h_resize_double(hashTable hashT)
{
        hashTable newHash;
        h_create(newHash, hashT.dimension*2);
        int i;
        for (i=0; i<hashT.dimension; i++)
        {
                node *N = hashT[i].first.next;
                while (N!=NULL)
                {
                        h_add(newHash, N->word);
                        N=N->next;
                }
        }
        h_clear(hashT);
        return newHash;
}


hashTable h_resize_halve(hashTable hashT)
{
        hashTable newHash;
        create(newHash, hashT.dimension/2);
        int i;
        for (i=0; i<hashT.dimension; i++)
        {
                node *N = hashT[i].first.next;
                while (N!=NULL)
                {
                        h_add(newHash, N->word);
                        N=N->next;
                }
        }
        h_clear(hashT);
        return newHash;
}

int print_word(char *word, char *where)
{
	int fd = open(where, O_WRONLY |O_CREAT | O_APPEND, 0664);

	if(fd < 0)
		return -1;

	int succes = write(fd, word, strlen(word));

	if(succes<0)
		return -1;


	return 0;
}

int h_print_bucket (hashTable hashT, int i, char *where)
{
        //returneaza:
        //-1 -> eroare
        //nr de elemente printate

        if(hashT.dim>=i)
        {
                return -1;
        }
        int nr=0;
        node *N = hashT.first[i].next;
        while(N!=NULL)
        {
                if (print_word(strcat(word, " "), where)==-1)
                {
                        return -1;
                }
                N=N->next;
                nr++;
        }
        return nr;
}

int h_print (hashTable hashT, char *where)
{
        int i;
        for (i=0; i<hashT.dimension; i++)
        {
                int succes=h_print_bucket(hashT, i, where);
                if (succes==-1)
                {
                        return -1;
                }
                if (succes>0)
                {
                        print_word("\n");
                }
        }
}
