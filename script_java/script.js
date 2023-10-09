function exibirMensagemErro() {
	var urlParams = new URLSearchParams(window.location.search);
	var erro = urlParams.get('erro');
	if (erro === 'email_duplicado') {
		var mensagemErro = document.createElement('p');
		mensagemErro.style.color = 'red';
		mensagemErro.innerHTML = 'Este email já está registrado!';
		document.body.appendChild(mensagemErro);
	}else if (erro === 'senhas_iguais') {
		var mensagemErro = document.createElement('p');
		mensagemErro.style.color = 'red';
		mensagemErro.innerHTML = 'As senhas não coincidem!';
		document.body.appendChild(mensagemErro);
	}
}

