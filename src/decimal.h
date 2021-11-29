#ifndef DECIMAL_H
#define DECIMAL_H

#define DECIMAL_VERSION__LIST		\
  X(DECIMAL_VERSION_MAJOR, = 3)		\
  X(DECIMAL_VERSION_MINOR, = 2)		\
  X(DECIMAL_VERSION_REVISION, = 0) 

#define X(ident, value) ident value, 
enum { 
  DECIMAL_VERSION__LIST 
}; 
#undef X 

#define X(ident, value) extern const uint8_t ident##__compiled_value; 
DECIMAL_VERSION__LIST 
#undef X 

static void decimal_version__check_and_assert(void) { 
#define X(ident, value) assert(ident == ident##__compiled_value); 
DECIMAL_VERSION__LIST 
#undef X 
}; 

extern const char       decimal_version[]; 
extern const uint16_t   decimal_version__strlen; 
extern const char     * decimal_version__get(void); 
extern void             decimal_version__print(const int stduser_d); 

extern const char       decimal_url[]; 
extern const uint16_t   decimal_url__strlen; 
extern const char     * decimal_url__get(void); 
extern void             decimal_url__print(const int stduser_d); 

extern const char       decimal_copyright[]; 
extern const uint16_t   decimal_copyright__strlen; 
extern const char     * decimal_copyright__get(void); 
extern void             decimal_copyright__print(const int stduser_d); 

extern const char       decimal_example[]; 
extern const uint16_t   decimal_example__strlen; 
extern const char     * decimal_example__get(void); 
extern void             decimal_example__print(const int stduser_d); 


// *** ERROR CODES & RETURN VALUES *** 
// See «man 2 wait» & «man 3 exit». 
// The exit value is gotten by the parent using the macro WEXITSTATUS(…), 
// which returns the lower 8 bits of the exit status. All other bits are 
// used as status information on the process. 
// The WEXITSTATUS(…) value is gotten from the lower 8 bits of the exit 
// call. 
// The system, the environment, can interpret the WEXITSTATUS(…) 8-bit value as 
// signed or unsigned — that depends. Thus: 
//  - Only the 0-127 range is sure. 
//  - The 128-255 range (the -128_-1 range) could be interpreted as positive or negative. 
// However, in the program, the sign interpretation of these values depends only 
// on the type declaration, «int8_t error_id» or «uint8_t error_id» — so they are safe. 


