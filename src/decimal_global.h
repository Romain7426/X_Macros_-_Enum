#ifndef DECIMAL_GLOBAL_H
#define DECIMAL_GLOBAL_H

#include <unistd.h> // syscall functions (man 2: write, read, etc.) 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <limits.h> // NL_TEXTMAX 
#include <fcntl.h>
#include <errno.h>
#include <stdint.h> // INT64_MAX, etc. 
#include <inttypes.h> // int8_t, etc 
#include <ctype.h>
//#include <sys/types.h>
#include <time.h>
#include <math.h> // man 3 FPCLASSIFY: int fpclassify(real-floating x); 

#define ASSERT_COMPILE(a) { int tab[((a) ? 1 : (-1))]; }; 

#ifndef max 
# define max(a,b) (((a)>(b))?(a):(b)) 
#endif 
#ifndef MAX 
# define MAX max 
#endif 

#ifndef BOOL_ABS 
# define BOOL_ABS(a) (((a)>0)?(a):(-(a)))
#endif 

#ifndef false
enum { false = (0 != 0) }; 
enum { true = (0 == 0) }; 
enum { undecided_boolean = 1+MAX(BOOL_ABS(false),BOOL_ABS(true)) }; 
#endif

#ifndef ARRAY_SIZE
#define BYTELEN(s)   (sizeof(s)) 
#define ARRAYLEN(s)  (sizeof(s)/sizeof(*s)) 
#define ARRAY_LEN     ARRAYLEN
#define ARRAY_SIZE    ARRAYLEN 
//#define STRLEN(s)  (ARRAYLEN(s)-1) 
// Beware of a string like "bob\0and\0mary", as the preprocessor's STRLEN will never behave like the run-time one (12 vs 3). 
// Therefore this one is kind of more accurate. 
#endif 


#ifndef __PCC__ 
#define DIGIT_TO_STRING(d) (			\
			    (d) == 0 ? "0" :	\
			    (d) == 1 ? "1" :	\
			    (d) == 2 ? "2" :	\
			    (d) == 3 ? "3" :	\
			    (d) == 4 ? "4" :	\
			    (d) == 5 ? "5" :	\
			    (d) == 6 ? "6" :	\
			    (d) == 7 ? "7" :	\
			    (d) == 8 ? "8" :	\
			    (d) == 9 ? "9" :	\
			    "?")
#endif 

#define DIGIT_TO_CHAR(d) (((d) >= 0 && (d) <= 9) ? '0' + (d) : '?') 

#define MALLOC_BZERO(ctype_t,this) ctype_t * this = NULL; this = (ctype_t *) malloc(sizeof(*this)); bzero(this, sizeof(*this)); 

#define PI_AS_MACRO          3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068 
#define E_AS_MACRO           2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427 
#define LN2_AS_MACRO         0.693147180559945309417232121458176568075500134360255254120680009493393621969694715605863326996418687 
#define LOG10_OF_2_AS_MACRO  0.301029995663981195213738894724493026768189881462108541310427461127108189274424509486927252118186172040684
#define GAMMA_EULER_AS_MACRO 0.577215664901532860606512090082402431042159335939923598805767234884867726777664670936947063291746749
#define LN10_AS_MACRO        2.30258509299404568401799145468436420760110148862877297603332790096757260967735248023599

