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
#define mod 1000000007
#define inf 1LL<<60
 
using namespace std;
 
using graph = vector<vector<int>>;
using ll = long long;
 
 
int dx[8]={1,0,-1,0,1,1,-1,-1},dy[8]={0,1,0,-1,1,-1,1,-1};
 
typedef pair<int,int> P;


long long power(long long n, long long m){
    if(m==1) return n;
    if(m%2==1) return (power(n,m-1)*power(n,1));
    else return (power(n,m/2)*power(n,m/2));
}

int digit(int n){
    int i=0;
    while(n!=0){
        n/=10;
        ++i;
    }
    return i;
}

int main(){
    int a,n;
    cin >> a >>n;
    vector<int> ans;
    ans.resize(1000000,-1);
    queue<int> q;
    q.push(1);
    ans[1]=0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if((ll)now*a<1000000&&ans[now*a]==-1){
            ans[now*a]=ans[now]+1;
            q.push(now*a);
        }
        int d = digit(now)-1;
        int u=now,t;
        t = u%10;
        if(digit(now)<2||t==0) continue;
        u = u/10;
        u+=power(10,d)*t;
        if(u<1000000&&ans[u]==-1){
            ans[u]=ans[now]+1;
            q.push(u);
        }
    }

    cout << ans[n] << endl;
}