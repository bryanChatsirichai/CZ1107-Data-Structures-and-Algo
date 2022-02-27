#include <stdio.h>
#include <stdlib.h>

enum days {mon=1,tues,wed,thurs,fri,sat,sun};
enum days today = 6;

int main()
{
  switch(today)
  {
      case 6 ... 7:
    {
      printf("Weekend\n");
      break;
    }
    case 1 ... 5:
    {
        printf("Weekday\n");
        break;
    }
    default:
    printf("Whateva\n");
    break;
    return 0 ;
 }
}
