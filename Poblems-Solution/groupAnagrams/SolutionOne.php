<?php

/**
 * Medium
 * Link: https://leetcode.com/problems/group-anagrams/description/
 * Constraints:
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * */

/**
 * @param String[] $strs
 * @return String[][]
 */
class Solution {

    /**
     * Approach:
     *      * How to check if two strings are anagrams?
     *      * One way to do this is to sort both of them is they are equal after soring then they are anagrams.
     *      * Nice, now what?
     *      * Now we can see that all anagrams can be mapped to a 'unique' value that results from sorting them,
     *          and no other value can be mapped to this value unless if it is an anagram of the other values,
     *          that is why it is a unique value.
     *      * Nice, now what?
     *      * Now we want to maintain a 'hashtable' -an array in php- which holds an array of anagrams as the value and
     *          their sorted value as the key.
     *      * Something like:
     *
     *          Anagrams = [
     *              'aet'   => ['eat', 'tea', 'ate'],
     *              'ant'   => ['tan', 'nat'],
     *              'abt'   => ['bat'],
     *          ]
     *
     *      * Nice, now what?
     *      * Now it is your turn, bye!
     *
     * ------------------------------------------------------------------------------------------------
     * Time analysis:
     *      * without counting the steps the functions like str_split, implode take!
     *      * The exact number of steps ( ∑ (strs[i].length * log(strs[i].length)) where 0 <= i < strs.length-1 )
     *      * O( 100 * log(100) * strs.length )
     *      * The worst number of steps is:  (100*log(100) * 10^4) = 6643856 step
     *
     * */



    function groupAnagrams($strs) {
        $groupedAnagrams = [];
        foreach ($strs as $index =>$str){
            $str = str_split($str);
            sort($str);
            $str = implode($str);
            $groupedAnagrams[$str][]= $strs[$index];
        }

        return $groupedAnagrams;
    }

}
