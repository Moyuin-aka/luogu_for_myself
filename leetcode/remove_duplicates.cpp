/*
 * LC 26. 删除有序数组中的重复项
 *
 * 给你一个 升序排列 的数组 nums，请你原地删除重复出现的元素，
 * 使每个元素只出现一次，返回删除后数组的新长度。
 * 不要使用额外的数组空间，必须在原地修改输入数组。
 *
 * 示例：
 *   输入：nums = [0,0,1,1,1,2,2,3,3,4]
 *   输出：5，且 nums 前5位变为 [0,1,2,3,4]
 *
 * 要求：O(n) 时间，O(1) 空间
 * 提示：双指针——慢指针 slow 指向下一个要写入的位置，
 *       快指针 fast 遍历数组，遇到和 slow 不同的元素就写入。
 */

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int slow=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=nums[slow]){
            slow++;
            nums[slow]=nums[i];
        }
    }

    // TODO
    return slow+1;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len = removeDuplicates(nums);
    cout << "长度: " << len << endl; // 期望: 5
    for (int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << endl; // 期望: 0 1 2 3 4
    return 0;
}
