#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random,tries,answer;
    time_t secondsFromEpoch = time(NULL);
    srand(secondsFromEpoch); // random the seeed
    random = rand() % 21; // ensure num 0 to 20
    printf("This is a guessing game\n");
    printf("Guess the number between 0 to 20\n");
    for(tries = 5;tries > 0; tries --)
    {
        printf("you have %d tries left\n",tries);
        printf("Enter a guess:");
        scanf("%d", &answer);
        if(answer == random)
        {
            printf("Congratulation you guess it\n");
            break; //exit loop
            //return will exit main
            /*When a return statement is in a function, it causes that function to
            immediately stop processing and return control to the code
            (main or another function) that called the function.
            If the return statement includes a variable name or a value,
            that var or value will be returned to the calling function.*/
        }
        else  if (answer < 0 || answer > 20)
            printf("Number is within 0 to 20 you enter out of range\n");

            else if (answer > random)
        {
            printf("Sorry %d is wrong my number is less than that\n",answer);
        }
        else if (answer <random)
        {
            printf("Sorry %d is wrong my number is more than that\n",answer);
        }

    }
        if (tries == 0)
            printf("You fail to guess within 5 tries\n");


    printf("Thanks for playing\n");

    return 0;
}
