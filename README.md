# RockPaperScissorsLizardSpock
A classic game of Rock, Paper, Scissors, Lizard, Spock
Written in C

Program will take input from user, (s)tart or (e)xit
  - if invalid input will ask again with error message

After start of game, user will be asked for **valid input, integer 0 to 4**,
  - if input != **integer**, error message follows
  - if input = integer but **out of range**, error message follows
  - if input is integer in range (0 - 4), valid input is chosen

- **Robot chooses random shape**
- Result is calculated
- **Scoreboard updated and printed**
- **First to 5 wins**, wins the entire game, and game ends.


Example gameplay:

```
(s) Single player
(e) Exit
Select an item: s
Starting game 🎉
Select a shape:
0🪨  || 1🦎  || 2✂️  || 3🗒️  || 4🖖 :1

Round 1! Best of 9!
You have selected 🦎
Computer chooses ✂️
Robot wins!
SCORE 👫:🤖  0:1
Select a shape:
0🪨  || 1🦎  || 2✂️  || 3🗒️  || 4🖖 :
```
