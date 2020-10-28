#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//question 1
int MinElement(vector<int> &A, int low, int high, int n) {
    if (low == high)
        return A[low];
    if (high - low == 1)
        return min(A[low], A[high]);
    int mid = (low + high) / 2;
    if (A[mid] > A[0])
        return MinElement(A, mid + 1, high, n);
    else
        return MinElement(A, low, mid, n);
}

//question 3
int merge(vector<int> &A, int n, int left, int right, int mid) {
    int leftmidsum = 0, rightmidsum = 0, maxleftmidsum = 0, maxrightmidsum = 0;
    for (int i = mid; i >= left; --i) {
        leftmidsum = leftmidsum + A[i];
        maxleftmidsum = max(maxleftmidsum, leftmidsum);
    }
    for (int i = mid + 1; i <= right; ++i) {
        rightmidsum = rightmidsum + A[i];
        maxrightmidsum = max(maxrightmidsum, rightmidsum);
    }
    return maxleftmidsum + maxrightmidsum;
}

int MaxSum(vector<int> &A, int n, int left, int right) {
    //最简单case
    if (left == right)
        return A[left];
    //分
    int mid = (left + right) / 2;
    int leftsum = MaxSum(A, n, left, mid);
    int rightsum = MaxSum(A, n, mid + 1, right);
    //合——计算跨越左右部分的最大子序列和
    int midsum = merge(A, n, left, right, mid);
    return max(leftsum, max(rightsum, midsum));
}

//question 4
vector<int> TargetRange(vector<int> &A, int n, int target) {
    vector<int> res = {-1, -1};
    int left = 0, right = A.size() - 1;
    //寻找左边界
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] < target) {
            left = mid + 1;
        } else
            right = mid;
    }
    if (A[right] != target) return res;
    res[0] = right;
    //寻找右边界
    right = A.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] <= target) {
            left = mid + 1;
        } else
            right = mid;
    }
    res[1] = left - 1;
    return res;
}

//question 5
int TriangleDivide(int n) {
    if (n == 2 || n == 3)
        return 1;
    int ans = 0;
    for (int i = 2; i <= n - 1; ++i) {
        ans = ans + TriangleDivide(i) * TriangleDivide(n - i + 1);
    }
    return ans;
}

int SignificantInversions(vector<int> &A,int low,int high){
    if (low==high){
        return 0;
    }
    int mid=(low+high)/2;
    SignificantInversions(A,low,mid);
    SignificantInversions(A,mid+1,high);
    int res=0,i=low,j=mid+1;
    while (i<=mid&&j<=high){
        if (A[i]>3*A[j]){
            res+=(mid-i+1);
            j=j+1;
        } else
            i=i+1;
    }
    int bi=low,bj=mid+1,k=0;
    int* B=new int[high-low+1];
    while (bi<=mid&& bj<=high){
        if (A[bi]<A[bj]){
            B[k++]=A[bi++];
        } else{
            B[k++]=A[bj++];
        }
    }
    while (bi<=mid){
        B[k++]=A[bi++];
    }
    while (bj<=high){
        B[k++]=A[bj++];
    }
    for (int l = 0; l <= k-1; ++l) {
        A[low+l]=B[l];
    }
    return res;
}

int main() {

    //question 1 求旋转矩阵的最小值
    vector<int> A1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "====question 1 求旋转矩阵的最小值====" << endl;
    cout << "旋转数组的最小值为: " << MinElement(A1, 0, 6, 7) << endl;

    //question 3 求最大子序列和
    vector<int> A3 = {-1, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "====question 3 求最大子序列和====" << endl;
    cout << "最大子序列和为：" << MaxSum(A3, 9, 0, 8) << endl;

    //question 4 求递增数组中目标值的所在区间
    vector<int> A4 = {5, 7, 7, 8, 8, 10};
    int target = 8;
    cout << "====question 4 求递增数组中目标值的所在区间====" << endl;
    vector<int> res = TargetRange(A4, 6, 8);
    cout << "目标值" << target << "在数组A4中的区间是：" << res[0] << "," << res[1] << endl;

    //question 5 凸多边形的三角剖分
    cout << "====question 5 凸多边形的三角剖分====" << endl;
    //输入：n多边形的顶点数
    int n = 5;
    //输出：多边形的三角剖分
    cout << n << "变形的三角剖分为: " << TriangleDivide(n) << endl;

    //question 6 显著逆序列数
    cout<<"====question 6 显著逆序列数===="<<endl;
    vector<int> A6={7,1,9,2,3,5,0};
    cout<<"显著逆序列数为："<<SignificantInversions(A6,0,6)<<endl;

    return 0;
}
