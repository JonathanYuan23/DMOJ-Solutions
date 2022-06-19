#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>; using vi = vector<int>; using vii = vector<pii>;
#define frein freopen("input.txt", "r", stdin)
#define sz(x) (int)(x.size())
#define fi first
#define se second

const int MX = 300005;
const char nl = '\n';

int X, Y, G, id = 0, ans = 0, pGroup[MX];
unordered_map<string, int> dict;
set<int> notGroup[MX];
vii sameGroup;

void putID(string s) {
    if(!dict.count(s)) {
        id++;
        dict[s] = id;
    }
}

void init() {
    for(int i=1; i<MX; i++) pGroup[i] = i;
}

int findSet(int i, int p[]) { 
    return (p[i] == i) ? i : (p[i] = findSet(p[i], p)); 
}

void unionSet(int i, int j, int p[]) { 
    int x = findSet(i, p), y = findSet(j, p);
    if (x != y) 
        p[y] = x;                          
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);  cout.tie(NULL);
    cin >> X;
    string s1, s2, s3;
    // same group
    for(int i=0; i<X; i++) {
        cin >> s1 >> s2;
        putID(s1); putID(s2);
        sameGroup.emplace_back(dict[s1], dict[s2]);
    }
    init();
    cin >> Y;
    // not same group
    for(int i=0, id1, id2; i<Y; i++) {
        cin >> s1 >> s2;
        putID(s1); putID(s2);
        id1 = dict[s1], id2 = dict[s2];
        if(id2 < id1) swap(id1, id2);
        notGroup[id1].insert(id2);
    }
    cin >> G;
    for(int i=0, id1, id2, id3; i<G; i++) {
        cin >> s1 >> s2 >> s3;

        // make sure people have id
        putID(s1); putID(s2); putID(s3);
        id1 = dict[s1], id2 = dict[s2], id3 = dict[s3];

        // person 1 can't be with person 2
        if(notGroup[min(id1, id2)].find(max(id1, id2)) != notGroup[min(id1, id2)].end()) 
            ans++;

        // person 1 can't be with person 3
        if(notGroup[min(id1, id3)].find(max(id1, id3)) != notGroup[min(id1, id3)].end()) 
            ans++;

        // person 2 can't be with person 3
        if(notGroup[min(id2, id3)].find(max(id2, id3)) != notGroup[min(id2, id3)].end()) 
            ans++;

        // put them into a same group
        unionSet(id1, id2, pGroup);
        unionSet(id2, id3, pGroup);
    }
    for(int i=0, id1, id2; i<sz(sameGroup); i++) {
        id1 = sameGroup[i].fi, id2 = sameGroup[i].se;
        if(findSet(id1, pGroup) != findSet(id2, pGroup)) 
            ans++;
    }
    cout << ans << nl;
}
