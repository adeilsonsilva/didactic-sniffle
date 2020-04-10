use std::io;

const MAXLINES: usize  =  5000;  // Maximum number of lines to be sorted
const MAXLEN:   usize  =  1000;  // Maximum length of a input line

fn main ()
{
    // The main diference from C implementation is that instead of using an
    // vec of references (as would be the first thought), we use a vec of Boxes.
    //
    // "A box is a smart pointer to a heap allocated value of type T.
    //  When a box goes out of scope, its destructor is called, the inner
    //  object is destroyed, and the memory on the heap is freed.
    //  Boxed values can be dereferenced using the * operator; this removes one
    //  layer of indirection."
    //
    //  https://doc.rust-lang.org/rust-by-example/std/box.html
    let mut lineptr: Vec<Box<String>> = Vec::with_capacity(MAXLINES);

    let nlines: usize;             // Number of read lines

    nlines = readlines(&mut lineptr, MAXLINES).ok().unwrap_or(0);

    if nlines != 0 {
        qsort(&mut lineptr, 0, nlines-1);
        writelines(&lineptr, nlines);
    } else {
        print!("[*]\tError:\tInput too big to sort!\n");
    }
}

fn getline (line: &mut String, lim: usize) -> Result<usize, ()>
{
    let mut input = String::new();

    match io::stdin().read_line(&mut input) {
        Ok (n_bytes) => {
            if n_bytes == 0 || n_bytes >= lim {
                return Ok(0);
            }

            *line = input.trim_end().to_string();

            input.clear();

            return Ok(n_bytes);
        },
        Err(_) => {
            panic!("Unexpected error.");
        }
    }
}

fn readlines (
    lineptr: &mut Vec<Box<String>>,
    maxlines: usize
) -> Result<usize, ()>
{
    let mut nlines: usize = 0;
    let mut line = String::with_capacity(MAXLEN);

    while getline(&mut line, MAXLEN).ok().unwrap_or(0) > 0 {
        if nlines >= maxlines { return Err(()); }

        // The main reason to the usage of a Box is here. As we want the string
        // saved in 'line' to exist after the scope of this function, we create
        // as box (reference) to it ans push to our array of boxes (references).
        lineptr.push(Box::new(line.trim_end().to_string()));

        nlines += 1;
    }

    Ok(nlines)
}

fn writelines (lineptr: &Vec<Box<String>>, nlines: usize)
{
    let mut i: usize = 0;

    while i < nlines {
        print!("[{:4}]\t=>\t\"{}\"\n", i, *lineptr[i]);
        i += 1;
    }
}

fn qsort(v: &mut Vec<Box<String>>, left: usize, right: usize)
{
    let mut i: usize;
    let mut last: usize;

    if left >= right { return; }

    swap(v, left, (left + right) / 2);

    last = left;
    i = left + 1;

    while i <= right {
        if strcmp(&*v[i], &*v[left]).ok().unwrap_or(0) < 0 {
            last += 1;
            swap(v, last, i);
        }

        i += 1;
    }

    swap(v, left, last);

    // As 'last' is a usize and can't be less than 0 (unsigned) we need to
    // saturate those operations
    qsort(v, left, last.saturating_sub(1));
    qsort(v, last.saturating_add(1), right);
}

fn swap(v: &mut Vec<Box<String>>, i: usize, j: usize)
{
    // In this context, we don't want our Boxes to be moved or borrowed, as they
    // must stay alive after the swap. We need to clone it to keep it alive
    let temp: Box<String> = v[i].clone();

    v[i] = v[j].clone();
    v[j] = temp.clone();
}

/// A brief implementation of C's strcmp
///
/// @param first    String to be compared
/// @param second   String to be compared with
///
/// @return Result  u64 indicating order or nothing to indicate error
fn strcmp (first: &String, second: &String) -> Result<i8, ()>
{
    let mut first_itr = first.chars();
    let mut second_itr = second.chars();

    // This loop will continue while there are chars in strings are equal
    loop {
        let _c1 = first_itr.next();
        let _c2 = second_itr.next();

        // If both strings ends, they are equal
        if _c1 == None && _c2 == None { return Ok(0); }

        // If string one ends before the other
        if _c1 == None && _c2 != None { return Ok(-1); }

        // If string two ends before the other
        if _c1 != None && _c2 == None { return Ok(1); }

        // If any character differs before any of them ends
        if _c1 != _c2 {

            // In Rust, 'char' implements trait 'Ord' and can be compared like this
            if _c1.unwrap() < _c2.unwrap() {
                return Ok(-1);
            }

            return Ok(1);
        }
    }
}
