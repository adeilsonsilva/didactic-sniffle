use std::io;

/// Print all input lines that are longer than 80 characters.
fn main ()
{
    // a mutable variable to hold input data
    let mut input = String::new();

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
                if input.chars().count() > 80 {
                    println!("SIZE: {:04} | \"{}\"", input.chars().count(), input);
                }

                // we need to clear input buffer because "read_line" appends all read bytes to it
                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }
}
