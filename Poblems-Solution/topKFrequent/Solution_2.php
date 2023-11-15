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


class Solution
{
    /* * *
     * Approach:
     *      * Build a frequency array $freq from the input $nums array.
     *      * Build a bucket array, the key should be the frequency, and the value should be a list of all values that has this frequency.
     *      * Iterate over this bucket array reversely and take the first $k elements you encounter in the list that is in the bucket array.
     *
     * ------------------------------------------------------------------------------------------------
     * Time analysis:
     *      * O(n) where n is the size of the array.
     *      * This is, in theory, but this implementation in php may take more time.
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

        $freq_sort = [];
        for ($i=0;$i<=10000;$i++){
            $freq_sort[$i]=[];
        }
        foreach ($freq as $num => $frequancy){
            $freq_sort[$frequancy][]=$num;
        }

        $ans = [];
        $ctr= 1;


        for ($i = 10000; $i >= 0; $i--) {
            if($ctr>$k){
                break;
            }

            if(count($freq_sort[$i])!=0){
                $ctr+=count($freq_sort[$i]);
                $ans= array_merge($ans,$freq_sort[$i]);
            }


        }


        return  $ans;
    }

}

