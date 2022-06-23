package br.uel.contatos;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class BuscarContatoServlet
 */
@WebServlet("/buscar")
public class BuscarContatoServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public BuscarContatoServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		String nomeContato = request.getParameter("nomeContato");
		
		ContatoDAO contatoDAO = 
				new ContatoDAO();
		
		List<Contato> listaContatos = 
				contatoDAO.buscarPorNome(nomeContato);
		
		request.setAttribute("listaContatos", listaContatos);
		
		RequestDispatcher view = 
				request.getRequestDispatcher("buscar-resposta.jsp");
		
		view.forward(request, response);
		
		
	}

}
