<%@page import="java.text.SimpleDateFormat"%>
<%@page import="br.uel.contatos.Contato"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Efetuar Alteracao</title>
</head>
<body>

	<%
		Contato contato = (Contato)request.getAttribute("contato");
		SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
		String dataTexto = formatter.format(contato.getDataNascimento().getTime());
	
	%>

	<form action="efetuarAlteracao" method="POST">
		Nome: <input type="text" name="nome" value="<%=contato.getNome()%>"/> <br />
		Endereço: <input type="text" name="endereco" value="<%=contato.getEndereco()%>"/> <br />
		E-mail: <input type="text" name="email" value="<%=contato.getEndereco()%>"/> <br />
		Data de nascimento: <input type="text" name="dtnasc" value="<%=dataTexto%>"/> <br />
		<input type="hidden" name=id value="<%=contato.getId()%>"/> <br />
		<input type="submit" value="Alterar" />
	</form>
</body>
</html>