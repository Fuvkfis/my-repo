#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long ;

struct fenwick {
    int n ;
    vector<ll> bit ;
    fenwick(int len){
        n = len ;
        bit.assign(n+1,0);
    }
    void update(int i , ll sum){
        while(i<=n){
            bit[i] = max(bit[i],sum) ;
            i+=i&-i ;
        }
    }
    ll query(int i){
        ll result = 0 ;
        while(i>0){
            result = max(result,bit[i]) ;
            i-=i&-i ;
        }
        return result ;
    }
};
int main(){
    int n ;
    cin >> n ;
    vector<int> arr(n) , sorted(n) ;
    for(int i=0;i<n;++i){
        cin >> arr[i] ;
        sorted[i] = arr[i] ;
    }
    fenwick tree(n) ;
    sort(sorted.begin(),sorted.end());
    ll max_sum = LLONG_MIN ;
    for(int i=0;i<n;++i){
        int pos = lower_bound(sorted.begin(),sorted.end(), arr[i] ) - sorted.begin() ;
        pos++;
        ll pre_max = tree.query(pos-1) ;
        tree.update(pos,pre_max+arr[i]) ;
        max_sum = max(max_sum, pre_max+arr[i]) ;
    }
    cout << max_sum ;
    return 0;
}
