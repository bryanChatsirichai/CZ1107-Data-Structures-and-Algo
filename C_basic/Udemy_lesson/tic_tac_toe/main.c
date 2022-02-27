#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define SIZE 10
void display_board(char *board); //ptr is a pointer to array of 3 char
int valid_space(char *board);
void update_board(char board[],char symbol);
int check_winner(char *board,char symbol);
int got_space(char *board);
int main()
{
    //board is a pointer constant to 1st element in the array
   char  board[SIZE] = { 'n','1','2','3',
                             '4','5','6',
                             '7','8','9'};
    char p1_symbol = 'X';
    char p2_symbol = 'O';
    char turn_symbol;
    int got_winner,is_tie,game_on,turn;
    //printf("Tic Tac Toe!!!\n");
    turn = 1; // 1 player 1 go first 2 player 2 go first
    game_on = 1; //start game
    while(game_on){
    turn = (turn % 2) ? 1 : 2;  //odd turn player 1 even turn player 2
    printf("\nplayer%d enter your choice\n",turn);
    display_board(board);
    turn_symbol = (turn == 1) ? p1_symbol : p2_symbol; //symbol depends on whose turn
    update_board(board,turn_symbol);
    display_board(board);
    got_winner = check_winner(board,turn_symbol);    //return 1 means turn player won, -1 means continue
    if(got_winner == 1 )
    {
        game_on = 0; //quit after this iteration
        printf("Congrats player%d has Won!!!\n",turn);
    }
    else
    {
        is_tie = got_space(board) ;// return 1 when space fill else return -1
        if(is_tie == 1) //tie-game
        {
            game_on = 0;
            printf("All space has been occupy!\n");
            printf("TIE GAME!!!\n");
        }
    }

    turn++; //alternate between players;
    }

    return 0;
}
void display_board(char *board){ //display the board and elements in each box
    //system("cls"); //clear screen anything before this system function
    printf("Player1 (X), Player2 (O)\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[1],board[2],board[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[4],board[5],board[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[7],board[8],board[9]);
}
int valid_space(char *board){ //return a index if space is available
    int index;
    do{
    printf("Enter a spot to place symbol\n");
    scanf("%d",&index);
    if(index >= 1 && index<=9) //option from 1 to 9 only
        {

            if( board[index] != 'X' && board[index] != 'O' ) //check if someone place a symbol
                {
                    printf("index is accepted\n");
                    return index; //means space ava
                }
            else
                printf("This space is already taken please enter another index\n");
                //scanf("%d",&index);
                //continue; continue will go to the condition while(   )

        }
    else
        printf("Number you enter is out of range\n");
    }while(1); //exit only when available index is entered;
}
void update_board(char board[],char symbol){
    //update index with player symbol
    int choice;
    choice = valid_space(board);
    printf("choice is %d\n",choice);
    board[choice] = symbol;

}
int check_winner(char *board,char symbol){ // return 1 means player won -1 means game continue

    //check the board after players input
    if(board[1] == symbol && board[2] == symbol && board[3] == symbol)
        return 1;

    else if(board[4] == symbol && board[5] == symbol && board[6] == symbol)
        return 1;

    else if(board[1] == symbol && board[4] == symbol && board[7] == symbol)
        return 1;

    else if(board[2] == symbol && board[5] == symbol && board[8] == symbol)
        return 1;

    else if(board[9] == symbol && board[6] == symbol &&  board[9] == symbol)
        return 1;

    else if(board[1] == symbol && board[5] == symbol &&  board[9] == symbol)
        return 1;

    else if(board[3] == symbol && board[5] == symbol && board[7] == symbol)
        return 1;

    else
        return -1; //ame still or Tie
}
int got_space(char *board){ // return 1 when space fill else return -1
    int i,result;
    for(i = 1 ;i< SIZE; i++)
    {
        if( (board[i] - '0') == i ) //char c = '5' c = c = '0' convert char 5 to int
            {  //char -+ char will give the perfome arithmatic in their ascii in decimal
                result = -1;
                return result; //still got slots empty
            }
    }
    result = 1; //exit loop means all space occupy
    return result;
}
