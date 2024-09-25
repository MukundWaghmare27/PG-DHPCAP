	<!-- Create a PHP script that will display the square of all numbers between 1 to 20.  -->
<!-- Use function to do the calculation -->

<?php

function square($num) {
    return $num * $num;
}

for ($i = 1; $i <= 20; $i++) {
    echo "The square of $i is " . square($i) . "<br>";
}

?>
