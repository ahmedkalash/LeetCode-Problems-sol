<?php

/**
 * Idea:
 *      - Find the peeks that can't be covered with water.
 *      - For each two consecutive peeks:
 *          - Calculate the area between them
 *          - Subtract the inner height value form the total area to get the inner water area
 *      - Accumulate the water area you get to the total water area
 * Time: O(n)
 * Space: O(n)
 * */


class Solution_1 {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        $size = count($height);
        $may_not_be_top = [];
        $greatest_so_far = $height[0];
        foreach ($height as $index => $value){
            if($index == 0){
                if(isset($height[$index+1]) && $height[$index] > $height[$index+1]){
                    $may_not_be_top[$index]=0;
                }else{
                    $may_not_be_top[$index]=2;
                }
            }
            elseif($index == $size-1){
                continue;
            }
            elseif($greatest_so_far > $value){
                $may_not_be_top[$index] = 1;
            }
            else{
                $may_not_be_top[$index] = 0;
                $greatest_so_far = $value;
            }
        }

        $greatest_so_far = $height[$size-1];
        for ($index=$size-1; $index>=0; $index--){
            if($index == $size-1){
                if(isset($height[$size-2]) && $height[$index] > $height[$size-2]){
                    $may_not_be_top[$index]=0;
                }else{
                    $may_not_be_top[$index]=2;
                }
            }
            elseif($index == 0){
                continue;
            }
            elseif($greatest_so_far > $height[$index]){
                $may_not_be_top[$index]++;
            }
            else{
                $greatest_so_far = $height[$index];
            }
        }


        $water_area = 0;
        for($index = 0; $index<$size; $index++){
            if($may_not_be_top[$index] != 2){
                $first_top = $index;
                $blocks_area = 0;
                for(++$index; $index<$size && ($may_not_be_top[$index]==2); $index++){
                    $blocks_area += $height[$index];
                }
                if($index >= $size){
                    continue;
                }

                $last_top = $index;
                $total_area = ($last_top - $first_top - 1) * min($height[$last_top] , $height[$first_top]);
                $water_area += $total_area-$blocks_area;
                $index--;
            }
        }

        return $water_area;
    }
}

