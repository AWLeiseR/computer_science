package br.uel.contatos;

import java.io.IOException;
import java.util.LinkedList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class RemoverBuscaServlet
 */
@WebServlet("/removerBusca")
public class RemoverBuscaServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public RemoverBuscaServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String id = request.getParameter("sequenciaBusca");
		
		int idInt = new Integer(id);
		
		LinkedList<String> listaBuscados = 
				(LinkedList)request.getSession().getAttribute("listaBuscados");
		
		
		for (int i = 0; i < listaBuscados.size(); i++){
			System.out.println(i+" "+listaBuscados.get(i));
		}
		
		System.out.println("identificador de remoção "+idInt);
		
		listaBuscados.remove(idInt);
		
		for (int i = 0; i < listaBuscados.size(); i++){
			System.out.println(i+" "+listaBuscados.get(i));
		}
		
		//request.getSession().setAttribute("listaBuscados", listaBuscados);
		
		RequestDispatcher view = 
				request.getRequestDispatcher("buscar-contato.jsp");
		
		view.forward(request, response);
	}

	

}
