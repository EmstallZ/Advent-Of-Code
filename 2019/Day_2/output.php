<?php
//function
function programAlarm($input){
    $i = 0;
    $active = true;

    while ($active) {
        $opcode = $input[$i];
        if ($opcode == 99) {
            return $input[0];
        } elseif ($opcode == 1) {
            $input[$input[$i + 3]] = $input[$input[$i + 1]] + $input[$input[$i + 2]];
        } elseif ($opcode == 2) {
            $input[$input[$i + 3]] = $input[$input[$i + 1]] * $input[$input[$i + 2]];
        } else {
            return "more magic smoke";
        }
        $i += 4;
    }
}

function partTwo($arrInput, $output){
    for ($noun = 0; $noun <= 99; $noun++) {
        for ($verb = 0; $verb <= 99; $verb++) {
            $arrInput[1] = $noun;
            $arrInput[2] = $verb;
            if (programAlarm($arrInput) == $output) {
                $answer = 100 * $noun + $verb;
                return $answer;
            }
        }
    }
    return "Given number not found";
}

//main
$input = file_get_contents("input");
$input = explode(",", $input);

$input2 = file_get_contents("input");
$input2 = explode(",", $input2);

$input[1] = 12;
$input[2] = 2;

print programAlarm($input) . "\n";
print partTwo($input2, 19690720);

?>