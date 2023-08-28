# Project--2-smart-Tic-Tac-Toe
# Text-Based Tic Tac Toe Game

This is a simple text-based implementation of the classic game Tic Tac Toe, written in C. The game is played in the console and offers various play modes, including player vs. player, player vs. computer, and player vs. evil computer. The game also features sound effects for various events.

## Features

- Play Tic Tac Toe on the console.
- Choose from different play modes:
  - Player vs. Player
  - Player vs. Computer
  - Player vs. Evil Computer
- Customize the player's name.
- Sound effects for game events:
  - Winning
  - Losing
  - Drawing
  - Making a move

## Getting Started

1. Clone this repository to your local machine.
```sh Clone the Repository: Open your terminal and clone this repository to your local machine.
git clone https://github.com/devendradhare/Project--2-smart-Tic-Tac-Toe.git
cd tictactoe
```
2. Compile the C code using a C compiler (e.g., GCC).
3. Run the compiled executable to play the game on the console.

```sh
gcc tictactoe.c -o tictactoe
./tictactoe
```

## Gameplay

1. Choose your play mode from the main menu:
   - Use the up ⬆️ and down ⬇️ arrow keys to navigate.
   - Press Enter ⤵️ to select an option.

2. The player with ⭕ makes the first move in the game.
3. The game board is represented as a  3x3 grid, and each cell is numbered from 1 to 9.
4. To make a move, enter the number of the cell you want to mark.
   - For example, entering "1" marks the top-left cell.
5. The game will display the updated board and switch turns between players or computer opponents.
6. The game ends when a player 🏆wins, 🥹loses, or the game is a 🙂draw.
7. 🔊 Sound effects accompany various game events.

## How to Play

- ⬆️⬇️⬅️➡️Use arrow keys to navigate through menus.
- ⤵️Press Enter to select options.
- During 🕹️gameplay, input the cell number to make a move.
- Follow on-screen instructions for various game modes.

## Dependencies

- The code uses standard C 📚libraries such as `<stdio.h>`, `<windows.h>`, `<string.h>`, `<conio.h>`, and `<time.h>`.

## Contributions

Contributions are welcome! If you'd like to contribute to this project, feel free to create a pull request.
