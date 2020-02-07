/// A function that returns the value of the integer x rotated to the right by n
/// positions.
///
/// @param u32 x Number to have its bits rotated.
/// @param i32 n Amount of bits to be rotated.
///
/// @return u32  Number resultant from operation.
fn rightrot(x: u32, n: i32) -> u32
{
    let mut n_bits = 0;
    let mut k = x;

    let rightmost_mask = !(!0 << n);
    
    if x == 0 {
        return 0;
    }

    while k > 0 {
        k /= 2;
        n_bits += 1;
    }

    return ((x & rightmost_mask) << (n_bits - (n % n_bits))) | (x >> n);
}

/// A program to test changing bits.
fn main()
{
    print!("rightrot(255, 1)\t=>\t{}\n", rightrot(255, 1));
    print!("rightrot(0, 4)\t\t=>\t{}\n", rightrot(0, 4));
    print!("rightrot(85, 4)\t\t=>\t{}\n", rightrot(85, 4));
    print!("rightrot(!0, 4)\t\t=>\t{}\n", rightrot(!0, 4));
    print!("rightrot(!0, 31)\t=>\t{}\n", rightrot(!0, 31));
    print!("rightrot(10, 3)\t\t=>\t{}\n", rightrot(10, 3));
}
