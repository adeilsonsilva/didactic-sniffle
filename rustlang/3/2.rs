/// A function that converts characters like newline and tab into visible escape
/// sequences like \n and \t as it copies the string t to s.
///
/// @param  &str s Source string
///
/// @return String Scaped string
fn escape(s : &str) -> String
{
    let mut result = String::with_capacity(s.len());

    for c in s.chars() {
        match c {
            '\n' => {
                result.push('\\');
                result.push('\\');
                result.push('n');
            },
            '\t' => {
                result.push('\\');
                result.push('\\');
                result.push('t');
            },
            _ => {
                result.push(c);
            }
        }
    }

    result
}

/// A function that converts visible escape sequences like \n and \t into
/// characters like newline and tab as it copies the string t to s.
///
/// @param  &str s Source string
///
/// @return String (UN)escaped string
fn escape_back(s : &str) -> String
{
    let mut result = String::with_capacity(s.len());

    // We use a peekable iterator, so we can check characters ahead
    let mut iter = s.chars().peekable();

    loop {
        let mut _c = iter.next();

        match _c {
            None => {
                // There are no more bytes to be read
                break;
            },
            Some('\\') => {
                if iter.peek() == Some(&&'\\'){
                    _c = iter.next();
                }

                if iter.peek() == Some(&&'n'){
                    result.push('\n');
                } else if iter.peek() == Some(&&'t'){
                    result.push('\t');
                }
                iter.next();
            }
            _ => {
                result.push(_c.unwrap());
            }
        }
    }

    result
}

/// A program to test string copying.
/// For the sake of simplicity, we assume only '\t' and '\n' can be scaped.
fn main()
{
    let input1 = String::from("A \n test \t whatever.");

    let output1 = escape(&input1);

    print!("escape('{}') => '{}'\n", input1, output1);

    let output2 = escape_back(&output1);

    print!("escape_back('{}') => '{}'\n", output1, output2);
}
