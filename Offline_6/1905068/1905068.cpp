#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t ;

    while(t--){
        int n, x, l, s;
        cin >> n >> x;
        vector<int> path, vis(x+1), ladder(x+1), snake(x+1);

        for(int i=1; i<=x; i++){
            vis[i] = 0;
            ladder[i] = 0;
            snake[i] = 0;
        }
        cin >> l;
        for(int i=0; i<l; i++){
            int a, b;
            cin >> a >> b;
            ladder[a] = b;
        }
        cin >> s;
        for(int i=0; i<s; i++){
            int a, b;
            cin >> a >> b;
            snake[a] = 1;
        }

        // vis[i] == 0 means there is a snake head in that cell. vis[i] == -1 mean unvisited cell
        // ladder[a] = b means there is ladder from cell a to cell b

        vector<int> parent(x+1), len(x+1);

        // parent array is used for keeping the parent of a cell to backtrack the answer. len array is used to store the number of minimum dice roll needed to the cell.

        for(int i=1; i<=x; i++) parent[i] = 0;
        queue<int> q;
        q.push(1);
        len[1] = 0;
        vis[1] = 1;


        // bfs
        while(!q.empty()){
            int f = q.front();
            q.pop();

            if(ladder[f]){ // if cell f has a ladder we will not roll dice from this point.
                parent[ladder[f]] = f;
                vis[ladder[f]] = 1;
                len[ladder[f]] = len[f];
                q.push(ladder[f]);
            }
            else {
                for(int i=1; i<=n; i++){
                    if(i + f <= x && !vis[i + f]){
                        parent[i + f] = f; // parent array is used for backtracking the result
                        vis[i + f] = 1;
                        len[i + f] = len[f] + 1; // minimum length to reach a cell
                        if(snake[i + f] == 0) q.push(i + f);
                    }
                }
            }
        }

        vector<int> res;
        int z = x;
        res.push_back(z);
        while(parent[z] != 0){
            res.push_back(parent[z]); // backtracking the result
            z = parent[z];
        }

        if(parent[x] != 0){
            cout << len[x] << endl;
            reverse(res.begin(), res.end());
            for(int i=0; i<res.size(); i++){
                cout << res[i];
                if(i < res.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
            cout << "No solution" << endl;
        }

        bool cek = true;
        for(int i=1; i<=x; i++){
            if(vis[i] == 0) {
                cek = false; // checking for a element not visited yet
            }
        }

        if(cek) cout << "All reachable" << endl;
        else {
            for(int i=1; i<=x; i++){
                if(vis[i] == 0) cout << i << " ";
            }
            cout << endl;
        }
    }
}
