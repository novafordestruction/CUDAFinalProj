#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//small c program to read each individual element of a file
//uses comma-spaces as delimiters
FILE *fp;
int main()
{
    int numSum = 0;
    fp = fopen("test.txt" , "r");
    if (fp == NULL)
    {
        printf("error, file not read");
        return -99;
    }
    char text[2040];
    printf("%s", text);
    while (fgets(text, sizeof text, fp) != NULL)
    {


        char * token;
        token = strtok( text, ", " );
        while( token != NULL )
        {
          /* While there are tokens in "string" */
          //printf( "%s\n", token );
          /* Get next token: */
          token = strtok( NULL, ", \n{}"  );
          numSum = numSum +1;
        }
    }
    //takes 5 and a half minutes with print statements for each element
    //takes 1 second without
    printf("total entries scanned = %i",numSum);
    fclose(fp);
    return 0;
}
