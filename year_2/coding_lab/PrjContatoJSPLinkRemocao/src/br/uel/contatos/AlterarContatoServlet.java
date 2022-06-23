package br.uel.contatos;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class AlterarContatoServlet
 */
@WebServlet("/alterar")
public class AlterarContatoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AlterarContatoServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ContatoDAO contatoDao = 
				new ContatoDAO();
		
		Long id = 
				Long.parseLong(request.getParameter("id"));
		
		Contato contato = 
				contatoDao.buscarPorId(id);
		
		request.setAttribute("contato", contato);
		
		RequestDispatcher view = 
				request.getRequestDispatcher("efetuar-alteracao.jsp");
		
		view.forward(request, response);
	}

}
