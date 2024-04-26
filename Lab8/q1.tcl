
puts "Enter a number greater than 4: "
flush stdout
set userInput [gets stdin]

# Check if the input is a positive integer greater than 4
if {![string is integer -strict $userInput] || $userInput <= 4} {
    puts "Invalid input. Please enter a positive integer greater than 4."
} else {
    # Convert the input to an integer
    set number [expr {$userInput}]

    if {$number % 2 == 0} {
        # Number is even, print even integers starting from 4
        for {set i 4} {$i <= $number} {incr i 2} {
            puts $i
        }
    } else {
        # Number is odd, print odd integers starting from 3
        for {set i 3} {$i <= $number} {incr i 2} {
            puts $i
        }
    }
}