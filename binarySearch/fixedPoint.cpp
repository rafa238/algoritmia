#include<iostream>

using namespace std;

//Given a list of unique integers nums sorted in ascending order, return the minimum i such that nums[i] == i. If there's no solution, return -1.
int solve(vector<int>& nums) {
    if(nums.size()==0) return -1;
    vector<int> res;
    int l=0, r=nums.size()-1, m=0;

    while(l <= r) {
        m = (r - l) / 2 + l;
        if(nums[m] == m) {
            res.push_back (m);
            r=m-1;
        } else if(nums[m]<m) {
            l=m+1;
        } else {
            r=m-1;
        }
    }
    if(res.size()<=0 ) return -1;
    return res[res.size()-1];
}
