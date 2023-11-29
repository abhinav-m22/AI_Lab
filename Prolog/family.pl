male(parshu).
male(wasudev).
male(shyam).
male(ram).
male(pankaj).
male(manish).
male(nilesh).
male(deep).
male(kush).
male(punit).
male(devansh).
male(ansh).
male(rahul).
male(roshan).
male(pravin).
male(shlok).
male(raj).
male(ayush).
male(jagdish).
male(pradip).
male(hitesh).
male(neeraj).
male(suyog).
female(smita).
female(pramila).
female(radha).
female(meera).
female(shilpa).
female(preeti).
female(sheetal).
female(riya).
female(ruchi).
female(usha).
female(chanchal).
female(sayli).
female(sunita).
female(anchal).
female(shreya).
female(sangita).
female(mini).


% Parent-child relationships
parent(parshu, wasudev).
parent(parshu, shyam).
parent(parshu, ram).
parent(smita, wasudev).
parent(smita, shyam).
parent(smita, ram).
parent(wasudev, pankaj).
parent(wasudev, preeti).
parent(wasudev, nilesh).
parent(pramila, pankaj).
parent(pramila, preeti).
parent(pramila, nilesh).
parent(pankaj, deep).
parent(pankaj, riya).
parent(shilpa, deep).
parent(shilpa, riya).
parent(preeti, kush).
parent(preeti, punit).
parent(manish, kush).
parent(manish, punit).
parent(nilesh, devansh).
parent(nilesh, ansh).
parent(sheetal, devansh).
parent(sheetal, ansh).
parent(radha, rahul).
parent(radha, usha).
parent(radha, chanchal).
parent(shyam, rahul).
parent(shyam, usha).
parent(shyam, chanchal).
parent(rahul, shlok).
parent(ruchi, shlok).
parent(usha, raj).
parent(usha, ayush).
parent(roshan, raj).
parent(roshan, ayush).
parent(chanchal, sayli).
parent(pravin, sayli).
parent(ram, jagdish).
parent(ram, pradip).
parent(meera, jagdish).
parent(meera, pradip).
parent(jagdish, hitesh).
parent(jagdish,shreya).
parent(sunita,hitesh).
parent(sunita,shreya).
parent(pradip,mini).
parent(pradip,suyog).
parent(sangita,mini).
parent(sangita,suyog).


% Marriage relationships
married(parshu, smita).
married(wasudev,pramila).
married(shyam, radha).
married(ram, meera).
married(pankaj,shilpa).
married(manish,preeti).
married(nilesh,sheetal).
married(rahul,ruchi).
married(roshan,usha).
married(pravin,chanchal).
married(jagdish,sunita).
married(pradip,sangita).
married(hitesh,anchal).
married(neeraj,shreya).


brother(X,Y):- male(X),parent(Z,X),parent(Z,Y),X\=Y.


sister(X,Y):- female(X),parent(Z,X),parent(Z,Y),X\=Y.


husband(X,Y):- male(X),female(Y),married(X,Y).


wife(X,Y):- female(X),male(Y),married(Y,X).


son(X,Y):- male(X),parent(Y,X).


daughter(X,Y):- female(X),parent(Y,X).


grandmother(X,Y):- female(X),parent(X,Z),parent(Z,Y).


grandfather(X,Y):- male(X),parent(X,Z),parent(Z,Y).


mother(X,Y):- female(X),parent(X,Y).


father(X,Y):- male(X),parent(X,Y).


cousin(X,Y):- parent(P,X),parent(Q,Y),parent(Z,P),parent(Z,Q),P\=Q,X\=Y.


daughter_in_law(X, Y) :- female(X),married(Z,X),parent(Y, Z).


son_in_law(X,Y):- male(X),married(X,Z),parent(Y,Z).


maternaluncle_mama(X,Y):- parent(Z,Y),parent(P,Z),parent(P,X),male(X),female(Z).


maternalaunt(X,Y):- married(Z,X),maternaluncle(Z,Y).


uncle(X,Y):- parent(Z,Y),parent(P,Z),parent(P,X),Z\=X,male(X).


aunt(X,Y):- female(X),parent(Z,Y),married(P,X),parent(Q,Z),parent(Q,P),Z\=P,male(Z).


second_uncle(X,Y):- male(X),father(D,Y),father(Z,D),father(S,X),brother(S,Z),Z\=S.


second_aunt(X,Y):- female(X),father(D,Y),father(Z,D),husband(R,X),father(T,R),brother(T,Z).


second_maternal_uncle(X,Y):- male(X),mother(D,Y),father(Z,D),father(S,X),brother(S,Z),Z\=S.


second_maternal_aunt(X,Y):- female(X),mother(D,Y),father(Z,D),husband(R,X),father(T,R),brother(T,Z).


aunt_masi(X,Y):-sister(X,Z),mother(Z,Y).


second_cousin(X, Y) :- grandfather(W, Y), brother(W, Z), grandfather(Z, X).


great_grandfather(X, Z) :- father(X, Y), grandfather(Y, Z).


great_grandmother(X, Z) :- mother(X, Y), grandfather(Y, Z).


grandson(X, Y) :- male(X), grandmother(Y, X).


grandson_2(X, Y) :- male(X), grandfather(Y, X).


granddaughter(X,Y):-female(X), grandmother(Y,X).


granddaughter_2(X,Y):-female(X), grandfather(Y,X).


second_grandmother(X, Y) :- second_uncle(W, Y), mother(X, W).


second_grandfather(X, Y) :- second_uncle(W, Y), father(X, W).


sister_in_law(X,Y):-married(Z,Y),brother(Z,X).


second_sister_in_law(X,Y):- married(Z,Y),cousin(Z,X).


brother_in_law(X,Y):-married(X,Z),brother(Y,Z).


brother_in_law_2(X,Y):- married(X,Z),married(Y,W),sister(Z,W).


sisterinlaw_bhabhi1(X,Y):-husband(Z,X),parent(W,Z),parent(W,Y).