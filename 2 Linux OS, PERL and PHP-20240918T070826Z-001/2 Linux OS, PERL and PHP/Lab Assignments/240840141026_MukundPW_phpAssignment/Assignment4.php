<!-- WAP to produce two sums: sum of odd numbers and sum of even numbers from 1 to 100. -->
 <!-- Also compute their absolute difference. -->

<?php

$sumOfEven = 0;
$sumOfOdd = 0;

for ($i = 1; $i <= 100; $i++) {
    if ($i % 2 == 0) {
        $sumOfEven += $i;
    } else {
        $sumOfOdd += $i;
    }
}

$diff = $sumOfOdd - $sumOfEven;

echo "Sum of even no: $sumOfEven<br>";
echo "Sum of odd no: $sumOfOdd<br>";
echo "Difference : $diff";
?>
