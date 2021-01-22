#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *file = NULL;
    FILE *Q = stdin;
    int opt;
    char *separator = ",";
    char quote;

	while ((opt = getopt(argc, argv, ":f:qd")) != -1) {
		switch (opt)
		{
			case 'f':
				file = optarg;
				break;
			case 'q':
				separator = "','";
                quote = '\'';
				break;
			case 'd':
				separator = "\",\"";
                quote = '"';
				break;
		}
	}
        
    if(file) {
        if(!(Q = fopen(file, "r"))) {
            printf("Error while trying to open file: %s\n", file);
            exit(1);
        }
    }
    
    int c = getc(Q);
    int next_char;
    
    if(quote) putchar(quote);
    
    while(c != EOF) {
        
        if(c != '\n') {
            putchar(c);
        }

        next_char = getc(Q);
        if(next_char != EOF && c == '\n') {
            printf("%s", separator);
        }
        
        c = next_char;
    }
    
    if(quote) putchar(quote);
    
    putchar('\n');
    
    fclose(Q);
    
	return 0;
}
