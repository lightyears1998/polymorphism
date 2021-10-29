# Chess Match
# https://www.codechef.com/problems/BLITZ3_2

gets stdin T
while {$T > 0} {
    lassign [gets stdin] N A B
    puts [expr {180*2 + 2*$N - $A - $B}]
    incr T -1
}
