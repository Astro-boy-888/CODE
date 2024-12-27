#include <bits/stdc++.h>

using namespace std;
/*
# 射击比赛

## 题目描述

给定一个射击比赛成绩单

包含多个选手若干次射击的成绩分数

请对每个选手按其最高三个分数之和进行降序排名

输出降序排名后的选手ID序列

条件如下:

1. 一个选手可以有多个射击成绩的分数 且次序不固定
2. 如果一个选手成绩小于三个 则认为选手的所有成绩无效 排名忽略该选手
3. 如果选手的成绩之和相等,则成绩相等的选手按照其ID降序排列

## 输入描述

输入第一行:一个整数 `N`

表示该场比赛总共进行了`N`次射击

产生`N`个成绩分数 `2 <= N <= 100`

输入第二行 一个长度为`N`的整数序列

表示参与本次射击的选手Id

`0 <= ID <= 99`

输入第三行是长度为`N`的整数序列

表示参与每次射击的选手对应的成绩

`0 <= 成绩 <= 100`

## 输出描述

符合题设条件的降序排名后的选手ID序列

## 示例一

### 输入

```
13
3,3,7,4,4,4,4,7,7,3,5,5,5
53,80,68,24,39,76,66,16,100,55,53,80,55
```

### 输出

```
5,3,7,4
```

### 说明

该场射击比赛进行了`13`次,参赛选手为`3 4 5 7`

`3`号选手的成绩为`53 80 55`最高三个成绩的和为 `188`

`4`号选手的成绩为`24 39 76 66`最高三个和为`181`

`5`号选手的成绩为`53 80 55` 最高三个和为`188`

`7`号选手成绩为`68 16 100` 最高三个和`184`

比较各个选手最高三个成绩的和

`3 = 5 > 7 > 4`

由于`3`和`5`成绩相等 且`5 > 3` 所以输出为`5,3,7,4`
*/

/*
TODO:
    1.输入 N , string ids_input ,string scores_input 并解析，将其分割并转化为 int 类型 id 和 score 传入vector<int> ids 和vector<int> scores
    2.使用 unordered_map<int, vector<int>> playerScores 存储每个选手的成绩
    3.输入成绩进入 playerScores
    4.使用vector<pair<int, int>> results 存储选手的 ID 和其最高三个成绩的和
    5.遍历 playerScores 将每个选手的ID和其最高三个成绩的和 输入results
        a.如果选手没有三次成绩则continue 跳过该选手
        b.有三次及三次以上要对成绩进行 sort排列 并且将 最高三次成绩 累加输入 results
    6.自定义排序规则对results进行排序
        a. 按照 最高三个成绩的和 降序排列
        b. 如果和相等，则按选手 ID 降序排列
    7.输出结果，按逗号分隔选手 ID

*/
bool myScoreCompare(const int &a,const int &b)
{
    return a > b;
}

class MyCompare
{
public:
    bool operator ()(const pair<int,int> &a,const pair<int,int>&b)
    {
        if(a.second != b.second)
        {
            return a.second > b.second;
        }
        else 
        {
            return a.first > b.first;
        }
    }
};

int main()
{
    int N;
    string ids_input;
    string scores_input;
    vector<int> ids;
    vector<int> scores;
    string id;
    string score;
    cin >> N;
    cin.ignore();
    getline(cin,ids_input);
    getline(cin,scores_input);
    for (char c:ids_input)
    {
        if(c == ',')
        {
            ids.push_back(stoi(id));
            id.clear();
        }
        else
        {
            id += c;
        }
    }
    ids.push_back(stoi(id));
    for (char c:scores_input)
    {
        if(c == ',')
        {
            scores.push_back(stoi(score));
            score.clear();
        }
        else
        {
            score += c;
        }
    }
    scores.push_back(stoi(score));
    unordered_map<int, vector<int>> playerScores;
    for (size_t i = 0; i < scores.size(); i++)
    {
        playerScores[ids[i]].push_back(scores[i]);
    }
    vector<pair<int, int>> results;
    for (auto c:playerScores )
    {
        if(c.second.size() < 3)
        {
            continue;
        }
        sort(c.second.begin(),c.second.end(),myScoreCompare);
        results.push_back(make_pair(c.first,(c.second[0]+c.second[1]+c.second[2])));
    }
    sort(results.begin(),results.end(),MyCompare());

    for (vector<pair<int, int>>::const_iterator it = results.begin(); it != results.end(); it++)
    {   
        if(it !=results.begin())
        {
            cout << ",";
        }
        cout << (*it).first;
    }
    cout << endl;
}