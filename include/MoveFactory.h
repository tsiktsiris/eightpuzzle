/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H

#include <stdio.h>
#include "Move.h"
#include "State.h"
#include "BFSMove.h"
#include "IDSMove.h"
#include "AStarManhattanMove.h"

using namespace std;

class MoveFactory
{
    int mode;
public:
    MoveFactory(int);
    Move* generate_move(State, int = 0);
};

#endif /* defined(MOVEFACTORY_H) */
