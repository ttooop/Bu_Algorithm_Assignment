#include <iostream>
#include <cstdio>

using namespace std;

int TriangleDivide(int n) {
    if (n == 2 || n == 3)
        return 1;
    int ans = 0;
    for (int i = 2; i <= n - 1; ++i) {
        ans = ans + TriangleDivide(i) * TriangleDivide(n - i + 1);
    }
    return ans;

}

int main() {


    //question 5 凸多边形的三角剖分
    cout << "====question 5 凸多边形的三角剖分====" << endl;
    //输入：n多边形的顶点数
    int n = 5;
    //输出：多边形的三角剖分
    cout << n << "变形的三角剖分为" << TriangleDivide(n) << endl;
    return 0;
}
