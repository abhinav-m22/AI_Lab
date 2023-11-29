% Knowledge Base
destination(paris, europe, culture, moderate, spring).
destination(tokyo, asia, culture, expensive, spring).
destination(new_york, north_america, shopping, expensive, autumn).
destination(dubai, middle_east, luxury, expensive, winter).
destination(bangkok, asia, beach, moderate, summer).
destination(rio_de_janeiro, south_america, beach, moderate, summer).
destination(london, europe, culture, moderate, summer).
destination(rome, europe, culture, moderate, spring).
destination(sydney, australia, beach, expensive, summer).
destination(amsterdam, europe, culture, moderate, spring).
destination(hong_kong, asia, shopping, expensive, autumn).
destination(cancun, north_america, beach, moderate, summer).
destination(cairo, africa, culture, cheap, spring).
destination(cape_town, africa, beach, moderate, summer).
destination(mexico_city, north_america, culture, cheap, autumn).
destination(moscow, europe, culture, moderate, winter).
destination(athens, europe, culture, moderate, summer).
destination(istanbul, europe, culture, moderate, spring).
destination(mumbai, asia, culture, cheap, winter).
destination(seoul, asia, culture, moderate, autumn).
destination(bali, asia, beach, moderate, summer).

% Rules for travel recommendations
recommendation(Destination, Budget, Interest, Weather) :-
    destination(Destination, _, Interest, Budget, Weather).

% User Interface
start :- 
    write('Welcome to the Travel Planning Expert System!'), nl,
    write('Please answer a few questions to get travel recommendations.'), nl,
    ask_budget(Budget),
    ask_interest(Interest),
    ask_weather(Weather),
    findall(Destination, recommendation(Destination, Budget, Interest, Weather), Destinations),
    display_destinations(Destinations).

ask_budget(Budget) :-
    write('What is your budget? (cheap, moderate, expensive, luxury): '),
    read(Budget).

ask_interest(Interest) :-
    write('What are you interested in? (culture, shopping, beach, luxury): '),
    read(Interest).

ask_weather(Weather) :-
    write('What is your preferred weather? (spring, summer, autumn, winter): '),
    read(Weather).

display_destinations([]) :-
    write('Sorry, no matching destinations found for your preferences.').
    
display_destinations(Destinations) :-
    write('Recommended destinations for you: '), nl,
    display_list(Destinations).

display_list([]).
display_list([H|T]) :-
    write('- '), write(H), nl, display_list(T).
