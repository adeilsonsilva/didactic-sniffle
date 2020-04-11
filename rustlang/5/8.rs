const DAYTAB: [[u8; 13]; 2] = [
    [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31],
    [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
];

/// Set day of year from month and day
///
/// @param year
/// @param month
/// @param day
///
/// @return i8 Ordered number of the day inside year
fn day_of_year (year: u64, month: u8, day: u16) -> Result<u16, i8>
{
    let mut _day = day;

    if year < 1752 || month < 1 || month > 12 || day > 31 { return Err(-1); }

    let mut i: usize = 1;
    let leap: usize = if ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) { 1 } else { 0 };

    while i < month as usize {
        _day += DAYTAB[leap][i] as u16;
        i += 1;
    }

    return Ok(_day);
}


/// Set month and day based on day of year
///
/// @param year
/// @param yearday
/// @param pmonth Place to save computed month
/// @param pday   Place to save computed day
fn month_day (year: u64, yearday: u16, pmonth: &mut u8, pday: &mut u16) -> i8
{
    if year < 1752 || yearday < 1 || yearday > 366 {
        return -1;
    }

    let leap: usize = if ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) { 1 } else { 0 };

    if (leap == 1 && yearday > 366) || (leap == 0 && yearday > 365) {
        return -1;
    }

    let mut i: usize = 1;
    let mut _yearday = yearday;

    while _yearday > DAYTAB[leap][i] as u16 && i < 13 {
        _yearday -= DAYTAB[leap][i] as u16;
        i += 1;
    }

    *pmonth = i as u8;
    *pday = _yearday;

    1
}

fn main ()
{
    let mut month: u8 = 0;
    let mut day:   u16 = 0;

    print!("[*] {}-{}-{}: {}th day.\n", 1925, 8, 14, day_of_year(1925, 8, 14).ok().unwrap());

    if month_day(1967, 27, &mut month, &mut day) > 0 {
        print!("[*] The {}th day of {} is the day {}-{}-{}.\n", 27, 1967, 1967, month, day);
    }
}
