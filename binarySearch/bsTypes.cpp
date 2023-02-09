#include <bits/stdc++.h>
using namespace std;

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
