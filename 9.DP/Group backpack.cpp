#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

struct log{
    int size;
    int download;
};

int main(){

    int N,M,C;
    cin >> N >> M >> C;
    
    vector<vector<log>> logs(N+1);
    for(int i=0;i<N*M;i++){
        int id, sz, d;
        cin >> id >> sz >> d;
        log temp = {sz, d};
        logs[id+1].push_back(temp);
    }

    for(int i=0;i<N;i++){
        sort(logs[i].begin(), logs[i].end(), [](log &A, log &B){
            if(A.size == B.size){
                return A.download > B.download;
            }else{
                return A.size < B.size;
            }
        });
    }
    vector<vector<int>> dp(N+1,vector<int>(C+1));
    int sum = 0;
    for(int i=1;i<=N;i++){
        log a = logs[i][0];
        for(int j=C;j-a.size>=sum;j--){
            dp[i][j] = dp[i-1][j-a.size] + a.download;
        }
        for(int t=1; t<logs[i].size();t++){
            a = logs[i][t];
            for(int j=C;j-a.size>=sum;j--){
                dp[i][j] = max(dp[i][j],dp[i-1][j-a.size]+a.download);
                dp[i][j] = max(dp[i][j],dp[i][j-a.size] + a.download);
            }
        }
        sum += logs[i][0].size;
        if(sum > C){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << dp[N][C] << endl;
    return 0;
}