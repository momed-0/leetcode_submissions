//https://leetcode.com/problems/contains-duplicate/

func containsDuplicate(nums []int) bool {
    hashMap := make(map[int]int);
    for i := range len(nums) {
        _, exists := hashMap[nums[i]];
        if exists {
            return true;
        }
        hashMap[nums[i]] = 1;
    }
    return false;
}

/*
  hashmap
  for num in arr:
    if exist in hashmapp:
        return true
    hashmap[num]++ 
  return false

  or sort the array and check if repeating
*/
