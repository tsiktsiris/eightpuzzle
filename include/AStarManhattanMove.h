/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#ifndef ASTARMANHATTANMOVE_H
#define ASTARMANHATTANMOVE_H

#include <stdio.h>
#include "Move.h"

class AStarManhattanMove : public Move
{
    int depth;
public:
    AStarManhattanMove(State state_obj): Move(state_obj){};
    void add_to_queue();
    int do_calculate(int, int, State);
    bool is_legal(int, int);
};

#endif /* defined(ASTARMANHATTANMOVE_H) */
