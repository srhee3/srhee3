#include <stdio.h>
#include <math.h>

int main()
{
    int withdraw,hundred,fifty,twenty,ten,five,one;
    printf("Please enter the amount of money you wish to withdraw: ");
    scanf("%d", &withdraw);
    
    hundred = withdraw/100;
    withdraw = withdraw - hundred*100;
    printf("You received %d hundred(s)\n",hundred);
    
    fifty = withdraw/50;
    withdraw = withdraw - fifty*50;
    printf("You received %d fifty(s)\n",fifty);
    
    twenty = withdraw/20;
    withdraw = withdraw - twenty*20;
    printf("You received %d twenty(s)\n",twenty);
    
    ten = withdraw/10;
    withdraw = withdraw - ten*10;
    printf("You received %d ten(s)\n",ten);
    
    five = withdraw/5;
    withdraw = withdraw - five*5;
    printf("You received %d five(s)\n",five);
    
    one = withdraw/1;
    withdraw = withdraw - one*1;
    printf("You received %d one(s)",one);
    scanf("%d", &one);
  
    return 0;
}

