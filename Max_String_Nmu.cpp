#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // 引入用于排序的库

using namespace std;

// 自定义比较函数，用于排序
// 如果 s1+s2 的字典序大于 s2+s1，则 s1 应排在前
bool compare(const string& s1, const string& s2) {
    return s1 + s2 > s2 + s1;
}

int main() {
    string input;

    // 输入以逗号分隔的多个正整数字符串
    getline(cin, input);

    vector<string> numbers; // 用于存储分割后的数字字符串
    string current;

    // 按逗号分割输入字符串
    for (char c : input) {
        if (c == ',') { // 遇到逗号表示一个数字结束
            numbers.push_back(current);
            current.clear();
        } else {
            current += c; // 拼接数字字符
        }
    }
    numbers.push_back(current); // 添加最后一个数字

    // 使用自定义比较函数对数字进行排序
    sort(numbers.begin(), numbers.end(), compare);

    // 拼接排序后的结果
    string result;
    for (const string& num : numbers) {
        result += num;
    }

    // 输出结果
    cout << result << endl;

    return 0;
}
