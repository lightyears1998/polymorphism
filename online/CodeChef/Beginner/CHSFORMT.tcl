for {gets stdin T} {$T} {incr T -1} {
    lassign [gets stdin] a b
    set sum [expr {$a + $b}]
    if {$sum < 3} {
        puts 1
    } elseif {$sum <= 10} {
        puts 2
    } elseif {$sum <= 60} {
        puts 3
    } else {
        puts 4
    }
}
