/// A function which returns the first location in a string s1 where any
/// character from thestring s2 occurs, or -1 if s1 contains no characters
/// from s2.
///
/// @param  &str s1 String to be searched at
/// @param  &str s2 String to be checked against
///
/// @return i32
fn any(s1: &str, s2: &str) -> i32
{
    // Remember that in Rust you can't index a string the same way as C
    // (i.e. string[0], string[1]). By using this 'idx' mutable variable
    // we are count the number of characters inside the string not the real
    // index on the array (a character might be represented by more than one
    // byte!).
    let mut _idx : i32 = 0;

    for _c2 in s2.chars() {
        _idx = 0;
        for _c1 in s1.chars() {
            if _c1 == _c2 {
                return _idx;
            }
            _idx += 1;
        }
    }

    return -1;
}

/// A program to test string squeezing.
fn main ()
{
    let vowels = String::from("aeiou");
    let a = String::from("*****a*****.");
    let e = String::from("******e******.");
    let i = String::from("*******i*******.");
    let o = String::from("********o********.");
    let u = String::from("*********u********.");

    print!("\t{} {} {} {} {} \n", any(&a, &vowels), any(&e, &vowels), any(&i, &vowels), any(&o, &vowels), any(&u, &vowels));
}
