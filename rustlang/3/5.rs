/// Converts integer x to a string.
///
/// @param  i32 x The integer to be converted
/// @param  i16 b The base to be changed to
///
/// @return String  The resultant string
fn itob(x: i32, b: i16) -> String
{
    // Set of possible characters
    let characters = String::from("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    let mut result = String::new();

    if b < 0 || b > 36 {
        print!("Invalid radix: {}!\n", b);
        return result;
    }

    // Handling overflow
    let mut n: i64 = x as i64;
    if n < 0 {
        n = -n;
    }

    loop {
        // get next digit
        let c = characters.chars().nth((n % (b as i64)) as usize).unwrap();
        result.push(c);

        n /= b as i64;
        if n <= 0 {
            break;
        }
    }

    result.chars().rev().collect::<String>()
}

fn main()
{
    print!("itob(10, 2) => '{}'\n", itob(10, 2));

    print!("itob(15, 16) => '{}'\n", itob(15, 16));

    print!("itob(32, 2) => '{}'\n", itob(32, 2));

    print!("itob(2130440, 10) => '{}'\n", itob(2130440, 10));

    print!("itob(128, 16) => '{}'\n", itob(128, 16));

    print!("itob(std::i32::MAX, 2) => '{}'\n", itob(std::i32::MAX, 2));

    print!("itob(std::i32::MIN, 2) => '{}'\n", itob(std::i32::MIN, 2));

    print!("itob(std::i32::MIN, 16) => '{}'\n", itob(std::i32::MIN, 16));
}
