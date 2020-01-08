use std::io;

/// Copy input to output, replacing each string of one or more blanks by a single blank.
fn main()
{
    // a mutable variable to hold input data
    let mut input = String::new();

    let mut blanks: u32 = 0;

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
                        ' '  => {
                            if blanks == 0 {
                                print!(" ");
                            }
                            blanks += 1;
                        },
                        _    => {
                            print!("{}", _c);
                            blanks = 0;
                        },
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
