#include <iostream>

int bs(int G, int *autos, int N){
    int l = 0, r = N-1;
    int m;
    while(l <= r){
        m = (l+r)/2;
        if(autos[m] == G){
            return m+1;
        } else if(autos[m] < G){
            l = m +1;
        } else if(autos[m] > G){
            r = m - 1;
        }
    }
    return m;
}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int Q, N;
    std::cin >> Q >> N;
    int autos[N];
    int sum=0;
    for (int i = 0; i < N; i++){
        int num; std::cin>>num;
        sum += num;
        autos[i] = sum;
    }
    while(Q--){
        int G;
        std::cin>>G;
        int ans = bs(G, autos, N);
        std::cout<< ans <<" " << G - autos[ans-1]<<std::endl;
    }   
    return 0;
}