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
    int n, x; cin >> n >> x;
    vi nums(n); forn(i,n) cin >> nums[i];
    double average = 0;
    forn(i,n){
        average += (double)  nums[i] * (double) (((double) nums[i])/((double)n));
    }
    double c = sqrt(x / average);
    
    forn(i,n - 1){
        printf("%0.9lf ", c * nums[i]);
    }
    printf("%0.9lf\n", c * nums[n-1]);
    
    return 0;
}