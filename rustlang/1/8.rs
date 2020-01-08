use std::io;

/// Counting blanks, tabs and newlines from stdin.
fn main()
{
    // a mutable variable to hold input data
    let mut input = String::new();

    let (mut blanks, mut tabs, mut nls) : (u32, u32, u32) = (0, 0, 0);

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
                        ' '  => { blanks += 1; },
                        '\t' => { tabs += 1;   },
                        '\n' => { nls += 1;    },
                        _    => {              }, // matches are exaustive, so we need to use
                                                  // this placeholder for every other case
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

    print!("\n==============================================\n");
    println!("Blanks: {}; Tabs: {}; Newlines: {}", blanks, tabs, nls);
}
