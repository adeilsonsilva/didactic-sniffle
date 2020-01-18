use std::io;

/// A program to remove all comments from a C program.
/// 
/// CAVEAT: Ansi C does not support comments with double slashes ('//').
fn main ()
{
    let mut input = String::new();

    enum STATE {
        OUT = 0,
        IN = 1,
        QuotedString = 2,
        DEFINE = 3,
        LEFT = 4,
        RIGHT = 5
    }

    let mut _state = STATE::OUT;

    loop {
        match io::stdin().read_line(&mut input) {
            Ok (n_bytes) => {
                if n_bytes == 0 {
                    break;
                }

                for _c in input.chars() {
                    if let STATE::OUT = _state {
                        if _c != '/' {
                            if _c == '\'' || _c == '\"' {
                                _state = STATE::QuotedString;
                            } else if _c == '#' {
                                _state = STATE::DEFINE;
                            }
                            print!("{}", _c);
                        } else {
                            _state = STATE::LEFT;
                        }
                    } else if let STATE::QuotedString = _state {
                        if _c == '\'' || _c == '"' {
                            _state = STATE::OUT;
                        }
                        print!("{}", _c);
                    } else if let STATE::LEFT = _state {
                        if _c == '*' {
                            _state = STATE::IN;
                        } else {
                            _state = STATE::OUT;
                            print!("/{}", _c);
                        }
                    }  else if let STATE::RIGHT = _state {
                        if _c == '/' {
                            _state = STATE::OUT;
                        } else {
                            _state = STATE::IN;
                        }
                    } else if let STATE::IN = _state {
                        if _c == '*' {
                            _state = STATE::RIGHT;
                        }
                    } else if let STATE::DEFINE = _state {
                        if _c == '\n' {
                            _state = STATE::OUT;
                        }
                        print!("{}", _c);
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
