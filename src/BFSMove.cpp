/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#include "BFSMove.h"


void BFSMove::add_to_queue()
{
    DEBUG_PRINT("Preparing for adding new child..\n");
    string key = current_state_obj.get_id();

    if (visit_map.count(key)) 
	{
        DEBUG_PRINT("Child exists! Abort adding\n");
        return;
    }

    State new_state = current_state_obj;
    new_state.increase_step();
    state_queue.push(new_state);
    DEBUG_PRINT("New child added.\n");
}