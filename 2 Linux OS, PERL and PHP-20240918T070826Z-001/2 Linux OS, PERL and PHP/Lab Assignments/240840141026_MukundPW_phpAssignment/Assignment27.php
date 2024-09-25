<?php
    function test($filename,$startno) {
    
        $file = fopen("sample.txt", "r");

        $lineno = $startno;

        while(!feof($file)){

            $line = fgets($file);

            echo $lineno . ". " . $line . "<br>";  

            $lineno++;
        }
        fclose($file);
        
    }
    test("sample.txt", 11); 
?>