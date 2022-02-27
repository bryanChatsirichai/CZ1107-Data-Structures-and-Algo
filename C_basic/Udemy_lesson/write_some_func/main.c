#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int greatestCommonDivisor(int num1, int num2);
float absolute(float number);
float squareRoot(float num);
int main()
{

    int num1,num2,gcd;
    float number,numTosquare,result;
    printf("Enter num1 and num2\n");
    scanf("%d %d",&num1,&num2);
    gcd = greatestCommonDivisor(num1,num2);
    printf("The GCD is %d\n",gcd);
    printf("Enter a number to convert to its absolute:\n");
    scanf("%f",&number);
    printf("The absolute value of %.2f is %.2f\n",number,absolute(number));
    printf("Enter a number to square\n");
    scanf("%f",&numTosquare);
    result = squareRoot(numTosquare);
    if(result == -1.0)
        printf("Invalid number enter %.2f is negative\n",numTosquare);
    else if (result >= 0)
        printf("The square root of %.2f is %.2f\n",numTosquare,result);
    return 0;
}
int greatestCommonDivisor(int num1, int num2){
        int i,max_gcd;
        max_gcd = 1;
        i = 1; //1 is factor of every number
        if(num1 == 0 || num2 == 0)
        {
            max_gcd = 0;
            return max_gcd;
        }
        while(i <= num1  && i<= num2 ) //or loop all numbers till nums
        {    //break out loop if either when i equals either num        //try next num see if its a factor of both
        if(num1 % i == 0 && num2 % i ==0)
            {
                max_gcd = i;

            }

            i++;
        }
return max_gcd;

}
float absolute(float number){
    float abs_num;
    abs_num = number;
    if(abs_num>=0)
        return abs_num;
    else
        abs_num = number * -1; //convert negative to positibe

    return abs_num;
}
float squareRoot(float num){

        float squred;

        if(num < 0)
            return -1.0; //negative numbers cannot be square root
        else
            {
                num = absolute(num);
                squred = sqrt(num);
            }

        return squred;


}
