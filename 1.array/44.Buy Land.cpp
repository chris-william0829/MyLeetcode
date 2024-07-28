/*

https://kamacoder.com/problempage.php?pid=1044
2024-7-28

*/

#include<iostream>
#include<vector>

int abs(int x){
    return x < 0 ? -x : x;
}

using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<vector<int>> vec(n, vector<int>(m, 0)) ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }
    // 统计横向
    vector<int> horizontal(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            horizontal[i] += vec[i][j];
        }
        cout << horizontal[i] << endl;
    }
    // 统计纵向
    vector<int> vertical(m , 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0 ; i < n; i++) {
            vertical[j] += vec[i][j];
        }
    }
    int result = INT32_MAX;
    int horizontalCut = 0;
    for (int i = 0 ; i < n; i++) {
        horizontalCut += horizontal[i];
        result = min(result, abs(sum - horizontalCut - horizontalCut));
    }
    int verticalCut = 0;
    for (int j = 0; j < m; j++) {
        verticalCut += vertical[j];
        result = min(result, abs(sum - verticalCut - verticalCut));
    }
    cout << result << endl;
}
