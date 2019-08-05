
// int     main(void)
// {
//     __SIZE_TYPE__ i;

//     for(i=1; i<=100000000UL; ++i)
//     {
//         if (i % 3 == 0)
//             __builtin_printf("Fizz");
//         if (i % 5 == 0)
//             __builtin_printf("Buzz");
//         if ((i % 3 != 0) && (i % 5 != 0))
//             __builtin_printf("%zu", i);
//         __builtin_printf("\n");
//     }
// }

// int main(void)
// {
//     long i, f = 2, b = 4; 
 
//     for ( i = 1 ; i <= 100000000L ; ++i, --f, --b )
//     {
//         if ( f && b ) { __builtin_printf("%zu", i);       }
//         if ( !f )     { __builtin_printf("Fizz"); f = 3;  }
//         if ( !b )     { __builtin_printf("Buzz"); b = 5;  }
//         __builtin_printf("\n");
//     }
// }

// int     main(void)
// {
//     for(register unsigned long i = 1; i<=100000000UL; ++i)
//     {
//         const _Bool fizz = (i % 3) == 0;
//         const _Bool buzz = (i % 5) == 0;

//         if (fizz)           __builtin_printf("Fizz");
//         if (buzz)           __builtin_printf("Buzz");
//         if (!fizz && !buzz) __builtin_printf("%zu", i);
//         __builtin_printf("\n");
//     }
// }

// int main(void)
// {
//     for (unsigned long i = 1; i <= 100000000UL ; ++i) {
//         if (i % 3 == 0) __builtin_printf("fizz");
//         if (i % 5 == 0) __builtin_printf("buzz");
//         if (i * i * i * i % 15 == 1) __builtin_printf("%ld", i);
//         __builtin_printf("\n");
//     }
// }

// #include <stdio.h>
// #include <string.h>
// 
// char *fizzbuzz(unsigned long int x)
// {
//     static char b[0115];
// 
//     if (b[42] != 98)
//     {
//         b[21]  = 102; b[22]  = 105; b[23]  = 122; b[24]  = 122;
//         b['A'] = 122; b['B'] = 122; b['C'] = 98;  b['D'] = 117;
//         b['E'] = 122; b['F'] = 122; b[','] = 122; b['*'] = 98;
//         b['?'] = 102; b['@'] = 105; b['+'] = 117; b['-'] = 122;
//     }
//     return (sprintf(b, "%zu", x), b + ((x % 5) ? 0 : 0x15) + ((x % 3) ? 0 : '*'));
// }
// 
// int main(void)
// {
//     for (unsigned long int i = 0; i < 100000000UL; i++)
//     {
//         printf("%s\n", fizzbuzz(i));
//     }
// }

static const char   *const restrict	__fizz_buzz = "FizzBuzz\n";
static const char   *const restrict	__fizz = "Fizz\n";
static const char   *const restrict	__buzz = "Buzz\n";
static const char   *const restrict	__number = "%zu\n";

const char *const restrict fmt_str[16] = {
	__fizz_buzz,	__number,	__number,	__fizz, 
	__number,		__buzz,		__fizz,		__number,
	__number,		__fizz,		__buzz,		__number,
	__fizz,			__number,	__number	};

int   main(void)
{
	__builtin_prefetch((const void*)fmt_str, 0, 0);
	for(register unsigned long i = 1;i <= 100000000UL; i++) __builtin_printf(fmt_str[i % 15UL], i);
}
