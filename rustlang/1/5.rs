/// print Fahrenheit-Celsius table
fn main()
{
    // it is preceded with an underscore as suggested by the compiler (because it is unused)
    let _fahr: i32;

    // A few things about this for loop:
    //    + "step_by" is exclusive at the last position, so we need to go until 320
    //    + "rev" must be after "step_by", or the result won't be as stable
    //    + this iterator takes ownership of the immutable variable "_fahr". That's why
    //      we don't need it to be mutable.
    //      Check out "Ownership Controls Mutability" for more info. (https://kasma1990.gitlab.io/2017/05/07/ownership-controls-mutability/)
    for _fahr in (0..320).step_by(20).rev() {
        print!("{:3.0} {:6.1}\n", _fahr, (5.0/9.0) * (_fahr as f32 - 32.0)); // we need to cast "_fahr" to float, or it won't compile
    }
}
