/*
 * LC 88. 合并两个有序数组
 *
 * 给你两个按非递减顺序排列的整数数组 nums1 和 nums2，
 * 以及两个整数 m 和 n，分别表示 nums1 和 nums2 中的元素数目。
 * 请你合并 nums2 到 nums1 中，使合并后的数组同样按非递减顺序排列。
 *
 * 注意：nums1 的初始长度为 m + n，后 n 个元素为 0，用于存放合并结果。
 *
 * 示例：
 *   nums1 = [1,2,3,0,0,0], m = 3
 *   nums2 = [2,5,6],       n = 3
 *   输出：[1,2,2,3,5,6]
 *
 * 要求：O(m+n) 时间，O(1) 空间
 * 提示：从后往前填会更自然，想想为什么。
 */

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // TODO
    int i=m-1,j=n-1,k=m+n-1; // 从后往前比起，k代表最后一个空闲的数。
    while(i>=0&&j>=0){
        if (nums1[i]>=nums2[j]){
            nums1[k]=nums1[i];
            k--,i--;
        }
        else {
            nums1[k]=nums2[j];
            k--,j--;
        }
    }
    if(j>=0){
        for(int t=j;t>=0;t--){
            nums1[k]=nums2[t];
            k--;
        }
    }

}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    for (int x : nums1) cout << x << " ";
    cout << endl; // 期望: 1 2 2 3 5 6
    return 0;
}
