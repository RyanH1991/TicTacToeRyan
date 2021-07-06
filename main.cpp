#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std; 

class game {
  public:
    char places[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char currentPlayer = 'X';

    void printBoard(){
      printf(" %c | %c | %c \n", places[1],places[2],places[3]);
      printf("-----------\n");
      printf(" %c | %c | %c \n", places[4],places[5],places[6]);
      printf("-----------\n");
      printf(" %c | %c | %c \n", places[7],places[8],places[9]);
    }
    int checkWinCondition(){
      //only 8 win conditions. check all.
      if(((places [1] == currentPlayer) && (places [2] ==currentPlayer) && (places[3] == currentPlayer))||((places [4] == currentPlayer) && (places [5] ==currentPlayer) && (places[6] == currentPlayer))||((places [7] == currentPlayer) && (places [8] ==currentPlayer) && (places[9] == currentPlayer))||((places [1] == currentPlayer) && (places [4] ==currentPlayer) && (places[7] == currentPlayer))||((places [2] == currentPlayer) && (places [5] ==currentPlayer) && (places[8] == currentPlayer))||((places [3] == currentPlayer) && (places [6] ==currentPlayer) && (places[9] == currentPlayer))||((places [1] == currentPlayer) && (places [5] ==currentPlayer) && (places[9] == currentPlayer))||((places [3] == currentPlayer) && (places [5] ==currentPlayer) && (places[7] == currentPlayer))){
        //printf("%c is the winner! Good job!",currentPlayer);
        return 1; 
      }
      else if((places[1]!='1')&&(places[2]!='2')&&(places[3]!='3')&&(places[4]!='4')&&(places[5]!='5')&&(places[6]!='6')&&(places[7]!='7')&&(places[8]!='8')&&(places[9]!='9')){
        //printf("Tie Game!\n");
        return 2;
      }
      else{
        return 0;
      }
    }
    void switchPlayer(){
      if (currentPlayer == 'X'){
        currentPlayer = 'O';
      }
      else if(currentPlayer == 'O'){
        currentPlayer = 'X';
      }
    }
    void playGame(){
      //printBoard();
      printf("\n");
      printf("It is %c's turn! choose a board space from 1-9.\n",currentPlayer);
      int input = -1;
      while ((input < 1)||(input > 9)){
        cin >> input;
        if((input < 1)||(input > 9)){
          printf("your input is invalid! Try again!\n");
        }
      }
      //convert input to char
      char convertedInput = '0' + input;
      if(places[input] == convertedInput){
        places[input] = currentPlayer;
      }
      else{
        printf("Invalid move. Try again.\n");
        switchPlayer();
      }
      printBoard();
      //check win condition
      if (checkWinCondition() != 0){
        return;
      }
      //switch player
      switchPlayer();
    }
};

int main() {
  /*cout << " 1 | 2 | 3 " << endl;
  cout << "-----------" << endl;
  cout << " 4 | 5 | 6 " << endl;
  cout << "-----------" << endl;
  cout << " 7 | 8 | 9 " << endl;*/

  game test1;
  test1.printBoard();
  while(test1.checkWinCondition() == 0){
    test1.playGame();
  }
  if(test1.checkWinCondition() == 1){
    printf("%c is the winner! Good job!",test1.currentPlayer);
  }
  if(test1.checkWinCondition() == 2){
    printf("Tie game!\n");
  }

  return 0;
}