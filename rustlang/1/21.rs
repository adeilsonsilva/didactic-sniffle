use std::io;

const TABSTOP : i32 = 8;

/// A program entab that replaces strings of blanks by the minimum number of tabs
/// and blanks to achieve the same spacing. Check C code for a better undertanding
/// of what a TABSTOP is.
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

                                while base_column + (TABSTOP - base_column % TABSTOP) <= current_column {
                                    base_column += TABSTOP - base_column % TABSTOP;
                                    print!("\t");
                                }

                                while (base_column + 1) <= current_column {
                                    base_column += 1;
                                    print!(" ");
                                }

                                print!("{}", _c);
                            }
                        }
                    }

                    // We don't need to deal with newline characters, 'read_line'
                    // does it for us.
                    // Using rust expression assignment
                    current_column += if _c == '\t' {
                        (TABSTOP - current_column % TABSTOP)
                    } else {
                        1
                    }
                }

                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }
}
