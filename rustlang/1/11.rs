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

    let (mut nl, mut nw, mut nc, mut _state) : (i32, i32, i32, STATE) = (0, 0, 0, STATE::OUT);

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
                    nc += 1;

                    if _c == '\n' {
                        nl += 1;
                    }

                    if _c == ' ' || _c == '\n' || _c == '\t' {
                        _state = STATE::OUT;
                    } else if let STATE::OUT = _state {
                        // this syntax is kinda confusing, but if I understand correctly,
                        // the compiler destrucutres the enum into its value so it becomes
                        // something like "if let 0 = 0"
                        _state = STATE::IN;
                        nw += 1;
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

    println!("{} {} {}", nl, nw, nc);
}
