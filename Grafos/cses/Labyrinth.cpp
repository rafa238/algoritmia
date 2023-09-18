#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> visited;


struct Node {
    int x, y;
    string direction;
    Node(int x, int y, string d) : x(x), y(y), direction(d) {};
    Node() {};
};

vector<vector<Node>> trackP;
int r, c;
int si, sj, ei, ej;

void bfs() {
    queue<Node> q;
    q.push(Node(si, sj, ""));
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        
        if(visited[curr.x][curr.y]) 
            continue;
        visited[curr.x][curr.y] = true; 
        if (grid[curr.x][curr.y] == '#') 
            continue;
        
        if(curr.x + 1 < r && !visited[curr.x +1][curr.y]) {
            q.push(Node(curr.x + 1, curr.y, ""));
            trackP[curr.x+1][curr.y] = curr;
            
        }
        if(curr.x - 1 >= 0 && !visited[curr.x -1][curr.y]) {
            q.push(Node(curr.x - 1, curr.y, "0"));
            trackP[curr.x-1][curr.y] = curr;
        }
        if(curr.y + 1 < c && !visited[curr.x][curr.y+1]) {
            q.push(Node(curr.x, curr.y + 1, "0"));
            trackP[curr.x][curr.y+1] = curr;
        }
        if(curr.y - 1 >= 0 && !visited[curr.x][curr.y-1]) {
            q.push(Node(curr.x, curr.y - 1, "0"));
            trackP[curr.x][curr.y-1] = curr;
        }
    }
}
string s;
void buildAns(int x, int y){
    if(x == -1){
        return;
    }
    int currPx = trackP[x][y].x;
    int currPy = trackP[x][y].y;
    if(currPx < x ){
        s += "D";
    }
    else if(currPx > x ){
        s += "U";
    }
    else if(currPy < y ){
        s += "R";
    }
    else if(currPy > y ){
        s += "L";
    }
    buildAns(trackP[x][y].x, trackP[x][y].y);
}

int main() {
    cin >> r >> c;
    grid.resize(r, vector<char>(c));
    visited.resize(r, vector<bool>(c, false));
    trackP.resize(r, vector<Node>(c, Node(-1, -1, "0"))); // Redimensionar como una matriz de edger

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                si = i;
                sj = j;
            } else if (grid[i][j] == 'B') {
                ei = i;
                ej = j;
            }
        }
    }
    s = "";
    bfs();
    buildAns(ei, ej);

    cout << ((s.size() > 1) ? "YES" : "NO")<<endl;

    if(s.size() > 1){
        s.pop_back();
        cout << s.size() << endl;
        reverse(s.begin(), s.end());
        cout << s;
    }
    
    return 0;
}
