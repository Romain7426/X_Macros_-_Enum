#include "decimal_global.h" 
#include "decimal.h" 




int main(const int argc, const char * argv[]) { 
  decimal__check_and_assert(); 

  const int stduser_d = STDOUT_FILENO; 
  decimal_version__print(stduser_d); 
  decimal_url__print(stduser_d); 
  decimal_copyright__print(stduser_d); 
  decimal_example__print(stduser_d); 
  
  for (int i = 0; i < DECIMAL_ERROR__COUNT; i++) { 
    const char *  cstr  = int_decimal_error__id_cstr[i]; 
    const uint8_t value = int_decimal_error__id_value[i]; 
    char value_buffer[64]; 
    const char * value_cstr = uint_string_in_the_buffer(value, ARRAY_SIZE(value_buffer), value_buffer); 
    write_string(stduser_d, cstr); 
    write_string(stduser_d, " = "); 
    write_string_ln(stduser_d, value_cstr); 
  }; 
  
  for (int i = 0; i < DECIMAL_STATUS__COUNT; i++) { 
    const char *  cstr  = decimal_status__id_cstr[i]; 
    const uint8_t value = decimal_status__id_value[i]; 
    char value_buffer[64]; 
    const char * value_cstr = uint_string_in_the_buffer(value, ARRAY_SIZE(value_buffer), value_buffer); 
    write_string(stduser_d, cstr); 
    write_string(stduser_d, " = "); 
    write_string_ln(stduser_d, value_cstr); 
  }; 
  
  return 0; 
}; 






