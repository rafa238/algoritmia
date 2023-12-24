class Solution {
    fun minOperations(s: String): Int {
        //zeros: bad positioning zeros
        //ones: bad positioning ones
        var answer: Int = Int.MAX_VALUE; var zeros: Int = 0; var ones: Int = 0

        for (i in 0 until s.length step 2) {
            if (s[i] == '1') {
                ones++
            }
            if (i+1 < s.length && s[i+1] == '0') {
                zeros++
            }
        }
        answer = minOf(answer, ones + zeros)
        zeros = 0 
        ones = 0
        for (i in 0 until s.length step 2) {
            if (s[i] == '0') {
                zeros++
            }
            if (i+1 < s.length && s[i+1] == '1') {
                ones++
            }
        }
        answer = minOf(answer, ones + zeros)

        return answer
    }
}