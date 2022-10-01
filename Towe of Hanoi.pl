tower(N,From,To,Aux):-
	N>1,
	M is N-1,
	tower(M,From,Aux,To),
	tower(1,From,To,_),
	tower(M,Aux,To,From).

tower(1,From,To,_):-
	write('Move disk from'),
	write(From),
	write(' to '),
	write(To),
	nl.