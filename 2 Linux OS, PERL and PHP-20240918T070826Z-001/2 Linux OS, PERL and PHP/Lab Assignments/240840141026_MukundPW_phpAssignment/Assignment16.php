<?php
function printEvenLengthWordsStartingWithA($words) {
    if (count($words) !== 5) {
        echo "Please provide exactly 5 words.";
        return;
    }

    foreach ($words as $word) {
        if (strlen($word) % 2 === 0 && (strtoupper($word[0]) === 'A')) {
            echo $word . "<br>";
        }
    }
}

$wordArray = ["Apple", "banana", "Avocado", "grape", "kiwi"];

printEvenLengthWordsStartingWithA($wordArray);
?>
