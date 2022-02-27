#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*Enums,define a variable and specify the valid values that could be store into that variable*/
    //variable declear this data type can be assign red yellow blue and nthing else
    //Compiler treats enumeration identifiers as integers constants
    //Never assign integers, list start as 0
    enum primaryColour {red,yellow,blue};
    enum primaryColour myColour, myColor2;
    char letter = 'A';
    char x ='\n'; //escapesequences
    myColour = red;
    myColor2 = yellow;
    printf("%d %d",myColour,myColor2);

    return 0;
}
