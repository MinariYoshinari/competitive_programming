#include<utility> // この行はなくても動く
#include<iostream>
#include<vector>

using namespace std;

int main(){
    pair<int, char> p(1, 'A'); // pairの宣言
    cout << p.first << p.second << "\n"; // first, secondでアクセスできる

    vector< pair<int, int> > v;
    v.push_back(make_pair(1, 2)); // vectorの最後に追加
    v.emplace_back(2, 1); // emplace_backを使うと最後に追加するときのタイプ数がちょっと減る
    v.emplace_back(1, 1);

    sort(v.begin(), v.end()); // pairの各要素に大小関係があればソートもできる
    for(int i=0;i<(int)v.size();i++){
        cout << v[i].first << v[i].second << "\n";
    }

}