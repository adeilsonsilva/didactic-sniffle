use std::io;

/// Reverses string s in place.
///
/// @param s String to be reversed.
fn reverse(s: &mut String)
{
    let size = s.chars().count();

    for _i in 0..size {
        let _c = s.pop().unwrap_or('#');
        s.insert(_i as usize, _c);
    }
}

/// A function to check for the rightmost occurence of t in s.
///
/// @param s         The string to be searched at
/// @param t         The pattern to be searched for
///
/// @return usize    Position of rightmost occurrence .
fn strindex(s: &str, t: &str) -> i32
{
    let mut rightmost: i32 = -1;


    for _idx in 0..=s.chars().count() {

        let mut s_iter = s.chars().skip(_idx);
        let mut t_iter = t.chars();

        loop {
            let _s = s_iter.next();
            let _t = t_iter.next();

            if _s == None || _s != _t { break; }
        }

        if t_iter.next() == None  {
            rightmost = _idx as i32;
        }
    }

    rightmost
}

fn main ()
{
    let mut input = String::new();

    let numbers = String::from("12345");

    print!("Enter a line to be read:\n");

    match io::stdin().read_line(&mut input) {
        Ok (n) => {
            input = input.trim_end().to_string();

            print!("{} characters were read:\t\"{}\"\n", n-1, input);

            reverse(&mut input);
            print!("Check it reversed:\t\"{}\"\n", input);

            reverse(&mut input);
            print!("Check it reversed back:\t\"{}\"\n", input);

            print!("The rightmost index of \"{}\" inside \"{}\" is {}\n", numbers, input, strindex(&input, &numbers));
        },
        Err(_) => {
            panic!("Unexpected error.");
        }
    }


}
