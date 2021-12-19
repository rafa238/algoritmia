//Guess the Root
//Given a non-negative integer n, find a number r such that r * r = n and round down to the nearest integer.Can you implement this without using the built-in square root?

int solve(int n) {
    if(n<=1) return n;
    int l=0, r=n, m;
    while(l <= r) {
        m =(int)(r - l) / 2 + l;
        if(m*m <= n){
            l=m+1;
        } else {
            r=m-1;
        }
    }
    return r;
}

int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
