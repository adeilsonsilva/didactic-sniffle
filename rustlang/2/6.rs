/// A function that returns x with the n bits that begin at position p set to
/// the rightmost n bits of y, leaving the other bits unchanged.
///
/// PS: check C code for a better explanation of the expressions.
///
/// @param u32 x Number to have its bits set.
/// @param i32 p Position of the first bit to be set.
/// @param i32 n Amount of bits to be set.
/// @param u32 y Number to have its bits used to set.
///
/// @return u32  Number resultant from operation.
fn setbits(x: u32, p: i32, n: i32, y: u32) -> u32
{
    let shift = p - n + 1;

    // In Rust, bitwise not is computed with '!' instead of C's '~'.
    let mask = !(!0 << n);

    let masked_y = (y & mask) << shift;

    let masked_x = x & (!(mask << shift));

    return masked_x | masked_y;
}

/// A program to test changing bits.
fn main()
{
    print!("setbits(0, 4, 3, 5)\t=>\t{}\n", setbits(0, 4, 3, 5));
    print!("setbits(0, 4, 3, !0)\t=>\t{}\n", setbits(0, 4, 3, !0));
    print!("setbits(85, 4, 3, 2)\t=>\t{}\n", setbits(85, 4, 3, 2));
    print!("setbits(!0, 4, 5, 0)\t=>\t{}\n", setbits(!0, 4, 5, 0));
    print!("setbits(!0, 31, 31, 0)\t=>\t{}\n", setbits(!0, 31, 31, 0));
    print!("setbits(0, 15, 4, 10)\t=>\t{}\n", setbits(0, 15, 4, 10));
}
