#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string x, y;
    cin >> x >> y;

    // increasing size 1 of the input strings to set the base case 0
    x = "#" + x;
    y = "#" + y;

    int n = x.size(), m = y.size();
    // way -> used for backtracking the result
    int dp[n][m], way[n][m];

    for(int i=0; i<m; i++) {
        dp[0][i] = 0;
        way[0][i] = 0;
    }
    for(int i=0; i<n; i++) {
        dp[i][0] = 0;
        way[i][0] = 0;
    }

    // 3 dp transitions based on current character
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(x[i] == y[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                way[i][j] = 1;
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                way[i][j] = 2;
            }
            else{
                dp[i][j] = dp[i][j-1];
                way[i][j] = 3;
            }
        }
    }

    int ans = dp[n-1][m-1];
    string f;
    int n1 = n-1, m1 = m-1;

    // backtracking the optimal string
    while(1){
        if(way[n1][m1] == 1) {
            f.push_back(x[n1]);
            m1--;
            n1--;
        }
        else if(way[n1][m1] == 2) {
            n1--;
        }
        else if(way[n1][m1] == 3) {
            m1--;
        }
        else break;
    }

    reverse(f.begin(), f.end());

    cout << ans << endl;
    cout << f << endl;
}
