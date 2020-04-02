pub const EOF : char = '#';       // Simulate C EOF
pub const NUMBER : char = '0';    // Signal that a number was found
pub const LAST : char = 'L';      // signal that last value command was found
pub const SWAP : char = '~';      // signal that swap command was found
pub const DUPLICATE : char = 'D'; // signal that duplicate command was found
pub const CLEAR : char = 'C';     // signal that clear was found

pub const FAKE_DOUBLE_MIN : f32 = -999999.0; // set a minimum value for stack operands
