#include <bits/stdc++.h>

using namespace std;
/*
题目：
    # 字符串分割

    ### 描述

    给定一个非空字符串S，其被N个`-`分隔成N+1的子串，给定正整数K，要求除第一个子串外，其余的子串每K个字符组成新的子串，并用`-`分隔。对于新组成的每一个子串，如果它含有的小写字母比大写字母多，则将这个子串的所有大写字母转换为小写字母；反之，如果它含有的大写字母比小写字母多，则将这个子串的所有小写字母转换为大写字母；大小写字母的数量相等时，不做转换。

    ### 输入描述:

    输入为两行，第一行为参数K，第二行为字符串S。

    ### 输出描述:

    输出转换后的字符串。

    ### 示例1

    输入
    3
    12abc-abCABc-4aB@
    输出
    12abc-abc-ABC-4aB-@

    说明
    子串为12abc、abCABc、4aB@，第一个子串保留，后面的子串每3个字符一组为abC、ABc、4aB、@，abC中小写字母较多，转换为abc，ABc中大写字母较多，转换为ABC，4aB中大小写字母都为1个，不做转换，@中没有字母，连起来即12abc-abc-ABC-4aB-@

    ### 示例2

    输入
    12
    12abc-abCABc-4aB@
    输出
    12abc-abCABc4aB@

    说明
    子串为12abc、abCABc、4aB@，第一个子串保留，后面的子串每12个字符一组为abCABc4aB@，这个子串中大小写字母都为4个，不做转换，连起来即12abc-abCABc4aB@
*/

/*
TODO:
    1.将一个string按照分割符分为多个子串 返回一个由子串组成的vector<string> 
        vector<string> split(const string& s, char delimiter) 
        TODO:
        a.创建vector<string> tokens 存储所有子串 token 存储当前子串
        b.遍历 s 遇到 delimiter 就将这之前的子串 token 尾插入 vector<string> tokens 没遇到将当前字符 c 插入 token
        c.将最后的子串 token 插入vector<string> tokens
        d.返回tokens
    
    2.根据规则处理单个子串 
        string processSubstring(const string& str)
        TODO:
        a.遍历整个子串计数 lowerCount upperCount
        b.根据规则处理
            i.  lowerCount > upperCount => 设置 result，str 全部转为 lower 传给 result 返回 result
            ii. lowerCount < upperCount => 设置 result，str 全部转为 upper 传给 result 返回 result
            iii.lowerCount = upperCount => 不变 返回 str

    3.对整个字符串进行处理
        string transformString(int K, const string& S)
        TODO:
        a.调用split生成子串vector<string> substrings
        b.substrings[0] 直接赋值给结果result
        c.把所有剩下的substrings[1]到substrings[substrings.size()-1]加到一个剩下的子串 string remaining 中
        d.遍历remaining 每次间隔为 K 
            i. 设置segment用于存储子串 调用以下函数
                string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
            ii.对segment进行规则处理 processSubstring "-" + 处理后的 segment 直接加在 result 上
        e.返回result
    
    4.主方法
        int main()
        TODO：
        a.输入读取K S
        b.transformString处理字符串并输出结果result

 */

vector<string> split(const string& s, char delimiter) 
{
    /*
    TODO:
    a.创建vector<string> tokens 存储所有子串 token 存储当前子串
    b.遍历 s 遇到 delimiter 就将这之前的子串 token 尾插入 vector<string> tokens 没遇到将当前字符 c 插入 token
    c.将最后的子串 token 插入vector<string> tokens
    d.返回tokens
    */
    vector<string> tokens;
    string token;
    for (char c:s)
    {
        if(c == delimiter)
        {
            tokens.push_back(token);
            token.clear();           // ******清空子串为下一次切分做准备******
        }
        else
        {
            token += c;
        }
    }
    tokens.push_back(token);
    return tokens;
}

string processSubstring(const string& str)
{   
    /*
    TODO:
    a.遍历整个子串计数 lowerCount upperCount
    b.根据规则处理
        i.  lowerCount > upperCount => 设置 result，str 全部转为 lower 传给 result 返回 result
        ii. lowerCount < upperCount => 设置 result，str 全部转为 upper 传给 result 返回 result
        iii.lowerCount = upperCount => 不变 返回 str
    */
    int lowerCount=0,upperCount=0;
    for (char c:str)
    {
        if(islower(c)) lowerCount++;
        if(isupper(c)) upperCount++;
    }

    if(lowerCount > upperCount)
    {
        string result;
        // result = str.lower() 没有这种函数！！！！！只能逐个字符修改
        for (char c:str)
        {
            result += tolower(c); //******记住将字符转化为小写 tolower() ******
        }
        return result;
    }
    else if(lowerCount < upperCount)
    {
        string result;
        // result = str.upper() 没有这种函数！！！！！只能逐个字符修改
        for (char c:str)
        {
            result += toupper(c); //******记住将字符转化为大写 toupper() ******
        }
        return result;
    }
    else
    {
        return str;
    }
}

string transformString(int K, const string& S)
{
    /*
    TODO:
    a.调用split生成子串vector<string> substrings
    b.substrings[0] 直接赋值给结果result
    c.把所有剩下的substrings[1]到substrings[substrings.size()-1]加到一个剩下的子串 string remaining 中
    d.遍历remaining 每次间隔为 K 
        i. 设置segment用于存储子串 调用以下函数
            string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
        ii.对segment进行规则处理 processSubstring "-" + 处理后的 segment 直接加在 result 上
    e.返回result
    */
    vector<string> substrings = split(S, '-') ;
    string result = substrings[0];
    string remaining;
    for (size_t i = 1; i < substrings.size(); i++) 
    {
        remaining += substrings[i];
    }

    for (size_t i = 0; i < remaining.size(); i += K)
    {
        string segment = remaining.substr(i,K);
        result += '-' + processSubstring(segment);
    }
    return result;
}

int main()
{
/*
    TODO：
    a.输入读取K S
    b.transformString 处理字符串并输出结果result
*/
    int K;
    string S;

    cin >> K;
    cin.ignore();
    getline(cin,S);

    string result = transformString(K,S);
    cout << result << endl;
    return 0;
}