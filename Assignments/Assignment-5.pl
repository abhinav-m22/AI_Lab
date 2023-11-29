% Facts
female(mary).
female(lisa).
female(susan).
female(emma).
male(john).
male(david).
male(alex).
male(paul).
parent(mary, david).
parent(alex, david).
parent(alex, lisa).
parent(david, susan).
parent(david, emma).
parent(emma, john).
parent(david, paul).
parent(paul, john).

% Rules
sister(X, Y) :- parent(Z, X), parent(Z, Y),
    female(X),
    X \== Y.

mother(X, Y) :- parent(X, Y),
    female(X).
father(X, Y) :- parent(X, Y),
    male(X).
brother(X, Y) :- parent(Z, X), parent(Z, Y),
    male(X).