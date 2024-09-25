<!-- Write a function pow(x,y) that calculates xy. Do not use the Math predefined functions -->

<?php


function customPow($x, $y) {
    $result = 1;
    
        for ($i = 1; $i <= $y; $i++) {
            $result *= $x;
        }

    return $result;
}

echo "2^3 = " . customPow(2, 4) . "<br>";
?>
