#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // 用于排序
#include <sstream> // 用于处理输入

using namespace std;

class MyCompare
{
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second != b.second) {
            return a.second > b.second; // 按成绩和降序
        }
        return a.first > b.first; // 按 ID 降序
    }
};

int main() {
    int N;
    cin >> N; // 输入射击次数 N
    cin.ignore(); // 忽略换行符

    string ids_input, scores_input;
    getline(cin, ids_input); // 输入选手 ID，逗号分隔
    getline(cin, scores_input); // 输入每次射击的成绩，逗号分隔

    vector<int> ids;
    vector<int> scores;

    // 解析选手 ID
    string id;
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
    

    // 解析射击成绩
    string score;
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

    // 使用 unordered_map 存储每个选手的成绩
    unordered_map<int, vector<int>> playerScores;

    // 将成绩按选手 ID 分类
    for (int i = 0; i < N; ++i) {
        playerScores[ids[i]].push_back(scores[i]);
    }

    // 存储选手的 ID 和其最高三个成绩的和
    vector<pair<int, int>> results;

    for (auto& entry : playerScores) {
        vector<int>& scoreList = entry.second;

        // 如果成绩少于 3 次，则跳过该选手
        if (scoreList.size() < 3) {
            continue;
        }

        // 对成绩排序，取最高的三个
        sort(scoreList.rbegin(), scoreList.rend());
        int topThreeSum = scoreList[0] + scoreList[1] + scoreList[2];

        // 将选手 ID 和最高三个成绩的和存入结果
        results.emplace_back(entry.first, topThreeSum);
    }

    // 排序规则
    // 1. 按照最高三个成绩的和降序排列
    // 2. 如果和相等，则按选手 ID 降序排列
    sort(results.begin(), results.end(), MyCompare());

    // 输出结果，按逗号分隔选手 ID
    for (size_t i = 0; i < results.size(); ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << results[i].first;
    }

    cout << endl;
    return 0;
}
