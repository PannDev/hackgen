//? Header Files and namespaces
#include<bits/stdc++.h>
using namespace std;

//? Code Shortners
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define POP pop_back
#define len(s) (int)s.size()
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define PannDev ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define slv solve();

ll mod = 1e9+7;

//? y = hitung Digit
int hitungDigit(int x) {
    int jumlahDigit = 0;
    while (x != 0) {
        x /= 10;
        jumlahDigit++;
    }
    return jumlahDigit;
}

//? sum = sum of each digit of x^y
int sumDigitPow(int x, int y) {
    int sum = 0;

    while (x != 0) {
        int digit = x % 10;
        sum += pow(digit,y);
        x /= 10;
    }

    return sum;
}

// 127 % 10 = 7
// 12 % 10 = 2
// 1 % 10 = 1
// 1 / 10 = 0 (exit)

//? void
void solve() {
    
    int x; cin >> x;

    // y = jumlah digit x
    int y = hitungDigit(x);
    // penjumlahan dari each digit x^y
    int sum = sumDigitPow(x, y); 

    //? Pisi! : Jika x == sum x^y
    //! Nitnot! : x != sum 
    (sum == x) ? cout << "Pisi!\n" : cout << "Nitnot!\n";

    //! 1^3 + 2^3 + 7^3 = 352 != 127
    
}

//! main
int main () { PannDev slv return 0; }
