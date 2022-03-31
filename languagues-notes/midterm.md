Logic Languages

 - Specfify what needs to be done or what needs constraints need to be satisfied
 - What needs to be true in the end. "Make it so" -Star Trek

Layout Engines use this.
 - "This should be above that, and to the left of this."

Logic programming is also part of more languages, because it does not micro manage the problem.

In SQL SELECT COUNT (*) 
FROM USERS WHERE(LastLogin > 365)
(but not HOW to compute this)

Functional.

Output = someFunctionOf(Input)
RecommendedSeatAssignments = SeatSelector(Passenger,Airplane,Flight)

Function Anti-Pattern:
Global bool passengerIsFirstClass = true/false;

List = ans[]

for (;;) {
    
    //make a new list with one more element
    
    //this is functional

    ans = append(ans,nextSeat);

    //modify the list (not functional)
    ans.append(nextSeat);   
}

Regular Expressions describe sets of strings.



Reg libraries can convert RE's into matcher, that can identify whether something is in that set or not.

    Ex: C id  [A-Za-z_][A-Za-z0-9_]*
    -?(0|([1-9][0-9]*)) //integers
    (if|else|while|do|const) //keywords
    
    plain letter x - {"x"}
    abc - {string s | s can be split into(maybe empty) = x + y + z | x in a, y in b, z in c}
    a|b|c - {s in a or s in b or s in c}
    
    a{n,m} = a repeated n to m times
    a{3,5} = (aaa|aaaa|aaaaa)

    a* = a{0,infinity}
    a+ = a{1,infinity}
    
    [A-C1-3] = (A|B|C|1|2|3)
    