/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#include "IDSMove.h"


void IDSMove::add_to_queue()
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
    state_stack.push(new_state);
    DEBUG_PRINT("New child added.\n");
}


bool IDSMove::is_legal(int x, int y)
{
    if (current_state_obj.get_steps() > depth) return false;
    if (x >= 0 & x <=2 & y >=0 & y <=2) return true;
    else return false;
}