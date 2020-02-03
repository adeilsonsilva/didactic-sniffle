/// A function to find a character inside a string.

/// @param &str    s  A reference to the string to be searched
/// @param char    c  The character to be searched for

/// @return bool      A boolean indicating if the character was found or not.
fn find (s: &str, c: char) -> bool
{
    for _c in s.chars() {
        if _c == c {
            return true;
        }
    }

    return false;
}

/// A function that deletes each character in s1 that matches any character in
/// the strings2.

/// @param &String s1  A reference to the String to be squeezed
/// @param &str    s2  A reference to an immutable string slice with chars to be searched

/// @return String     The string resultant of all searches
fn squeeze(s1: &String, s2: &str) -> String
{
    // Because of Rust's way of dealing with strings, instead of modifying the
    // original one it is better to create a empty one and append all desired
    // characters. Rust strings are not the same thing as C array of chars.
    let mut result = String::with_capacity(s1.capacity());

    for _c in s1.chars() {
        // We don't really need this 'find' function, just kept it for no reason.
        if !find(s2, _c) {
            result.push(_c,);
        }
    }

    result
}

/// A program to test string squeezing.
fn main ()
{
    let first = String::from("A string with multiple characters.");
    let second = String::from("aeiou");

    print!("*** BEFORE ***\n");

    print!("\t'{}'\n\t'{}'\n", first, second);

    print!("\n*** AFTER ***\n");

    print!("\t'{}'\n\t'{}'\n", squeeze(&first, &second), second);
}