#define LN3_AS_MACRO         1.09861228866810969139524523692252570464749055782274945173469433363749429321860896687361575481373208878797
#define LN5_AS_MACRO         1.60943791243410037460075933322618763952560135426851772191264789147417898770765776463013387809317961
#define LN7_AS_MACRO         1.94591014905531330510535274344317972963708472958186118845939014993757986275206926778765849858787152
#define LN11_AS_MACRO        2.39789527279837054406194357796512929982170685393741717521856770913057362391323671307505470800263479
#define LN13_AS_MACRO        2.56494935746153673605348744156531860480526794476020711641904551066346466732441017939957466344048948
#define LN17_AS_MACRO        2.83321334405621608024953461787312653558820301258574478729723773788229257580093128091209486803750294
#define LN19_AS_MACRO        2.94443897916644046000902743188785353723737926129912881853796023640929270206419728871415838381573989
#define LN23_AS_MACRO        3.13549421592914969080675283181019611844238031484043574199863537748299324598479829819840109215299481
#define LN29_AS_MACRO        3.36729582998647402718327203236191160549451291392274407892167035164278078113785233329336711481785642
#define LN31_AS_MACRO        3.43398720448514624592916432454235721044993893048059197175671807247498141659755123221386483133608663
#define LN37_AS_MACRO        3.61091791264422444436809567103144716390007758716763616364491268119298974699036106539902153367216866
#define LN41_AS_MACRO        3.71357206670430780386676337303740758837641046939930163361926291025997861640565750596231714137198681
#define LN43_AS_MACRO        3.76120011569356242347284251334584703555913618488155541519168526492285917387298643853759199808399728
#define LN47_AS_MACRO        3.85014760171005858682095066977217370889605050202022403320050834680681821350580107261068975343474598
#define LN53_AS_MACRO        3.97029191355212183414446913902905777035997775291121760304812947001800463394348985853465994448592122984211
#define LN59_AS_MACRO        4.07753744390571945061605037371969762406334678933045452951203669705920011426542747735933995980263376
#define LN61_AS_MACRO        4.11087386417331124875138910342561474631568174308126106293738364641943980684494873118542920610010377
#define LN67_AS_MACRO        4.20469261939096605967007199636372275056693290322189533713778413077526850552808689663891418782102548
#define LN71_AS_MACRO        4.26267987704131542132945453251303409675957652671056610812142580202735150682423036596624332427263513
#define LN73_AS_MACRO        4.29045944114839112909210885743854257090475284487159766459569885716178997592059729327632932283485889
#define LN79_AS_MACRO        4.36944785246702149417294554148141092217354122442260962541217111755980606112443227814594036577407960
#define LN83_AS_MACRO        4.41884060779659792347547222329137045302931305666323637018794346293857898988899060583842729697057343
#define LN89_AS_MACRO        4.48863636973213983831781554066984921940466038713295936410669757728795389277945624644706355194947574
#define LN97_AS_MACRO        4.57471097850338282211672162170396171380891490265878135597623436876017729177818712534228274503427454992695

#define LOG2_OF_1_AS_MACRO     0 
#define LOG2_OF_2_AS_MACRO     1 
#define LOG2_OF_3_AS_MACRO     1.58496250072115618145373894394781650875981440769248106045575265454109822779435856252228047491808824 
#define LOG2_OF_4_AS_MACRO     2 
#define LOG2_OF_5_AS_MACRO     2.32192809488736234787031942948939017586483139302458061205475639581593477660862521585013974335937015 
#define LOG2_OF_6_AS_MACRO     2.58496250072115618145373894394781650875981440769248106045575265454109822779435856252228047491808824 
#define LOG2_OF_8_AS_MACRO     3 
#define LOG2_OF_7_AS_MACRO     2.80735492205760410744196931723183080864102662596614078367729172407032084886219298649786099917021078 
#define LOG2_OF_9_AS_MACRO     3.16992500144231236290747788789563301751962881538496212091150530908219645558871712504456094983617648 
#define LOG2_OF_10_AS_MACRO    3.32192809488736234787031942948939017586483139302458061205475639581593477660862521585013974335937015 
#define LOG2_OF_11_AS_MACRO    3.45943161863729725619936304672579295870323152568176807131280164572633061972001835270949129928690048 
#define LOG2_OF_12_AS_MACRO    3.58496250072115618145373894394781650875981440769248106045575265454109822779435856252228047491808824 
#define LOG2_OF_13_AS_MACRO    3.70043971814109216039681265425669473362843640179103736953846352584285518663302530014737653028115489 
#define LOG2_OF_14_AS_MACRO    3.80735492205760410744196931723183080864102662596614078367729172407032084886219298649786099917021078 
#define LOG2_OF_15_AS_MACRO    3.90689059560851852932405837343720668462464580071706167251050905035703300440298377837242021827745839 
#define LOG2_OF_16_AS_MACRO    4 
#define LOG2_OF_17_AS_MACRO    4.08746284125033940825406601081040435401126728234482068812660906438669650904738206829734315184368427 
#define LOG2_OF_18_AS_MACRO    4.16992500144231236290747788789563301751962881538496212091150530908219645558871712504456094983617648 
#define LOG2_OF_19_AS_MACRO    4.24792751344358549379351942290683442269350756966153401458152473086456520820546488680270805417217651 
#define LOG2_OF_20_AS_MACRO    4.32192809488736234787031942948939017586483139302458061205475639581593477660862521585013974335937015 
#define LOG2_OF_21_AS_MACRO    4.39231742277876028889570826117964731740084103365862184413304437861141907665655154902014147408829902 
#define LOG2_OF_22_AS_MACRO    4.45943161863729725619936304672579295870323152568176807131280164572633061972001835270949129928690048 
#define LOG2_OF_23_AS_MACRO    4.52356195605701287229414824416266884449882512544255505949444373201477814556276469611075452586208821 
#define LOG2_OF_24_AS_MACRO    4.58496250072115618145373894394781650875981440769248106045575265454109822779435856252228047491808824 
#define LOG2_OF_32_AS_MACRO    5 
#define LOG2_OF_64_AS_MACRO    6 
#define LOG2_OF_100_AS_MACRO   6.64385619 // log2(100) = log2(4) + log2(5^2) = 2 + 2 * log2(5) 
#define LOG2_OF_150_AS_MACRO   7.22881869 // 150 = 2*3*25 
#define LOG2_OF_180_AS_MACRO   7.4918531 // 180 = 4*5*9 
#define LOG2_OF_128_AS_MACRO   7 
#define LOG2_OF_200_AS_MACRO   7.64385619 // log2(200) = 1 + log2(100) 
#define LOG2_OF_210_AS_MACRO   7.71424552 // 210 = 2*3*5*7 
#define LOG2_OF_240_AS_MACRO   7.9068905956 // 240 = 60*4 = 3*5*16 
#define LOG2_OF_255_AS_MACRO   7.99435344 
#define LOG2_OF_256_AS_MACRO   8 
#define LOG2_OF_512_AS_MACRO   9 
#define LOG2_OF_1024_AS_MACRO  10 

