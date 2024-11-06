#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h> 

using namespace std; 

int const FLOORS = 21;
// this SHOULD update and get new target for where to go if someone entered the elevator and overrides where to next, updating direction
void floorUpdate(string dir, vector<int> in, int cur, int i);

string checkZero(int cur_flor, string dir);

int main(){
    vector<int> in = {3, 13, 4, 7, 9, 18};
    int cur = 0;
    // directions UP and DOWN
    // if at 0 dir auto changed to up
    string dir = 'UP';
// sort in order to get map of where to go
    sort(in.begin(), in.end());
    int target = in.end();
    int count = 0;
    for (int i : in){
        if(dir == 'UP'){
            if(i > cur){
                floorUpdate(string dir, vector<int> in, int cur, int i)
            }
        }
        else if(dir == 'DOWN'){
            if(i < cur){
                floorUpdate(string dir, vector<int> in, int cur, int i) 
            }
        }
        count++;
    }

    return 0;
}

void floorUpdate(string dir, vector<int> in, int cur, int i){
    cur = i;
    // erases floor we just got to
    in.erase(count);
    string newIN = '';
    // checks if person in elevator hit new button, setting it as new direction
    cin >> newIN;
    if (newIn == 'Y'){
        int newFl = 0;
        cin >> newFl;
        in.insert(in.begin(), newFl);
        if(newFl > cur)
            dir = 'UP';
        else
            dir = 'DOWN';
        }
}


string checkZero(int cur_flor, string dir){
    string ret = dir;
    if (cur_flor = 0)
        return ret;
    else
        return ret;
}
