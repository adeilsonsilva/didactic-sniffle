fn atof(s: &str) -> f64
{
    let mut _result: f64 = 0.0;
    let mut iter = s.chars();

    let mut _c : char = ' ';

    // skip white space
    while _c.is_ascii_whitespace() {
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }

    // compute integer part
    let sign : f64 = if _c == '-' { -1.0 } else { 1.0 };
    if _c == '+' || _c == '-' {
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }
    let mut val : f64 = 0.0;
    while _c.is_ascii_digit() {
        val = 10.0 * val + _c.to_digit(10).unwrap_or(0) as f64;
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }

    // compute decimal part
    if _c == '.' {
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }
    let mut power : f64 = 1.0;
    while _c.is_ascii_digit() {
        val = 10.0 * val + _c.to_digit(10).unwrap_or(0) as f64;
        power *= 10.0;
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }

    // get _result without scientific notation conversion
    _result = sign * val / power;

    // Checking for scientific notation
    if _c == 'e' {
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }
    let sci_sign : i8 = if _c == '-' { -1 } else { 1 };
    if _c == '+' || _c == '-' {
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }
    let mut sci_value : u64 = 0;
    while _c.is_ascii_digit() {
        sci_value = 10 * sci_value + _c.to_digit(10).unwrap_or(0) as u64;
        // get next character or a invalid one, in case it is not possible
        _c = iter.next().unwrap_or('#');
    }
    // Divide or multiply by 10 to compute conversion
    while sci_value > 0 {
        if sci_sign == -1 {
            _result /= 10.0;
        } else {
            _result *= 10.0;
        }

        sci_value -= 1;
    }

    _result
}

fn main ()
{
    print!("'{}' => {}\n", "123.45e-6", atof("123.45e-6"));
    print!("'{}' => {}\n", "123.45e6", atof("123.45e6"));
    print!("'{}' => {}\n", "145e-6", atof("145e-6"));
    print!("'{}' => {}\n", "145e6", atof("145e6"));
    print!("'{}' => {}\n", "895.56", atof("895.56"));
}