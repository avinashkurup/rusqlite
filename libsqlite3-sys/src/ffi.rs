// src/ffi.rs
// use std::ffi::c_char;

extern "C" {
    pub fn sqlite3_html_init();
    // pub fn html_extract(document: *const c_char, selector: *const c_char) -> *const c_char;
}
