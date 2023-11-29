% Facts
destination(beach, 'Maldives').
destination(mountain, 'Swiss Alps').
destination(city, 'Paris').
destination(adventure, 'Costa Rica').

accommodation('Maldives', luxury_resort).
accommodation('Swiss Alps', chalet).
accommodation('Paris', hotel).
accommodation('Costa Rica', eco_lodge).

activity('Maldives', snorkeling).
activity('Swiss Alps', skiing).
activity('Paris', sightseeing).
activity('Costa Rica', zip_lining).

% Rules
recommended_destination(X, Budget) :-
    destination(X, _),
    affordable_accommodation(X, Budget),
    preferred_activity(X).

affordable_accommodation(Destination, Budget) :-
    accommodation(Destination, AccommodationType),
    cost(AccommodationType, Cost),
    Budget >= Cost.

preferred_activity(Destination) :-
    activity(Destination, Activity),
    likes_activity(Activity).

likes_activity(sightseeing).

% Costs of accommodations
cost(luxury_resort, 500).
cost(chalet, 300).
cost(hotel, 200).
cost(eco_lodge, 150).