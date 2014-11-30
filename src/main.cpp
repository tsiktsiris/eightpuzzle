/**
	8 Puzzle Solver using BFS,IDS & AStar
	Assignment 01 @ Artificial Intelligence
	Dimitris Tsiktsiris - University Of Western Macedonia
**/

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <array>
#include <stack> 
#include <vector>
#include <time.h>
#include <cstdlib>      // std::rand, std::srand
#include <algorithm>
#include "State.h"


using namespace std;

//Define functions
string ArrayToString(int arr[][3]);
void read_default_state();
void read_random_state();
int read_search_mode();
int run_search(int);
int run_uninformed_bfs();
int run_interactive_deepening_search();
int run_a_star_search(int);
void update_statistics(int, int & );

//Global variables
//int init_state_for_test[3][3]  = {1,3,4,8,6,2,7,0,5}; //Easy
int init_state_for_test[3][3]  = {2,8,1,4,6,3,0,7,5}; //Hard

int State::goal_state[][3] = {1,2,3,8,0,4,7,6,5};
int init_state[3][3];
map<string, bool> visit_map;
queue<State> state_queue;
stack<State> state_stack;
priority_queue<State, std::vector<State>, GreaterThanByCost > state_priority_queue;


int main(int argc, const char * argv[]) 
{
	
    //read_default_state();
	int n = 2;

	int *statistics_bfs, *statistics_ids, *statistics_astar;
	statistics_bfs = new int[n];
	statistics_ids = new int[n];
	statistics_astar = new int[n];

	for(int idx = 0; idx < n; idx++)
	{
		cout << "Running case " << idx + 1 << " of " << n <<endl<<endl;

		read_random_state();

		cout << "Default state is " << ArrayToString(init_state) << endl;
		cout << "Goal state is " << ArrayToString(State::goal_state) << endl << endl;

		cout << "[*] Running an Uninformed breadth-first search..." << endl;
		update_statistics(run_uninformed_bfs(),statistics_bfs[n]);

		cout << "[*] Running an Iterative Deepening search..." << endl;
		update_statistics(run_interactive_deepening_search(),statistics_ids[n]);

		cout << "[*] Running A* with Manhattan distance as heuristic..." << endl;
		update_statistics(run_a_star_search(A_MANHATTAN_MODE),statistics_astar[n]);

		system("CLS");
	}

	int bfs_total = 0, bfs_counter = 0;
	int ids_total = 0, ids_counter = 0;
	int astar_total = 0, astar_counter = 0;

	for(int idx = 0; idx < n; idx++)
	{
		if(statistics_bfs[n] != 0)  
		{
			bfs_total += statistics_bfs[n];
			bfs_counter++;
		}

		if(statistics_ids[n] != 0)
		{
			ids_total += statistics_ids[n];
			ids_counter++;
		}

		if(statistics_astar[n] != 0)
		{
			astar_total += statistics_astar[n];
			astar_counter++;
		}
	}
	
	cout << "RESULTS" << endl << endl;

	cout << "BFS Average Steps: " << bfs_total / bfs_counter << endl;
	cout << "BFS solving ratio: " << bfs_counter / n << "% (" << bfs_counter<<" of " << n << ")" << endl << endl;

	cout << "IDS Average Steps: " << ids_total / ids_counter << endl;
	cout << "IDS solving ratio: " << ids_counter / n  << "% (" << ids_counter<<" of " << n << ")" << endl << endl;

	cout << "AStar Average Steps: " << astar_total / astar_counter << endl;
	cout << "Astar solving ratio: " << astar_counter / n << "% ("<<astar_counter<<" of " << n << ")" << endl << endl;

	system("PAUSE");
    return 0;
    
}

void update_statistics(int result,  int &sta)
{
	if(result) 
	{
		cout << "Path found: " << ArrayToString(State::goal_state) << endl;
		cout << "Number of steps: " << result << endl;
	}
	else
		cout << "Solution not found" << endl;

	cout << endl;
	sta = result;
}



string ArrayToString(int arr[][3])
{
    string str;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j<3; j++)
            str += to_string(arr[i][j]);

    return str;
}


void read_random_state()
{
	std::srand ( unsigned ( time(0) ) );
	std::vector<int> myvector;

	// set some values:
	for (int i=0; i<=8; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

	// using built-in random generator:
	std::random_shuffle ( myvector.begin(), myvector.end() );

	std::vector<int>::iterator it = myvector.begin();

		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
			{
				init_state[i][j] = *it;
				*it++;
				DEBUG_PRINT(init_state[i][j]);
			}
}

void read_default_state()
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
		{
            init_state[i][j] = init_state_for_test[i][j];
            DEBUG_PRINT(init_state[i][j]);
        }
}

int run_uninformed_bfs()
{
    State init_state_object = State(init_state);
    state_queue.push(init_state_object);
    
    while (!state_queue.empty())
	{
        State current_state_obj = state_queue.front();
        state_queue.pop();
        
        if (current_state_obj.check_goal_state() == true)
            return current_state_obj.get_steps();
        else
		{
            visit_map[current_state_obj.get_id()] = true;
            current_state_obj.generate_candidate(UNINFORMED_BFS_MODE);
        }
    }

    DEBUG_PRINT("Queue exhausted..\n");
    return 0;
}

int run_interactive_deepening_search()
{

    int depth = 1;
    while (depth < 25)
	{
        State init_state_object = State(init_state);
        state_stack.push(init_state_object);
        
        while (!state_stack.empty())
		{
            State current_state_obj = state_stack.top();
            state_stack.pop();
            
            if (current_state_obj.check_goal_state() == true)
                return current_state_obj.get_steps();
            else
			{
                visit_map[current_state_obj.get_id()] = true;
                current_state_obj.generate_candidate(IDS_MODE, depth);
            }
        }
        visit_map.clear();
        depth++;

        DEBUG_PRINT("current depth:");
        DEBUG_PRINT(depth);
        DEBUG_PRINT(endl);
    }
    
    DEBUG_PRINT("Stack exhausted..\n");
    return 0;
}
int run_a_star_search(int search_mode)
{
    int checked = 0;
    State init_state_object = State(init_state);
    state_priority_queue.push(init_state_object);
    
    while (!state_priority_queue.empty())
	{
        checked ++;
        State current_state_obj = state_priority_queue.top();
        state_priority_queue.pop();
        DEBUG_PRINT("New state object from priority queue with cost: ");
        DEBUG_PRINT(current_state_obj.get_cost());
        DEBUG_PRINT(endl);
        
        if (current_state_obj.check_goal_state() == true)
		{
            DEBUG_PRINT("Number of nodes checked:");
            DEBUG_PRINT(checked);
            DEBUG_PRINT(endl);
            
            return current_state_obj.get_steps();
            
        }
        else
		{
            visit_map[current_state_obj.get_id()] = true;
            current_state_obj.generate_candidate(search_mode);
        }
    }

    DEBUG_PRINT("Queue exhausted..\n");
    return 0;
};
