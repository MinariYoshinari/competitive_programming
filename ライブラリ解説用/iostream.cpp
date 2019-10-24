#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); //高速化のおまじない

    // 説明するまでもない
    int n;
    cin >> n;
    cout << n << endl;
    cout << n << "\n"; // 上の行と同じ

    // おまじないをすると以下のコードが意図した通りに動かない可能性がある
    cout << "your age?";
    int age;
    cin >> age;
}