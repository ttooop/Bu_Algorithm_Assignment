#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//Question 1
int MonkeyandBanana(vector<int> &M, vector<int> &B, int N) {
    int ans = 0;
    sort(M.begin(), M.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < N; ++i) {
        ans = max(ans, abs(M[i] - B[i]));
    }
    return ans;
}

int main() {
    //question 1 猴子吃香蕉，最少时间
    vector<int> M = {1, 3, 6};
    vector<int> B = {2, 4, 6};
    cout << "====question1 求猴子吃香蕉问题，使得最后一个吃到香蕉的猴子花费的时间最小 ====" << endl;
    cout << MonkeyandBanana(M, B, M.size()) << endl;
    return 0;
}
