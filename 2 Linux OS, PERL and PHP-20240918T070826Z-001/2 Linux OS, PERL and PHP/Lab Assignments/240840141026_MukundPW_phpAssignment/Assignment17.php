<?php
function countWebsitesStartingWithWWW($websites) {
    $count = 0;

    foreach ($websites as $website) {
        if (strpos($website, 'www.') === 0) {
            $count++;
        }
    }

    echo "Total number of websites starting with 'www': $count";
}

$websiteArray = ["www.google.com","www.msn.com","www.amazon.co.in","in.answers.yahoo.com",
    "en.m.wikipedia.com","codehs.gitbooks.io","www.coderanch.com"];

countWebsitesStartingWithWWW($websiteArray);
?>
