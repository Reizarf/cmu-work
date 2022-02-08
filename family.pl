#https://stackoverflow.com/questions/28102602/get-only-one-solution-for-sibling-pairs-in-family-tree
#docker build -t prolog .           //build the container
#docker run --rm -i -t prolog               //run the container
#swipl family.pl                     //open query


mother_child(trude, sally).
 
father_child(tom, sally).
father_child(tom, erica).
father_child(mike, tom).
father_child(mike,alice).

sibling(X, Y)      :- parent_child(Z, X), parent_child(Z, Y).
 
parent_child(X, Y) :- father_child(X, Y).
parent_child(X, Y) :- mother_child(X, Y).


#constraint based programming language
#maxima - wxmaxmima-developers.github.io

