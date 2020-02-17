/// Converts integer x to a string.
///
/// @param  i32 x The integer to be converted
///
/// @return String  The resultant string
fn itoa(x: i32) -> String
{
    let mut result = String::new();

    // We cast input i32 to a i64 to handle the case of std::i32::MIN.
    // Remember that i32 interval is [-2147483648, 2147483647].
    let mut n: i64 = x as i64;

    // We have to negate after casting x into an i64 or the code will panic:
    // "thread 'main' panicked at 'attempt to negate with overflow'"
    if n < 0 {
        n = -n;
    }

    // generate digits in reverse order
    // 'do-while' in C is convert into a 'loop with a break' in Rust
    loop {
        // get next digit
        result.push((((n % 10) as u8) + ('0' as u8)) as char);

        n /= 10;
        if n <= 0 {
            break;
        }
    }

    if x < 0 {
        result.push('-');
    }

    result.chars().rev().collect::<String>()
}

fn main()
{
    print!("itoa(958585) => '{}'\n", itoa(958585));

    print!("itoa(10) => '{}'\n", itoa(10));

    print!("itoa(958000) => '{}'\n", itoa(958000));

    print!("itoa(-914124) => '{}'\n", itoa(-914124));

    print!("itoa(std::i32::MIN+1) => '{}'\n", itoa(std::i32::MIN+1));

    print!("itoa(std::i32::MIN) => '{}'\n", itoa(std::i32::MIN));
}
