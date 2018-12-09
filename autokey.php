<?php

$text = "";
$pass = "AUTOKEY";

echo "Plain text: " . $text;
echo '<br>';
echo "Password: " . $pass;
echo '<br>';

$encodedText = autokey($text, $pass, true);
echo "Encoded: " . $encodedText;
echo '<br>';
$decodedText = autokey($encodedText, $pass, FALSE);
echo "Decoded: " . $decodedText;
echo '<br>';

function autokey($src, $key, $is_encode)
{
    $key = strtoupper($key);
    $src = strtoupper($src);
    $dest = '';

    for($i = 0; $i <= strlen($src); $i++) {
        $char = substr($src, $i, 1);
        if(ctype_upper($char)) {
            $dest .= $char;
        }
    }

    for($i = 0; $i <= strlen($dest); $i++) {
        $char = substr($dest, $i, 1);
        if(!ctype_upper($char)) {
            continue;
        }

        if($is_encode)
        {
            $key .= $char;
        }

        $dest = substr_replace($dest,
            chr (
                ord('A') +
                ($is_encode
                    ? ord($char) - ord('A') + ord($key[$i % strlen($key)]) - ord('A')
                    : ord($char) - ord($key[$i % strlen($key)]) + 26
                ) % 26
            )
            , $i, 1);

        if(!$is_encode)
        {
            $key .= $dest[$i];
        }
    }
    return $dest;
}