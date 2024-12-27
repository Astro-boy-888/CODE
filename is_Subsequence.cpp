#include <iostream>
#include <string>

using namespace std;
//这里是子序列 而非模式匹配
bool isSubsequence(string s, string t) {
    int m = s.length(); // 字符串 s 的长度
    int n = t.length(); // 字符串 t 的长度
    
    int i = 0; // s 的指针
    int j = 0; // t 的指针
    
    // 遍历字符串 t
    while (i < m && j < n) {
        if (s[i] == t[j]) { // 如果 s 的字符和 t 的字符相同
            i++; // 移动 s 的指针
        }
        j++; // 不管是否匹配，始终移动 t 的指针
    }
    
    // 如果 s 的指针已经遍历完了，说明 s 是 t 的子序列
    return i == m;
}

int main() {
    string s, t;
    
    // 输入两个字符串 s 和 t
    cin >> s;
    cin >> t;
    
    // 判断 s 是否是 t 的子序列
    if (isSubsequence(s, t)) {
        cout << "true" << endl; // 是子序列
    } else {
        cout << "false" << endl; // 不是子序列
    }
    
    return 0;
}
