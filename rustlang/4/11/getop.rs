use std::io;

use calc::*;

static mut INPUT : String = String::new(); /// Holds characters from stdin (getchar simulation)

/// getop:  get next character or numeric operand
/// It is unsafe because we manipulate a static mut variable inside it.
pub unsafe fn getop(s: &mut String) -> char
{
    let mut c: char;

    s.clear();
    loop {
        c = getchar();

        if c != ' ' && c != '\t' {
            break;
        }
    }

    s.push(c);

    if !c.is_digit(10) && c != '.' {
        return c; // not a number
    }

    if c.is_digit(10) { // collect integer part
        loop {
            c = getchar();

            if c.is_digit(10) {
                s.push(c);
            } else {
                break;
            }
        }
    }

    if c == '.' { // collect fraction part
        loop {
            c = getchar();

            if c.is_digit(10) {
                s.push(c);
            } else {
                break;
            }
        }
    }

    return NUMBER;
}

/// A simulation of C getchar function.
/// It is unsafe because we manipulate a static mut variable inside it.
pub unsafe fn getchar() -> char
{
    let mut c = INPUT.pop();

    if c == None {
        // clear input so lines don't get appended
        INPUT.clear();

        match io::stdin().read_line(&mut INPUT) {
            Ok (_bytes) => {
                if _bytes == 0 { return EOF }
                INPUT = INPUT.chars().rev().collect::<String>();
                c = INPUT.pop();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }

    c.unwrap_or(EOF)
}
