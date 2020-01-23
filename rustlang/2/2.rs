use std::io;

/// A program to read a line, without logical operators.
fn main()
{
    let mut input = String::new();

    let lim = 999;
    let mut s = Vec::with_capacity(lim);

    match io::stdin().read_line(&mut input) {
        Ok (_bytes) => {
            let mut i = 0;

            for _c in input.chars() {
                // Rust doesn't behave the same way as C
                // error[E0369]: binary operation `+` cannot be applied to type `bool`
                if i < lim-1 && _c != '\n' {
                    s.push(_c);
                }

                i += 1;
            }
        },
        Err(_) => {
            panic!("Unexpected error.");
        }
    }

    // As we used a vec, we have to convert each position to a string, and collect everything
    print!("{}\n", s.into_iter().map(|i| i.to_string()).collect::<String>());
}
