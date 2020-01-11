/// Print Fahrenheit-Celsius Table with header.
fn main()
{
    // these variables are declared mutable to be updated inside the loop
    // rust variables are immutable by default
    let (mut fahr, mut celsius) : (f32, f32);

    // Defining upper and lower limitf of temperature scale, as long as
    // the loop step, using rust tuple destructuring
    //
    // We have to use a float literal here (ex 3.0) or it won't compile
    let (lower, upper, step) : (f32, f32, f32) = (0.0, 300.0, 20.0);

    fahr = lower;

    /* Print table header */
    print!("|------------------------------|\n"); // here we use "print!" instead of
    print!("|  Fahrenheit  |   Celsius     |\n"); // "println!" to avoid unnecessary
    print!("|------------------------------|\n"); // new lines (it's a table, after all)

    while fahr <= upper { // parentheses are removed as warned by the compiler
        celsius = fahr_to_celsius(fahr);
        print!("|     {:3.0}      |    {:6.1}     |\n", fahr, celsius);
        fahr = fahr + step;
    }

    /* Print table footer */
    print!("|------------------------------|\n");
}

/// Converts Fahrenheit to Celsius.
fn fahr_to_celsius(fahr: f32) -> f32 {
    (5.0/9.0) * (fahr-32.0) // In Rust, the last statement without
                            // a semicolon is the return value. Interesting...
}
