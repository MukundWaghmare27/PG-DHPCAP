<?php

function even($array) {
    $sum = 0;

    foreach ($array as $number) {

        if ($number % 2 === 0) {
            $sum += $number; 
        }
    }

    return $sum; 
}

$numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

$evenSum = even($numbers);

echo "Sum of even elements: $evenSum\n";

?>