#define GET_LOG2_VALUE_AS_MACRO_AUX(B)  LOG2_OF_##B##_AS_MACRO
#define GET_LOG2_VALUE_AS_MACRO(B)      GET_LOG2_VALUE_AS_MACRO_AUX(B) 

#define GET_LOG2_VALUE_AS_ENUM LOG2 

#ifndef __PCC__ 
#define LOG2_POS(VALUE)						\
  ((VALUE) <  0) ? -2 :						\
  ((VALUE) == 0) ? ((~0) << ((sizeof((VALUE)) << 3) - 1)) :	\
  ((VALUE) >>  0) == 1 ?  0 :					\
    ((VALUE) >>  1) == 1 ?  1 :					\
    ((VALUE) >>  2) == 1 ?  2 :					\
    ((VALUE) >>  3) == 1 ?  3 :					\
    ((VALUE) >>  4) == 1 ?  4 :					\
    ((VALUE) >>  5) == 1 ?  5 :					\
    ((VALUE) >>  6) == 1 ?  6 :					\
    ((VALUE) >>  7) == 1 ?  7 :					\
    ((VALUE) >>  8) == 1 ?  8 :					\
    ((VALUE) >>  9) == 1 ?  9 :					\
    ((VALUE) >> 10) == 1 ? 10 :					\
    ((VALUE) >> 10) == 1 ? 10 :					\
    ((VALUE) >> 11) == 1 ? 11 :					\
    ((VALUE) >> 12) == 1 ? 12 :					\
    ((VALUE) >> 13) == 1 ? 13 :					\
    ((VALUE) >> 14) == 1 ? 14 :					\
    ((VALUE) >> 15) == 1 ? 15 :					\
    ((VALUE) >> 16) == 1 ? 16 :					\
    ((VALUE) >> 17) == 1 ? 17 :					\
    ((VALUE) >> 18) == 1 ? 18 :					\
    ((VALUE) >> 19) == 1 ? 19 :					\
    ((VALUE) >> 20) == 1 ? 20 :					\
    ((VALUE) >> 21) == 1 ? 21 :					\
    ((VALUE) >> 22) == 1 ? 22 :					\
    ((VALUE) >> 23) == 1 ? 23 :					\
    ((VALUE) >> 24) == 1 ? 24 :					\
    ((VALUE) >> 25) == 1 ? 25 :					\
    ((VALUE) >> 26) == 1 ? 26 :					\
    ((VALUE) >> 27) == 1 ? 27 :					\
    ((VALUE) >> 28) == 1 ? 28 :					\
    ((VALUE) >> 29) == 1 ? 29 :					\
    ((VALUE) >> 30) == 1 ? 30 :					\
    ((VALUE) >> 31) == 1 ? 31 :					\
    ((VALUE) >> 32) == 1 ? 32 :					\
    ((VALUE) >> 33) == 1 ? 33 :					\
    ((VALUE) >> 34) == 1 ? 34 :					\
    ((VALUE) >> 35) == 1 ? 35 :					\
    ((VALUE) >> 36) == 1 ? 36 :					\
    ((VALUE) >> 37) == 1 ? 37 :					\
    ((VALUE) >> 38) == 1 ? 38 :					\
    ((VALUE) >> 39) == 1 ? 39 :					\
    ((VALUE) >> 40) == 1 ? 40 :					\
    ((VALUE) >> 41) == 1 ? 41 :					\
    ((VALUE) >> 42) == 1 ? 42 :					\
    ((VALUE) >> 43) == 1 ? 43 :					\
    ((VALUE) >> 44) == 1 ? 44 :					\
    ((VALUE) >> 45) == 1 ? 45 :					\
    ((VALUE) >> 46) == 1 ? 46 :					\
    ((VALUE) >> 47) == 1 ? 47 :					\
    ((VALUE) >> 48) == 1 ? 48 :					\
    ((VALUE) >> 49) == 1 ? 49 :					\
    ((VALUE) >> 50) == 1 ? 50 :					\
    ((VALUE) >> 51) == 1 ? 51 :					\
    ((VALUE) >> 52) == 1 ? 52 :					\
    ((VALUE) >> 53) == 1 ? 53 :					\
    ((VALUE) >> 54) == 1 ? 54 :					\
    ((VALUE) >> 55) == 1 ? 55 :					\
    ((VALUE) >> 56) == 1 ? 56 :					\
    ((VALUE) >> 57) == 1 ? 57 :					\
    ((VALUE) >> 58) == 1 ? 58 :					\
    ((VALUE) >> 59) == 1 ? 59 :					\
    ((VALUE) >> 60) == 1 ? 60 :					\
    ((VALUE) >> 61) == 1 ? 61 :					\
    ((VALUE) >> 62) == 1 ? 62 :					\
    ((VALUE) >> 63) == 1 ? 63 :					\
    64 
