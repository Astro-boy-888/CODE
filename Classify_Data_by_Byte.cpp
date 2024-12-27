#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 输入：c 和 b，及10个数据
    int c, b;
    vector<int> data(10);

    // 读取输入
    cin >> c >> b;
    for (int i = 0; i < 10; ++i) {
        cin >> data[i];
    }

    // 用于存储每个有效类型的数据个数
    unordered_map<int, int> typeCount;

    // 遍历每个数据
    for (int a : data) {
        // 计算数据a的四个字节之和
        int sum = ((a >> 24) & 0xFF) + ((a >> 16) & 0xFF) + ((a >> 8) & 0xFF) + (a & 0xFF);
        
        // 计算 sum 对 b 取模的结果
        int mod = sum % b;

        // 如果取模结果小于 c，则是有效类型
        if (mod < c) {
            // 统计该类型的数据个数
            typeCount[mod]++;
        }
    }

    // 找到有效类型中数据最多的类型的数量
    int maxCount = 0;
    for (auto& entry : typeCount) {
        maxCount = max(maxCount, entry.second);
    }

    // 输出结果
    cout << maxCount << endl;

    return 0;
}
