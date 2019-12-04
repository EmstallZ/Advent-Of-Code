<?php
//main
$input = file_get_contents("input");
$input = explode("-", $input);

$arrAllNumbers = array();
$answer1 = 0;
$answer2 = 0;

for ($i = $input[0]; $i <= $input[1]; $i++) {
    $i = strval($i);
    if (strlen($i) == 6) {
        if ($i[0] == $i[1] || $i[1] == $i[2] || $i[2] == $i[3] || $i[3] == $i[4] || $i[4] == $i[5]) {
            if ($i[0] <= $i[1] && $i[1] <= $i[2] && $i[2] <= $i[3] && $i[3] <= $i[4] && $i[4] <= $i[5]) {
                $answer1++;
            }
        }
    }
}

for ($i = $input[0]; $i <= $input[1]; $i++) {
    $i = strval($i);
    if (strlen($i) == 6) {
        if (($i[0] == $i[1] && $i[1] != $i[2]) || ($i[1] == $i[2] && $i[2] != $i[3] && $i[2] != $i[0]) || ($i[2] == $i[3] && $i[3] != $i[4] && $i[3] != $i[1]) || ($i[3] == $i[4] && $i[4] != $i[5] && $i[3] != $i[2]) || ($i[4] == $i[5] && $i[5] != $i[3])) {
            if ($i[0] <= $i[1] && $i[1] <= $i[2] && $i[2] <= $i[3] && $i[3] <= $i[4] && $i[4] <= $i[5]) {
                $answer2++;
            }
        }
    }
}

print $answer1 . "\n" . $answer2;

?>