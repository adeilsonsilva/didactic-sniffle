use std::io;

const MAXOP : usize = 100;   /// Max size of operand or operator
const NUMBER : char = '0';  /// Signal that a number was found
const EOF : char = '#'; /// Simulate C EOF

const MAXVAL : usize = 100;             /// Maximum depth of operand stack
static mut val : Vec<f32> = Vec::new(); /// Our operand stack

const BUFSIZE : usize = 100;             /// Max size for ungetch buffer
static mut buf : Vec<char> = Vec::new(); /// Buffer to control characters read from input (ungetch)

static mut input : String = String::new(); /// Holds characters from stdin (getchar simulation)

/// reverse Polish calculator
fn main()
{
    let mut _type : char;
    let mut op2 : f32;

    let mut s = String::new();
    s.reserve(MAXOP);

    // We need a unsafe scope here, because we create global (static) variables
    // and manipulate them here. Rust makes a big effort to avoid concurrency
    // bugs hard to run into, that's the reason for code that doesn't guarantee
    // data race protection being labeled unsafe.
    
    // SOURCES:
    // https://doc.rust-lang.org/reference/items/static-items.html
    unsafe {
        loop {
            _type = getop(&mut s);
    
            if _type == EOF {
                break;
            }
    
            match _type {
                NUMBER => { push(s.parse().unwrap_or(-0.0)); },
                '+' => { push(pop() + pop()); },
                '*' => { push(pop() * pop()); },
                '-' => {
                    op2 = pop();
                    push(pop() - op2);
                },
                '/' => {
                    op2 = pop();
                    if op2 != 0.0 {
                        push(pop() / op2);
                    } else {
                        print!("error: zero divisor\n");
                    }
                },
                '%' => {
                    op2 = pop();
                    if op2 != 0.0 {
                        push(pop() as f32 % op2 as f32);
                    } else {
                        print!("error: zero divisor\n");
                    }
                },
                '\n' => { print!("\t{}\n", pop()); },
                _ => { print!("error: unknown command {}\n", s); }
            }
        }
    }
}

/// push:  push f onto value stack
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn push(f: f32)
{
    if val.len() < MAXVAL {
        val.push(f);
    } else {
        print!("error: stack full, can't push {}\n", f);
    }
}

/// pop:  pop and return top value from stack
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn pop() -> f32
{
    if val.len() > 0 {
        return val.pop().unwrap_or(0.0);
    } else {
        print!("error: stack empty\n");
        return 0.0;
    }
}

/// getop:  get next character or numeric operand
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn getop(s: &mut String) -> char
{
    let mut c: char;

    s.clear();
    loop {
        c = getch();

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
            c = getch();

            if c.is_digit(10) {
                s.push(c);
            } else {
                break;
            }
        }
    }

    if c == '.' { // collect fraction part
        loop {
            c = getch();

            if c.is_digit(10) {
                s.push(c);
            } else {
                break;
            }
        }
    }

    if c != EOF {
        ungetch(c);
    }

    return NUMBER;
}

/// get a (possibly pushed-back) character
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn getch() -> char
{
    return  if buf.len() > 0 { buf.pop().unwrap_or(EOF) } else { getchar() };
}

/// push character back on input
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn ungetch(c: char)
{
    if buf.len() > buf.capacity() {
        print!("ungetch: too many characters\n");
    } else {
        buf.push(c);
    }
}

/// A simulation of C getchar function.
/// It is unsafe because we manipulate a static mut variable inside it.
unsafe fn getchar() -> char
{
    let mut c = input.pop();
    
    if c == None {
        // clear input so lines don't get appended
        input.clear();

        match io::stdin().read_line(&mut input) {
            Ok (_bytes) => {
                if _bytes == 0 { return EOF }
                input = input.chars().rev().collect::<String>();
                c = input.pop();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }

    c.unwrap_or(EOF)
}