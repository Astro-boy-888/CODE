#include <bits/stdc++.h>

using namespace std;

/*
题目描述
给定一组不等式，判断是否成立并输出不等式的最大差(输出浮点数的整数部分)

要求:

不等式系数为 double类型，是一个二维数组

不等式的变量为 int类型，是一维数组;

不等式的目标值为 double类型，是一维数组

不等式约束为字符串数组，只能是:“>”,“>=”,“<”,“<=”,“=”，

例如，不等式组:

 a11x1 + a12x2 + a13x3 + a14x4 + a15x5 <= b1; 
 a21x1 + a22x2 + a23x3 + a24x4 + a25x5 <= b2; 
 a31x1 + a32x2 + a33x3 + a34x4 + a35x5 <= b3; 
1
2
3
最大差 = max{(a11x1+a12x2+a13x3+a14x4+a15x5-b1),(a21x1+a22x2+a23x3+a24x4+ a25x5-b2),(a31x1+a32x2+a33x3+a34x4+a35x5-b3)},

类型为整数(输出浮点数的整数部分)

输入描述
a11,a12,a13,a14,a15,a21,a22,a23,a24,a25, a31,a32,a33,a34,a35,x1,x2,x3,x4,x5,b1,b2,b3,<=,<=,<=

不等式组系数(double类型):

a11,a12,a13,a14,a15

a21,a22,a23,a24,a25

a31,a32,a33,a34,a35

不等式变量(int类型):x1,x2,x3,x4,x5

不等式目标值(double类型):b1,b2,b3

不等式约束(字符串类型):<=,<=,<=

输出描述
true或者 false，最大差

示例1
输入

2.3,3,5.6,7.6;11,3,8.6,25,1;0.3,9,5.3,66,7.8;1,3,2,7,5;340,670,80.6;<=,<=,<=
1
输出

false 458
1
说明

示例2
输入

2.36,3,6,7.1,6;1,30,8.6,2.5,21;0.3,69,5.3,6.6,7.8;1,13,2,17,5;340,67,300.6;<=,>=,<=
1
输出

false 758
1
说明

解题思路
题目解读
题目要求你根据一组不等式判断其是否成立，并计算这些不等式中左边表达式和目标值之间的最大差值。具体来说，每个不等式都包含如下内容：

不等式系数：一个二维数组，表示每个变量的系数。
不等式的变量：一个一维数组，表示每个变量的值。
不等式的目标值：一个一维数组，表示每个不等式右边的目标值。
不等式约束：一个字符串数组，表示不等式的关系，只能是 “>”, “>=”, “<”, “<=”, “=” 其中之一。
输入和输出示例
示例 1
输入：

2.3,3,5.6,7.6;11,3,8.6,25,1;0.3,9,5.3,66,7.8;1,3,2,7,5;340,670,80.6;<=,<=,<=
1
输出：

false 458
1
说明：

不等式系数：

第一行：2.3, 3, 5.6, 7.6
第二行：11, 3, 8.6, 25, 1
第三行：0.3, 9, 5.3, 66, 7.8
变量：x1=1, x2=3, x3=2, x4=7, x5=5
目标值：b1=340, b2=670, b3=80.6
不等式关系：<=, <=, <=
计算每个不等式的左侧表达式，判断是否成立，并计算差值：
第一个不等式的左侧值大于340，不成立。
计算差值，并输出最大差值的整数部分（458）。
最后输出 false 和最大差值 458。

*/

/*
*/

double dotProduct(vector<double> &a,vector<int> &b)
{
    double result = 0.0;
    for (int i = 0; i < 5; i++)
    {
        result += a[i]*b[i];
    }
    return result;
}

int main()
{
    string input;
    getline(cin,input);

    vector<string> in;
    string str;
    for (char c : input)
    {
        if (c ==';')
        {
            in.push_back(str);
            str.clear();
        }
        else
        {
            str += c;
        }
    }
    in.push_back(str);

    vector<vector<double>> matrix(3, vector<double>(5, 0.0));
    for (size_t i = 0; i < 3; i++)
    {   
        string num;
        int col =0;
        for (char c:in[i])
        {
            if (c ==',')
            {
                matrix[i][col++] = stod(num);
                num.clear();
            }
            else
            {
                num += c;
            }
        }
        matrix[i][col]= stod(num);
    }
    
    vector<int> x;
    string num_x;
    for (char c:in[3])
    {
        if (c ==',')
        {
            x.push_back(stoi(num_x));
            num_x.clear();
        }
        else
        {
            num_x += c;
        }
    }
    x.push_back(stoi(num_x));
    
    vector<double> y;
    string num_y;
    for (char c:in[4])
    {
        if (c ==',')
        {
            y.push_back(stod(num_y));
            num_y.clear();
        }
        else
        {
            num_y += c;
        }
    }
    y.push_back(stod(num_y));

    vector<string> cons;
    string con;
    for (char c:in[5])
    {
        if (c ==',')
        {
            cons.push_back(con);
            con.clear();
        }
        else
        {
            con += c;
        }
    }
    cons.push_back(con);

    vector<double> result(3,0.0);
    bool answer = true;

    for (int i = 0; i < 3; i++)
    {
        result[i] = dotProduct(matrix[i],x) - y[i];
        if (cons[i] == ">" && !(result[i] > 0))
        {
            answer =false;
        }
        if(cons[i] == ">=" && !(result[i] >= 0))
        {
            answer = false;
        }
        if (cons[i] == "<" && !(result[i] < 0))
        {
            answer = false;
        }
        if (cons[i] == "<=" && !(result[i] <= 0))
        {
            answer = false;
        }
        if (cons[i] == "=" && !(result[i] == 0))
        {
            answer = false;
        }        
    }
    
    double z = *(max_element(result.begin(),result.end()));
    cout << (answer ? "true" :"false") << " " << static_cast<int>(z) <<endl;
    
}