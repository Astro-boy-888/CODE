#include<bits/stdc++.h>

using namespace std;
/*
题目描述
一个人设定一组四码的数字作为谜底，另一方猜。

每猜一个数，出数者就要根据这个数字给出提示，提示以XAYB形式呈现，直到猜中位置。

其中X表示位置正确的数的个数（数字正确且位置正确），而Y表示数字正确而位置不对的数的个数。

例如，当谜底为8123，而猜谜者猜1052时，出题者必须提示0A2B。

例如，当谜底为5637，而猜谜者才4931时，出题者必须提示1A0B。

当前已知N组猜谜者猜的数字与提示，如果答案确定，请输出答案，不确定则输出NA。

输入描述
第一行输入一个正整数，0＜N ＜ 100。

接下来N行，每一行包含一个猜测的数字与提示结果。

输出描述
输出最后的答案，答案不确定则输出NA。

示例1
输入

6
4815 1A1B
5716 0A1B
7842 0A1B
4901 0A0B
8585 3A0B
8555 2A1B

输出
3585
*/

/*
    TODO:

    bool isValid(const string &candidate, const vector<pair<string, string>> &guesses)：
    1.将 candidate 与所有的 guess 进行对比得出 A表示位置正确的数字数，B表示数字正确但位置不对的数字数
        string guessNumber = guess.first; 
        string hint = guess.second;
        设置vector<bool> used(4, false); 用于标记 candidate 中哪些位置已经被匹配
    2.将结果和hint进行对比检查是否与给定hint一致
    
    主函数：
    1.结合题设输入数据 vector<pair<string, string>> guesses记录所有的猜测和对应的提示
    2.设置 string result = "NA" ， count 记录符合条件的答案数量
        string answer 保留可能的答案
    3.枚举所有的四位数 设置为 candidate (由int 0~9999 转化成 string 不足四位的while循环 进行string加法)
        分别进行 isValid 判断 candidate
            如果满足所有条件 count++ ; answer = candidate
                如果 count > 1 result = "NA" 跳出循环
    4.如果 count == 1 => result = answer 
    5. cout << result <<endl

*/

bool isValid(const string &candidate, const vector<pair<string, string>> &guesses) 
{
    for (const auto &guess : guesses)
    {
        string guessNumber = guess.first;
        string hint = guess.second;

        int A = 0, B = 0;
        vector<bool> used(4, false); // 标记 candidate 中的数字是否已被匹配

        // 计算 A（数字和位置都正确）
        for (int i = 0; i < 4; i++)
        {
            if (guessNumber[i] == candidate[i])
            {
                A++;
                used[i] = true; // 标记 candidate[i] 已匹配
            }
        }

        // 计算 B（数字正确但位置不对）
        for (int i = 0; i < 4; i++) 
        // i :指向 guessNumber 中当前正在检查的数字索引（猜测的数字）。
        // 目的是找到 guessNumber[i] 中的数字在 candidate 中的位置是否存在匹配但位置错误的情况。
        {
            if (guessNumber[i] != candidate[i]) // 仅检查位置不正确的数字
            {
                for (int j = 0; j < 4; j++)
                // j: 指向 candidate 中的数字索引（谜底的数字）。
                // 目的是检查 candidate[j] 是否和当前的 guessNumber[i] 相等，同时确保 candidate[j] 没有被标记为已匹配。
                {
                    if (!used[j] && guessNumber[i] == candidate[j]) // 确保 candidate[j] 未匹配过
                    {
                        B++;
                        used[j] = true; // 标记 candidate[j] 已匹配
                        break;
                    }
                }
            }
        }

        // 检查提示是否一致
        if (to_string(A) + "A" + to_string(B) + "B" != hint)
        {
            return false; // 若有一组猜测不匹配，直接返回 false
        }
    }

    return true; // 所有猜测匹配时返回 true
}

int main()
{
    int N;
    cin >> N;

    vector<pair<string, string>> guesses;
    for (size_t i = 0; i < N; i++)
    {   
        string guess,hint;
        cin >> guess >> hint ;
        guesses.push_back(make_pair(guess,hint));
    }

    string result = "NA" ;
    int count = 0;
    string answer;

    for (int i = 0; i <= 9999; i++)
    {
        string candidate = to_string(i);
        while (candidate.size() < 4 )
        {
            candidate = '0' + candidate; 
        }
        
        if(isValid(candidate,guesses))
        {
            count ++;
            answer = candidate;
            if (count >1)
            {
                result = "NA";
                break;
            }
        }
    }
    
    if(count ==1)
    {
        result = answer;
    }

    cout << result << endl;
    return 0;
}


