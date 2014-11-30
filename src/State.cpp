/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#include "State.h"
#include "Move.h"
#include "MoveFactory.h"

State::State()
{
    this->steps = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j<3; j++)
            this->current_state[i][j] = 0;

    this->x = 0;
    this->y = 0;
    this->cost = 0;
}

State::State(int initial_state[][3], int steps)
{
    this->steps = steps;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j<3; j++)
		{
            this->current_state[i][j] = initial_state[i][j];
            if (initial_state[i][j] == 0)
            {   x = i;
                y = j;
            }
        }
}

bool State::check_goal_state() 
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (current_state[i][j] != goal_state[i][j])
                return false;

    return true;
};

int State::get_steps()
{
    return this->steps;
}

string State::get_id()
{
    return ArrayToString(current_state);
}

void State::generate_candidate(int mode, int depth)
{
    DEBUG_PRINT("Generating candidates..\n");
    MoveFactory move_factory = MoveFactory(mode);
    Move* move = move_factory.generate_move(*this, depth);
    move->generate_all_move();
}

void State::swap_array(int x1, int y1, int x2, int y2)
{
    int temp = current_state[x1][y1];
    current_state[x1][y1] = current_state[x2][y2];
    current_state[x2][y2] = temp;
    update_position(x2, y2);
}

void State::update_position(int new_x,int new_y)
{
    this->x = new_x;
    this->y = new_y;
}


