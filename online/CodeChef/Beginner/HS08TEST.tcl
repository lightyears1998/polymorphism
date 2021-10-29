# ATM
# https://www.codechef.com/problems/HS08TEST

gets stdin line
lassign $line X Y

proc output {Z} {
    puts [format "%.2f" $Z]
}

if {$X % 5 != 0} {
    output $Y
} else {
    set Z [expr {$Y - $X - 0.5}]
    if {$Z >= 0} {
        output $Z
    } else {
        output $Y
    }
}
