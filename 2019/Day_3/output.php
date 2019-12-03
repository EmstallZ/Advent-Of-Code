<?php
//functions
function findCrossed($arr1, $arr2){

    $arrPath1 = array();
    $arrPath2 = array();

    $path1 = [0, 0];
    $path2 = [0, 0];

    foreach ($arr1 as $direction) {
        if (stristr($direction, "R")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path1[0] += 1;
                $arrPath1[] = "$path1[0],$path1[1]";
            }
        }
        if (stristr($direction, "L")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path1[0] -= 1;
                $arrPath1[] = "$path1[0],$path1[1]";
            }
        }
        if (stristr($direction, "U")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path1[1] += 1;
                $arrPath1[] = "$path1[0],$path1[1]";
            }
        }
        if (stristr($direction, "D")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path1[1] -= 1;
                $arrPath1[] = "$path1[0],$path1[1]";
            }
        }
    }

    foreach ($arr2 as $direction) {
        if (stristr($direction, "R")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path2[0] += 1;
                $arrPath2[] = "$path2[0],$path2[1]";
            }
        }
        if (stristr($direction, "L")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path2[0] -= 1;
                $arrPath2[] = "$path2[0],$path2[1]";
            }
        }
        if (stristr($direction, "U")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path2[1] += 1;
                $arrPath2[] = "$path2[0],$path2[1]";
            }
        }
        if (stristr($direction, "D")) {
            $value = substr($direction, 1);
            for ($i = 1; $i <= $value; $i++) {
                $path2[1] -= 1;
                $arrPath2[] = "$path2[0],$path2[1]";
            }
        }
    }
    $arrCrossed = array_intersect($arrPath1, $arrPath2);

    $arrOutput = array("crossed" => $arrCrossed, "arrPath1" => $arrPath1, "arrPath2" => $arrPath2);
    return $arrOutput;
}

//main
$input_raw = file_get_contents("input");
$input_split = explode("\r\n", $input_raw);

$input1 = explode(",", $input_split[0]);
$input2 = explode(",", $input_split[1]);

$arrCrossed = findCrossed($input1, $input2)["crossed"];
$arrDistance = array();
foreach ($arrCrossed as $coordinate) {
    $x = explode(",", $coordinate)[0];
    $y = explode(",", $coordinate)[1];

    $arrDistance[] = abs($x) + abs($y);
}

$arrPath1 = findCrossed($input1, $input2)["arrPath1"];
$arrPath2 = findCrossed($input1, $input2)["arrPath2"];

$answer2 = array();

foreach (findCrossed($input1, $input2)["crossed"] as $value) {
    $answer2[] = array_search($value, $arrPath1) + array_search($value, $arrPath2) + 2;
}


print (min($arrDistance) . "\n");
print(min($answer2));

?>