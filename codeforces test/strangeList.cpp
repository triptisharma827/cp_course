#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long double x){
    long double square_root = sqrt(x);
    return ((square_root - floor(square_root)) == 0);
}

void solve(){
    int len1;
    cin >> len1;
    int len2;
    cin >> len2;
    vector<pair<int, int>> vec_pair;
    for (int i = 0; i < len1; i++){
        int temp;
        cin >> temp;
        vec_pair.push_back({temp, 1});
    }

    for (int i = 0; i < vec_pair.size(); i++){
        if (vec_pair[i].first % len2 == 0){
            vec_pair.push_back({vec_pair[i].first / len2, len2 * vec_pair[i].second});
        }

        else{
            break;
        }
    }
    int total = 0;
    for (int i = 0; i < vec_pair.size(); i++){
        total += (vec_pair[i].first * vec_pair[i].second);
    }

    cout << total << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        solve();
    }
    return 0;
}