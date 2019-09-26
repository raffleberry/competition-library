#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
    pt(double _x, double _y): x(_x), y(_y) {};
    bool operator<(const pt &rhs) const {
        return (x < rhs.x || (x == rhs.x && y < rhs.y));
    }
};

double dis(pt a, pt b) {
    return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) );
}

int turn(pt a, pt b, pt c) {
    double pred = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
    if(pred > 0.0) return 1;//cckw
    if(pred < 0.0) return -1;//ckw
    return 0;//cl
}

int n;
vector<pt> in;
vector<pt> out;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        in.emplace_back(a, b);
    }

    sort(begin(in), end(in));
    
    //lower hull
    for(int i = 0; i < n; i++) {
        while(out.size() >= 2 && turn(out[out.size() - 2], out[out.size() - 1], in[i]) <= 0) {
            out.pop_back();
        }
        out.push_back(in[i]);
    }

    //upper hull
    int lim = out.size();
    for(int i = n - 1; i >= 0; i--) {
        while(out.size() > lim && turn(out[out.size() - 2], out[out.size() - 1], in[i]) <= 0) {
            out.pop_back();
        }
        out.push_back(in[i]);
    }

    double per = 0.0;

    for(int i = 0; i < out.size(); i++) {
        per += dis(out[i], out[(i + 1) % out.size()]);
    }
    printf("%.9lf\n", per);    
    return 0;
}
