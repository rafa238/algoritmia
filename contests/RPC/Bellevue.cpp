#include <bits/stdc++.h>

#define endl '\n'
#define ll long long 
#define lli long long int
#define ld long double
#define fore(i,a,b) for (int i = a; i < b; i++)
#define forr(i,a,b) for (int i = a; i > b; i--)
#define forn(i,n) for (int i = 0; i < n; i++)
#define fi first
#define se second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef pair<ll, ll>  pll;
typedef pair<int, int>  pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef map<int, int> mii;

const int inf = 1<<30;


int main() {
    fast_io;
    int n; cin >> n;
    vector<pair<double, double>> coord(n); forn(i,n) cin >> coord[i].fi >> coord[i].se ;
    
    double theta = 0;
    fore(i,1,n){
        theta = max( theta, (double)(coord[i].se / (coord[i].fi - coord[0].fi)) );
    }
    forr(i, n-2, 0 ){
        theta = max( theta, (double)(coord[i].se / (coord[n-1].fi - coord[i].fi)));
    }
    printf("%0.9lf", atan(theta) * 180 / (3.141592653589793238462643383279502884));
    return 0;
}