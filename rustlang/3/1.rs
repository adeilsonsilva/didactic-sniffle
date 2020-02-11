use std::time::Instant; // time measurements

// All indexes must be of type usize
const SIZE : usize = 999999;

/// This function performs a binary search.
/// 
/// @param i32       x      Value to be searched for
/// @param &Vec<i32> v      Reference to the vector to search at
/// @param usize     n      Size of the vector
/// 
/// @return i32             Index of found value or -1
fn binsearch(x: i32, v: &Vec<i32>, n: usize) -> i32
{
    let mut low : usize = 0;
    let mut high : usize = n - 1;
    let mut mid : usize;

    while low <= high {
        mid = (low + high) / 2;
        
        if x < v[mid] {
            high = mid - 1;
        } else if x > v[mid] {
            low = mid + 1;
        } else {
            return mid as i32;
        }
    }

    -1
}


/// This function performs a binary search.
/// 
/// @param i32       x      Value to be searched for
/// @param &Vec<i32> v      Reference to the vector to search at
/// @param usize     n      Size of the vector
/// 
/// @return i32             Index of found value or -1
fn binary_search(x: i32, v: &Vec<i32>, n: usize) -> i32
{
    let mut low : usize = 0;
    let mut high : usize = n - 1;
    let mut mid : usize = high / 2;

    while
        low <= high && x != v[mid]
    {
        mid = (low + high) / 2;
        
        if x < v[mid] {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if x == v[mid] {
        return mid as i32;
    }

    -1
}

/// A program to test binary search
fn main()
{
    let _idx = 0;
    let mut result;

    // Beware that, by using a constant size, this array is allocated at the
    // stack. It means SIZE can't be a very high value, because the OS will not
    // allow to allocate that much space on the stack. Things could be different
    // in the heap.
    let mut v: Vec<i32> = Vec::with_capacity(SIZE);

    // Initializing v
    let now = Instant::now();
    for _idx in 0..SIZE { v.push(_idx as i32); }
    print!("Allocation took {:.10} seconds\n", now.elapsed().as_secs_f64());

    // binsearch (book version)
    let now = Instant::now();
    result = binsearch(324781, &v, SIZE);
    print!("binsearch(324781, v, SIZE) => {}, {:.10}s\n", result, now.elapsed().as_secs_f64());

    // binary_search (improved version)
    let now = Instant::now();
    result = binary_search(324781, &v, SIZE);
    print!("binary_search(324781, v, SIZE) => {}, {:.10}s\n", result, now.elapsed().as_secs_f64());
}