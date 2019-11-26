#include <stdio.h>

int main(int ac, char** av)
{
    FILE* filePtr;
    if(ac > 1)
    {
        puts("Reading file:");
        puts(av[1]);
        puts("Contents:");
        filePtr = fopen(av[1],"r");
        char c;
        c = fgetc(filePtr);
        while(c != EOF)
        {
            printf ("%c", c); 
            c = fgetc(filePtr); 
        }
        fclose(filePtr);
        puts("Appending file name to file");
        filePtr = fopen(av[1],"a");
        fprintf(filePtr, "%s\n", av[1]);
        fclose(filePtr);
    }
}