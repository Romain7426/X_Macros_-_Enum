#include "decimal_global.h"
#include "decimal.h" 


#define X(ident, value) const uint8_t ident##__compiled_value value; 
DECIMAL_VERSION__LIST 
#undef X 

const char       decimal_version[] = { DIGIT_TO_CHAR(DECIMAL_VERSION_MAJOR), '.', DIGIT_TO_CHAR(DECIMAL_VERSION_MINOR), '.', DIGIT_TO_CHAR(DECIMAL_VERSION_REVISION), '\0' }; 
enum {           decimal_version__strlen__const_value = ARRAY_SIZE(decimal_version) - 1 }; 
const uint16_t   decimal_version__strlen = decimal_version__strlen__const_value; 
const char     * decimal_version__get(void) { return decimal_version; }; 
void             decimal_version__print(const int stduser_d) { if (stduser_d > 0) { write(stduser_d, decimal_version, decimal_version__strlen__const_value); write(stduser_d, "\n", 1); }; };

const char       decimal_example[] = "1 + 2"; 
enum {           decimal_example__strlen__const_value = ARRAY_SIZE(decimal_example) - 1 }; 
const uint16_t   decimal_example__strlen = decimal_example__strlen__const_value; 
const char     * decimal_example__get(void) { return decimal_example; }; 
void             decimal_example__print(const int stduser_d) { if (stduser_d > 0) { write(stduser_d, decimal_example, decimal_example__strlen__const_value); write(stduser_d, "\n", 1); }; }; 

#define PROGRAM_NAME "Decimal number lib & calculator" 
static const char program_name[] = PROGRAM_NAME; 
enum {  program_name__cstrlen    = ARRAY_SIZE(program_name) - 1 }; 
#define PROGRAM_COPYRIGHT_YEAR1 "2021" 
#define PROGRAM_COPYRIGHT_YEAR2 "2021" 
#define PROGRAM_URL             "https://github.com/Romain7426/Calculatrice_decimale" 
#define PROGRAM_AUTHOR          "https://github.com/Romain7426" 

const char       decimal_url[] = PROGRAM_URL; 
enum {           decimal_url__strlen__const_value = ARRAY_SIZE(decimal_url) - 1 }; 
const uint16_t   decimal_url__strlen = decimal_url__strlen__const_value; 
const char     * decimal_url__get(void) { return decimal_url; }; 
void             decimal_url__print(const int stduser_d) { if (stduser_d > 0) { write(stduser_d, decimal_url, decimal_url__strlen__const_value); write(stduser_d, "\n", 1); }; }; 

const char decimal_copyright[] = 
"_Software_       : " PROGRAM_NAME "                       " "\n"
"_License_        : " "ISC-like license                                  " "\n" 
"                   " "https://en.wikipedia.org/wiki/ISC_license          " "\n"
"_URL_            : " PROGRAM_URL "         " "\n"
"_Copyright years_: " PROGRAM_COPYRIGHT_YEAR1 " - " PROGRAM_COPYRIGHT_YEAR2 "\n"
"                                                                        " "\n"
PROGRAM_NAME "                         " "\n"
"Copyright (c) " PROGRAM_COPYRIGHT_YEAR1 " - " PROGRAM_COPYRIGHT_YEAR2 " " "\n"
"                                                                        " "\n"
"Permission to use, copy, modify, and distribute this software for any   " "\n"
"purpose with or without fee is hereby granted without any restrictions. " "\n"
"                                                                        " "\n"
"THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL WARRANTIES" "\n"
"WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF        " "\n"
"MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR " "\n"
"ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  " "\n"
"WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN   " "\n"
"ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF " "\n"
"OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.          " "\n"
"                                                                        " "\n" 
"NB: We do not care of what you do with this code as long as             " "\n" 
"    you do not prevent us nor others from using it.                     " "\n" 
;

enum {           decimal_copyright__strlen__const_value = ARRAY_SIZE(decimal_copyright) - 1 }; 
const uint16_t   decimal_copyright__strlen = (uint16_t) decimal_copyright__strlen__const_value; 
const char     * decimal_copyright__get(void) { return decimal_copyright; }; 
void             decimal_copyright__print(const int stduser_d) { if (stduser_d > 0) { write(stduser_d, decimal_copyright, decimal_copyright__strlen__const_value); if ('\n' != *(decimal_copyright + decimal_copyright__strlen__const_value - 1)) write(stduser_d, "\n", 1); }; }; 



// --- DECIMAL_ERROR --- 

