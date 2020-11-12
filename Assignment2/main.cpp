#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

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

//Question 2 求最大可分集合大小
int LargestDivisibleSub(vector<int> &nums, int n) {
    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = dp[i];
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0) {
                tmp = max(dp[j] + 1, tmp);
            }
        }
        dp[i] = tmp;
        res = max(res, dp[i]);
    }
    return res;
}

//leetcode 368
vector<int> LargestDivSubset(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> forward(n, 0);
    vector<int> ans;
    if (n == 0) {
        return ans;
    }
    int resindex = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < (dp[j] + 1)) {
                dp[i] = dp[j] + 1;
                forward[i] = j;
            }
        }
        if (dp[i] > res) {
            res = dp[i];
            resindex = i;
        }
    }
    while (res--) {
        ans.push_back(nums[resindex]);
        resindex = forward[resindex];
    }
    return ans;
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

int SmallestDiffer(vector<int> stones) {
    int sum = 0, n = stones.size();
    for (int i = 0; i < n; ++i) {
        sum += stones[i];
    }
    int dp[n + 1][sum / 2 + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= sum / 2 + 1; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < sum / 2 + 1; ++j) {
            if (j >= stones[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return sum - 2 * dp[n][sum / 2];
}

int main() {
    //question 1 求能偷得的最大金额
    vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    cout << "====question1 求能偷得的最大金额  在没有环的情况下结果为 ====" << endl;
    cout << MoneyRobbing(A) << endl;
    cout << "====question1 求能偷得的最大金额  在有环的情况下结果为 ====" << endl;
    cout << MoneyRobbingCicle(A) << endl;

    //question 2 求最大可分集合
    cout << "====question2 求最大可分集合====" << endl;
    vector<int> nums = {3, 4, 16, 8};
    cout << LargestDivisibleSub(nums, 5) << endl;

    vector<int> ans = LargestDivSubset(nums);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    //question 3 求二叉搜索树个数
    cout << "====question3 求二叉搜索树个数====" << endl;
    cout << "给定节点数为3，二叉搜索树个数为：" << BSTcount(3) << endl;

    //question 4 计算零钱组合的方法数
    vector<int> coins = {1, 2, 5};
    cout << "====question4 计算零钱组合的方式====" << endl;
    cout << CoinChanges(coins, 5) << endl;

    //question 5 求分为两组石头的最小重量差
//    vector<int> stones = {1, 6, 11, 5};
    vector<int> stones = {3, 1, 4, 2, 2, 1};
    cout << "====question5 求分成两组石头的最小重量差====" << endl;
    cout << SmallestDiffer(stones) << endl;
    return 0;
}
