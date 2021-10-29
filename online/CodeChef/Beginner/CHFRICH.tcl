# Richie Rich
# https://www.codechef.com/problems/CHFRICH

gets stdin T
while {$T > 0} {
    lassign [gets stdin] A B X
    puts [expr {($B - $A) / $X}]
    incr T -1
}
