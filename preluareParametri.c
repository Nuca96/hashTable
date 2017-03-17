#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "myHash.h"
#include "preluareParametri.h"

unsigned int selectOPCODE(char *operatie) {
	if (strcmp(operatie, "add") == 0)
		return OPCODE_ADD;

	if (strcmp(operatie, "remove") == 0)
		return OPCODE_REMOVE;

	if (strcmp(operatie, "find") == 0)
		return OPCODE_FIND;

	if (strcmp(operatie, "print") == 0)
		return OPCODE_PRINT;

	if (strcmp(operatie, "print_bucket") == 0)
		return OPCODE_PRINT_LIST;

	if (strcmp(operatie, "resize") == 0)
		return OPCODE_RESIZE;

	if (strcmp(operatie, "clear") == 0)
		return OPCODE_CLEAR_HASH;

	return -1;
}

void executare_instructiune(char *line)
{
	unsigned int opcode,index;
	char *p = NULL;
	char *aux;
        p = strtok(line," \n");
        opcode=selectOPCODE(p);

        switch(opcode) {
                case OPCODE_ADD:
                {

                        p=strtok(NULL," \n");

                        //apelez functia de adaugare cu p (in p se regaseste cuvantul acum)
                        if (p!=NULL)
                                add(p);
                        break;
                }
                case OPCODE_REMOVE:
                {
                        p=strtok(NULL," \n");

                        remove_word(p);
                        //apelez functia de stergere cu p (in p se regaseste cuvantul acum)
                        break;
                }
                case OPCODE_FIND:
                {

                        p=strtok(NULL," \n");
                        if(p!=NULL)
                                aux= (char *) malloc( sizeof(char) * (strlen(p)+1) );
                        strcpy(aux, p);
                        p=strtok(NULL," \n");
                        if (p==NULL)
                        {
                                find(aux, "consola");
                        }
                        else{
                                find(aux, p);
                        }
                        break;
                }
                case OPCODE_PRINT:
                {
                        p=strtok(NULL," \n");
                        if(p != NULL)
                        {
                                print(p);
                        }
                        else
                        {
                                print("consola");
                        }
                        //apelez functia de afisare a intregului hash cu outputfile
                        break;
                }
                case OPCODE_PRINT_LIST:
                {
                        p=strtok(NULL," \n");
                        index=atoi(p);
                        p=strtok(NULL," \n");
                        if(p != NULL)
                        {
                                print_bucket(index, p);
                        }
                        else
                        {
                                print_bucket(index, "consola");
                        }

                        //apelez functia de printare a unui singur bucket cu outputfile (in p se regaseste cuvantul acum)
                        break;
                }
                case OPCODE_RESIZE:
                {
                        p=strtok(NULL," \n");
                        if(p != NULL)
                        {
                                if(strcmp(p,"double"))
                                {
                                        resize_double();
                                }
                                else
                                {
                                        if(strcmp(p,"halve"))
                                                resize_halve();
                                }
                        }
                        break;
                }
                case OPCODE_CLEAR_HASH:
                {

                        clear();
                        break;
                }
                case -1:
                {
                        break;
                }
        }
}

void UniversalParse(char *where)
{
	FILE *f;
	char line[DIM];
	if( strcmp(where, "consola") !=0 )
	{

		f = fopen(where, "r");
		while(fgets(line,DIM,f) != NULL)
		{
		        executare_instructiune(line);
		}


	}
	else
	while (1)
	{
		fgets(line,DIM,stdin);
		executare_instructiune(line);
	}
}
