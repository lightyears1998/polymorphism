# Cyclic Quadrilateral
# https://www.codechef.com/problems/CYCLICQD

for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] A B C D
    if {$A + $C == 180 && $B + $D == 180} {
        puts YES
    } else {
        puts NO
    }
}
