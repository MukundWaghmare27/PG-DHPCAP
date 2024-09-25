<?php

function sumNumbers() {
    $numbers = func_get_args();
    
    return array_sum($numbers);
}

$result = sumNumbers(10, 20, 30, 5);
echo "The sum is: " . $result;
?>
