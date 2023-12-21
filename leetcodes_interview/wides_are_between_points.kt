class Solution {
    fun maxWidthOfVerticalArea(points: Array<IntArray>): Int {
        val xs = mutableListOf<Int>()

        for (point in points) {
            xs.add(point[0])
        }
        xs.sort()

        var maxSize = Int.MIN_VALUE
        for (i in 0 until xs.size - 1) {
            maxSize = maxOf(maxSize, xs[i + 1] - xs[i])
        }

        return maxSize
    }
}