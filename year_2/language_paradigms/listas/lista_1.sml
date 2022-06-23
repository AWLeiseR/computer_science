fun is_older (d1: int list , d2: int list)=
  if null d1 then false
      else if (hd(d1)) < (hd(d2))
              then true
              else is_older (tl(d1),tl(d2))

fun number_in_month (d1: (int*int*int) list, m: int) =
    if null d1 
      then 0
      else if ((#2(hd(d1))) = m)
        then 1 + number_in_month (tl (d1), m)
        else number_in_month (tl (d1), m)

fun number_in_months (d1: (int*int*int) list, m2: int list) =
      if null m2 
      then 0
      else number_in_month(d1, hd(m2)) + number_in_months ( d1, tl(m2))

 

val v1 = [2000,12,30];
val v2 = [2000,12,31];
val L3 = [(2019, 01, 18), (2018, 01, 20), (2019, 01, 07), (2019, 01, 15)];
val m = 1;
val m2 = [03,01];

number_in_months(L3,m2);