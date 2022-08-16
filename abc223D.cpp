#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<deque>

#define rep(i,s,e) for(int i=s;i<e;i++)
#define mod 998244353
#define inf 1LL<<60

using namespace std;

using graph = vector<vector<int>>;
using ll = long long;

typedef pair<int,int> P;

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};



int seen[200010]={};
int degree[200010]={};
int main(){
    int n,m;

    cin >> n >> m;

    graph g(n+1);

    rep(i,0,m){
        int a,b;

        cin >> a >> b;

        g[a].push_back(b);
        degree[b]++;
        //次数の記録が肝
    }

    priority_queue<int,vector<int>,greater<int>> zero;

    rep(i,1,n+1){
        if(!degree[i]) zero.push(i); 
    }
    vector<int> ans;
    while(!zero.empty()){
        int now = zero.top();
        zero.pop();
        if(seen[now]) continue;
        ans.push_back(now);
        seen[now]=1;
        rep(j,0,g[now].size()){
            if(seen[g[now][j]]){
                cout << -1 <<endl;
                return 0;
            }
            degree[g[now][j]]--;
            if(!degree[g[now][j]]) zero.push(g[now][j]);
        }
    }
    if(ans.size()<n){
        cout << -1 <<endl;
        return 0;
    }
    rep(i,0,ans.size()) cout << ans[i] <<" ";
    cout << "\n";
}
