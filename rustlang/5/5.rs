/// @brief Copies at most n chars from string s to t.
///
/// @param s Source string
/// @param t Target string
/// @param n Number of characters
fn pstrncpy(s: &str, t: &mut String, n: i32)
{
    let mut i: i32 = 0;

    for _c in s.chars() {
        if i >= n {
            break;
        }

        t.remove(i as usize);
        t.insert(i as usize, _c);
        i += 1;
    }
}

/// Copies at most n chars from string s to the end of t.
///
/// @param s Source string
/// @param t Target string
/// @p
fn pstrncat(s: &str, t: &mut String, n: i32)
{
    let mut i: i32 = 0;

    for _c in s.chars() {

        if i >= n {
            break;
        }

        t.push(_c);
        i += 1;
    }
}

/// Compares at most n chars from string s and t.
///
/// @param s      Source string
/// @param t      Target string
/// @param n      Number of characters to be matched
///
/// @return bool  True if they match, false otherwise
fn pstrncmp(s: &str, t: &str, n: i32) -> bool
{
    let mut i: i32 = 0;

    let mut s_iter = s.chars();
    let mut t_iter = t.chars();

    // Check if characters match
    while (s_iter.next() == t_iter.next()) && i != n {
        i += 1;
    }

    // If i == n all chars are matched
    if i == n {
        return true;
    }

    false
}

/// Implementing a strcat function.
fn main ()
{
    let mut t1 = String::from("The first string is");
    let s1 = String::from(" IN NEED OF COMPLETION!");

    let mut t2 = String::from("abcdef678910");
    let s2 = String::from("12345");
    let s3 = String::from("123456789");

    print!("\"{}\"\t(pstrncat)=>\t", t1);
    pstrncat(&s1, &mut t1, 24);
    print!("\"{}\"\n", t1);

    print!("\"{}\"\t(pstrncpy)=>\t", t2);
    pstrncpy(&s2, &mut t2, 5);
    print!("\"{}\"\n", t2);

    print!("\"{}\"\tpstrncmp\t\"{}\"=>\t{}\n", s2, s3, pstrncmp(&s2, &s3, 5));
    print!("\"{}\"\tpstrncmp\t\"{}\"=>\t{}\n", t1, s2, pstrncmp(&t1, &s2, 5));
}
