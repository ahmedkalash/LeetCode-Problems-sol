<?php

/**
 * Easy
 * Problem:  https://leetcode.com/problems/valid-anagram
 *
 * We need to check if all characters of string $s exist in $string $t,
 * and all characters of string $t exist in string $s.
 * ==> We need to check is {s} === {t}
 * {s} is a set that contain all the characters of the string $s.
 * {t} is a set that contain all the characters of the string $t.
 * */

function solution_1($s, $t) {

    // create a frequency array of $s
    $s_freq = [];
        foreach (str_split($s) as $char){
        ($s_freq[$char]!==null)? $s_freq[$char]++ :$s_freq[$char] = 1;
    }

    // create a frequency array of $t
    $t_freq = [];
        foreach (str_split($t) as $char){
        ($t_freq[$char]!==null)? $t_freq[$char]++ :$t_freq[$char] = 1;
    }

    // return $s_freq == $t_freq;   // this line does what code below does

    // I assume that {s} === {t} until I prove the opposite.
    $same = 1;

    // if there is a character in $s that does not exist in $t,
    // OR the frequency of a character in $s != its frequency in $t
    // then the two sets are not equal.

    foreach ($s_freq as $char =>$freq){
        if(!$t_freq[$char] || $t_freq[$char] !== $freq){
        $same = 0;
        break;
        }
    }

    // Till now, I am sure that all chars in $s exist in $t with the same frequency
    // but, we still want to make sure that $t does not have extra char that is not in $s
    if(count($s_freq) !== count($t_freq)){
        $same = 0;
    }

    return $same;

}




function solution_2($s, $t) {

    $s=str_split($s);
    $t=str_split($t);
    sort($s);
    sort($t);

    return $s == $t;

}



