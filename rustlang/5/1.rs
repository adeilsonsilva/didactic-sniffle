use std::io;

const EOF: char = '#';                        // Simulating C EOF char
const SIZE : usize = 100;                   // Max size for array of numbers

const BUFSIZE : usize = 100;                // Max size for ungetch buffer
static mut BUFFER : Vec<char> = Vec::new(); // Buffer to control characters

static mut INPUT : String = String::new();  // Holds characters from stdin (getchar simulation)

fn main()
{
    let mut array: Vec<i64> = Vec::with_capacity(SIZE);
    let mut n = 0;

    unsafe {
        while n < SIZE {
            // Altough the capacity is set, the length is 0
            array.push(0);

            if getint(&mut array[n]) == 0 {
                break;
            }

            println!("Read: {}", array[n]);

            n += 1;
        }
    }
}

/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn getint(pn: &mut i64) -> i32
{
    let mut c: char = ' ';

    // skip white spaces
    while c.is_whitespace() {
        c = getch();
    }

    // skip invalid characters before signal character
    while
        !c.is_ascii_digit()
        && c != EOF
        && c != '+'
        && c != '-'
    {
        c = getch();
    }

    let sign = if c == '-' { -1 } else { 1 };

    if c == '+' || c == '-' {
        c = getch();
    }

    // skip invalid characters after signal character
    while
        !c.is_ascii_digit()
        && c != EOF
        && c != '+'
        && c != '-'
    {
        c = getch();
    }

    *pn = 0;

    while c.is_ascii_digit() {
        *pn = 10 * *pn + (c.to_digit(10).unwrap_or(0) as i64 - '0'.to_digit(10).unwrap_or(0) as i64);

        c = getch();
    }

    *pn *= sign;

    if c != EOF {
        ungetch(c);
    }

    c as i32
}

/// get a (possibly pushed-back) character
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn getch() -> char
{
    return  if BUFFER.len() > 0 { BUFFER.pop().unwrap_or(EOF) } else { getchar() };
}

/// push character back on input
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn ungetch(c: char)
{
    if BUFFER.len() >= BUFSIZE {
        print!("ungetch: too many characters\n");
    } else {
        BUFFER.push(c);
    }
}

/// A simulation of C getchar function.
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn getchar() -> char
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

