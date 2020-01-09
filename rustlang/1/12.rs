use std::io;

/// There's no code to build, as the exercise is about answering the question.
/// Check the C file for the answer.

/// Here's  a Rust bare-bone version of the UNIX wc program
fn main ()
{
    enum STATE {
        OUT = 0,
        IN = 1,
    }

    // a mutable variable to hold input data
    let mut input = String::new();

    let mut _state : STATE = STATE::OUT;
    let mut blanks : i32 = 0;

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

                    if _c == ' ' || _c == '\n' || _c == '\t' {
                        _state = STATE::OUT;
                        if blanks == 0 { print!("\n"); blanks += 1 }; // avoid printing lots of white spaces
                    } else if let STATE::OUT = _state {
                        _state = STATE::IN;
                    }

                    if let STATE::IN = _state {
                        print!("{}", _c);
                        blanks = 0;
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
