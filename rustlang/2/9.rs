/// A function that counts the number of 1-bits in its integer argument.
/// 
/// @param  u32 x Number to have its 1-bits counted
/// 
/// @return i32   Number of 1-bits
fn bitcount(x : u32) -> i32
{
    let mut b = 0;

    // We cast x to a signed integer so we can check if
    // the operation was succesful
    let mut n : i32 = x as i32;

    while n > 0 {
        // We make the operation here because in Rust, different from C,
        // the result of the assignment is not returned, so we were not able to
        // do if (n &= n-1) >= 0
        n &= n-1;

        // If n is not declared as i32, the compiler will throw an warning
        // for this comparison (because u32 is never less than 0).
        if n >= 0 {
            b += 1;
        }
    }

    b
}

/// A program to test bitcount.
fn main()
{
    print!("bitcount(255)\t=>\t{}\n", bitcount(255));
    print!("bitcount(56452)\t=>\t{}\n", bitcount(56452));
    print!("bitcount(0)\t=>\t{}\n", bitcount(0));
    print!("bitcount(!0)\t=>\t{}\n", bitcount(!0));
    print!("bitcount(10)\t=>\t{}\n", bitcount(10));
    print!("bitcount(32)\t=>\t{}\n", bitcount(32));
    print!("bitcount(16)\t=>\t{}\n", bitcount(16));
    print!("bitcount(8)\t=>\t{}\n", bitcount(8));
    print!("bitcount(4)\t=>\t{}\n", bitcount(4));
    print!("bitcount(2)\t=>\t{}\n", bitcount(2));
    print!("bitcount(1)\t=>\t{}\n", bitcount(1));
}