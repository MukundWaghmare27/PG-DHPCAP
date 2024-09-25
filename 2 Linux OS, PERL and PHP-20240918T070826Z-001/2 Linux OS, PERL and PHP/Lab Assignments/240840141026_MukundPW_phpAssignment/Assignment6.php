	<!-- Write a php function that accepts two numbers and an operator like (+,-,*, /) and -->
 <!-- perform the appropriate operation indicated by the operator. Use switch case -->

<?php

function calculate($num1, $num2, $operator) {
    switch ($operator) {
        case '+':
            return $num1 + $num2;
        case '-':
            return $num1 - $num2;
        case '*':
            return $num1 * $num2;
        case '/':
            if ($num2 != 0) {
                return $num1 / $num2;
            } else {
                return "Error: Division by zero.";
            }
        default:
            return "Error: Invalid operator.";
    }
}

$result1 = calculate(10, 5, '+');
$result2 = calculate(10, 5, '-');
$result3 = calculate(10, 5, '*');
$result4 = calculate(10, 0, '/');
$result5 = calculate(10, 5, '/');
$result6 = calculate(10, 5, '%'); 
echo "10 + 5 = $result1<br>";
echo "10 - 5 = $result2<br>";
echo "10 * 5 = $result3<br>";
echo "10 / 5 = $result5<br>";
echo "10 / 0 = $result4<br>";
echo $result6; 
?>
