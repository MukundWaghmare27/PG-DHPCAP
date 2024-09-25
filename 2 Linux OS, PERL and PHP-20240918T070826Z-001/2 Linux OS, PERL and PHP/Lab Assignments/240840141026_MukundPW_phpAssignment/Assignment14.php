<?php
    $inputString = 'chamber';

    $cleanString = strtolower(str_replace(' ', '', $inputString));

    $reversedString = strrev($cleanString);

    if ($cleanString === $reversedString) {
        $result = "The string '$inputString' is a palindrome.";
    } else {
        $result = "The string '$inputString' is not a palindrome.";
    }

    echo "<h1>Result</h1>";
    echo "<p>$result</p>";
    echo "<p>Reversed String: '$reversedString'</p>";
?>
