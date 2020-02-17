/// Converts integer x to a string.
///
/// @param  i32 x The integer to be converted
/// @param  i32 w The minimum field width
///
/// @return String  The resultant string
fn itoa(x: i32, w: i32) -> String
{
    let mut l = 0;
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
        l += 1;

        n /= 10;
        if n <= 0 {
            break;
        }
    }

    if x < 0 {
        result.push('-');
        l += 1;
    }

    /* Adding padding characters to match width field */
    while l < w {
        result.push(' ');
        l += 1;
    }

    result.chars().rev().collect::<String>()
}

fn main()
{
    print!("itoa(958585, 10) => '{}'\n", itoa(958585, 10));

    print!("itoa(10, 10) => '{}'\n", itoa(10, 10));

    print!("itoa(958000, 10) => '{}'\n", itoa(958000, 10));

    print!("itoa(-914124, 10) => '{}'\n", itoa(-914124, 10));

    print!("itoa(std::i32::MIN+1, 10) => '{}'\n", itoa(std::i32::MIN+1, 10));

    print!("itoa(std::i32::MIN, 10) => '{}'\n", itoa(std::i32::MIN, 10));
}
