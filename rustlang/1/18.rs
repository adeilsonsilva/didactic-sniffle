use std::io;

/// Remove trailing blanks and whitespaces, delete blank lines.
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
                // We need to delete entirely blank lines.
                if input.chars().count() > 1 {
                    let trimmed = trim(&input);
                    println!("READ: {:04}; NEW SIZE: {:04} | {}", input.chars().count(), trimmed.chars().count(), trimmed);
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

/// A function that borrows the original input and return it trimmed.
fn trim (original : &String) -> &str {
    original.trim_end()
}