#define DECIMAL_ERROR__LIST			\
  X(DECIMAL__OK, = 0)				\
  /* Unspecified */				\
  X(DECIMAL__ERROR_GENERIC, = INT8_MIN)	\
  /* Errors */			\
  X(DECIMAL__STRCOPY, = INT8_MIN + 1) \
  X(DECIMAL__MAIN_ERROR_ID_NOT_ASSIGNED, ) \
  X(DECIMAL__STDERR_IS_NOT_A_TTY, ) \
  X(DECIMAL__STDOUT_IS_NOT_A_TTY, ) \
  X(DECIMAL__STDIN_IS_NOT_A_TTY, ) \
  X(DECIMAL__REPL_EXTRA_ARGS, ) \
  X(DECIMAL__REPL_ERROR_WHILE_READING, ) \
  X(DECIMAL__STDUSER_NOT_POS, ) \
  X(DECIMAL__MAKE_B_BUFFER_SIZE_TOO_SMALL, ) \
  X(DECIMAL__MAKE_B_BUFFER_IS_NULL, ) \
  X(DECIMAL__STATUS_NOT_LISTED_IN_SWITCH, ) \
  X(DECIMAL__NULL_NEW_D_STATUS_R, ) \
  X(DECIMAL__MALFORMED_NUMBER, ) \
  X(DECIMAL__NUMBER_WAS_EMPTY, ) \
  X(DECIMAL__D_LEN_WAS_ZERO, ) \
  X(DECIMAL__D_LAMBDA_WAS_ZERO, ) \
  X(DECIMAL__INTERNAL_ERROR, ) \
  X(DECIMAL__FD_NEG, ) \
  X(DECIMAL__FDOPEN, ) \
  X(DECIMAL__NULL_FIELD_NAME, ) \
  X(DECIMAL__UNKNOWN_FIELD, ) \
  X(DECIMAL__INDEX_OF_OUT_BOUNDS, ) \
  X(DECIMAL__NULL_ERROR_ID_R, ) \
  X(DECIMAL__ERROR_SIZE_LOWER_THAN_1, ) \
  X(DECIMAL__NULL_INPUT_ENV, ) \
  X(DECIMAL__NULL_TOKEN_ENV, ) \
  X(DECIMAL__TOKEN_PARSER__ERROR_WHILE_READING__, ) \
  X(DECIMAL__TOKEN_PARSER__TOKEN_MATCHES_NO_PATTERN, ) \
  X(DECIMAL__TOKEN_PARSER__ERROR_TOKEN, ) \
  X(DECIMAL__TOKEN_PARSER__STACK_OVERFLOW, ) \
  X(DECIMAL__DATA_GEN__NULL_SYNTAX_FILTERING, ) \
  X(DECIMAL__DATA_GEN__NULL_TOKEN_ENV, ) \
  X(DECIMAL__DATA_GEN__NULL_DIRECTIVE_OR__, ) \
  X(DECIMAL__DATA_GEN__NULL_BYTECODE_DATA, ) \
  X(DECIMAL__DATA_GEN__NULL_BYTECODE_LEN_R, ) \
  X(DECIMAL__DATA_GEN__NULL_CONST_STRING_ARRAY, ) \
  X(DECIMAL__DATA_GEN__NULL_CONST_STRING_LEN_R, ) \
  X(DECIMAL__DATA_GEN__ERROR_ID_NOT_ASSIGNED, ) \
  X(DECIMAL__DATA_GEN__NULL_FLOATVAL_R, ) \
  X(DECIMAL__DATA_GEN__NULL_INTVAL_R, ) \
  X(DECIMAL__DATA_GEN__NULL_ERROR_ID_R, ) \
  X(DECIMAL__DATA_GEN__ERROR_SIZE_LOWER_THAN_1, ) \
  X(DECIMAL__DATA_GEN__NOT_ENOUGH_TOKENS, ) \
  X(DECIMAL__DATA_GEN__TOO_MANY_TOKENS, ) \
  X(DECIMAL__DATA_GEN__NON_MATCHING_TOKEN_TYPE, ) \
  X(DECIMAL__DATA_GEN__NON_MATCHING_TOKEN_VALUE, ) \
  X(DECIMAL__DATA_GEN__NULL_TREE_ENV, ) \
  X(DECIMAL__DATA_GEN__TREE_ENV__EMPTY, ) \
  X(DECIMAL__DATA_GEN__TREE_ENV__BEING_FILLED, ) \
  X(DECIMAL__DATA_GEN__TREE_ENV__NOT_FILLED, ) \
  X(DECIMAL__DATA_GEN__NOT_ENOUGH__, ) \
  X(DECIMAL__DATA_GEN__TREE__WRONG__, ) \
  X(DECIMAL__DATA_GEN__MISSING_PHYSIQUE__, ) \
  X(DECIMAL__DATA_GEN__MISSING_GAMEPLAY__, ) \
  X(DECIMAL__DATA_GEN__MISSING_GRAPHIQUE__, ) \
  X(DECIMAL__DATA_GEN__STACK_OVERFLOW, ) \
  X(DECIMAL__DATA_GEN__STACK_UNDERFLOW, ) \
  X(DECIMAL__DATA_GEN__STACK_UNEXPECTED_TOKEN, ) \
  X(DECIMAL__DATA_GEN__STACK_TOO_MANY_ITEMS, ) \
  X(DECIMAL__DATA_GEN__STACK_NOT_ENOUGH_ITEMS, ) \
  X(DECIMAL__DATA_GEN__MEMBRES_OVERFLOW, ) \
  X(DECIMAL__DATA_GEN__RACINES_OVERFLOW, ) \
  X(DECIMAL__BYTECODE_GEN__NOT__, ) \
  X(DECIMAL__STACK__EMPTY, ) \
  X(DECIMAL__VM__STRCOPY, ) \
  X(DECIMAL__VM__ERROR_ID_NOT_ASSIGNED, ) \
  X(DECIMAL__VM__PC_OUT_OF_BOUNDS, ) \
  X(DECIMAL__VM__STACK_OVERFLOW, ) \
  X(DECIMAL__VM__STACK_UNDERFLOW, ) \
  X(DECIMAL__VM__CONST_STRING_ARRAY_OUT_OF_BOUNDS, ) \
  X(DECIMAL__VM__NULL_BYTECODE, ) \
  X(DECIMAL__TREE__NO_SPACE_LEFT, ) \
  X(DECIMAL__TREE__WRONG_ADDRESS, ) \
  X(DECIMAL__SYNTAX_FILTERING__NULL_THIS, ) \
  X(DECIMAL__SYNTAX_FILTERING__NULL_TOKEN_ENV, ) \
  X(DECIMAL__SYNTAX_FILTERING__NULL_TOKEN_I, ) \
  X(DECIMAL__SYNTAX_FILTERING__OUTPUT_POSTFIX__, ) \
  X(DECIMAL__SYNTAX_FILTERING__PARENTHESIS__, ) \
  X(DECIMAL__SYNTAX_FILTERING__MISSING_C__, ) \
  X(DECIMAL__SYNTAX_FILTERING__MISSING_O__, ) \
  X(DECIMAL__SYNTAX_FILTERING__MISMATCHING__, ) \
  X(DECIMAL__SYNTAX_FILTERING__NOT_AN_O__, ) \
  X(DECIMAL__SYNTAX_FILTERING__NOT_AN_C__, ) \
  X(DECIMAL__SYNTAX_FILTERING__OUT_OF_BOUND__, ) \
  X(DECIMAL__SYNTAX_FILTERING__IS_INVALID__, ) \
  X(DECIMAL__SYNTAX_FILTERING__IS_EOF__, ) \
  X(DECIMAL__SYNTAX_FILTERING__LAST__, ) \
  X(DECIMAL__SYNTAX_FILTERING__LALR__, ) \
  X(DECIMAL__SYNTAX_FILTERING__UNEXPECTED__, ) \
  X(DECIMAL__MAIN__OPTIONS__PARSING_ERROR, ) \
  X(DECIMAL__MAIN__OPTIONS__UNKNOWN, ) \
  X(DECIMAL__MAIN__OPTIONS__EXIT_QUICK, ) \
  X(DECIMAL__MAIN__CANNOT_OPEN_INPUT__, ) \
  X(DECIMAL__TOKEN__PARSER__ERROR, ) \
  X(DECIMAL__TOKEN__INPUT__ERROR, ) \
  /* Warnings */ \
  X(DECIMAL__NULL_STRUCT, = 1) \
  X(DECIMAL__EMPTY_STRUCTURE, ) \
  X(DECIMAL__FILLING_NOT_COMPLETED, ) \
  X(DECIMAL__HAS_BREAKING_UNCONSISTENCIES, ) \
  X(DECIMAL__HAS_NON_BREAKING_UNCONSISTENCIES, ) \
  X(DECIMAL__SYNTAX_F__TOKEN_ENV_HAS_ZERO_TOKEN, ) 

