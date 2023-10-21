<?php
/**
 * Medium
 * Link: https://leetcode.com/problems/product-of-array-except-self/description/
 * */

class Solution {
    /* * *
    * Approach:
    *     * Build a prefix array that hold the accumulated product of the input array from the start to the end
    *     * Build a suffix array that hold the accumulated product of the input array from the end to the start
    *     * when i = 0 : ans[i] =  suffix[i+1]
    *     * else when i = n-1 : ans[i] = prefix[i-1]
    *     * else ans[i] = prefix[i-1] * suffix[i+1]
    *
    * ------------------------------------------------------------------------------------------------
    * Time analysis:
    *      * O(n) where n is the size of the array.
    *
    * Space analysis:
    *      * O(2*n) where n is the size of the input array.
    *
    * * */


    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function productExceptSelf($nums) {
        $nums_len = count($nums);
        $prefix = [];
        $prefix[0] = $nums[0];
        for ($i=1; $i<$nums_len; ++$i){
            $prefix[$i] = $prefix[$i-1] * $nums[$i];
        }


        $suffix = [];
        $suffix[$nums_len-1] = $nums[$nums_len-1];
        for ($i=$nums_len-2 ; $i>=0; --$i){
            $suffix[$i] = $suffix[$i+1] * $nums[$i];
        }


        $ans = [];
        for ($i=0; $i<$nums_len; ++$i){
            if($i == 0){
                 $ans[$i] =  $suffix[$i+1];
            }elseif ($i==$nums_len-1){
                 $ans[$i] = $prefix[$i-1] ;
            }else{
                $ans[$i] = $prefix[$i-1] * $suffix[$i+1];
            }
        }

        return $ans;


    }
}
