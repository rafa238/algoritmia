//https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int largestprime(long N){
    long large=0;
    while(N%2==0){
        large=2;
        N=N/2;
        
    }
    for (int i = 3; i <= sqrt(N); i = i + 2){
        while (N % i == 0){
            large=i;
            N = N/i;
        }
    }
    if (N > 2){
        large=N;
    }
    cout<<large<<"\n";
    return 0;
}


int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));
        largestprime(n);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}