class Solution {
    fun maxScore(s: String): Int {
        val n = s.length
        val zerosSum = IntArray(n)
        val onesSum = IntArray(n)

        var countZeros = 0
        var countOnes = 0

        // Prefix Sum de izquierda a derecha para ceros
        for (i in s.indices) {
            if (s[i] == '0') {
                countZeros++
            }
            zerosSum[i] = countZeros
        }

        // Prefix Sum de derecha a izquierda para unos
        for (i in n - 1 downTo 0) {
            if (s[i] == '1') {
                countOnes++
            }
            onesSum[i] = countOnes
        }
        var ans: Int = Int.MIN_VALUE
        for (i in 0 until n - 1) {
            ans = maxOf(zerosSum[i] + onesSum[i+1], ans)
        }
        return ans
    }
}