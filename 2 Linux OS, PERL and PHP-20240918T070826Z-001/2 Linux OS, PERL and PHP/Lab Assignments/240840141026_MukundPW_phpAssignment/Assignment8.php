	<!-- Write a function that takes a mandatory character as first parameter and 
subsequently any no of strings. The method must concatenate the strings with the
 mandatory char as separator. -->

<?php

function conc($separator, ...$strings) {
    return implode($separator, $strings);
}

$result1 = conc('#', 'apple', 'banana', 'cherry');
$result2 = conc('*', 'PHP', 'is', 'fun');

echo $result1;
echo "<br>";
echo $result2;
?>
