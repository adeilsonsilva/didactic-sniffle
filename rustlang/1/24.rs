use std::io;

/// A program to check a C source file for rudimentary syntax errors.
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

    let (
        mut comments_counter,
        mut quotes_counter,
        mut parentheses_counter,
        mut brackets_counter,
        mut braces_counter
    ) : (i32, i32, i32, i32, i32)
    = (0, 0, 0, 0, 0);

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
                                quotes_counter += 1;
                            } else if _c == '#' {
                                _state = STATE::DEFINE;
                            } else if _c == '(' {
                                parentheses_counter += 1;
                            } else if _c == ')' {
                                parentheses_counter -= 1;
                            } else if _c == '{' {
                                brackets_counter += 1;
                            } else if _c == '}' {
                                brackets_counter -= 1;
                            } else if _c == '[' {
                                braces_counter += 1;
                            } else if _c == ']' {
                                braces_counter -= 1;
                            }
                        } else {
                            _state = STATE::LEFT;
                        }
                    } else if let STATE::QuotedString = _state {
                        if _c == '\'' || _c == '"' {
                            _state = STATE::OUT;
                            quotes_counter -= 1;
                        }
                    } else if let STATE::LEFT = _state {
                        if _c == '*' {
                            _state = STATE::IN;
                            comments_counter += 1;
                        } else {
                            _state = STATE::OUT;
                        }
                    }  else if let STATE::RIGHT = _state {
                        if _c == '/' {
                            _state = STATE::OUT;
                            comments_counter -= 1;
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
                    }
                }
                input.clear();
            },
            Err(_) => {
                panic!("Unexpected error.");
            }
        }
    }

    if
        quotes_counter != 0
        || comments_counter != 0
        || parentheses_counter != 0
        || brackets_counter != 0
        || braces_counter != 0
    {
        print!("Bad formatted characters: \n\t[+] ");
        print!(
            "\' | \": {}; /*: {}; (): {}; {{}}: {}; []: {};\n", 
            quotes_counter, comments_counter, parentheses_counter,
            brackets_counter, braces_counter
        );
    } else {
        println!("Everything is okay!");
    }
}