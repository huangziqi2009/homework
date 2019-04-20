/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/

double myPow(double x, int n) {
    double pow = 1;    

    if (n < 0) {
        x = 1/x;
        n = -n;
    }
    
    while (n > 0) {
        
        if (n % 2 == 1) {
            pow = pow * x;
        }

        x = x * x;
        n = n >> 1;
    }
    
    return pow;
}

#include <stdio.h>

int main(int argc, char *argv[]) {

    double x = 2.0;
    int n = 5;
    double pow = myPow(x, n);

    printf("myPow(%f,%d) = %f.\n", x, n, pow);

    return 0;
}
