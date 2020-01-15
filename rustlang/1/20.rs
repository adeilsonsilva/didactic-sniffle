use std::io;

// Rust constants work the same way as symbolic constansts in C
const TABSTOP : i32 = 4;

/// A program 'detab' that replaces tabs in the input with the proper number of
/// blanks to space to the next tab stop. Basically, there is a tabstop every Nth
/// position in the input string and all we need to do is expand output with
/// whitespaces until the next tabstop every time a tab character (\t) is found
/// within length of the current tabstop. The concept of a tabstop makes more
/// sense in the context of typewriters and robust text editor (for alignment).
///
/// For more info on tabstops check: https://en.wikipedia.org/wiki/Tab_stop
fn main ()
{
    let mut input = String::new();

    loop {
        match io::stdin().read_line(&mut input) {
            Ok (n_bytes) => {
                // Break out of main loop if EOF has been reached.
                if n_bytes == 0 {
                    break;
                }

                // a mutable counter to keep track of where we are inside TABSTOP
                let mut idx : i32 = 0;

                for _c in input.chars() {
                    match _c {
                        '\t' => {
                            for _ in idx..TABSTOP {
                                print!(" ");
                            }
                        },
                        _ => {
                            print!("{}", _c);
                            idx += 1;
                        }
                    }

                    // Reset tabstop counter when limit is reached
                    // We don't need to reset when newline is found because 'read_line'
                    // function will read everything until a '\n' is found
                    if idx == TABSTOP {
                        idx = 0;
                    }
                }

                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }
}
