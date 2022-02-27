#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum Company  {GOOGLE,FACEBOOK,XEROX,YAHOO,EBAY,MICROSOFT};
    enum Company x,y,z;
    x = GOOGLE;
    y = XEROX;
    z = EBAY;
    printf("%d\n%d\n%d\n",y,x,z);
    return 0;
}
