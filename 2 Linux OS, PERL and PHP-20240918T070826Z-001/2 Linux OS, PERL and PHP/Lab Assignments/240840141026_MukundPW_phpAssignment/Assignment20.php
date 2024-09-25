<?php
// Check if the form was submitted
    // Get the input values
    $string1 = htmlspecialchars($_POST['string1']);
    $string2 = htmlspecialchars($_POST['string2']);
    
    // Initialize index position variable
    $index = strpos($string1, $string2);
    
    // Start HTML output
    echo "<html>";
    echo "<head><title>Search Result</title></head>";
    echo "<body>";
    
    if ($index !== false) {
        echo "<h1>Result</h1>";
        echo "<p>The smaller string was found at index: <strong>" . $index . "</strong>.</p>";
    } else {
        echo "<h1>Result</h1>";
        echo "<p>The smaller string was not found in the larger string.</p>";
    }

    echo "</body>";
    echo "</html>";
?>
