<?php

$numbers = [10, 20, 30, 40, 50];

$sum = array_sum($numbers);

$average = $sum / count($numbers);

$countLessThanAverage = 0;

foreach ($numbers as $number) {
    if ($number < $average) {
        $countLessThanAverage++;
    }
}

echo "Sum: $sum\n";
echo "Average: $average\n";
echo "Count of values less than average: $countLessThanAverage\n";
?>
