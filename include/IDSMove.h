/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#ifndef IDSMOVE_H
#define IDSMOVE_H

#include <stdio.h>
#include "Move.h"

class IDSMove : public Move
{
    int depth;
public:
    IDSMove(State state_obj, int depth): Move(state_obj){ this->depth = depth;};
    void add_to_queue();
    bool is_legal(int, int);
};



#endif /* defined(IDSMOVE_H) */
