<?php
    $string1 = htmlspecialchars($_POST['string1']);
    $string2 = htmlspecialchars($_POST['string2']);
    $string3 = htmlspecialchars($_POST['string3']);
    
    echo "<html>";
    echo "<head><title>Submitted Data</title></head>";
    echo "<body>";
    echo "<h1>Submitted Strings</h1>";
    echo "<ol>";
    echo "<li>" . $string1 . "</li>";
    echo "<li>" . $string2 . "</li>";
    echo "<li>" . $string3 . "</li>";
    echo "</ol>";
    echo "</body>";
    echo "</html>";
?>
