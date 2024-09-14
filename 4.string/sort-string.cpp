//排序字符串
//1.如果s是t的前缀，则s在t前面
//2.如果s和t前i-1个相同，但第i个不同，根据第i个字符大小关系排序，大小关系通过rank表示


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 自定义排序的比较函数
bool customCompare(const string& s, const string& t, const vector<int>& rank) {
    int len = min(s.size(), t.size());
    
    // 比较两个字符串的每个字符
    for (int i = 0; i < len; i++) {
        if (s[i] != t[i]) {
            // 按照 rank 中的顺序比较不同字符
            return rank[s[i] - 'a'] < rank[t[i] - 'a'];
        }
    }
    
    // 如果 s 是 t 的前缀，则 s 排在前面
    return s.size() < t.size();
}

int main() {
    // 输入字符顺序
    vector<int> rank(26);
    cout << "请输入26个字母的顺序（如：cba... 表示c>b>a...）：" << endl;
    string order;
    cin >> order;
    
    // 生成rank数组，rank[i]表示字符i对应的顺序
    for (int i = 0; i < 26; i++) {
        rank[order[i] - 'a'] = i;
    }

    // 输入要排序的字符串
    vector<string> strs;
    cout << "请输入字符串数量：" << endl;
    int n;
    cin >> n;
    
    cout << "请输入字符串：" << endl;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    // 使用自定义比较器进行排序
    sort(strs.begin(), strs.end(), [&](const string& s, const string& t) {
        return customCompare(s, t, rank);
    });

    // 输出排序后的结果
    cout << "排序后的字符串：" << endl;
    for (const string& s : strs) {
        cout << s << endl;
    }

    return 0;
}
