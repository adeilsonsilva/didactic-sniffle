/// @brief Converts an integer into a string recursively.
///
/// @param n     Number to be converted
/// @param s     Array of characters to be filled
fn itoa(mut n: i32, s: &mut String)
{
    if (n / 10) != 0 {
        itoa(n / 10, s);
    } else {
        if n < 0 {
            s.push('-'); // We add a sign at the first position, in case its a negative number
        }
    }

    if n < 0 {
        n = -n;
    }

    s.push(std::char::from_u32((n as u32 % 10) + ('0' as u32)).unwrap_or('#'));
}

fn main()
{
    let mut result: String = String::new();

    let numbers: Vec<i32> = vec![
        23123,
        -53352,
        24,
        12,
        0,
        -516361361,
        123632,
        236,
        352,
        1412,
        -12414
    ];

    for _number in numbers {
        result.clear();

        itoa(_number, &mut result);
        print!("\t[*] {} => \"{}\"\n", _number, result);
    }
}
