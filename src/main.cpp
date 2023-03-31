#include <iostream>
#include <string>
#include "board.h"
#include "engine_board.h"
#include <cassert>

using namespace std;
string file_name = "./boards/board.txt";

void test_empty_board() {
    Board b(7);
    b.print();
    b.save_board(file_name);
}

void load_board_and_move() {
    Board b(file_name);
    b.make_move(0, 2);
    b.print();
    b.make_move(0, 1);
    assert(b.make_move(0, 2) < 0);
    b.print();
    b.save_board(file_name);
}

void test_engine_board() {
    Engine_Board e(file_name);
    cout << e.get_size() << endl;
}
int main() {
    test_empty_board();
    load_board_and_move();  
    test_engine_board();  
    return 0;
}