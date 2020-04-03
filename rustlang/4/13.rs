/// @brief Reverses a string s in place.
///
/// @param s The string to be reversed.
unsafe fn reverse (s: &mut String)
{
    static mut BEGIN: usize = 0; // Index of start of the string s.
    static mut AUX: usize = 0;   // Used to compute the end of the string s.

    let end = s.len() - AUX; // Compute current end position

    if BEGIN < end-1 {

        // Remove character from current end
        let mut _b = if end < s.len() { s.remove(end-1) } else { s.pop().unwrap_or('#') };

        // Insert at current beginning
        s.insert(BEGIN, _b);

        // Remove character from current begin
        let mut _e = s.remove(BEGIN+1);

        // Insert at current end
        if end <= s.len() { s.insert(end-1, _e); } else { s.push(_e); }

        // Update begin and offset
        BEGIN += 1;
        AUX += 1;

        // Call reverse recursively
        reverse(s);
    } else {
        // Resetting static variables
        BEGIN = 0;
        AUX = 0;
    }
}

fn main()
{
    let mut first = String::from("Socorram-me, subi no onibus em Marrocos!");
    let mut second = String::from("ovo");
    let mut third = String::from("Lorem ipsum");

    unsafe {
        print!("[*]\"{}\" =>\n", first);
        reverse(&mut first);
        print!("\t\t\"{}\"\n\n", first);

        print!("[*]\"{}\" =>\n", second);
        reverse(&mut second);
        print!("\t\t\"{}\"\n\n", second);

        print!("[*]\"{}\" =>\n", third);
        reverse(&mut third);
        print!("\t\t\"{}\"\n\n", third);
    }
}
