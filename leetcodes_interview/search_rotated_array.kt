class Solution {
    fun search(nums: IntArray, target: Int): Int {
        var l: Int = 0
        var r: Int = nums.size - 1

        while (l <= r) {
            var m: Int = (l + r) / 2
            if (nums[m] == target) return m
            
            // Verificación de las condiciones
            if (nums[l] <= nums[m] && nums[m] > nums[r]) {
                if (target >= nums[l] && target <= nums[m]) {
                    r = m - 1
                } else {
                    l = m + 1
                }
            } else if (nums[l] > nums[m] && nums[m] <= nums[r]) {
                if (target >= nums[m] && target <= nums[r]) {
                    l = m + 1
                } else {
                    r = m - 1
                }
            } else {
                if (target <= nums[m]) {
                    r = m - 1
                } else {
                    l = m + 1
                }
            }
        }
        return -1
    }
}
