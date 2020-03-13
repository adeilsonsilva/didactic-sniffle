use std::io;

// Pattern to be searched for.
const PATTERN : &str = "ould";

/// A program to test pattern search.
fn main()
{
    let mut input = String::new();

    loop {
        match io::stdin().read_line(&mut input) {
            Ok (_bytes) => {
                if _bytes == 0 {
                    break;
                }

                let trimmed_input = input.trim_end();
                let pos: i32 = strindex(trimmed_input, PATTERN);

                print!("[*] Rightmost position of '{}' in '{}' is: '{}'\n", PATTERN, trimmed_input, pos);

                // clear input so lines don't get appended
                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }
}

/// A function to check for the rightmost occurrence of t in s.
///
/// @param &str s The string to be searched at
/// @param &str t The pattern to be searched for
///
/// @return i32   Position of rightmost occurrence of t inside s.
fn strindex(s: &str, t: &str) -> i32
{
    let mut rightmost : i32 = -1;

    for (idx, _) in s.chars().enumerate() {
        let mut str_iter = s.chars().skip(idx+1);
        let mut pattern_iter = t.chars();
        let mut k = 0;
        let pend;

        loop {
            let _sc = str_iter.next();
            let _pc = pattern_iter.next();

            if _pc == None || _sc != _pc {
                pend = _pc;
                break;
            }


            k += 1;
        };

        if k > 0 && pend == None {
            rightmost = (idx+1) as i32;
        }
    }

    rightmost
}