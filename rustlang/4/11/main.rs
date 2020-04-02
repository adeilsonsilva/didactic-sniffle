mod calc;
mod getop;
mod stack;

use calc::*;
use getop::*;
use stack::*;

const MAXOP : usize = 100;    /// Max size of operand or operator

/// reverse Polish calculator
fn main()
{
    let mut _type : char;
    let mut op2 : f32;
    let mut aux : f32;
    let mut _lp : f32 = 0.0;
    let mut _last_read_variable : usize = 0;

    let mut s = String::new();
    s.reserve(MAXOP);

    let mut variables : Vec<f32> = Vec::new(); // keeps track all variable values

    // init variables value
    for _i in 0..26 {
        variables.push(FAKE_DOUBLE_MIN);
    }

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
                'S' => { push( pop().sin() ); },
                'E' => { push( pop().exp() ); },
                '^' => {
                    op2 = pop();
                    aux = pop();
                    if aux == 0.0 && op2 <= 0.0 {
                        print!("error: pow({}, {}) is not a valid operation.\n", aux, op2);
                    } else {
                        push( aux.powf(op2) );
                    }
                },
                LAST => { _lp = last(); print!("top value: {}\n", _lp); },
                DUPLICATE => { duplicate(); },
                SWAP => { swap(); },
                CLEAR => { clear(); },
                '\n' => { _lp = pop(); print!("\t{}\n", _lp); },
                '=' => { variables[_last_read_variable] = pop(); },
                '_' => { push(_lp); },
                '?' => {
                    for _i in 0..26 {
                        if variables[_i] != FAKE_DOUBLE_MIN {
                            print!("'{}' == {}\n", std::char::from_u32('a' as u32 + (_i as u32)).unwrap_or('#'), variables[_i]);
                        }
                    }
                },
                _ => {
                    if _type.is_ascii_lowercase() {
                        _last_read_variable = (_type as u32 - 'a' as u32) as usize;
                        //if variable had a value assigned before, push it to stack
                        if variables[_last_read_variable] != FAKE_DOUBLE_MIN {
                            push(variables[_last_read_variable]);
                        } else {
                            // if variable wasn't used before, initialize it to 0
                            variables[_last_read_variable] = 0.0;
                        }
                    } else {
                        print!("error: unknown command {}\n", s);
                    }
                }
            }
        }
    }
}