#define X(ident, value) const int_decimal_error_t ident##__compiled_value = ident; 
DECIMAL_ERROR__LIST 
#undef X 

#define X(ident, value) #ident, 
const char * int_decimal_error__id_cstr[DECIMAL_ERROR__COUNT + 1] = { 
DECIMAL_ERROR__LIST 
  NULL
}; 
#undef X 
 
const uint8_t int_decimal_error__id_cstr__size__compiled_value = ARRAY_SIZE(int_decimal_error__id_cstr); 

#define X(ident, value) ident, 
const int_decimal_error_t int_decimal_error__id_value[DECIMAL_ERROR__COUNT] = { 
DECIMAL_ERROR__LIST 
}; 
#undef X 

const uint8_t int_decimal_error__id_value__size__compiled_value = ARRAY_SIZE(int_decimal_error__id_value); 

const char * int_decimal_error__get_cstr(const int_decimal_error_t error_id) { 
  const char * error_id__cstr = NULL; 
  switch (error_id) { 
#define X(ident, value) case ident: error_id__cstr = #ident; break; 
  DECIMAL_ERROR__LIST
#undef X 
  }; 
  return error_id__cstr; 
}; 


// --- DECIMAL_ENV_T --- 

#define X(ident, value) const uint16_t ident##__compiled_value value; 
DECIMAL_ENV_CONST__LIST 
#undef X 

struct decimal_env_t { 
  uint8_t malloced_flag; // 0 if not, 1 if yes. 
  
  int stdlog_d; // Foreign — we don't own it; valid only if 'stdlog_d > 0' 
  
  int_decimal_error_t error_id; // 0: none; …<0: error; …>0: warning 
  char                error_str[DECIMAL_ENV__ERROR_BUFFER_SIZE]; 
  uint16_t            error_size; 
  
  char     string_stack[DECIMAL_ENV__STRING_STACK_SIZE]; 
  uint16_t string_stack_nb; 
  
  const char * copyright; 
  
  const char * filename; 
  
}; 


enum { DECIMAL_ENV__SIZEOF__E = sizeof(struct decimal_env_t) }; 
const uint16_t decimal_env__sizeof = sizeof(struct decimal_env_t); 




// --- DECIMAL_STATUS --- 

#define X(ident, value) const uint8_t ident##__compiled_value = ident; 
DECIMAL_STATUS__LIST 
#undef X 

#define X(ident, value) #ident, 
const char * decimal_status__id_cstr[DECIMAL_STATUS__COUNT + 1] = { 
DECIMAL_STATUS__LIST 
  NULL
}; 
#undef X 
 
const uint8_t decimal_status__id_cstr__size__compiled_value = ARRAY_SIZE(decimal_status__id_cstr); 

#define X(ident, value) ident, 
const uint8_t decimal_status__id_value[DECIMAL_STATUS__COUNT] = { 
DECIMAL_STATUS__LIST 
}; 
#undef X 

const uint8_t decimal_status__id_value__size__compiled_value = ARRAY_SIZE(decimal_status__id_value); 



const char * decimal_status__cstr(const uint8_t status) { 
  const char * status_cstr = NULL; 
  switch (status) { 
#define X(ident, value) case ident: status_cstr = #ident; break; 
  DECIMAL_STATUS__LIST 
#undef X 
  }; 
  return status_cstr; 
}; 

uint8_t decimal_status__id(const uint8_t status) { 
  uint8_t status_id; // = DECIMAL_STATUS__COUNT; 
  switch (status) { 
#define X(ident, value) case ident: status_id = ident##___ID; break; 
  DECIMAL_STATUS__LIST 
#undef X 
  }; 
  return status_id; 
}; 

int decimal_status__value_is_a_status_huh(const uint8_t status) { 
  int value_is_a_status_huh; // = false; status_id; // = DECIMAL_STATUS__COUNT; 
  switch (status) { 
#define X(ident, value) case ident: value_is_a_status_huh = true; break; 
  DECIMAL_STATUS__LIST 
#undef X 
    default: value_is_a_status_huh = false; break; 
  }; 
  return value_is_a_status_huh; 
}; 




// --- DECIMAL STRUCT --- 

