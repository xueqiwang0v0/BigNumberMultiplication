//
//  main.cpp
//  BigNumberMultiplication
//  大数乘法
//  竖式手工计算方法
//
//  Created by 王雪琪 on 5/23/20.
//  Copyright © 2020 Xueqi Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    输入：大数A，B
    输出：结果C
    倒序相乘两个乘数的每一位，即为ai和bj，结果为cij。
 */
string multiply(string num1, string num2){
    // 其中一个乘数为0
    if(num1=="0" || num2=="0")
        return "0";
    // 向量vector是一个能够存放任意类型的动态数组
    vector<int> res(num1.length()+num2.length());
    // 倒序逐位相乘
    for(int i=num1.length()-1; i>=0; i--){
        int a = num1[i] - '0';
        for(int j=num2.length()-1; j>=0; j--){
            int b = num2[j] - '0';
            // 逐位相乘
            int c = res[i+j+1] + a*b;
            // 处理进位
            // 个位
            res[i+j+1] = c % 10;
            // 十位
            res[i+j] += c / 10;
        }
    }
    // 将倒序的结果变为正序
    string result = "";
    for(int i=0; i<res.size(); i++){
        // 最高位为0时不显示
        if(i==0 && res[0]==0)
            continue;
        result += res[i] + '0';
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // 输入乘数
    string num1, num2;
    cin >> num1 >> num2;
    // 输出结果
    cout << multiply(num1, num2) << endl;
    return 0;
}
