/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <string>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define DEBUG_MODE 0
#define UNINFORMED_BFS_MODE 1
#define IDS_MODE 2
#define A_MANHATTAN_MODE 3

#if (DEBUG_MODE)
#define DEBUG_PRINT(str) std::cout << str
#else
#define DEBUG_PRINT(str) ;
#endif


class State 
{

    int steps;
    int x;
    int y;
    int cost;
    
public:
    int current_state[3][3];
    static int goal_state[3][3];
    int key;
    
    void swap_array(int, int, int, int);
    State();
    State(int [][3], int = 0);
    bool check_goal_state();
    void generate_candidate(int = 0, int = 0);
    int get_steps();
    string get_id();
    int get_cost() const { return this->cost;};
    void set_cost(int cost){ this->cost = cost;};
    int get_x() const {return x;};
    int get_y() const {return y;};
    void increase_step(){ this->steps ++;};
    void update_position(int new_x,int new_y);
};

struct GreaterThanByCost
{
    bool operator()(const State& lhs, const State& rhs) const
    {
        return lhs.get_cost() > rhs.get_cost();
    }
};

extern queue<State> state_queue;
extern string ArrayToString(int [][3]);
extern map<string, bool> visit_map;
extern stack<State> state_stack;
extern priority_queue<State, std::vector<State>, GreaterThanByCost > state_priority_queue;

#endif /* defined(STATE_H) */
