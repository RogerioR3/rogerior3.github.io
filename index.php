<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Meu Repositório</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 600px;
            margin: 20px auto;
        }

        h1 {
            text-align: center;
        }

        ul {
            list-style-type: none;
            padding: 0;
        }

        li {
            margin-bottom: 8px;
        }

        a {
            text-decoration: none;
            color: #0366d6;
        }

        a:hover {
            text-decoration: underline;
        }
    </style>
</head>
<body>
    <h1>Meu Repositório</h1>
    <ul>
        <?php
        $dirs = array_filter(glob('*'), 'is_dir');
        foreach ($dirs as $dir) {
            echo "<li><a href=\"$dir\">$dir</a></li>";
        }
        ?>
    </ul>
</body>
</html>
