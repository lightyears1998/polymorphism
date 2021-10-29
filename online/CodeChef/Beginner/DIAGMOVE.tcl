# Diagonal Movement
# https://www.codechef.com/problems/DIAGMOVE

gets stdin T
while {$T > 0} {
    lassign [gets stdin] x y
    if {abs($x % 2) == abs($y % 2)} {
        puts YES
    } else {
        puts NO
    }
    incr T -1
}
