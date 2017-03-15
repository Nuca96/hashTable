#include "hashTable.h"
#include "myHash.h"

int create(int dim)
{
        return h_create(H, dim);
}

void add(char *word)
{
        int succes= h_add(H, word);
}

void remove_word(char *word)
{
        int succes = h_remove(H, word);
}

void find(char *word, char *where)
{
        bool is;
        int succes;
        is = h_find(H, word);
        if (is)
        {
                succes=print_word("true", where);
        }
        else
        {
                succes=print_word("false", where);
        }

}

void clear()
{
        int succes = h_clear(H);

}

void print_bucket(int i, char *where)
{
        int succes = h_print_bucket(H, i, where);
}

void print(char *where)
{
        int succec = h_print(where);
}

void resize_double()
{
       struct hashTable nou = h_resize_double(H);
       if (nou.dimension !=NULL)
       {
               h_clear(H);
               H = nou;
       }
       else
       {
               //cazul in care hash-table-ul nu a putut fi realocat
       }
}

void resize_halve()
{
       struct hashTable nou = h_resize_halve(H);
       if (nou.dimension !=NULL)
       {
               h_clear(H);
               H = nou;
       }
       else
       {
               //cazul in care hash-table-ul nu a putut fi realocat
       }
}


