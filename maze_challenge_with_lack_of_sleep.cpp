//拡張ダイクストラ:方向i
//最小コストが同じでも方向が違うかもしれないので方向も記録する必要あり


#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<utility>
 
#define rep(i,s,e) for(int i=s;i<e;i++)
#define mod 998244353
#define inf 1LL<<60
#define P pair<int,int>
 
using namespace std;
 
using graph = vector<vector<int>>;
using ll = long long;
 
 
int dx[8]={1,0,-1,0,1,1,-1,-1},dy[8]={0,1,0,-1,1,-1,1,-1};
 
 
 
long long power(long long n, long long m){
    if(m==0) return 1;
    if(m==1) return n;
    if(m%2==1) return (power(n,m-1)*power(n,1));
    else return (power(n,m/2)*power(n,m/2));
}

int dist[1001][1001][4];
int main(){
    int h,w;
    cin >> h >> w;
    int sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    --sx; --sy; --gx; --gy;
    vector<string> g(h);
    rep(i,0,h){
        cin >> g[i];
    }
    P p;
    p.first = -2;
    p.second = sx*1000+sy;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(p);
    while(!q.empty()){
        P now = q.top(); q.pop();
        // cout << now.second << endl;
        int dir = now.second/10000000;
        now.second%=10000000;
        int x = now.second/1000;
        int y = now.second%1000;
        if(dist[x][y][dir]&&dist[x][y][dir]<=now.first) continue;
        dist[x][y][dir] = now.first;
        rep(i,1,4) dist[x][y][(dir+i)%4]=now.first+1;
        rep(i,0,4){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0||ny<0||nx>=h||ny>=w||g[nx][ny]=='#') continue;
            P next;
            next.second=i*10000000+nx*1000+ny;
            if(now.first==-2){
                next.first=0;
            }
            else if(dir==i) next.first=now.first;
            else next.first=now.first+1;
            q.push(next);
        }
    }
    int ans = 1<<30;
    rep(i,0,4){
        if(ans>dist[gx][gy][i]) ans = dist[gx][gy][i];
    }

    cout << ans << endl;
}