#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

/* Board Details:
Boards are square, size x size 
There are 2 players: x and o. Empty position is represented by a .
Each position at a board is either:
x - represented by 1 in our array
o - represented by -1 in our array
. - represented by 0 in our array 

In board files, the format is:
- first line is the size
- second line is the who's turn
- followed by a space-separated grid of the board
E.g.
3 x
. x o
x o .
o o x
*/

class Board {
public:
  // initialize an empty board
  Board(int board_size=19) {
    size = board_size;
    turn = 1;
    int total = size * size;
    board = new char[total];
    memset(board, 0, total);
  }

  // initialize a board from a file
  Board(string filename) {
    fstream board_file;
    board_file.open(filename, fstream::in);
    if (!board_file.is_open()) {
      cout << "Failed to open file: " << filename << endl;
    }

    string line;

    // get board size
    getline(board_file, line);
    size = stoi(line);

    // get who's turn
    getline(board_file, line);
    if (line[0] == 'x') turn = 1;
    else                turn = -1;

    int total = size * size;
    board = new char[total];
    int i = 0;
    while (getline(board_file, line)) {
      if (line.size() != (2 * size - 1)) {
        return;
      }

      for (int c = 0; c < 2 * size; c += 2) {
        int n;
        if (line[c] == 'x')      n = 1;
        else if (line[c] == 'o') n = -1;
        else if (line[c] == '.') n = 0;
        else {
          cout << "invalid piece marker: " << line[c] << endl;
          return;
        }
        board[i + c/2] = n;
      }

      i += size;
      if (i > total) {
        cout << "Too many squares\n";
        return;
      }
    }

    board_file.close();
  }

  // make move n on board[r,c]
  // TODO: maybe make this virtual
  int make_move(int r, int c) {
    if (r < 0 || r >= size || c < 0 || c >= size) {
      return -1;
    }
    if (board[r * size + c] != 0) {
      return -1;
    }
    board[r * size + c] = turn;
    turn *= -1;
    return 0;
  }

  // save the existing board to a file
  void save_board(string filename) {
    fstream board_file;
    board_file.open(filename, fstream::out | fstream::trunc);
    if (!board_file.is_open()) {
      cout << "Failed to open file: " << filename << endl;
    }

    board_file << size << "\n";
    if (turn == 1) board_file << "x\n";
    else           board_file << "o\n";

    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int n = board[r * size + c];
        if (n == 1)       board_file << "x";
        else if (n == -1) board_file << "o";
        else              board_file << ".";

        if (c == size - 1) board_file << "\n";
        else               board_file << " ";
      }
    }

    board_file.close();
  }

  // print the board to console
  void print() {
    if (turn == 1) cout << "Next Up: x\n";
    else           cout << "Next Up: o\n";
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        int n = board[r * size + c];
        if (n == 1)       cout << "x";
        else if (n == -1) cout << "o";
        else              cout << ".";

        if (c == size - 1) cout << "\n";
        else               cout << " ";
      }
    }
    cout << endl;
  }
  
  // get board size
  int get_size() {
    return size;
  }

  ~Board() {
    delete board;
  }

protected:
  char *board;
  int size;
  char turn;

};
#endif
