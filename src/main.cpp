#include <iostream>
#include <string>
#include "board.h"

using namespace std;
string file_name = "./boards/board.txt";

void test_empty_board() {
    Board b = Board(7);
    b.print();
    b.save_board(file_name);
}

void load_board_and_move() {
    Board b = Board(file_name);
    b.make_move(0, 2, 1);
    b.print();
    b.make_move(0, 1, -1);
    b.make_move(0, 2, 0);
    b.print();
    b.save_board(file_name);
}

int main() {
    test_empty_board();
    load_board_and_move();    
    return 0;
}