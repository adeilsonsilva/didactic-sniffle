/// Copies the string s to the end of t.
///
/// @param s Source string
/// @param t Target string
fn pstrcat(s: &str, t: &mut String)
{
    // In Rust is kinda boring, but way safer xD
    for _c in s.chars() {
        t.push(_c);
    }

}

/// Implementing a strcat function.
fn main ()
{
    let mut t1 = String::from("The first string is");
    let s1 = String::from(" IN NEED OF COMPLETION!");

    let mut t2 = String::from("Say what again, I da");
    let s2 = String::from("re you, I DOUBLE DARE YOU, MOTHERFUCKER!");

    print!("\"{}\"\t=>\t", t1);
    pstrcat(&s1, &mut t1);
    print!("\"{}\"\n", t1);

    print!("\"{}\"\t=>\t", t2);
    pstrcat(&s2, &mut t2);
    print!("\"{}\"\n", t2);
}