#define X(ident, value) ident value, 
enum { 
  DECIMAL_ERROR__LIST
}; 
#undef X 

#define X(ident, value) ident##___ID, 
enum { 
  DECIMAL_ERROR__LIST
  DECIMAL_ERROR__COUNT
}; 
#undef X 

typedef      int8_t               int_decimal_error_t;
extern const char *               int_decimal_error__get_cstr(const int_decimal_error_t error_id); 
extern const char *               int_decimal_error__id_cstr [DECIMAL_ERROR__COUNT + 1]; 
enum {                            int_decimal_error__id_cstr__size = ARRAY_SIZE(int_decimal_error__id_cstr) }; 
extern const uint8_t              int_decimal_error__id_cstr__size__compiled_value; 
extern const  int_decimal_error_t int_decimal_error__id_value[DECIMAL_ERROR__COUNT]; 
enum {                            int_decimal_error__id_value__size = ARRAY_SIZE(int_decimal_error__id_value) }; 
extern const uint8_t              int_decimal_error__id_value__size__compiled_value; 

#define X(ident, value) extern const int_decimal_error_t ident##__compiled_value; 
DECIMAL_ERROR__LIST 
#undef X 

static void int_decimal_error__check_and_assert(void) { 
  assert(DECIMAL_ERROR__COUNT <= UINT8_MAX); 
#define X(ident, value) assert(ident == ident##__compiled_value); 
DECIMAL_ERROR__LIST 
#undef X 
  assert(int_decimal_error__id_cstr__size  == int_decimal_error__id_cstr__size__compiled_value ); 
  assert(int_decimal_error__id_value__size == int_decimal_error__id_value__size__compiled_value); 
}; 



