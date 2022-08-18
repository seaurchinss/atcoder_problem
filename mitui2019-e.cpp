#include<iostream>
#include<vector>

#define rep(i,s,e) for(int i=s;i<e;i++)
#define mod 1000000007

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    int A=0,B=0,C=0;
    ll sum=1;
    rep(i,0,n){
        int now = a[i];
        int tmp = 0;
        int flag = 0;
        if(A==now){
            flag = 1;
            ++A;
            ++tmp;
        }
        if(B==now){
            if(flag==0) {
                flag = 1;
                ++B;
            }
            ++tmp;
        }
        if(C==now){
            if(flag==0) {
                flag = 1;
                ++C;
            }
            ++tmp;
        }
        sum*=tmp;
        sum%=mod;
    }
 
    cout << sum << endl;    
}