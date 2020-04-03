macro_rules! swap {
    ($t:ty, $x:expr, $y:expr) => {
        let _z: $t = $x;
        $x = $y;
        $y = _z;
    };
}

fn main()
{
    {
        let mut a = 10;
        let mut b = 20;

        print!("[*] {} {}\t=>\t", a, b);
        swap!(i32, a, b);
        print!("{}\t{}\n", a, b);
    }

    {
        let mut c = 35.62;
        let mut d = 012.51;

        print!("[*] {} {}\t=>\t", c, d);
        swap!(f32, c, d);
        print!("{}\t{}\n", c, d);
    }

    {
        let mut i = '^';
        let mut j = '~';

        print!("[*] '{}' '{}'\t=>\t", i, j);
        swap!(char, i, j);
        print!("'{}'\t'{}'\n", i, j);
    }
}
