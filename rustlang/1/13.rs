use std::io;
use std::collections::HashMap; // using HashMap for the first time

/// A program that draws an histogram of the length of words from input.
fn main ()
{
    enum STATE {
        OUT = 0,
        IN = 1,
    }

    // We will set a max length to match the C program
    let max_length = 1001; // TIL 'MAX_LENGTH' is not in snake case

    // a mutable variable to hold input data
    let mut input = String::new();

    let mut _state : STATE = STATE::OUT;
    let mut word_size : i32 = 0;

    // We will use a hashmap to hold our histogram values
    let mut histogram = HashMap::new();

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
                        // The end of a word.
                        if word_size > 0 && word_size < max_length {
                            let freq = histogram
                                        .entry(word_size) // Returns mutable reference or
                                        .or_insert(0);    // inserts in case it is not on
                                                          // the HashMap.
                            *freq += 1;
                        }
                        word_size = 0;
                    } else if let STATE::OUT = _state {
                        _state = STATE::IN;
                    }

                    if let STATE::IN = _state {
                        // Start of a new word
                        word_size += 1;
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

    // Prints horizontal histogram
    for _idx in 1..max_length {
        let freq = histogram.entry(_idx).or_insert(0);

        if *freq > 0 {
            print!("{:05} ({:05}): ", _idx, *freq);

            for _l in 0..*freq {
                print!("|")
            }

            print!("\n");
        }
    }
}
