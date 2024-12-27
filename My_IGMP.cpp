#include <bits/stdc++.h>

using namespace std;
/*
题目描述
IGMP 协议中，有一个字段称作最大响应时间 (Max Response Time) ，HOST收到查询报文，解折出 MaxResponsetime 字段后，需要在 (0，MaxResponseTime] 时间 (s) 内选取随机时间回应一个响应报文，如果在随机时间内收到一个新的查询报文，则会根据两者时间的大小，选取小的一方刷新回应时间。
最大响应时间有如下计算方式：
当 Max Resp Code < 128, Max Resp Time = Max Resp Code；
当 Max Resp Code ≥ 128, Max Resp Time = (mant | 0x10) << (exp + 3)；
注: exp最大响应时间的高5~7位: mant 为最大响应时间的低4位。
其中接收到的MaxRespCode 最大值为 255，以上出现所有字段均为无符号数。
现在我们认为 HOST收到查询报文时，选取的随机时间必定为最大值，现给出 HOST 收到查询报文个数 C，HOST 收到该报文的时间T，以及查询报文的最大响应时间字段值 M，请计算出HOST 发送响应报文的时间。
输入描述
第一行为查询报文个数 C，后续每行分别为 HOST 收到报文时间 T，及最大响应时间M，以空格分割。
输出描述
HOST 发送响应报文的时间。
备注
用例确定只会发送一个响应报文， 不存在计时结束后依然收到查询报文的情况。
示例1
输入
3
0 20
1 10
8 20
输出
11
说明
收到3个报文，
第0秒收到第1个报文，响应时间为20秒，则要到0+20=20秒响应；
第1秒收到第2个报文，响应时间为10秒，则要到1+10=11秒响应，与上面的报文的响应时间比较获得响应时间最小为11秒；
第8秒收到第3个报文，响应时间为20秒，则要到8+20=28秒响应，与第上面的报文的响应时间比较获得响应时间最小为11秒；
最终得到最小响应报文时间为11秒
示例2
输入
2
0 255
200 60
输出
260
说明
收到2个报文，
第0秒收到第1个报文，响应时间为255秒，则要到(15 | 0x10) << (7 + 3)= 31744秒响应; (mant = 15，exp =7)
第200秒收到第2个报文，响应时间为60秒，则要到200+60-260秒响应，与第上面的报文的响应时间比较获得响应时间最小为260秒:
最终得到最小响应报文时间为260秒
解题思路
这道题目要求计算在IGMP协议下，HOST在收到多个查询报文后，确定的最早发送响应报文的时间点。HOST需要根据每个报文的最大响应时间字段MaxRespCode来计算其最大响应时间，并在计算出所有可能的响应时间后选取最早的那个时间点。
核心是：
当 m < 128 时，m 直接作为 MaxResponseTime。
当 m >= 128 时，需要将 m 转换为8位二进制字符串，将第1至第3位提取为 exp，第4至第7位提取为 mant。接着，将 exp 和 mant 转换为十进制值，并代入公式 (mant | 0x10) << (exp + 3) 进行计算，即可得到 MaxResponseTime。
示例解释
示例1:
报文1: 在 0 秒收到，M=20，最大响应时间是 20 秒，因此最迟在 0 + 20 = 20 秒响应。
报文2: 在 1 秒收到，M=10，最大响应时间是 10 秒，因此最迟在 1 + 10 = 11 秒响应。
报文3: 在 8 秒收到，M=20，最大响应时间是 20 秒，因此最迟在 8 + 20 = 28 秒响应。
最早的响应时间是 11 秒。
示例2:
报文1: 在 0 秒收到，M=255，因为 M >= 128，需要计算 (mant | 0x10) << (exp + 3):
mant = 15, exp = 7。计算得 MaxRespTime = (15 | 0x10) << (7 + 3) = 31744 秒。
报文2: 在 200 秒收到，M=60，最大响应时间是 60 秒，因此最迟在 200 + 60 = 260 秒响应。
最早的响应时间是 260 秒。
*/

/*
    TODO：
    1.设置一个calculateMaxResponseTime(int maxRespCode)函数返回每个maxRespCode的MaxRespTime
        a.当 maxRespCode < 128, maxRespTime = maxRespCode；
        b.当 maxRespCode ≥ 128, maxRespTime = (mant | 0x10) << (exp + 3)；
        注: maxRespCode => 我们需要用的为第1~7位 
            补:0x十六进制 0b二进制 0d十进制 0o八进制
            exp为maxRespCode的高5~7位 => 先右移4位 => 再和 0b111 进行与运算得到 高5~7位
            mant为maxRespCode的低4位 => 无需右移 => 直接和0b1111 进行与运算得到 低4位 
    2.主函数中设置vector<pair< int,  int>> queries(c); 
        进行对每个报文的接收时间t 和每个报文的 maxRespCode 进行存储
        初始化 earliestResponseTime 为INT_MAX
        循环整个queries 找到 t + maxRespTime 最小的数更新为 earliestResponseTime
*/
int calculateMaxResponseTime(int maxRespCode)
{   
    if (maxRespCode <128)
    {
        return maxRespCode;
    }
    else
    {
        int mant = (maxRespCode >> 4) & 0b111;
        int exp = maxRespCode & 0b1111;
        return (mant | 0x10) << (exp + 3);
    }
}

int main()
{
    int c;
    cin >>c;
    
    vector<pair<int,int>> queries(c);
    for (size_t i = 0; i < c; i++)
    {   
        int arrivalTime;
        cin >> arrivalTime;
        queries[i].first = arrivalTime;
        int maxRespCode;
        cin >> maxRespCode;
        queries[i].second = calculateMaxResponseTime(maxRespCode);
    }

    int minResponseTime = INT_MAX;
    for (int i = 0; i < c; i++)
    {
        int responseTime = queries[i].first + queries[i].second;
        minResponseTime = min(minResponseTime,responseTime);
    }
    cout << minResponseTime <<endl;
    return 0;
}