#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE* fp;
char c;

void
cat(char *s)
{
    printf("File name : [%s]\n",s);
    while((c = fgetc(fp) )!=  EOF) printf("%c",c);
}

void
main(int argc, char *argv[])
{
	int f,j;
    int i;

	if(argc == 1){
		fprintf(stderr, "Please enter a file name\n");
        exit(1);
    }

	else for(i=1; i<argc; i++){
        
        j = access(argv[i], F_OK);

		if(j < 0){
            fprintf(stderr, "The %s File does not exist\n", argv[i]);
            continue;
        }

        f =access(argv[i], R_OK);

		if(f < 0){
            fprintf(stderr, "You don't have permission to read the %s file\n", argv[i]);
            continue;
        }

		else{
            fp = fopen(argv[i],"rt");
			cat(argv[i]);
			close(f);
		}
	}
	exit(0);
}
