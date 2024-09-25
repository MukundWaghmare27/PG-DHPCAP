<!-- ⦁	Write a PHP prg that will print star(*) in the form of triangle. -->
 

<?php
    $n=7;
    for($i=1;$i<=$n;$i++){
        for($j=1;$j<=$n;$j++){
            if($i>=$j){
                echo "*";
            }else{
                echo "<br>";
            }
        }

    }
?>