#include <bits/stdc++.h>
#define fastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
 
#define N 10000000 
vector<bool> is(N+1, true);
 
vector<int> primesSieve()
{
    vector<int> primes = {2}; 
    is[0] = is[1] = false; 
    for(int i = 4; i <= N; i += 2)
        is[i] = false; 
    for(int i = 3; i <= N; i += 2)
    {
        if(is[i])
        {
            primes.push_back(i); 
            if((ll)i*i <= N)
            {
                for(int j = i*i; j <= N; j += 2*i)
                    is[j] = false; 
            }
        }
    }
 
    return primes; 
}
 
int main(){
    fastIO();
    vector<int> primes = primesSieve();
 
    int t; 
    cin >> t; 
    while(t--){
        ll a, b; 
        cin >> a >> b;  
        ll temp = a + b;
        bool flag = true; 
        if(temp > 10000000)
        {
            for(int j = 0; j < primes.size(); j++)
            {
                if(temp % primes[j] == 0)
                {
                    flag = false; 
                    break;
                }
            }
        }
        else if(!is[temp]) flag = false; 
 
        if((a - b == 1) && flag)
            cout << "YES\n";
        else 
            cout << "NO\n"; 
    }
    return 0;
}