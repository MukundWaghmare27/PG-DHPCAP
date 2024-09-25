<?php
function nameLength($names) {
    $longNames = [];

    foreach ($names as $name) {
        if (strlen($name) > 4) {
            $longNames[] = $name;
        }
    }

    if (!empty($longNames)) {
        echo "Employee names with more than 4 characters: " . implode(", ", $longNames);
    } else {
        echo "No employee names with more than 4 characters found.";
    }
}

$employeeNames = ["Joy", "Meena", "Anne", "Xi", "Veena"];
nameLength($employeeNames);
?>
