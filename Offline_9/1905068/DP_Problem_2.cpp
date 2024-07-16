#include<iostream>
#include<cstring>

using namespace std;

#define MAX 2e9

int main(){
    int n, mask;
    cin >> n;
    int a[n+1][n+1], dp[1<<n][n+1];


    memset(a, 0, sizeof(a)); // setting the values of the cost 0 initially

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }


    mask = (1<<n) - 1;  //mask for different combinations of visit


    for(int i=0;i<=(1<<n);i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0) dp[i][j] = 0; //here base case is 0 when mask(i) = 0 or current city(j) = 0 as none of the cities are visited
            else dp[i][j] = MAX;  //setting the dp values maximum initially
        }
    }


    for(int curr_mask=1; curr_mask<=mask; curr_mask++){
        for(int curr_city=1; curr_city<=n; curr_city++){

            int vis_mask = curr_mask - (1 << (curr_city - 1));

            if(vis_mask >= 0 && !(vis_mask&(1<<(curr_city-1)))){ //checking the vis_mask is valid and doesn't contain curr_city

                int nw = 0;  // nw -> the extra cost paid to visit curr_city
                for(int k=1; k<=n; k++){
                    if(vis_mask&(1<<(k-1))) nw += a[curr_city][k];
                }

                for(int k=1; k<=n; k++){
                    if(k == curr_city) continue;
                    dp[curr_mask][curr_city] = min(dp[curr_mask][curr_city], dp[vis_mask][k] + nw + a[curr_city][curr_city]);   // the dp[curr_mask][curr_city] will be the minimum of all vis_musk + the total cost to visit curr_city
                }
            }
        }
    }


    int ans = MAX;
    for(int i=1; i<=n; i++) ans = min(ans, dp[mask][i]);   // final answer will be the minimum of dp[mask][i] where i denotes all cities

    cout << ans << endl;

    return 0;
}
