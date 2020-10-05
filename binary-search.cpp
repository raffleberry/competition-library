#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool p(...) {
    //predicate
}

// Just remember to always test your code on a two-element set
// where the predicate is false for the first element and true for the second
int main() {
    int lo = , hi = ;
    
    while (lo < hi) {
        int m = lo + (hi - low + 1)>>1;
        if (p(m)) {
            lo = m;
        } else {
            hi = m-1;
        }
    }
    if (p(lo) == false) // p(x) is false for all values
    cout << lo << endl;
    //TTTTT T FFFFFFFF // this is kind of difficult
   //       *
    
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (p(m)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << lo << endl;
    //FFFFFF T TTTTTT
    //       *       
    if (lo == hi && p(lo)) {
        //ans = lo
    } else {
        //ans doesn't exist
    }
    
    //over real numbers
    double EPS = 1e-10, lo = -1000.0, hi = 1000.0;
    
    while (hi - lo > EPS) {
        double mid = (lo + hi) / 2.0;
        if (p(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return 0;
}
