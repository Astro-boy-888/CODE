#include <bits/stdc++.h>

using namespace std;

// Helper function to split a string by a delimiter
// 将一个字符串根据指定分隔符切分为多个子串
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens; // 用于存储切分后的子串
    string token;          // 存储当前子串
    for (char c : s) {//逐个遍历字符 将每个字符赋给c
        if (c == delimiter) { // 如果遇到分隔符
            tokens.push_back(token); // 将子串加入结果集合
            token.clear();           // 清空子串为下一次切分做准备
        } else {
            token += c; // 添加字符到当前子串
        }
    }
    tokens.push_back(token); // 将最后一个子串加入结果
    return tokens; // 返回切分完成的子串集合
}

// Helper function to process a substring based on the rules
// 根据规则处理单个子串
string processSubstring(const string& str) {
    int lowerCount = 0, upperCount = 0; // 计数大写和小写字母的数量
    for (char c : str) {
        if (islower(c)) lowerCount++; // 如果是小写字母，小写计数+1
        if (isupper(c)) upperCount++; // 如果是大写字母，大写计数+1
    }

    if (lowerCount > upperCount) { // 小写字母超过大写字母
        string result;
        for (char c : str) {
            result += tolower(c); // 全部转为小写
        }
        return result;
    } else if (upperCount > lowerCount) { // 大写字母超过小写字母
        string result;
        for (char c : str) {
            result += toupper(c); // 全部转为大写
        }
        return result;
    } else {
        return str; // 如果大小写数量相等，不做处理
    }
}

// Main function to transform the string
// 对整个字符串进行处理
string transformString(int K, const string& S) {
    vector<string> substrings = split(S, '-'); // 将字符串按“-”切分
    string result = substrings[0]; // 保留第一个子串，不做处理

    string remaining; // 用于存储剩余的子串
    for (size_t i = 1; i < substrings.size(); ++i) {
        remaining += substrings[i]; // 将剩余子串合并
    }

    for (size_t i = 0; i < remaining.size(); i += K) { // 每K个字符分组
        string segment = remaining.substr(i, K); // 拉取K个字符作为子串
        result += "-" + processSubstring(segment); // 处理子串并加入结果
    }

    return result; // 返回最终处理结果
}

int main() {
    int K;
    string S;

    // Input reading
    // 输入读取
    cin >> K;          // 读取K
    cin.ignore();      // 忽略行进符
    getline(cin, S);   // 读取整个字符串

    // Process and output the result
    // 处理字符串并输出
    string result = transformString(K, S);
    cout << result << endl;

    return 0;
}
