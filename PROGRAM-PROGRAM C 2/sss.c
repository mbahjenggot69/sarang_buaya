#include <stdio.h>
 
int main()
{
    FILE *fileptr1, *fileptr2;
    char filename[] = "triallist.txt";
    char ch;
 
    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
   while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);

    //open new file in write mode
    fileptr2 = fopen("replica.txt", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
            
                //copy all lines in file replica.c
                putc(ch, fileptr2);
            
    }
    fclose(fileptr1);
    fclose(fileptr2);
    
    return 0;
}
