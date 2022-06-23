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

fun createCar(a:INT) =
    let
        val xs = createRandList(27, a, a*a)
        fun aux(xs:listINT, ys:listINT, zs:listINT, cont:INT) =
            if cont >18
                then aux(tl xs, hd xs::ys, zs, cont-1)
            else if cont>9
                then aux(tl xs, ys, hd xs::zs, cont-1)
            else (a, xs,ys,zs,[0])
    in
        aux(xs, [], [], 27)
    end;