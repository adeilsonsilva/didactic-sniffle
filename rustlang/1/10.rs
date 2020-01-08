use std::io;

/// Copy input to output, replacing each tab by \t, each backspace by \b,
/// and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
fn main()
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

                // iterate list of chars read from input
                let _c : char;
                for _c in input.chars() {
                    match _c {
                        '\t'    => { print!("\\t");   },
                        '\x08'  => { print!("\\b");    }, // using '\b' will result in "error: unknown character escape: b"
                        '\\'    => { print!("\\\\");   }, // escaping the escape!
                        _       => { print!("{}", _c); },
                    }
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
