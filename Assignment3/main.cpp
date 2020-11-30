#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
//    第一阶段
    int p;
//    第二阶段
    int f;
};

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

bool jobcompare(Job j1, Job j2) {
    return j1.f > j2.f;
}

//Question 2
long long int JobSchedule(int n, vector<Job> Job) {
    long long int ans = 0L, sumP = 0L;
    sort(Job.begin(), Job.end(), jobcompare);
    for (int i = 0; i < n; ++i) {
        ans = max(ans, sumP + Job[i].p + Job[i].f);
        sumP += Job[i].p;
    }
    return ans;
}

//Question 3
int CrossRiver(int n, vector<int> &Weight, int limit) {
    int ans = 0;
    sort(Weight.begin(), Weight.end());
    int i = 0, j = n - 1;
    while (i < j) {
        if (Weight[i] + Weight[j] <= limit) {
            ans = ans + 1;
            i += 1;
            j -= 1;
        } else {
            //体重超过limit则单独做一条船
            ans = ans + 1;
            j -= 1;
        }
        if (i == j) {
            ans = ans + 1;
        }
    }
    return ans;
}

//Question 4
void Partition(int n, int k, vector<int> &P) {
    const int mod = 998244353;
    int sum = 0, ans = 1;
    int pre = -1;
    //n=7,k=3
    //2 7 3 1 5 4 6;
    for (int i = 0; i < n; ++i) {
        if (P[i] >= (n - k + 1)) {
            sum += P[i];
            if (pre != -1) {
                ans = ans * (i - pre) % mod;
            }
            pre = i;
        }
    }
    cout << "max partition value: " << sum << "\t num of way: " << ans << endl;
}

//Question 5
int ToyBuildings(int n, vector<int> &Height) {
    int ans = 0;
//    5 1 3 1 2 7 2
    for (int i = 0; i < n - 1; ++i) {
        if (Height[i] <= Height[i + 1]) {
            continue;
        } else {
            ans = ans + (Height[i] - Height[i + 1]);
        }
    }
    return ans;
}

//Question 6
int CowCrossRiver(int n, vector<int> Cow) {
    int ans = 0;
    sort(Cow.begin(), Cow.end());
    for (int i = n; i > 0; i = i - 2) {
        if (i <= 2) {
            return ans + Cow[i - 1];
        } else if (i == 3) {
            return ans + Cow[0] + Cow[1] + Cow[2];
        } else if (i > 3) {
            int s1 = Cow[0] * 2 + Cow[i - 1] + Cow[i - 2];
            int s2 = Cow[0] + Cow[1] * 2 + Cow[i - 1];
            if (s1 > s2) {
                ans = ans + s2;
            } else {
                ans = ans + s1;
            }
        }
    }
    return ans;
}

int main() {
    //question 1 猴子吃香蕉，最少时间
    vector<int> M = {1, 3, 6};
    vector<int> B = {2, 4, 6};
    cout << "====question1 求猴子吃香蕉问题，使得最后一个吃到香蕉的猴子花费的时间最小 ====" << endl;
    cout << MonkeyandBanana(M, B, M.size()) << endl;

    //question 2 作业调度
    Job j1 = {1000, 3000};
    Job j2 = {2000, 2000};
    Job j3 = {3000, 1000};
    vector<Job> Job = {j1, j2, j3};
    cout << "====question2 作业调度最短时间====" << endl;
    cout << JobSchedule(3, Job) << endl;

    //question 3 过河问题
    vector<int> Weight = {3, 2, 2, 1};
    int limit = 3;
    cout << "====question3 求过河问题，需要的最少船只数量====" << endl;
    cout << CrossRiver(4, Weight, limit) << endl;

    //question 6 求最大分区值
    cout << "====question4 求最大分区值和分区情况=====" << endl;
    vector<int> P1 = {2, 7, 3, 1, 5, 4, 6};
    vector<int> P2 = {1, 7, 2, 3, 4, 5, 6};
    Partition(7, 3, P1);
    Partition(7, 3, P2);

    //question 5 玩具非递减排序
    cout << "====question5 求完成非递减序列的最小操作数 =====" << endl;
//    vector<int> Height = {5, 1, 3, 1, 2, 7, 2};
//    vector<int> Height = {5, 1, 3, 1};
    vector<int> Height = {5, 3, 2, 5};
    cout << ToyBuildings(4, Height) << endl;

    //question 6 牛过河问题
    cout << "====question6 求牛过河的最短时间 ====" << endl;
    vector<int> Cow1 = {1, 2, 5, 10};
    cout << CowCrossRiver(4, Cow1) << endl;
    vector<int> Cow2 = {1, 2};
    cout << CowCrossRiver(2, Cow2) << endl;
    vector<int> Cow3 = {1, 2, 5};
    cout << CowCrossRiver(3, Cow3) << endl;
    return 0;
}
