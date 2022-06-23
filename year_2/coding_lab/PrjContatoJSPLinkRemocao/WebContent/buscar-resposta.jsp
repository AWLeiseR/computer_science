<%@page import="java.text.SimpleDateFormat"%>
<%@page import="br.uel.contatos.Contato"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ taglib uri='http://java.sun.com/jsp/jstl/core' prefix='c'%>
<%@ taglib uri='http://java.sun.com/jsp/jstl/fmt' prefix='fmt' %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<style>
	table, th, td { border: 1px solid black; }
</style>
<title>Resposta da busca</title>
</head>
<body>
	<table>
		<tr>
			<th> Nome </th>
			<th> Endereço </th>
			<th> E-mail </th>
			<th> Data de nascimento </th>
		</tr>
		
	<c:forEach var="contato" items="${requestScope['listaContatos']}">
		<tr>
			<td> ${contato.nome} </td>
			<td> ${contato.endereco} </td>
			<td> ${contato.email} </td>
			<td>
				<fmt:formatDate 
					value="${contato.dataNascimento.time}" pattern="dd/MM/yyyy" />
			</td>
			<td>
				<a href="/PrjContatoJSP/alterar?id=${contato.id}">Alterar</a>
			</td>
			<td>
				<a href="/PrjContatoJSP/excluir?id=${contato.id}">Excluir</a>
			</td>
		</tr>
	</c:forEach>	
	</table>
	
	<br />
	
	<a href="/PrjContatoJSP/buscar-contato.jsp">Buscar contato</a>
	
</body>
</html>