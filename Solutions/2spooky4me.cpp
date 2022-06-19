#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1<<30
#define LSOne(S) (S & (-S))
using namespace std;
const int MAXN=1005;

int N, L, S, a, b, s;

unordered_map<int, int> id; unordered_map<int, ll> overlap;

class BIT {
private:
  vector<ll> ft;

public:
  BIT() {}
  BIT(int n) { ft.assign(n + 1, 0); }

  ll rsq(int b) {                          
    ll sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  ll rsq(int a, int b) {                   
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  void adjust(int k, int v) {                 
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }

  void range_add(int l, int r, int val){
    adjust(l, val);
    adjust(r+1, -val);
  }

};

int main(){

    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);

    vector<int> points; vector<pair<int, pair<int, int>>> updates;

    cin >> N >> L >> S;
    for(int i=0; i<N; i++){
        cin >> a >> b >> s;
        points.push_back(a); points.push_back(b);
        updates.push_back({s, {a, b}});
    }

    points.push_back(1); points.push_back(L);
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    for(int i=0; i<points.size(); i++)  id[points[i]]=i+1;

    BIT spooky(points.size()+5);

    for(auto x: updates){
        a=id[x.second.first];   b=id[x.second.second];  s=x.first;
        spooky.range_add(a, b-1, s);
        overlap[a]+=s; overlap[b]+=s;
    }

    //for(int i=1; i<=points.size()-1; i++) cout << spooky.rsq(i) << " "; cout << "\n";

    ll ret=0; bool prev=0, le=0;
    for(int i=0; i<points.size()-1; i++){
        int l=i+1, r=i+2, rl=spooky.rsq(i+1), rr=spooky.rsq(i+2);
        if(rl<S){
            if(overlap[l]>=S && overlap[r]>=S){
                ret+=(points[i+1]-1)-(points[i]+1)+1;
                prev=0;
                le=1;
            } else if(overlap[l]>=S) {
                ret+=(points[i+1])-(points[i]+1)+1;
                prev=1;
            } else if(overlap[r]>=S){
                ret+=(points[i+1]-1)-(points[i]);
                if(!prev) ret+=1;
                prev=0;
                le=1;
            } else {
                if(i==0){
                    if(rr>=S){
                        ret+=(points[i+1]-1)-(points[i])+1;
                        prev=1;
                        le=0;
                    } else {
                        ret+=(points[i+1])-(points[i])+1;
                        prev=1;
                        le=0;
                    }
                } else {
                    if(rr>=S){
                        if(le){
                            ret+=(points[i+1]-1)-(points[i]+1)+1;
                            prev=1;
                            le=0;
                        } else {
                            ret+=(points[i+1]-1)-(points[i]);
                            if(!prev) ret+=1;
                            prev=1;
                            le=1;
                        }
                    } else {
                        if(le){
                            ret+=(points[i+1])-(points[i]+1)+1;
                            prev=1;
                            le=0;
                        } else {
                            ret+=(points[i+1])-(points[i]);
                            if(!prev) ret+=1;
                            prev=1;
                            le=0;
                        }
                    }
                }
            }
        } else {
            prev=0;
            le=1;
        }
    }   

    cout << ret << "\n";
    return 0;
}
