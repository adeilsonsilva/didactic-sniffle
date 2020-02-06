/// A function that returns x with the n bits that begin at position p inverted
/// (i.e., 1 changedinto 0 and vice versa), leaving the others unchanged.
///
/// @param u32 x Number to have its bits inverted.
/// @param i32 p Position of the first bit to be inverted.
/// @param i32 n Amount of bits to be inverted.
///
/// @return u32  Number resultant from operation.
fn invert(x: u32, p: i32, n: i32) -> u32
{
    let shift = p - n + 1;

    let mask = !(!0 << n);

    let masked_x = x & (!(mask << shift));

    let flipped_bits = (!((x >> shift) & mask) & mask) << shift;

    return masked_x | flipped_bits;
}

/// A program to test changing bits.
fn main()
{
    print!("invert(255, 1, 2)\t=>\t{}\n", invert(255, 1, 2));
    print!("invert(0, 4, 3)\t\t=>\t{}\n", invert(0, 4, 3));
    print!("invert(85, 4, 3)\t=>\t{}\n", invert(85, 4, 3));
    print!("invert(!0, 4, 5)\t=>\t{}\n", invert(!0, 4, 5));
    print!("invert(!0, 31, 31)\t=>\t{}\n", invert(!0, 31, 31));
    print!("invert(0, 15, 4)\t=>\t{}\n", invert(0, 15, 4));
}
