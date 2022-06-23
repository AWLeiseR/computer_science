<%@page import="java.text.SimpleDateFormat"%>
<%@page import="br.uel.contatos.Contato"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
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
	<%
		List<Contato> listaContatos = 
			(List<Contato>)request.getAttribute("listaContatos");
		
		for (int i = 0; i < listaContatos.size(); i++){
			%>
			<tr>
				<td>
					<%=listaContatos.get(i).getNome()%>
				</td>
				<td>
					<%=listaContatos.get(i).getEndereco()%>
				</td>
				<td>
					<%=listaContatos.get(i).getEmail()%>
				</td>
				<td>
					<%
					SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
					out.println(formatter.format(
							listaContatos.get(i).getDataNascimento().getTime()));
					%>
				</td>
				<td>
					<a href="/contatos/alterar?id=<%=listaContatos.get(i).getId()%>">Alterar</a>
				</td>
				<td>
					<a href="/contatos/excluir?id=<%=listaContatos.get(i).getId()%>">Excluir</a>
				</td>
			</tr>
		<%
		}
		%>
		
	</table>
</body>
</html>