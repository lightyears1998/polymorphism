# Solubility
# https://www.codechef.com/problems/SOLBLTY

for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] X A B
    puts [expr {((100 - $X) * $B + $A) * 10}]
}
