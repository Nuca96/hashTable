#include "hashTable.h"

int create(int dim)
{
        return h_create(H, dim);
}

void add(char *word)
{
        int succes= h_add(H, word);
}

void remove(char *word)
{
        int succes h_remove(H, word);
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
        int succes = h_clear
}



