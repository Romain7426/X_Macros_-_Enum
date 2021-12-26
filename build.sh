#!/bin/sh

rm -Rf build 2>&1

mkdir -p build 2>&1











cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG -O0  -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -fstack-check  -fverbose-asm -ffreestanding -feliminate-unused-debug-types  -Wall -W -Wextra  -Werror -Wfatal-errors  -Werror-implicit-function-declaration -Wparentheses -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type -Wstrict-prototypes -Wpacked -Wcast-qual -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas  -gfull -W -Wextra -Wnewline-eof -Wno-unsequenced         -fno-exceptions -fno-omit-frame-pointer  -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -Wno-cast-align -Wno-system-headers  -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral    -c src/decimal.c -o build/decimal.o  2>&1
ar -r -c build/x_macros_-_enum.a build/decimal.o 2>&1
ranlib build/x_macros_-_enum.a 2>&1
cc -o build/x_macros_-_enum.exe build/x_macros_-_enum.a     2>&1

rm -f run
ln -s build/x_macros_-_enum.exe run
chmod +x run

