/**
 * A program to convert hex to integer.
 */
fn main ()
{
    let hex_a = String::from("0x7DE");
    let hex_b = String::from("7DE");
    let hex_c = String::from("0X45eFa56");
    let hex_d = String::from("45eFa56");
    let hex_e = String::from("ffffffffff");
    let hex_f = String::from("0X0a");

    println!("{} : {:.2}", hex_a, htoi(&hex_a));
    println!("{} : {:.2}", hex_b, htoi(&hex_b));
    println!("{} : {:.2}", hex_c, htoi(&hex_c));
    println!("{} : {:.2}", hex_d, htoi(&hex_d));
    println!("{} : {:.2}", hex_e, htoi(&hex_e));
    println!("{} : {:.2}", hex_f, htoi(&hex_f));
}

/// A function which converts a string of hexadecimal digits (including an optional
/// 0x or 0X) into its equivalent integer value. The allowable digits are 0 through
/// 9, a through f, and A through F.
/// 
/// @param &String s      A reference to a string of hexadecimal digits
/// 
/// @return f64           Integer result of operation
fn htoi(s : &String) -> f64
{
    let _size = s.chars().count();
    let mut i = 0;
    let mut result : f64 = 0.0;

    /* Dealing with leading '0x' */
    if _size > 2 
        && s.chars().nth(0) == Some('0') 
        && (s.chars().nth(1) == Some('x') || s.chars().nth(1) == Some('X'))
    {
        i = 2;
    }

    let mut base = (_size - i) - 1;

    s
    .chars()
    .skip(i)
    .for_each(|_c| {
        let value = _c.to_digit(16);

        println!("{} {:?}", base, value);

        match value {
            None => {
                result = -1.0;
                return;
            },
            _ => {
                result += value.unwrap() as f64 * 16_usize.pow(base as u32) as f64;
                i += 1;
                base -= 1;
            }
        }
    });

    return result;
}