#else 
#define LOG2_POS(VALUE)	64 
#endif 
 
#define LOG2(VALUE) ((VALUE) < 0 ? LOG2_POS(-(VALUE)) : LOG2_POS(VALUE)) 



static int write_string(const int d, const char * cstr) { 
  if (NULL == cstr) { 
    static const char s[] = "NULL"; 
    write(d, s, sizeof(s) - 1); 
    return sizeof(s) - 1; 
  }; 
  
  const char * p = cstr; 
  for (;;) { if (*p == '\0') break; p++; }; 
  const int len = p - cstr; 
  write(d, cstr, len); 
  return len; 
}; 

static int write_string_ln(const int d, const char * cstr) { 
  if (NULL == cstr) { 
    static const char s[] = "NULL" "\n"; 
    write(d, s, sizeof(s) - 1); 
    return sizeof(s); 
  }; 
  
  const char * p = cstr; 
  for (;;) { if (*p == '\0') break; p++; }; 
  const int len = p - cstr; 
  write(d, cstr, len); 
  write(d, "\n", 1); 
  return len + 1; 
}; 

static int write_eol(const int d) { 
  write(d, "\n", 1); 
  return 1; 
}; 


static char * uint_string_in_the_buffer(const unsigned int n_given, const int buffer_size, char buffer[]) {
  if (1 >= buffer_size) return NULL; 
  if (0 == n_given) return strcpy(buffer, "0"); 
  
  int i = 0;
  unsigned int n = n_given;
  assert(n > 0);
  while (n > 0) {
    const int quotient = n / 10;
    const int remainder = n % 10;
    assert(i < buffer_size);
    buffer[i] = remainder + '0';
    i++;
    n = quotient;
  }
  assert(i < buffer_size);
  buffer[i] = '\0';
  const int nb_chars_computed = i;
  assert(nb_chars_computed+1 <= buffer_size);
  
  char temp[nb_chars_computed+1];
  strcpy(temp, buffer);
  for (int j = 0; j < nb_chars_computed; j++)
    buffer[j] = temp[nb_chars_computed-j-1];
  assert(buffer[nb_chars_computed] == '\0');
  
  return buffer;
};

extern char * uint_string(const unsigned int n);
extern char * uint_string_on_the_heap(const unsigned int n);
extern char * uint_string_on_the_stack(const unsigned int n);
extern char * uint_string_in_the_buffer(const unsigned int n, const int buffer_size, char * buffer);
#define uint_string_buffer_size(n)   ((sizeof((n)) << 3)+1)
#define uint_string_on_the_heap(n)   uint_string_in_the_buffer((n), uint_string_buffer_size((n)), malloc(uint_string_buffer_size((n))))
#define uint_string_on_the_stack(n)  uint_string_in_the_buffer((n), uint_string_buffer_size((n)), alloca(uint_string_buffer_size((n))))
#define uint_string         uint_string_on_the_heap
#define uint_string__stack  uint_string_on_the_stack




#endif /* DECIMAL_GLOBAL_H */
