	<!-- Write a php function that takes any number of integers, determines how many positive and
 negative values have been read, and computes the total and average of the 
 input values (not counting zeros). -->

<?php

function filter(...$numbers) {
    $positiveCount = 0;
    $negativeCount = 0;
    $total = 0;
    $nonZeroCount = 0;

    foreach ($numbers as $number) {
        if ($number > 0) {
            $positiveCount++;
        } elseif ($number < 0) {
            $negativeCount++;
        }

        if ($number !== 0) {
            $total += $number;
            $nonZeroCount++;
        }
    }

    $average =  $total / $nonZeroCount;

    return  [$positiveCount , $negativeCount , $total , $average];
}

$result = filter(10, -5, 0, 3, -2, 0, 7);
print_r($result);
?>