// *** DECIMAL_ENV_T *** 

#define DECIMAL_ENV_CONST__LIST				\
  X(DECIMAL_ENV__ERROR_BUFFER_SIZE, = (1 << 11))	\
  X(DECIMAL_ENV__STRING_STACK_SIZE, = (1 << 12))	\
  X(DECIMAL_ENV__SIZEOF, = (6176))		

#define X(ident, value) ident value, 
enum { 
  DECIMAL_ENV_CONST__LIST
}; 
#undef X 

#define X(ident, value) ident##___ID, 
enum { 
  DECIMAL_ENV_CONST__LIST
  DECIMAL_ENV_CONST__COUNT
}; 
#undef X 

#define X(ident, value) extern const uint16_t ident##__compiled_value; 
  DECIMAL_ENV_CONST__LIST
#undef X 

extern const uint16_t decimal_env__sizeof; 

static void decimal_env_const__check_and_assert(void) { 
#define X(ident, value) assert(ident == ident##__compiled_value); 
  DECIMAL_ENV_CONST__LIST
#undef X 
  assert(DECIMAL_ENV__ERROR_BUFFER_SIZE >= 3); 
  assert(DECIMAL_ENV__STRING_STACK_SIZE >= 3); 
  assert(DECIMAL_ENV__SIZEOF >= decimal_env__sizeof); 
}; 




// *** DECIMAL_STATUS *** 

#define DECIMAL_STATUS__LIST		\
  X(DECIMAL_STATUS__INVALID, = UINT8_MAX)	\
  X(DECIMAL_STATUS__ZERO, = 0)		\
  X(DECIMAL_STATUS__INFINI, )		\
  X(DECIMAL_STATUS__POS, )		\
  X(DECIMAL_STATUS__NEG, )		\
  X(DECIMAL_STATUS__POS_INFINI, )	\
  X(DECIMAL_STATUS__NEG_INFINI, )	\
  X(DECIMAL_STATUS__POS_EPSILON, )	\
  X(DECIMAL_STATUS__NEG_EPSILON, )	\
  X(DECIMAL_STATUS__DEVELOPPEMENT_LIMITE_NECESSAIRE, ) 

#if 0 
  X(DECIMAL_STATUS__0_DIV_BY_0, )	\
  X(DECIMAL_STATUS__INF_DIV_BY_INF, )	\
  X(DECIMAL_STATUS__ZERO_BY_INF, )	\
  X(DECIMAL_STATUS__INF_BY_ZERO, )	
#endif 
    

#define X(ident, value) ident value, 
enum { 
  DECIMAL_STATUS__LIST 
}; 
#undef X 

#define X(ident, value) ident##___ID, 
enum { 
  DECIMAL_STATUS__LIST
  DECIMAL_STATUS__COUNT
}; 
#undef X 

#define X(ident, value) extern const uint8_t ident##__compiled_value; 
DECIMAL_STATUS__LIST 
#undef X 

extern const char *  decimal_status__id_cstr [DECIMAL_STATUS__COUNT + 1]; 
enum {               decimal_status__id_cstr__size = ARRAY_SIZE(decimal_status__id_cstr) }; 
extern const uint8_t decimal_status__id_cstr__size__compiled_value; 
extern const uint8_t decimal_status__id_value[DECIMAL_STATUS__COUNT]; 
enum {               decimal_status__id_value__size = ARRAY_SIZE(decimal_status__id_value) }; 
extern const uint8_t decimal_status__id_value__size__compiled_value; 

static void decimal_status__check_and_assert(void) { 
  assert(DECIMAL_STATUS__COUNT <= UINT8_MAX); 
#define X(ident, value) assert(ident == ident##__compiled_value); 
DECIMAL_STATUS__LIST 
#undef X 
  assert(decimal_status__id_cstr__size  == decimal_status__id_cstr__size__compiled_value ); 
  assert(decimal_status__id_value__size == decimal_status__id_value__size__compiled_value); 
}; 

extern const char *  decimal_status__cstr(const uint8_t status); 
extern       uint8_t decimal_status__id  (const uint8_t status); 
extern       int     decimal_status__value_is_a_status_huh(const uint8_t status); 



//* DECIMAL_T */

