has_symptom(john, fever).
has_symptom(john, headache).
has_symptom(mary, cough).
has_symptom(mary, fatigue).
has_symptom(jane, cough).
has_symptom(jane, fatigue).

diagnose_patient(Patient, Condition) :-
    has_symptom(Patient, fever),
    has_symptom(Patient, headache),
    Condition = flu.
diagnose_patient(Patient, Condition) :-
    has_symptom(Patient, cough),
    has_symptom(Patient, fatigue),
    Condition = common_cold.
diagnose_patient(_, unknown).