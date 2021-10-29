# Coldplay
# https://www.codechef.com/problems/SLOOP

for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] M S
    puts [expr {$M / $S}]
}
