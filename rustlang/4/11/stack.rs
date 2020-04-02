const MAXVAL : usize = 100;             /// Maximum depth of operand stack
static mut VAL : Vec<f32> = Vec::new(); /// Our operand stack

/// push:  push f onto value stack
/// It is unsafe because we manipulate a static mut variable inside it.
pub unsafe fn push(f: f32)
{
    if VAL.len() < MAXVAL {
        VAL.push(f);
    } else {
        print!("error: stack full, can't push {}\n", f);
    }
}

/// pop:  pop and return top value from stack
/// It is unsafe because we manipulate a static mut variable inside it.
pub unsafe fn pop() -> f32
{
    if VAL.len() > 0 {
        return VAL.pop().unwrap_or(0.0);
    } else {
        print!("error: stack empty\n");
        return 0.0;
    }
}

/// return top value from stack without popping
pub unsafe fn last() -> f32 {
    if VAL.len() > 0 {
        return *VAL.last().unwrap_or(&0.0);
    } else {
        print!("error: stack empty\n");
        return 0.0;
    }
}

/// duplicate top value from stack
pub unsafe fn duplicate() {
    if VAL.len() > 0 {
        push(last());
    } else {
        print!("error: stack empty\n");
    }
}

/// swap top two values from stack
pub unsafe fn swap() {
    let aux1 : f32;
    let aux2 : f32;

    if VAL.len() >= 2 {
        aux1 = pop();
        aux2 = pop();
        push(aux1);
        push(aux2);
    } else {
        print!("error: can't swap with {} elements\n", VAL.len());
    }
}

/// clear all stack
pub unsafe fn clear() {
    print!("stack cleared\n");
    VAL.clear();
}
