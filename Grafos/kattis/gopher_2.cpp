#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int>> g;
vector<int> g_left, g_right;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (g_left[to] == -1 || (!used[g_left[to]] && try_kuhn(g_left[to]))) {
            g_left[to] = v;
            g_right[v] = to;
            return true;
        }
    }
    return false;
}

double distance(pair<double, double> a, pair<double, double> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(){
    int gophers, holes, limitTime, velocity;
     while (scanf("%d %d %d %d", &gophers, &holes, &limitTime, &velocity) == 4){
        g.resize(gophers, vector<int>());
        vector<pair<double, double>> holesV(holes), gophersV(gophers);
        double max_distance = limitTime * velocity;
        max_distance *= max_distance; // Cuadrado de la distancia máxima

        for(int i=0; i<gophers; i++){
            double x, y;
            cin>>x>>y;
            gophersV[i] = make_pair(x, y);
        }

        for(int i=0; i<holes; i++){
            double x, y;
            cin>>x>>y;
            holesV[i] = make_pair(x, y);
        }

        for(int h = 0; h < gophers; h++){
            for(int ho = 0; ho < holes; ho++){
                if(distance(gophersV[h], holesV[ho]) <= max_distance){
                    g[h].push_back(ho);
                }
            }
        }

        g_left.assign(holes, -1);
        g_right.assign(gophers, -1);
        int unmatched = 0;
        for (int v = 0; v < gophers; ++v) {
            used.assign(gophers, false);
           try_kuhn(v);
        }
        for(int i=0; i<g_right.size(); i++){
            if(g_right[i] == -1){
                unmatched++;
            }
        }
        cout << unmatched << "\n"; // Gophers vulnerables
    }

    return 0;
}