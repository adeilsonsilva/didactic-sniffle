/// A program to print the range of basic data types.
/// Some C types have a different meaning in Rust,
/// so we print it's equivalent.
fn main ()
{

    print!("[*] Data types ranges!\n");

    // The 'char' type in Rust has a different meaning from 'char' type in C.
    print!("\t[+] u8: [{}, {}]\n", std::u8::MIN, std::u8::MAX);
    print!("\t[+] i8: [{}, {}]\n", std::i8::MIN, std::i8::MAX);

    print!("\t-------------------------------\n");

    // In C, short int (16 bits) < int (16 OR 32 bits) < long int (32 bits)
    print!("\t[+] u16: [{}, {}]\n", std::u16::MIN, std::u16::MAX);
    print!("\t[+] u32: [{}, {}]\n", std::u32::MIN, std::u32::MAX);

    print!("\t[+] i16: [{}, {}]\n", std::i16::MIN, std::i16::MAX);
    print!("\t[+] i32: [{}, {}]\n", std::i32::MIN, std::i32::MAX);
    print!("\t[+] i64: [{}, {}]\n", std::i64::MIN, std::i64::MAX);

    print!("\t-------------------------------\n");

    // In C, floating point types are implementation-defined. Rust has more
    // constraints about that.
    print!("\t[+] f32: [{}, {}]\n", std::f32::MIN, std::f32::MAX);
    print!("\t[+] f64: [{}, {}]\n", std::f64::MIN, std::f64::MAX);
}