// https://leetcode.com/problems/concatenation-of-array/
func getConcatenation(nums []int) []int {
    length := len(nums);
    ans := make([]int, 2 *length);
    for i := range length {
        ans[i] = nums[i];
        ans[i + length] = nums[i];
    }
    return ans;
}

/*

nums[]
ans = []
for i in nums
    ans[i] = nums[i]
    ans[i+nums.length] = nums[i]
*/
