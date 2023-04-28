#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// binaria clasica -> boolean
bool bs(vector<int>& a, int t, int l, int r) {
  if(l > r) return false;

  int m = (r - l) / 2 + l;

  if(a[m] == t) {
    return true;
  } else

  if(a[m] > t) {
    return bs(a, t, l, m - 1);
  } else

  if(a[m] < t) {
    return bs(a, t, m + 1, r);
  }
}

// lower bound -> posicion
int bsLower(vector<int>& a, int t, int l, int r) {
  if(l > r) return l;

  int m = (r - l) / 2 + l;

  if(a[m] == t) {
    return bs(a, t, l, m - 1);
  } else if(a[m] > t) {
    return bs(a, t, l, m - 1);
  } else if(a[m] < t) {
    return bs(a, t, m + 1, r);
  }
}

// upper bound -> posicion
int bsUpper(vector<int>& a, int t, int l, int r) {
  if(l > r) return l;

  int m = (r - l) / 2 + l;

  if(a[m] == t) {
    return bs(a, t, m + 1, r);
  } else if(a[m] > t) {
    return bs(a, t, l, m - 1);
  } else if(a[m] < t) {
    return bs(a, t, m + 1, r);
  }
}

int lowerBound(vector<ll> &v, ll target){
    ll mid,  l = 0, r = v.size() - 1;
    while(l < r){
        mid = (l+r)/2;
        if(target <= v[mid]){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int upperBound(vector<int> &v, int target){
    int mid,  l = 0, r = v.size() - 1;
    while(l < r){
        mid = (l+r)/2;
        if(target < v[mid]){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main(){
  vector<int> v = {1,4,5,6,7};
  int idx = (v, 2)-1;
  cout<<idx;
  return 0;
}