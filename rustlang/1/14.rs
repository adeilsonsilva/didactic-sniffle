use std::io;
use std::collections::HashMap; // using HashMap for the first time

/// A program that draws an histogram of the length of words from input.
fn main ()
{
    // a mutable variable to hold input data
    let mut input = String::new();

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
                for _c in input.chars() {
                    let freq = histogram
                                .entry(_c)         // Returns mutable reference or
                                .or_insert(0);     // inserts in case it is not on
                                                   // the HashMap.
                    *freq += 1;
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
    for (_char, _freq) in histogram.iter() {
        if *_freq > 0 {
            print!("{} ({:05}): ", _char, *_freq);

            for _l in 0..*_freq {
                print!("|")
            }

            print!("\n");
        }
    }
}
