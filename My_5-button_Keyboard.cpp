#include <bits/stdc++.h>

using namespace std;

/*
# 5键键盘的输出

有一个特殊的 5键键盘，上面有 a,ctrl-c,ctrl-x,ctrl-v,ctrl-a五个键。

a键在屏幕上输出一个字母 a;

ctrl-c将当前选择的字母复制到剪贴板;

ctrl-x将当前选择的 字母复制到剪贴板，并清空选择的字母;

ctrl-v将当前剪贴板里的字母输出到屏幕;

ctrl-a 选择当前屏幕上所有字母。

## 注意:

1、剪贴板初始为空，新的内容被复制到剪贴板时会覆盖原来的内容

2、当屏幕上没有字母时，ctrl-a无效

3、当没有选择字母时，ctrl-c和 ctrl-x无效

4、当有字母被选择时，a和ctrl-v这两个有输出功能的键会先清空选择的字母，再进行输出

给定一系列键盘输入，输出最终屏幕上字母的数量。

## 输入描述:

输入为一行，为简化解析，用数字 12345代表 a,ctrl-c,ctrl-x,ctrl-v,ctrl-a五个键的输入，数字用空格分隔

## 输出描述:

输出一个数字，为最终屏目上字母的数量。

## 示例:

### 输入

111

### 输出

3
*/

int main() {
    string input;
    getline(cin, input);

    int screenCount = 0;      // 屏幕上字母的数量
    int clipboardCount = 0;   // 剪贴板中的字母数量
    bool hasSelection = false;  // 是否有选中的字母
    int selectedCount = 0;      // 当前选中的字母数量

    for (auto c : input) {
        if (c == '1') {  // 按下 a 键
            if (hasSelection) {
                screenCount -= selectedCount;  // 清空当前选择的字母
            }
            screenCount++;  // 输出一个字母
        }
        else if (c == '2') {  // 按下 ctrl-c 键
            if (hasSelection) {
                clipboardCount = selectedCount;  // 将选中的字母复制到剪贴板
            }
        }
        else if (c == '3') {  // 按下 ctrl-x 键
            if (hasSelection) {
                clipboardCount = selectedCount;  // 将选中的字母复制到剪贴板
                screenCount -= selectedCount;  // 清空选中的字母
                hasSelection = false;  // 取消选中状态
            }
        }
        else if (c == '4') {  // 按下 ctrl-v 键
            if (hasSelection) {
                screenCount -= selectedCount;  // 清空当前选择的字母
            }
            screenCount += clipboardCount;  // 输出剪贴板里的字母
        }
        else if (c == '5') {  // 按下 ctrl-a 键
            if (screenCount > 0) {
                hasSelection = true;  // 选择屏幕上的所有字母
                selectedCount = screenCount;  // 选中屏幕上所有字母
            }
        }
    }

    cout << screenCount << endl;  // 输出最终屏幕上的字母数量
    return 0;
}
