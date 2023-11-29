object(apple)  :- is_true("is red"), is_true("is a fruit"), is_true("grows on trees").
object(banana)  :- is_true("is yellow"), is_true("is a fruit"), is_true("is a good source of potassium").
object(orange) :- is_true("is orange"), is_true("is a fruit"), is_true("has vitamin C").
object(grape)  :- is_true("is purple"), is_true("is a fruit"), is_true("is often used to make wine").
object(pear)   :- is_true("is green"), is_true("is a fruit"), is_true("has a distinctive shape").

is_true(Q) :-
        format("~s?\n", [Q]),
        read(yes).
