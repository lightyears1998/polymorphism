# Cars and Bikes
# https://www.codechef.com/problems/TYRES

gets stdin T
while {$T > 0} {
    gets stdin N
    if {$N % 4 >= 2} {
        puts YES
    } else {
        puts NO
    }
    incr T -1
}
