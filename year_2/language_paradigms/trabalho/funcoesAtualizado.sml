fun thereIs (xs:int list, valor: int) =
    if null xs
        then false
    else if (hd(xs)=valor) 
        then true
    else thereIs(tl(xs), valor);

fun createRandList (max:int, seed1:int, seed2:int) =
    let
    	val nextInt = Random.randRange (1,36)
    	val r = Random.rand (seed1, seed2)
    	fun auxCreate(xs:int list, max:int, cont:int, ys:int list) =
    	    if cont = max orelse cont = 36
    	       then []
    	    else
        		let
        		    val x = nextInt r
        		in
        		    if thereIs(ys, x)
        	            then auxCreate(xs, max, cont, ys)
        	        else
        		        x::auxCreate(xs, max, cont+1, x::ys)
        		end;
    in
	    auxCreate([], max, 0, [])
    end;

fun createCar (a:int) =
    let
        val xs = createRandList(27, a, a*a)
        fun aux(xs:int list, ys:int list, zs:int list, cont:int) =
            if cont >18
                then aux(tl xs, hd xs::ys, zs, cont-1)
            else if cont>9
                then aux(tl xs, ys, hd xs::zs, cont-1)
            else (a, 0, xs, ys, zs, [0])
    in
        aux(xs, [], [], 27)
    end;

fun calculaVisitas (xs, vis, qtd) =
    case vis of
[] => qtd
      | vis  => if thereIs (xs, hd(vis))
then calculaVisitas(xs, tl(vis), qtd+1)
   else calculaVisitas(xs, tl(vis), qtd);


fun createInvoice (id:int, valor:int, lGratis:int list, lNormal:int list, lPremium: int list, visitas:int list) =
    let
val vRua = calculaVisitas([0], visitas, 0);
val vNormal  = calculaVisitas(lNormal, visitas, 0)  * 2;
val vPremium = calculaVisitas(lPremium, visitas, 0) * 4;
    in
(id, vNormal + vPremium + vRua)
    end;

fun addGList (idGaragem:int, carro:(INT*INT*listINT*listINT*listINT*listINT)) =
    (#1 (carro), #2 (carro), #3 (carro), #4 (carro), #5 (carro), idGaragem::(#6 (carro)));
								 
fun contemId(c1:carro,id:INT)=
thereIs(#3c1,id) orelse
thereIs(#4c1,id) orelse
thereIs(#5c1,id)