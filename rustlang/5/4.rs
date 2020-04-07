/// Checks if string t occurs at the end of the string s.
///
/// @param s     String to be looked at
/// @param t     String to be searched for
///
/// @return bool  1 if occurs 0 otherwise
fn strend(s: &str, t: &str) -> bool
{
    let source_size = s.len();
    let target_size = t.len();

    // If t fits in s, jump to where t should start .
    if target_size <= source_size {
        let mut s_chars = s.chars()
                       .skip((source_size - target_size) as usize);
        let mut t_chars = t.chars();

        // Check if characters match
        let mut char_s = s_chars.next();
        let mut char_t = t_chars.next();
        while char_t != None && char_s == char_t {
            char_s = s_chars.next();
            char_t = t_chars.next();
        }

        // If t ended, it is inside s
        if char_t == None {
            return true;
        }
    }

    false
}

/// Implementing a strend function.
fn main ()
{
    let t1 = String::from("ABCDEF");
    let s1 = String::from("The alphabet is ABCDEF");

    let t2 = String::from("lorem ipsum");
    let s2 = String::from("lorem ipsum doler sit amet");

    print!("Checking for \"{}\" at the end of \"{}\"\t=>\t{}\n", t1, s1, strend(&s1, &t1));
    print!("Checking for \"{}\" at the end of \"{}\"\t=>\t{}\n", t2, s2, strend(&s2, &t2));
}
