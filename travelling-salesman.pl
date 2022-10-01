domains
  town = symbol
  distance = unsigned
  rib = r(town,town,distance)
  tlist = town*
  rlist = rib*
predicates
  nondeterm way(town,town,rlist,distance)
  nondeterm route(town,town,rlist,tlist,distance)
  nondeterm route1(town,tlist,rlist,tlist,distance)
  nondeterm ribsmember(rib,rlist)
  nondeterm townsmember(town,tlist)
  nondeterm tsp(town,town,tlist,rlist,tlist,distance)
  nondeterm ham(town,town,tlist,rlist,tlist,distance)
  nondeterm shorterRouteExists(town,town,tlist,rlist,distance)
  nondeterm alltown(tlist,tlist)
  nondeterm write_list(tlist)
clauses
  write_list([]).
  write_list([H|T]):-
    write(H,' '),
    write_list(T).
  townsmember(X,[X|_]).
  townsmember(X,[_|L]):-
    townsmember(X,L).   
  ribsmember(r(X,Y,D),[r(X,Y,D)|_]).
  ribsmember(X,[_|L]):-
    ribsmember(X,L).   
    alltown(_,[]).
  alltown(Route,[H|T]):-
    townsmember(H,Route),
    alltown(Route,T).
 
  
  way(Town1,Town2,Ways,OutWayDistance):-
    ribsmember(r(Town1,Town2,D),Ways),
    OutWayDistance = D.
   
%/*
  
  way(Town1,Town2,Ways,OutWayDistance):-
    ribsmember(r(Town2,Town1,D),Ways), here...*/
    OutWayDistance = D.
%*/
 
  route(Town1,Town2,Ways,OutRoute,OutDistance):-
    route1(Town1,[Town2],Ways,OutRoute,T1T2Distance),
%SWITCH HERE
    way(Town2,Town1,Ways,LasDist),
    OutDistance = T1T2Distance + LasDist.
   
  route1(Town1,[Town1|Route1],_,[Town1|Route1],OutDistance):-
    OutDistance = 0.
  route1(Town1,[Town2|PassedRoute],Ways,OutRoute,OutDistance):-
    way(TownX,Town2,Ways,WayDistance),
    not(townsmember(TownX,PassedRoute)),
    route1(Town1,[TownX,Town2|PassedRoute],Ways,OutRoute,CompletingRoadDistance),
    OutDistance = CompletingRoadDistance + WayDistance.
 
  shorterRouteExists(Town1,Town2,Towns,Ways,Distance):-
     ham(Town1,Town2,Towns,Ways,_,Other),
         Other < Distance.
    tsp(Town1,Town1,Towns,Ways,BestRoute,MinDistance):-
    way(OtherTown,Town1,Ways,_),
        tsp(Town1,OtherTown,Towns,Ways,BestRoute,MinDistance).
 
  tsp(Town1,Town2,Towns,Ways,BestRoute,MinDistance):-
        ham(Town1,Town2,Towns,Ways,Route,Distance),
        not(shorterRouteExists(Town1,Town2,Towns,Ways,Distance)),
    BestRoute = Route,
    MinDistance = Distance.
    ham(Town1,Town2,Towns,Ways,Route,Distance):-
    route(Town1,Town2,Ways,Route,Distance),
%SWITCH HERE
    alltown(Route,Towns), 
    write_list(Route),
    write(" tD = ",Distance,"n").
%   fail.
   
goal
  AllTowns = [a,b,c,d],
  AllWays = [r(a,b,1),r(a,c,10),r(c,b,2),r(b,c,2),r(b,d,5),r(c,d,3),r(d,a,4)],
*/
  AllTowns = [a,b,c,d,e],
  AllWays = [r(a,c,1),r(a,b,6),r(a,e,5),r(a,d,8),r(c,b,2),r(c,d,7),r(c,e,10),r(b,d,3),r(b,e,9),r(d,e,4)],
  tsp(a,a,AllTowns,AllWays,Route,Distance),
%SWITCH HERE
%  tsp(a,b,AllTowns,AllWays,Route,Distance),
  write("Finally:n"),
  write_list(Route),
  write(" tMIN_D = ",Distance,"n").
