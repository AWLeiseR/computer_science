<%@page import="java.text.SimpleDateFormat"%>
<%@page import="br.uel.contatos.Contato"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ taglib uri='http://java.sun.com/jsp/jstl/fmt' prefix='fmt' %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Efetuar Alteracao</title>
</head>
<body>

	<form action="efetuarAlteracao" method="POST">
		Nome: <input type="text" name="nome" 
			value="${requestScope['contato'].nome}"/> <br />
		Endereço: <input type="text" name="endereco" 
			value="${requestScope['contato'].endereco}"/> <br />
		E-mail: <input type="text" name="email" 
			value="${requestScope['contato'].email}"/> <br />
		Data de nascimento: <input type="text" name="dtnasc" 
			value="<fmt:formatDate 
			value="${requestScope['contato'].dataNascimento.time}" 
			pattern="dd/MM/yyyy" />"/> <br />
		<input type="hidden" name=id value="${requestScope['contato'].id}"/> <br />
		<input type="submit" value="Alterar" />
	</form>
</body>
</html>