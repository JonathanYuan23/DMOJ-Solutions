#pragma GCC optimize "Ofast"
#include <bits/stdc++.h>
using namespace std; using pii = pair<int, int>;  using piii = pair<int, pii>;  using piiii = pair<pii, pii>;  using vi = vector<int>;  using vii = vector<pii>;  using viii = vector<piii>;  using viiii = vector<piiii>; using ll = long long; using ull = unsigned long long; 
#define frein freopen("input.txt", "r", stdin)
#define freout freopen("output.txt", "w", stdout)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define LSB(x) (x & (-x))
#define sz(x) (int)(x.size())
#define ms(a, b) memset(a, b, sizeof a)

const int MOD = 1e9+7, INF = 0x3f3f3f3f, MX = 1e3, IMX = INT_MAX, IMN = INT_MIN;
const long long LLMX = LONG_LONG_MAX, LLMN = LONG_LONG_MIN;
const char nl = '\n';

struct Node {
    int maxChild = 0;
    unordered_map<int, Node*> children;
};

void insert(Node *root, vi member) {
    Node *cur = root;
    for(int i=1; i<sz(member); i++) {
        int childNum = member[i];
        if(!cur -> children.count(childNum)) {
            cur -> maxChild = max(cur -> maxChild, childNum);
            cur -> children[childNum] = new Node;
        }
        cur = cur -> children[childNum];
    }
}

void remove(Node *node) { 
    for(auto &e: node -> children) remove(e.se);
    node -> children.clear();
    delete node;
    node = nullptr;
}

ll accumulate(Node *node) {
    ll sum = node -> maxChild;
    for(auto &e: node -> children) sum = (sum + accumulate(e.se)) % MOD;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
    for(int tc=0; tc<10; tc++) {
        Node *root = new Node;
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            string member, cur = ""; vi parsedMember;
            cin >> member;
            for(auto &c: member) {
                if(c == '.') {
                    parsedMember.pb(stoi(cur));
                    cur = "";
                }
                else cur += c;
            }
            parsedMember.pb(stoi(cur));
            insert(root, parsedMember);
        }
        cout << accumulate(root) + 1 << nl;
        remove(root);
    }
    return 0;
}
