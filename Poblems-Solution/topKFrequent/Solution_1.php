<?php

namespace topKFrequent;

/**
 * Medium
 * Link: https://leetcode.com/problems/top-k-frequent-elements/description/
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * */


class Solution_1
{
    /* * *
     * Approach:
     *      * Build a frequency array from the input $nums array.
     *      * Sort it desc.
     *      * Take the first $k elements.
     *
     * ------------------------------------------------------------------------------------------------
     * Time analysis:
     *      * O(n * log(n)) where n is the size of the array.
     * * */




    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function topKFrequent($nums, $k) {
        $freq = [];
        foreach ($nums as $num){
            if(isset($freq[$num])){
                $freq[$num]++;
            }else{
                  $freq[$num] = 1;
            }
        }
        arsort($freq);
        $ans = [];
        $i= 1;
        foreach ($freq as $num =>$frequancy){
            if($i>$k){
                break;
            }
            $i++;
            $ans[]=$num;
        }
        return  $ans;
    }

}


