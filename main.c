#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>



const char *startMenu =
"Welcome to 🪨  ✂️  🗒️  🖖  🦎 !\n"
"(s) Single player\n"
"(e) Exit\n"
"Select an item: ";


typedef enum 
{
  e,
  s, 
  select_count
} menuSelect;


const char *selectShape = 
"Select a shape:\n"
"0🪨  || 1🦎  || 2✂️  || 3🗒️  || 4🖖 :";

char *resultString = 
"Agent: %d"
"👫:🤖  %d:%d";



typedef enum 
{
  ROCK,
  LIZARD,
  SCISSORS,
  PAPER,
  SPOCK,
  SHAPE_COUNT //SHAPE_COUNT is the length of shapes enum
} shapes;



//Alle muligheder i spillet:
const char *shapeArray[6] = 
{
  [0]=  "🪨",
  [1] = "🦎", 
  [2] = "✂️", 
  [3] = "🗒️", 
  [4] = "🖖",
  [5] = NULL
};

int robot_choice = 0;
int win_counter_player = 0;
int win_counter_robot = 0;
int round_counter = 0;
int input_selectShape;

int get_player_input(void)
{
  int choice;  
  while(1){
    printf("%s",selectShape);
    if (scanf("%d",&choice) != 1) //Problem going on because scanf is not an int as we expect
    {
    printf("Input not an integer! Please enter valid integer between 0 and 4!\n");
    int c;
    while((c = getchar()) != '\n' && c != EOF){} //flushing bad input from buffer
    continue; 
    }
    else if(choice >= 0 && choice < SHAPE_COUNT)
     {
      return choice;
     }
    else
     {
      printf("❌ Invalid input, try again.\n");
      continue;
     }

  }
}



void scoreboard(void)
{
printf("SCORE 👫:🤖  %d:%d\n",win_counter_player,win_counter_robot);
};
//PLAYER VERSUS ROBOT RESULTTABLE PLAYER IS THE ROW, ROBOT IS THE COLOUM
// 1 IS PLAYER WIN -1 IS ROBOT WIN, 0 IS TIE
int resultTable[SHAPE_COUNT][SHAPE_COUNT] =
{  
 //PLAYER/ROBOT             R      L      S      P     SPOCK
 /*ROCK    */     { 0, 1, 1,-1,-1},
 /*LIZARD  */     {-1, 0,-1, 1, 1},
 /*SCISSORS*/     {-1, 1, 0, 1,-1},
 /*PAPER   */     { 1,-1,-1, 0, 1},
 /*SPOCK   */     { 1,-1, 1,-1, 0}
};

void outcome(int player, int robot){
int result = resultTable[player][robot];

  switch(result)
    {
      case 1:
      printf("Player wins!\n");
      win_counter_player++;
      round_counter++;
      scoreboard();
      
      break;

      case -1:
      printf("Robot wins!\n");
      win_counter_robot++;
      round_counter++;
      scoreboard();
      break;

      case 0:
      printf("Tie!\n");
      round_counter++;
      scoreboard();
      break;
    }
}

int main(){

srand((unsigned)time(NULL)); //seeding the RNG

char input_selectMenu;

while(1)
{
  printf("%s",startMenu);
  scanf(" %c",&input_selectMenu);
  if(tolower((unsigned char)input_selectMenu) == 's')
  {
    printf("Starting game 🎉\n");
    break;
  }
  if(tolower((unsigned char)input_selectMenu)=='e')
  {
    printf("Exiting game!\n");
    return 0; // return 0; in order to escape both while loops and exit program completely as both are while(1)
  }
  else {
    printf("❌ Shape key %c does not exist. Try again.",input_selectMenu);   
  };
}

while(1)
{
  input_selectShape = get_player_input();
  printf("\nRound %d! Best of 9!\n",round_counter+1);
  shapes player = (shapes)input_selectShape;
  shapes robot = (shapes)(rand() % SHAPE_COUNT);
  printf("You have selected %s\n",shapeArray[player]);
  printf("Computer chooses %s\n",shapeArray[robot]);
  
  outcome(player, robot);

  if(win_counter_player >= 5)
  {
    printf("PLAYER WINS! %d to %d, congratulations!\n",win_counter_player, win_counter_robot);
    break;
  }
  else if (win_counter_robot >= 5)
  {
    printf("ROBOT WINS! %d to %d, try again!",win_counter_player, win_counter_robot);
    break;
  }  
};
};