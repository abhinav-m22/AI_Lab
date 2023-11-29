im_sick:-
 guessing(Disease),
 write("after checking your symptoms i think u have: "),write(Disease),nl,
 write(" thats it take care and remmber Prevention is better than cure "),undo.

guessing(cold):- cold,!.
guessing(flu):- flu,!.
guessing(covid):-covid,!.

cold :-
    check(sore_throat),
    check(runny_nose),
    check(sneezing),
    check(shortness_of_breath),
    check(cough),
    check(nasal_congestion),
    check(respiratory_issuse),
    check(lossing_appetite),
write("inclubation period is 1-3 days so dont woory just
take panadol , rest and drink hot drinks because "),nl.
flu :-
    check(fever),
    check(lossing_appetite),
    check(chills),
    check(headache),
    check(body_aches),
    check(cough),
    check(fatigue),
write("inclubation period is 1-4 days take antiviral drugs 2 time for 5 days, 
for watry eays you take antihstamine helpful for your flu,
stay home and u may use cold compresses for the fever because "),nl.
covid :-
    check(loos_of_taste/smell),
    check(fever),
    check(lossing_appetite),
    check(chills),
    check(headache),
    check(shortness_of_breath),
    check(cough),
    check(respiratory_issuse),
write("inclubation period is 2-14 days
there is no cure discovered just eat well ,sleep well ,
drink plenty of fluids, open windos if u breathless  because "),nl.

ask(Q):-
    write("dear patient do you have this Symptom: "),
    write(Q),write('?'),read(Answer),nl,
    ((Answer==yes;Answer==y)->assert(yes(Q));
    assert(no(Q)),fail).
:- dynamic yes/1,no/1.

check(Symptoms):-
  (yes(Symptoms)->true;(no(Symptoms)-> fail;ask(Symptoms))).
undo :- retract(yes(_)),fail.
undo :- retract(no(_)),fail.
undo.