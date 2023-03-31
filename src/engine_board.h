#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H

#include "board.h"
class Engine_Board : public Board {
public:
    Engine_Board(int board_size=19) : Board(board_size) {}
    Engine_Board(string filename) : Board(filename) {}
    
    void get_candidate_moves();
    void eval();
};
#endif