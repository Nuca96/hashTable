#include "preluareParametri.h"
#include "myhash.h"

int main(int argc, char* argv[]) {
	unsigned int dim = atoi(argv[1]);
	int i;
	create(dim);
	if(argc == 2)
	{
		UniversalParse("consola");
	}
	else
	{
	        for(i=2; i<argc; ++i)
                {
                        UniversalParse(argv[i]);
                }
	}
	clear();
	return 0;
}
