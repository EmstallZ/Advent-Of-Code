<?php
//functions
function fuelRequired1($mass){
    $mass = trim($mass);
    $mass /= 3;
    $mass = floor($mass);
    $mass -= 2;

    return $mass;
}

function fuelRequired2($mass){
    $mass = trim($mass);
    $mass /= 3;
    $mass = floor($mass);
    $mass -= 2;
    $totalmass = $mass;

    while ($mass > 0) {
        $mass = fuelRequired1($mass);
        if ($mass < 0){
            $mass = 0;
        }
        $totalmass += $mass;
    }
    return $totalmass;
}

//main
$input = file_get_contents("input");
$input = explode("\n", $input);
$sumFuelRequired1 = 0;
$sumFuelRequired2 = 0;

for ($i = 0; $i < count($input); $i++) {
    $sumFuelRequired1 += fuelRequired1($input[$i]);
    $sumFuelRequired2 += fuelRequired2($input[$i]);
}


print $sumFuelRequired1 . "\n";
print $sumFuelRequired2;

?>