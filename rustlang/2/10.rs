/// A function that converts an ASCII character to lower case.
/// In Rust, we could just use 'to_ascii_lowercase', but we are not lazy.
/// 
/// @param  char c The character to be converted
/// 
/// @return char   Resultant character
fn lower(c : char) -> char
{
    // We have to cast char to u8 to get its ASCII value...
    // ...and cast back to char to return.
    let digit_value = c as u8;

    // Rust doesn't have ternary operator, but the if-else syntax is
    // pretty flexible
    return if
                digit_value >= ('A' as u8) 
                && digit_value <= ('Z' as u8) 
            { 
                (digit_value + ('a' as u8) - ('A' as u8)) as char
            } else {
                digit_value as char
            };
}

/// A program to test bitcount.
fn main()
{
    print!("lower('a')\t=>\t{}\n", lower('a'));
    print!("lower('b')\t=>\t{}\n", lower('b'));
    print!("lower('c')\t=>\t{}\n", lower('c'));
    print!("lower('d')\t=>\t{}\n", lower('d'));
    print!("lower('e')\t=>\t{}\n", lower('e'));
    print!("lower('A')\t=>\t{}\n", lower('A'));
    print!("lower('B')\t=>\t{}\n", lower('B'));
    print!("lower('C')\t=>\t{}\n", lower('C'));
    print!("lower('D')\t=>\t{}\n", lower('D'));
    print!("lower('E')\t=>\t{}\n", lower('E'));

    // Compilation errors
    // print!("lower(❤️)\t=>\t{}\n", lower("❤️"));
}