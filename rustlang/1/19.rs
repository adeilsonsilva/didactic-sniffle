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
                let reversed = reverse(&input);
                println!("READ: {:04}; | {}", input.chars().count(), reversed);

                // we need to clear input buffer because "read_line" appends all read bytes to it
                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }
}

/// A function that borrows the original input and return it reversed.
fn reverse (original : &String) -> String {
    // to match C code we remove trailing newlines
    // also, we use trait methods to reverse char order and collect everything
    // into a new String object
    original.trim_end_matches('\n').chars().rev().collect::<String>()
}
