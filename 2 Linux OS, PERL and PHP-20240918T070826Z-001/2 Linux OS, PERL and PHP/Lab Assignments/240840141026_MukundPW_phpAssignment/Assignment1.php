<!-- ⦁	Write a PHP script that has three positive numbers hardcoded and output the largest of them. -->

<?php
    //echo "hello charger <br>";
    $a = 2 ;
    $b = 51 ;
    $c = 29 ;
    
    if($a>$b && $a>$c){
        echo "a is the largest number i.e $a <br>";
    }
    else if( $b>$c){
        echo "b is the largest number i.e $b<br>";
    }
    else{
        echo "c is the largest number i.e $c";
    }
?>