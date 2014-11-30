/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include "State.h"
using namespace std;

class Move
{
protected:
    State current_state_obj;
    
public:
    Move(State);
    
    void generate_all_move();
    int calculate_distance(State &);
    virtual int do_calculate(int, int, State){return 0;};
    virtual void add_to_queue(){};
    virtual bool is_legal(int x, int y);
};

extern queue<State> state_queue;
extern string ArrayToString(int [][3]);

extern map<string, bool> visit_map;
    
#endif /* defined(MOVE_H) */
