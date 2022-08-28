#![no_std]
use core::arch::asm;

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
        loop {}
}

fn set_reg(){
    unsafe { 
        asm!(
            "ldi r14, 0xffff",
            "xor r30, r30, r14");
    }
}

fn main() {
}
