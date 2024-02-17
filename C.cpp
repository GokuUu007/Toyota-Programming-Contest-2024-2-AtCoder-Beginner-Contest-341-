
/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}



// warning - integer overflow : )


const int mxN = 501;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};


int H, W, N, grid[mxN][mxN];

string S;

bool Dfs (int idx, int dir, int row, int col) {
    
    if (row < 0 || col < 0 || row >= H ||  col >= W || !grid[row][col]) {
        return 0;
    }

    if (idx >= N) {
        return 1;
    }

    int ans = 0;
    if (S[idx] == 'L') ans |= Dfs(idx + 1, 1, row + dx[1], col + dy[1]);
    if (S[idx] == 'R') ans |= Dfs(idx + 1, 2, row + dx[2], col + dy[2]);
    if (S[idx] == 'U') ans |= Dfs(idx + 1, 0, row + dx[0], col + dy[0]);
    if (S[idx] == 'D') ans |= Dfs(idx + 1, 3, row + dx[3], col + dy[3]);

    return ans;

}

void solve() {


    cin >> H >> W >> N >> S;

    for (int i = 0; i < H; ++i) {
        string t;
        cin >> t;
        for (int j = 0; j < W; ++j) {
            grid[i][j] = t[j] == '.';
        }
    }


    int ans = 0;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j]) {
                ans += Dfs(0, 0, i, j);
            }
        }
    }

    cout << ans;
} 

int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    // cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifndef ONLINE_JUDGE
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
