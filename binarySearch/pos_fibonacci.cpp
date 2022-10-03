#include <iostream>

int bs(int fibo[], int n){
    int l=0, r=(n+5)-1;
    while(l <= r){
        int t = (r + l)/2;
        if(fibo[t] == n){
            return t+1;
        } else if(fibo[t] < n){
            l = t+1;
        } else {
            r = t-1;
        }
    }
    return 0;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n; std::cin>>n;
    int arr[n+5];
    std::cout<<bs(arr, n)-1;

    return 0;
}