class Solution {
    fun isPathCrossing(path: String): Boolean {
        var walked: Set<Pair<Int, Int>> = mutableSetOf()
        var currX: Int = 0; var currY: Int = 0
        walked += Pair(currX, currY)
        var crossed: Boolean = true
        path.forEach { direction ->
            currX += when (direction) {
                'E' -> 1
                'W' -> -1
                else -> 0
            }

            currY += when (direction) {
                'N' -> 1
                'S' -> -1
                else -> 0
            }
            
            val coords: Pair<Int, Int> = Pair(currX, currY)
            if (coords in walked) {
                return true
            }
            walked += coords
        }
        return false
    }
}