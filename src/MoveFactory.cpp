/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#include "MoveFactory.h"

using namespace std;

MoveFactory::MoveFactory(int mode)
{
    this->mode  = mode;
};

Move* MoveFactory::generate_move(State state_obj, int depth)
{
    switch (mode) 
	{
        case UNINFORMED_BFS_MODE:
		{
            BFSMove* move = new BFSMove(state_obj);
            return move;
        }
        case IDS_MODE:
		{
            IDSMove* move = new IDSMove(state_obj, depth);
            return move;
        }
        case A_MANHATTAN_MODE:
		{
            AStarManhattanMove* move = new AStarManhattanMove(state_obj);
            return move;
        }
        default:
		{
            Move* move = new Move(state_obj);
            return move;
        }
    }
}