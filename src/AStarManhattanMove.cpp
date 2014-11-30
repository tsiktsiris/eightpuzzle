/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#include "AStarManhattanMove.h"

void AStarManhattanMove::add_to_queue()
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
    calculate_distance(new_state);
    state_priority_queue.push(new_state);
    DEBUG_PRINT("New child added.\n");
}


bool AStarManhattanMove::is_legal(int x, int y)
{
    if (x >= 0 && x <=2 && y >=0 && y <=2) return true;
    else return false;
}

int AStarManhattanMove::do_calculate(int x, int y, State state_obj)
{
    int dist = -1;

    switch ((state_obj.current_state)[x][y]) 
	{
        case 1:
            return dist = abs(x-0) + abs(y-0);
        case 2:
            return dist = abs(x-0) + abs(y-1);
        case 3:
            return dist = abs(x-0) + abs(y-2);
        case 8:
            return dist = abs(x-1) + abs(y-0);
        case 0:
            return dist = abs(x-1) + abs(y-1);
        case 4:
            return dist = abs(x-1) + abs(y-2);
        case 7:
            return dist = abs(x-2) + abs(y-0);
        case 6:
            return dist = abs(x-2) + abs(y-1);
        case 5:
            return dist = abs(x-2) + abs(y-2);
        default:
            break;
    };

    return dist;
}