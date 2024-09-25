
<?php
        $fahrenheit = $_POST['fahrenheit'];

        $celsius = ($fahrenheit - 32) * 5 / 9;

        echo "<h2>$fahrenheit °F is equal to " . round($celsius, 2) . " °C</h2>";
?>