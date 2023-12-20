class Solution {
    fun buyChoco(prices: IntArray, money: Int): Int {
        var minimum = Int.MAX_VALUE;
        var sndMinimum = Int.MAX_VALUE
        for (number in prices){
            if (minimum > number){
                sndMinimum = minimum
                minimum = number
            } else if (sndMinimum > number){
                sndMinimum = number
            }
        }
        val sum = money - minimum - sndMinimum

        if(sum >= 0){
            return sum 
        }
        return money
    }
}