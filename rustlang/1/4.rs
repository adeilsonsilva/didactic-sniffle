/// Print Celsius-Fahrenheit Table with header.
/// for fahr = 0, 20, ..., 300;
/// Floating-point version.
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
    print!("|   Celsius     |  Fahrenheit  |\n"); // "println!" to avoid unnecessary
    print!("|------------------------------|\n"); // new lines (it's a table, after all)

    while fahr <= upper { // parentheses are removed as suggested by the compiler
        celsius = (5.0/9.0) * (fahr-32.0);
        print!("|    {:6.1}     |     {:3.0}      |\n", celsius, fahr);
        fahr = fahr + step;
    }

    /* Print table footer */
    print!("|------------------------------|\n");
}
