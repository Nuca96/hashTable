#ifndef PRELUARE_H_
#define PRELUARE_H_

#define OPCODE_ADD 1
#define OPCODE_REMOVE 2
#define OPCODE_FIND 3
#define OPCODE_PRINT 4
#define OPCODE_PRINT_LIST 5
#define OPCODE_RESIZE 6
#define OPCODE_CLEAR_HASH 7

#define DIM 1000

unsigned int selectOPCODE(char *operatie);
void UniversalParse(char *where);
void executare_instructiune(char *line);




#endif