enum { DECIMAL_STATUS_INDEX              = 0 }; 
enum { DECIMAL_STATUS_SIZE               = 1 }; 
enum { DECIMAL_DIGITS_INDEX              = DECIMAL_STATUS_INDEX + DECIMAL_STATUS_SIZE }; 
enum { DECIMAL_DIGITS_SIZE               = DECIMAL_SIZE - DECIMAL_STATUS_SIZE }; 
enum { DECIMAL_DIGITS_INDEX_XLAST        = DECIMAL_DIGITS_INDEX + DECIMAL_DIGITS_SIZE }; 
enum { DECIMAL_DIGITS_INDEX_ELAST        = DECIMAL_DIGITS_INDEX_XLAST - 1 }; 
enum { DECIMAL_DIGITS_INDEX_FIRST        = DECIMAL_DIGITS_INDEX }; 
enum { DECIMAL_DIGITS_INDEX_FIRST_MINUS1 = DECIMAL_DIGITS_INDEX_FIRST - 1 }; 
enum { DECIMAL_DIGITS_INDEX_LAST         = DECIMAL_DIGITS_INDEX_ELAST }; 
enum { DECIMAL_DIGITS_INDEX_LAST_PLUS1   = DECIMAL_DIGITS_INDEX_LAST + 1 }; 
enum { DECIMAL_FIXED_POINT_INDEX         = DECIMAL_DIGITS_INDEX + DECIMAL_FIXED_POINT_SIZE }; 
enum { DECIMAL_ZERO_INDEX                = DECIMAL_FIXED_POINT_INDEX }; 
enum { DECIMAL_INT_INDEX                 = DECIMAL_FIXED_POINT_INDEX }; 
enum { DECIMAL_INT_SIZE                  = DECIMAL_DIGITS_SIZE - DECIMAL_FIXED_POINT_SIZE }; 
enum { DECIMAL_EOF_BYTE                  = 255 }; 
enum { DECIMAL_SIZE_MINUS1               = DECIMAL_SIZE - 1 }; 
enum { DECIMAL_SIZE_DOUBLE               = DECIMAL_SIZE << 1 }; 
enum { DECIMAL_SIZE_DOUBLE_MINUS1        = DECIMAL_SIZE_DOUBLE - 1 }; 
enum { DECIMAL_BASE_MINUS1               = DECIMAL_BASE - 1 }; 

const uint16_t DECIMAL_SIZE__compiled_value             = DECIMAL_SIZE; 
const uint8_t  DECIMAL_FIXED_POINT_SIZE__compiled_value = DECIMAL_FIXED_POINT_SIZE; 
const uint8_t  DECIMAL_BASE__compiled_value             = DECIMAL_BASE; 

 
#define LOG2_OF_DECIMAL_BASE_AS_MACRO (GET_LOG2_VALUE_AS_MACRO(DECIMAL_BASE)) 
//enum { LOG2_OF_DECIMAL_BASE = LOG2_OF_DECIMAL_BASE_AS_MACRO }; 
enum { LOG2_OF_DECIMAL_BASE_AS_ENUM = GET_LOG2_VALUE_AS_ENUM(DECIMAL_BASE) }; 

#define LOG2_OF_DECIMAL_BASE LOG2_OF_DECIMAL_BASE_AS_ENUM 
//#define LOG2_OF_DECIMAL_BASE LOG2_OF_DECIMAL_BASE_AS_MACRO

static const uint8_t LOG_2_OF_DECIMAL_BASE__compiled_value = LOG2_OF_DECIMAL_BASE; 

enum { ONE_THIRD_OF_DECIMAL_BASE = (DECIMAL_BASE >> 2) + (DECIMAL_BASE >> 4) + (DECIMAL_BASE >> 6) }; 


static void decimal_struct__check_and_assert_compile_d76384342(void) { 
  ASSERT_COMPILE(DECIMAL_DIGITS_SIZE >= 1); 
  ASSERT_COMPILE(DECIMAL_INT_SIZE >= 2); // To have a quick & simple way to check if a mantisse is zero, we assume that the size is always greater or equal than two. // TODO XXX FIXME: Could be improved though. I'll see that later. 
  ASSERT_COMPILE(DECIMAL_FIXED_POINT_SIZE >= 2); // To have a quick & simple way to check if a number is greater or equal to 4/3. 
}; 


// --- DECIMAL EXPR --- 

const uint8_t DECIMAL__EXPRESSION_NESTEDNESS_MAX__compiled_value = (uint8_t) DECIMAL__EXPRESSION_NESTEDNESS_MAX; 
const uint8_t DECIMAL__LONGEST_INFIX_EXPRESSION__compiled_value  = (uint8_t) DECIMAL__LONGEST_INFIX_EXPRESSION; 

