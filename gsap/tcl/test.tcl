proc facto { N } {
    if { $N == 0 } {
        return 1
    } else {
        set Next [expr $N - 1]
        expr $N * [ facto $Next ]
    }
}

proc mul { N M } {
    expr [ facto $N ] / [ facto $M ]
}

proc pstr { Str Time } {
    set RepCount [ RepeatString $Str $Time ]
    puts "String $Str was puts $Time times"
}

set globalInt 256
set globalString "Hello"