/// A program to convert hex to integer.
fn main ()
{
    let hex_a = String::from("0x7DE");
    let hex_b = String::from("7DE");
    let hex_c = String::from("0X45eFa56");
    let hex_d = String::from("45eFa56");
    let hex_e = String::from("ffffffffff");
    let hex_f = String::from("0X0a");

    println!("{} : {}", hex_a, htoi(&hex_a));
    println!("{} : {}", hex_b, htoi(&hex_b));
    println!("{} : {}", hex_c, htoi(&hex_c));
    println!("{} : {}", hex_d, htoi(&hex_d));
    println!("{} : {}", hex_e, htoi(&hex_e));
    println!("{} : {}", hex_f, htoi(&hex_f));
}

/// A function which converts a string of hexadecimal digits (including an optional
/// 0x or 0X) into its equivalent integer value. The allowable digits are 0 through
/// 9, a through f, and A through F.
/// 
/// @param &String s      A reference to a string of hexadecimal digits
/// 
/// @return i64           An integer number resultant from conversion
fn htoi(s : &String) -> i64
{
    let _size = s.chars().count();
    let mut i = 0;
    let mut result : i64 = 0;

    // Dealing with leading '0x'
    if _size > 2 
        && s.chars().nth(0) == Some('0') 
        && (s.chars().nth(1) == Some('x') || s.chars().nth(1) == Some('X'))
    {
        i = 2;
    }

    // _size is from type 'usize', hence the cast
    let mut base : i32 = ((_size - i) - 1) as i32;

    for _c in s
            .chars() // iterate trough the chars of the string
            .skip(i) // skip leading '0x' or '0X'
    {
        let value = _c.to_digit(16);

        match value {
            None => {
                result = -1;
                break;
            },
            _ => {
                // 'to_digit' returns an 'Option<u32>', so we need to 'unwrap' it (E0369)
                // we need to specify '16' type (E0689)
                // as 'result' is a i64, we need to cast all operands (E0277)
                result += value.unwrap() as i64 * 16_usize.pow(base as u32) as i64;
                i += 1;
                base -= 1;
            }
        }
    };

    return result;
}