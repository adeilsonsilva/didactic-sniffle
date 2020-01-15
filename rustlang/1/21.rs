use std::io;

const TABSTOPS : i32 = 4;

/// A program 'detab' that replaces tabs in the input with the proper number of
/// blanks to space to the next tab stop.
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

                // iterate list of chars read from input
                for _c in input.chars() {

                    match _c {
                        '\t' => {
                            for _ in 1..TABSTOPS {
                                print!(" ");
                            }
                        },
                        _ => {
                            print!("{}", _c);
                        }
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
