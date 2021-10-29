# The Preparations
# https://www.codechef.com/problems/SUPCHEF

gets stdin T

while {$T > 0} {
    gets stdin line
    lassign $line M N K
    if {$M > $N * $K} {
        puts YES
    } else {
        puts NO
    }
    incr T -1
}
