<?php
// Recupera os dados do formulário
$nome = $_POST['nome'];
$email = $_POST['email'];
$senha = $_POST['senha'];
$confirmacaoSenha = $_POST['confirmacao_senha'];

// Validação dos dados (você pode adicionar validações personalizadas aqui)

// Verifica se as senhas coincidem
if ($senha !== $confirmacaoSenha) {
    //echo "As senhas não coincidem!";
	header("Location: cadastrarUsuario.html?erro=senhas_iguais");
    exit;
}

// Conexão com o banco de dados (substitua as informações conforme a sua configuração)
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "bancoDeDadosTeste";

$conn = new mysqli($servername, $username, $password, $dbname);

// Verifica se houve erro na conexão
if ($conn->connect_error) {
    die("Falha na conexão com o banco de dados: " . $conn->connect_error);
}


// Verifica se o email já está registrado
$sqlCheckEmail = "SELECT * FROM usuarios WHERE email = '$email'";
$resultCheckEmail = $conn->query($sqlCheckEmail);

if ($resultCheckEmail->num_rows > 0) {
	//echo "Este email já está registrado!";
	header("Location: cadastrarUsuario.html?erro=email_duplicado");
	exit;
}


// Insere os dados na tabela 'usuarios'
$sql = "INSERT INTO usuarios (nome, email, senha) VALUES ('$nome', '$email', '$senha')";

if ($conn->query($sql) === TRUE) {
    //echo "Dados inseridos com sucesso!";
	header("Location: sucesso.html");
	exit;
}else {
	echo "Erro ao inserir os dados: " . $conn->error;
}

// Fecha a conexão com o banco de dados
$conn->close();
?>
