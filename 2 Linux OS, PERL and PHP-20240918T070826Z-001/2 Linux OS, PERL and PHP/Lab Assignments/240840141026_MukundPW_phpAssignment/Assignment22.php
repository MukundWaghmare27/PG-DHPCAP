<?php
    $principal = $_POST['principal'];
    $years = $_POST['years'];
    $rate = $_POST['rate'];

    $simpleInterest = ($principal * $rate * $years) / 100;

    echo "<h2>Simple Interest: " . number_format($simpleInterest, 2) . "</h2>";

?>
