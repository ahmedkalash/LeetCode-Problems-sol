<?php

/**
 * Medium
 * Link: https://leetcode.com/problems/group-anagrams/description/
 * Constraints:
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * */

class Solution {
    /**
     * Approach:
     *      * If we changed the problem so that the value of strs[i] will consists of an array of prime numbers instead of a string of lowercase English letters - think of the string as an array of characters -
     *          so the new problem will be like that:
     *          Input: strs = [[2,3,5],[3,5,2],[3,5],[3],[5,3]]
     *          Output: [
     *                      [ [2,3,5], [3,5,2] ],
     *                      [ [3,5], [5,3] ],
     *                      [ [3] ]
     *                  ]
     *      * Nice, now what?
     *      * There is a math fact that the prime factors of a number are unique per that number
     *          this means that no two or more numbers will have the same prime factors,
     *          and due to the fact that the multiplication of any group of numbers in any order will have the same result,
     *          we can conclude that there is a one to one map between any number and its prime factors.
     *      * Nice, now what?
     *      * Are You sure?
     *      * Yeah!
     *      * Ok, now, according to what we have established, for each group of anagrams arrays, the multiplication of the values of each array will be the same
     *           because they are the same numbers but in different order.
     *          ex:
     *                [ 2*3*5 ==  3*5*2 == 30 ],
     *                [ 3*5   ==  5*3   == 15 ],
     *                [ 3     == 3 ]
     *      * Now we can achieve something like that:
     *      *  Anagrams = [
     *              '30'   => [2,3,5], [3,5,2],
     *              '15'   => [3,5], [5,3],
     *              '3'   => [3],
     *          ]
     *      * Now we have one problem which is the overflow problem, as the length of $strs[i] can be 100,
     *          so we can have a value like 2^100. We can easily solve this problem by taking the mod to a large prime number
     *          like (10^9 +7) when multiplying. See The Code.
     *      * Now we have solved the new version of the problem. How to solve the original one?
     *      * You can easily map each character to a prim number.
     *
     *      * Nice, now what?
     *      * Now it is your turn, bye!
     *
     * ------------------------------------------------------------------------------------------------
     * Time analysis:
     *      * without counting the steps the functions like str_split, array_values take!
     *      * The exact number of steps ( ∑ (strs[i].len) where 0 <= i < strs.length-1 )
     *      * The worst number of steps = 100*10^4 = 10^6
     *
     * Collision possibility
     *      * AS I remember, the collision possibility is (1/mod), and we are using mod = 10^9, so it will be 10^(-9)
     *          which is too small and will pass from testcases but generally if it happens will leed to wrong answer.
     * */

    protected function getMod(){
        return 1000000000+7;
    }

    protected function mapToPrime(string $char)
    {
        // If you see the below code is ugly, you can use sieve of eratosthenes instead I just wanted to make it simple (:
        $char_to_prime_map=[
            'a' => 2,
            'b' => 3,
            'c' => 5,
            'd' => 7,
            'e' => 11,
            'f' => 13,
            'g' => 17,
            'h' => 19,
            'i' => 23,
            'j' => 29,
            'k' => 31,
            'l' => 37,
            'm' => 41,
            'n' => 43,
            'o' => 47,
            'p' => 53,
            'q' => 59,
            'r' => 61,
            's' => 67,
            't' => 71,
            'u' => 73,
            'v' => 79,
            'w' => 83,
            'x' => 89,
            'y' => 97,
            'z' => 101
        ];

        return $char_to_prime_map[$char];
    }

    protected function hashPrimly(string $str){
        $chars_array = str_split($str);
        $hashedValue = 1;
        foreach ($chars_array as $char){
            $hashedValue = (
                    $hashedValue * $this->mapToPrime($char)
                )%$this->getMod();
        }
        return $hashedValue;
    }

    public function groupAnagrams($strs) {
        $groupedAnagrams = [];
        foreach ($strs as $str){
            if($str==''){
                $groupedAnagrams[-1][]=$str;
            }else{
                $groupedAnagrams[$this->hashPrimly($str)][]= $str;
            }
        }
        return array_values($groupedAnagrams);
    }

}