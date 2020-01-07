use std::io; // we are using standard library now

/// a brief simulation of C 'getchar' function and its
/// relation with EOF
fn main()
{
    for _ in 0..10 {
        let mut input = String::new();

        let buf = io::stdin();

        buf.read_line(&mut input).ok().expect("Failed to read line");

        // Basically, we are reading one char at a time. If an EOF is sent,
        // the reading function will return 'None'. So, this program behaves
        // similarly to the one in C
        println!("{}", input.bytes().nth(0) == None);
    }

}
