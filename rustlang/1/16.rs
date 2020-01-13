use std::io;

/// Print the longest input line.
/// Differing from the C implementation, we don't
/// need to set a max string size.
fn main ()
{
    // a mutable variable to hold input data
    let mut input = String::new();

    let mut max : usize = 0;
    let mut longest = String::new();

    // using rust infinite loop
    loop {
        match io::stdin().read_line(&mut input) {
            // io::Result::Ok receives the number of bytes read
            Ok (n_bytes) => {
                // case EOF is reached, "read_lines" will return 0 and we break out of the loop
                if n_bytes == 0 {
                    break;
                }

                // In Rust it's a bit easier to do...
                // Check documentation, tough, because of how strings are handled
                if input.chars().count() > max {
                    // "This length is in bytes, not chars or graphemes. In other words,
                    // it may not be what a human considers the length of the string."
                    max = input.chars().count();
                    longest = input.clone();
                }

                // we need to clear input buffer because "read_line" appends all read bytes to it
                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }

    print!("SIZE: {:04} | \"{}\"\n", max, longest);

}
