#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//Question 1-a
int MoneyRobbing(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = A[0];

    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 2] + A[i - 1], dp[i - 1]);
    }
    return dp[n];
}

//Question 1-b
int MoneyRobbingCicle(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    int res = 0;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = A[0];
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 2] + A[i - 1], dp[i - 1]);
    }
    res = dp[n - 1];
//    dp[0] = 0;
//    dp[1] = A[1];
    dp[1] = 0;
    dp[2] = A[1];
//    for (int i = 2; i <= n; ++i) {
//        dp[i] = max(dp[i - 2] + A[i], dp[i - 1]);
//    }
    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 2] + A[i - 1], dp[i - 1]);
    }
    res = max(res, dp[n]);
    return res;
}

//Question 3 求二叉搜索树的个数
int BSTcount(int n) {
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int tmpsum = 0;
        for (int j = 1; j <= i; ++j) {
            tmpsum += dp[j - 1] * dp[i - j];
        }
        dp[i] = tmpsum;
    }
    return dp[n];
}

//Question 4 Coin Changes
int CoinChanges(vector<int> &coins, int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < coins.size(); ++j) {
        for (int i = coins[j]; i <= n; ++i) {
            dp[i] += dp[i - coins[j]];
        }
    }
    return dp[n];
}

int main() {
    //question 1 求能偷得的最大金额
    vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    cout << "====question1 求能偷得的最大金额  在没有环的情况下结果为 ====" << endl;
    cout << MoneyRobbing(A) << endl;
    cout << "====question1 求能偷得的最大金额  在有环的情况下结果为 ====" << endl;
    cout << MoneyRobbingCicle(A) << endl;

    //question 3 求二叉搜索树个数
    cout << "====question3 求二叉搜索树个数====" << endl;
    cout << "给定节点数为3，二叉搜索树个数为：" << BSTcount(3) << endl;

    //question 4 计算零钱组合的方法数
    vector<int> coins = {1, 2, 5};
    cout << "====question4 计算零钱组合的方式====" << endl;
    cout << CoinChanges(coins, 5) << endl;
    return 0;
}
