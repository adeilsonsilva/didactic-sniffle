use std::io;

const N : i32 = 50;
const HARD_LIMIT : i32= N - 2;
const TABSTOP : i32 = 4;


/// A function to apply the optimal amount of blank characters between two columns
///
/// @param int  start  The base column before whitespace sequence
/// @param int  end    The end column after whitespace sequence
///
/// @return void
fn entab (_start: i32, _end: i32)
{
    let mut j = _start;

    while j + (TABSTOP - j % TABSTOP) <= _end {
        j += TABSTOP - j % TABSTOP;
        print!("\t");
    }

    while (j + 1) <= _end {
        j += 1;
        print!(" ");
    }
}

/// A program to "fold" long input lines into two or more shorter lines after
/// the last non-blank character that occurs before the n-th column of input.
fn main ()
{
    let mut input = String::new();

    enum STATE {
        OUT = 0,
        IN = 1
    }

    loop {
        match io::stdin().read_line(&mut input) {
            Ok (n_bytes) => {
                if n_bytes == 0 {
                    break;
                }

                let mut _state = STATE::OUT;
                let (mut base_column, mut current_column) = (0, 0);

                for _c in input.chars() {

                    if current_column < HARD_LIMIT {
                        if let STATE::OUT = _state {
                            match _c {
                                '\t' | ' ' => {
                                    _state = STATE::IN;
                                    base_column = current_column;
                                },
                                _ => {
                                    print!("{}", _c);
                                }
                            }
                        } else if let STATE::IN = _state {
                            match _c {
                                '\t' | ' ' => { },
                                _ => {
                                    _state = STATE::OUT;
                                    if _c != '\n' {
                                        entab(base_column, current_column);
                                    }
                                    print!("{}", _c);
                                }
                            }
                        }
                    } else if current_column == HARD_LIMIT {
                        if !(_c == ' ' || _c == '\t' || _c == '\n') {
                            if let STATE::IN = _state {
                                entab(base_column, current_column);
                            }
                            print!("{}", _c);
                        }

                        _state = STATE::OUT;
                        current_column = 0;
                        println!();
                    }

                    // We don't need to deal with newline characters, 'read_line'
                    // does it for us.
                    current_column += if _c == '\t' {
                                        TABSTOP - current_column % TABSTOP
                                    } else {
                                        1
                                    };
                }

                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }
}
