/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#include "Move.h"

Move::Move(State new_state)
{
    current_state_obj = new_state;
    DEBUG_PRINT("Initializing move object..\n");
}

void Move::generate_all_move()
{
    DEBUG_PRINT("Generating all moves..\n");
    int x = current_state_obj.get_x();
    int y = current_state_obj.get_y();
    
    if (is_legal(x+1,y)) 
	{
        current_state_obj.swap_array(x, y, x+1, y);
        add_to_queue();
        current_state_obj.swap_array(x, y, x+1, y);
    }
    if (is_legal(x-1,y)) 
	{
        current_state_obj.swap_array(x, y, x-1, y);
        add_to_queue();
        current_state_obj.swap_array(x, y, x-1, y);
    }
    if (is_legal(x,y+1)) 
	{
        current_state_obj.swap_array(x, y, x, y+1);
        add_to_queue();
        current_state_obj.swap_array(x, y, x, y+1);
    }
    if (is_legal(x,y-1)) 
	{
        current_state_obj.swap_array(x, y, x, y-1);
        add_to_queue();
        current_state_obj.swap_array(x, y, x, y-1);
    }
    return;
}

int Move::calculate_distance(State & state_obj)
{
    int total_distance = state_obj.get_steps();

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            total_distance += do_calculate(i,j, state_obj);

    state_obj.set_cost(total_distance);
    return total_distance;
}

bool Move::is_legal(int x, int y)
{
    if (x >= 0 && x <=2 && y >=0 && y <=2) 
		return true;
    else 
		return false;
}


