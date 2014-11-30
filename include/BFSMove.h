/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#ifndef BFSMOVE_H
#define BFSMOVE_H

#include <stdio.h>
#include "Move.h"

class BFSMove : public Move
{

public:
    BFSMove(State state_obj): Move(state_obj){};
    void add_to_queue();

};



#endif /* defined(BFSMOVE_H) */
