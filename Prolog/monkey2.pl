% Dynamic facts to represent the state
:- dynamic at/2, has/1.

% Initial state of the monkey and bananas
at(monkey, floor).
at(box, floor).
at(bananas, ceiling).
has(bananas) :- false.

% Actions that the monkey can perform
% The monkey can climb the box
climb_box :-
    at(monkey, floor),
    at(box, floor),
    retract(at(monkey, floor)),
    assert(at(monkey, box)),
    write('Monkey climbs the box.'), nl.

% The monkey can grasp the bananas
grasp_bananas :-
    at(monkey, box),
    at(bananas, ceiling),
    retract(at(bananas, ceiling)),
    assert(has(bananas)),
    write('Monkey grasps the bananas.'), nl.

% Define the goal
goal :- has(bananas).

% Move function to achieve the goal
move :-
    goal,
    write('Goal achieved!'), nl.

move :-
    \+ goal,
    (climb_box ; grasp_bananas),
    move.

% Example query to run the program
% To see if the monkey can achieve the goal, run:
% ?- move.