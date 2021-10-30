for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] x m d
    puts [expr {min($x + $d, $m * $x)}]
}
