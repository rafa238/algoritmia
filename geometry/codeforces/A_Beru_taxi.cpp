#include<bits/stdc++.h>
using namespace std;
struct point{
    double x, y;
    point(){x = y = 0;}
    point(double _x, double _y): x(_x), y(_y){}
};

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y-p2.y);
};

int main(){
    double X, Y, V, n;
    cin>>X>>Y>>n;
    point vasily = point(X, Y);
    double betterDist = 10e15;
    while(n--){
        cin>>X>>Y>>V;
        point taxi = point(X, Y);
        betterDist = min(dist(vasily, taxi)/V, betterDist);
    }
   cout << fixed << setprecision(10)<<betterDist;
    return 0;
}