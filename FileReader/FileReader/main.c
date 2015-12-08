#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//small c program to read each individual element of a file
//uses comma-spaces as delimiters
FILE *fp;
int main()
{
    int numSum = 0;
    fp = fopen("precip_cv.1900" , "r");
    if (fp == NULL)
    {
        printf("error, file not read");
        return -99;
    }
    char text[2040];
    printf("%s", text);
    int numSkip = 0;
    float numAverage = 0;   //average still wrong
    float numMovAverage = 0;
    while (fgets(text, sizeof text, fp) != NULL)
    {
        char * token;
        token = strtok( text, " " );
        while( token != NULL )
        {
          float tokenF = strtof(token, NULL);
          numSum++;
          if (numSkip >= 2)
          {
            printf( "%s\n", token );
            numAverage += tokenF;
          }
          numSkip++;
          if (numSum == 1)
          {
              numMovAverage = tokenF;
          }
          else
          {
              numMovAverage = (tokenF + (numMovAverage * numSum)) / (numSum + 1);
          }
          //token = strtok( NULL, " " );
          //token = strtok( NULL, " " );
          /* While there are tokens in "string" */

          /* Get next token: */


          token = strtok( NULL, " \n"  );

        }
        numAverage /= 12;
        printf( "average of year: %.1f\n", numAverage );
        printf( "moving average of  all years: %.1f\n", numMovAverage );
        numSkip = 0;
        numAverage = 0;
    }
    //takes 5 and a half minutes with print statements for each element
    //takes 1 second without
    printf("total entries scanned = %i",numSum);
    fclose(fp);
    return 0;
}
