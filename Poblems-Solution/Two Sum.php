<?php

/**
 * Easy
 * Problem:  https://leetcode.com/problems/two-sum/
 * */

/**
 * @param Integer[] $nums
 * @param Integer $target
 * @return Integer[]
 */
function solution_1($nums, $target)
{
      /**
       * Tow pointers
       * O(n*log(n))
       */

    $original_nums = $nums;
    sort($nums);
    $left = 0;
    $right = count($nums)-1;

    while ($left < $right){
        if(($nums[$left] + $nums[$right]) == $target){
            $left_value_index  = array_keys($original_nums,$nums[$left])[0];
            $right_value_index  = array_keys($original_nums,$nums[$right])[count(array_keys($original_nums,$nums[$right]))-1];
            return [$left_value_index,$right_value_index];
        }elseif(($nums[$left] + $nums[$right]) > $target){
            $right--;
        }else{
            $left++;
        }
    }

}




function solution_2($nums, $target) {
    /***
     * Frequency array
     * O(n)
     */

    // build the frequency array having that the key is the value of the $nums
    // and the value is an array contains the indices of each occurrence of an element in the $nums array
    $map = [];
    foreach ($nums as $key=> $value){
        $map[$value][]=$key;
    }


    foreach ($map as $key =>$indices){
        if (array_key_exists($target-$key, $map)){
           if($key== ($target-$key)   &&   count($indices)>=2){
               $left_value_index  = $indices[0];
               $right_value_index = $indices[count($indices)-1] ;
               return [$left_value_index,$right_value_index];
           }elseif($key== ($target-$key)){
               continue;
           }else{
               $left_value_index  = $indices[0];
               $right_value_index = $map[$target-$key][count($map[$target-$key])-1] ;
               return [$left_value_index,$right_value_index];
           }

        }
    }
}

print_r(
    solution_2(
        [3,2,4],
        6
    )
);

