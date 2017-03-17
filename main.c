#include "myHash.h"


int main(int argc, char* argv[]) {

	unsigned int dim = 5; //atoi(argv[1]);
	int i;

	create(dim);


	/*if(argc == 2)
	
		UniversalParse("consola");
	}
	else
	{
	        for(i=2; i<argc; ++i)
                {
                        UniversalParse(argv[i]);
                }
	}*/
    add("cuvant");
    add("altcuvant");
    print_bucket(0,"consola");
    find("cuvant","consola");
    resize_double();
    resize_halve();
    clear();
	return 0;
}
