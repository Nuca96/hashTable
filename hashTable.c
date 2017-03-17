#include "hashTable.h"

int h_create(struct hashTable *hashT, int dim)
{
        //returns:
        //0 -> success
        //-1 -> fail
        int i;

        if (h_clear(hashT) == -1)
        {
                return -1;
        }
        hashT->dimension=dim;
        hashT->first = (struct node*) malloc(dim*sizeof(struct node ));
        for (i=0; i<dim; i++)
        {

                hashT->first[i].next=NULL;
                hashT->first[i].info=NULL;
        }
        return 0;

}

int h_clear(struct hashTable *hashT)
{
        int i;
        for (i=0; i<hashT->dimension; i++)
        {
                l_delete_all(&hashT->first[i].next);
        }
        free(hashT->first);
        return 0;
}

//unsigned int hash(const char *str, unsigned int hash_length)

int h_add (struct hashTable *hashT, char *word)
{
        int number;
        number = hash(word, hashT->dimension);

        if (l_insert(word, hashT->first[number].next) == -1)
        {
                return -1;
        }
        return 0;
}

_Bool h_find (struct hashTable hashT, char *word)
{
        if (word==NULL)
        {
                return 0;
        }
        int number = hash(word, hashT.dimension);
        return l_search(word, hashT.first[number].next);
}

int h_remove(struct hashTable *hashT, char *word)
{
        if (word==NULL)
        {
                return 0;
        }
        int number = hash(word, hashT->dimension);
        return l_remove(word, hashT->first[number].next);
}

struct hashTable h_resize_double(struct hashTable *hashT)
{
        struct hashTable newHash;
        h_create(&newHash, hashT->dimension*2);
        int i;
        for (i=0; i<hashT->dimension; i++)
        {
                struct node *N = hashT->first[i].next;

                while (N!=NULL)
                {
                        h_add(&newHash, N->info);
                        N=N->next;
                }
        }
        h_clear(hashT);
        return newHash;
}


struct hashTable h_resize_halve(struct hashTable *hashT)
{
        struct hashTable newHash;
        create(&newHash, hashT->dimension/2);
        int i;
        for (i=0; i<hashT->dimension; i++)
        {
                struct node *N = hashT->first[i].next;
                while (N!=NULL)
                {
                        h_add(&newHash, N->info);
                        N=N->next;
                }
        }
        h_clear(&hashT);
        return newHash;
}

int print_word(char *word, char *where)
{
        int succes;
        if (strcmp(where, "consola")!=0)
         {
                int fd = open(where, O_WRONLY |O_CREAT | O_APPEND, 0664);
                printf("%d\n",fd );
                if(fd < 0)
                        return -1;
                if(word!=NULL)
                 succes = write(fd, word, strlen(word));

                if(succes<0)
                        return -1;


                return 0;
         }
         else
         {
                 printf("%s", word);
         }
         return 0;
}

int h_print_bucket (struct hashTable hashT, int i, char *where)
{
        //returneaza:
        //-1 -> eroare
        //nr de elemente printate

        if(hashT.dimension<=i)
        {
                return -1;
        }
        int nr=0;
        struct node *N = hashT.first[i].next;
        while(N!=NULL)
        {
                if (print_word(strcat(N->info," "),where)==-1)
                {
                        return -1;
                }
                N=N->next;
                nr++;
        }
        return nr;
}

int h_print (struct hashTable hashT, char *where)
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
                        print_word("\n","consola");
                }
        }
        return 0;
}
