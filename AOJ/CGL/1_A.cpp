#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const LL MOD = 1000000007;
const double EPS = 1e-9;

struct Point{
    double x, y;
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
}

struct Line{
    Point p, q;
    double x, y, norm, grad;

    Line(Point p, Point q){
        this->p = p;
        this->q = q;
        x = q.x - p.x;
        y = q.y - p.y;
        grad = y / x;
        norm = sqrt(x*x + y*y);
    }
}

double inner_product(Line a, Line b){
    return a.x*b.x + a.y*b.y;
}

double cosine(Line a, Line b){
    return inner_product/(a.norm*b.norm);
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);

    int n;
    double x,y;
    Point p[2];
    rep(2){
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    Line a = Vecotr(p[0], p[1]);

    cin >> n;

    rep(n){
        double x, y;
        cin >> x >> y;
        Line b = Line(p[0], Point(x, y));
        double abcos = cosine(a, b);
        double c_norm = b.norm + abcos;
        cout << c_norm << endl;
    }

}