enum {  DECIMAL_SIZE             =                256 }; 
enum {  DECIMAL_FIXED_POINT_SIZE =                200 }; 
#define DECIMAL_BASE_MACRO                        100 
enum {  DECIMAL_BASE             = DECIMAL_BASE_MACRO }; 

#define DECIMAL_BASE_GENERIC__GET_QUOTIENT(__dividend__)  ((__dividend__) / DECIMAL_BASE) 
#define DECIMAL_BASE_GENERIC__GET_REMAINDER(__dividend__) ((__dividend__) % DECIMAL_BASE) 

#define DECIMAL_BASE_100__GET_QUOTIENT(__dividend__)  ((__dividend__) / DECIMAL_BASE) 
#define DECIMAL_BASE_100__GET_REMAINDER(__dividend__) ((__dividend__) % DECIMAL_BASE) 
  
#define DECIMAL_BASE_2__GET_QUOTIENT(__dividend__)  ((__dividend__) >> 1) 
#define DECIMAL_BASE_2__GET_REMAINDER(__dividend__) ((__dividend__) & 1) 
  
#if   (DECIMAL_BASE_MACRO == 100) 
#define DECIMAL_BASE__GET_QUOTIENT  DECIMAL_BASE_100__GET_QUOTIENT
#define DECIMAL_BASE__GET_REMAINDER DECIMAL_BASE_100__GET_REMAINDER 
#elif (DECIMAL_BASE_MACRO ==   2) 
#define DECIMAL_BASE__GET_QUOTIENT  DECIMAL_BASE_2__GET_QUOTIENT
#define DECIMAL_BASE__GET_REMAINDER DECIMAL_BASE_2__GET_REMAINDER 
#else 
#define DECIMAL_BASE__GET_QUOTIENT  DECIMAL_BASE_GENERIC__GET_QUOTIENT
#define DECIMAL_BASE__GET_REMAINDER DECIMAL_BASE_GENERIC__GET_REMAINDER 
#endif 

extern const uint16_t DECIMAL_SIZE__compiled_value; 
extern const uint8_t  DECIMAL_FIXED_POINT_SIZE__compiled_value; 
extern const uint8_t  DECIMAL_BASE__compiled_value; 

static void decimal_struct__check_and_assert(void) { 
  assert(DECIMAL_SIZE <= UINT8_MAX + 1); 
  assert(DECIMAL_FIXED_POINT_SIZE < DECIMAL_SIZE); 
  assert(DECIMAL_BASE < UINT8_MAX); 

  assert(DECIMAL_SIZE > 0); 
  assert(DECIMAL_FIXED_POINT_SIZE > 0); 
  assert(DECIMAL_BASE > 1); 

  assert(DECIMAL_SIZE             == DECIMAL_SIZE__compiled_value            ); 
  assert(DECIMAL_FIXED_POINT_SIZE == DECIMAL_FIXED_POINT_SIZE__compiled_value); 
  assert(DECIMAL_BASE             == DECIMAL_BASE__compiled_value            ); 
}; 

typedef unsigned char decimal_t[DECIMAL_SIZE]; 


enum { DECIMAL__EXPRESSION_NESTEDNESS_MAX = 16 }; // The stack has to be allocated beforehand. 
extern const uint8_t DECIMAL__EXPRESSION_NESTEDNESS_MAX__compiled_value; 

// Buffer has to be allocated. 
enum { DECIMAL__LONGEST_INFIX_EXPRESSION = 64 }; // 2^6 = 64 — therefore, it means roughly a six-height tree (on average). 
extern const uint8_t DECIMAL__LONGEST_INFIX_EXPRESSION__compiled_value; 



static void decimal_expr__check_and_assert(void) { 
  assert(DECIMAL__EXPRESSION_NESTEDNESS_MAX == DECIMAL__EXPRESSION_NESTEDNESS_MAX__compiled_value); 
  assert(DECIMAL__LONGEST_INFIX_EXPRESSION  == DECIMAL__LONGEST_INFIX_EXPRESSION__compiled_value ); 
}; 





static void decimal__check_and_assert(void) { 
  decimal_version__check_and_assert(); 
  int_decimal_error__check_and_assert(); 
  decimal_env_const__check_and_assert(); 
  decimal_struct__check_and_assert(); 
  decimal_status__check_and_assert(); 
  decimal_expr__check_and_assert(); 
}; 





#endif /* DECIMAL_H */
