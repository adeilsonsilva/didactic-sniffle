/// A function that expands shorthand notations like a-z in the string s1 into
/// the equivalent complete list abc...xyz in s2.
///
/// @param &str s1 The string with the shorthand notation
///
/// @return String The expanded string
fn expand(s1 : &str) -> String
{
    let mut result = String::new();

    // We use a peekable iterator, so we can check characters ahead
    let mut iter = s1.chars().peekable();

    // Dealing with leading dash.
    if iter.peek() == Some(&&'-'){
        iter.next();
    }

    loop {
        // Find first character of sequence.
        let first = iter.next();
        let last = if iter.peek() == Some(&&'-') {
                        iter.next();
                        // Just peek, without removing, because it might be the start of a new sequence later on
                        iter.peek()
                    } else {
                        // We have to return a reference here because that's what peek returns too
                        Some(&'-')
                    };

        if first == None {
            // No more characters to be read.
            break;
        } else if last != Some(&'-') {
            // iter.next() and iter.peek() both return options, so we have to unwrap them
            let begin : u8 = first.unwrap() as u8;
            // iter.peek() returns a reference, so we need to dereference to unwrap (E0606)
            let end : u8 = *last.unwrap() as u8;

            // Push characters to resultant array
            for _c in begin..end+1 {
                result.push(_c as char);
            }
        }
    }

    result
}

/// A program to test string expansion.
fn main()
{
    let input1 = String::from("a-z");

    let input2 = String::from("a-b-c");

    let input3 = String::from("a-z0-9");

    let input4 = String::from("-a-z");

    print!("expand('{}') => '{}'\n", input1, expand(&input1));

    print!("expand('{}') => '{}'\n", input2, expand(&input2));

    print!("expand('{}') => '{}'\n", input3, expand(&input3));

    print!("expand('{}') => '{}'\n", input4, expand(&input4));
}
