package br.uel.contatos;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class EfetuarAlteracaoServlet
 */
@WebServlet("/efetuarAlteracao")
public class EfetuarAlteracaoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public EfetuarAlteracaoServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String nome = request.getParameter("nome");
		String endereco = request.getParameter("endereco");
		String email = request.getParameter("email");
		String dataTexto = request.getParameter("dtnasc");
		Long id = Long.parseLong(request.getParameter("id"));
		
		Date date;
		try {
			date = new SimpleDateFormat("dd/MM/yyyy").parse(dataTexto);
		
		
			Calendar dataNascimento = 
					Calendar.getInstance();
			
			dataNascimento.setTime(date);
			
			Contato contato = new Contato();
			
			contato.setNome(nome);
			contato.setEndereco(endereco);
			contato.setEmail(email);
			contato.setDataNascimento(dataNascimento);
			contato.setId(id);
			
			ContatoDAO contatoDao = 
					new ContatoDAO();
			
			contatoDao.alterar(contato);
			
			RequestDispatcher view = 
					request.getRequestDispatcher("alterar-resposta.jsp");
			
			view.forward(request, response);
			
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			throw new RuntimeException(e);
		}
	}

}
