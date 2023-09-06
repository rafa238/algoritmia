#include <bits/stdc++.h>
using namespace std;

int changeTurn(char c){
    switch (c)
    {
    case 'a':
        /* code */
        return 1;
    case 'b':
        /* code */
        return 2;
    case 'c':
        /* code */
        return 3;
    }
    return -1;
}

int main(){
    string sa, sb, sc;
    cin>>sa>>sb>>sc;
    
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    reverse(sc.begin(), sc.end());
    bool finished = false;
    int currTurn = 1;
    char winner;
    while(!finished){
        char next;
        if(currTurn == 1){
            if(sa.empty()){
                winner = 'A';
               finished = true; 
            }
            currTurn = changeTurn(sa.back());
            sa.pop_back();
        } else if(currTurn == 2){
            if(sb.empty()){
                winner = 'B';
               finished = true; 
            }
            currTurn = changeTurn(sb.back());
            sb.pop_back();
        } else if(currTurn == 3){
            if(sc.empty()){
                winner = 'C';
               finished = true; 
            }
            currTurn = changeTurn(sc.back());
            sc.pop_back();
        }
    }
    cout<<winner<<"\n";
    return 0;
}