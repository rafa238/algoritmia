#include <iostream>
using namespace std;

long long calculate_black_area(long long A, long long B, long long C, long long D) {
    long long black_area = 0;
    
    for (long long x = A; x < C; ++x) {
        for (long long y = B; y < D; ++y) {
            // Determina si la celda (x, y) está pintada de negro
            if ((x % 2 == 0 && y % 2 == 0) || (x % 2 == 1 && y % 2 == 1)) {
                black_area++;
            }
        }
    }
    
    return black_area;
}

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    
    cout << calculate_black_area(A, B, C, D) << endl;
    return 0;
}