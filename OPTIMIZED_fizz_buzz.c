
#ifndef size_t
# define size_t __SIZE_TYPE__
#endif

typedef size_t __attribute__((__aligned__(1),__may_alias__))	t_a_size_t;

extern void		*valloc(size_t);
extern void		free(void*);
extern size_t	write(int, void*, size_t);

#if defined(__GNUC__) && defined(__clang__)
__attribute__((__unused__,__const__,__aligned__(64),__hot__))
#elif defined(__GNUC__) && !defined(__clang__)
__attribute__((__indirect_return__,__unused__,__const__,__aligned__(64),__hot__,__optimize__("Ofast")))
#endif
static size_t	str_int(register const size_t val)
{
	if (val < 10UL)
		return (0x30UL
			| val);
	else if (val < 100UL)
		return (0x3030UL
			| (val % 10UL)	<< (1UL * 8UL)
			| (val / 10UL) % 10UL);
	else if (val < 1000UL)
		return (0x303030UL
			| (val				% 10UL)	<< (2UL * 8UL)
			| ((val	/ 10UL)		% 10UL)	<< (1UL * 8UL)
			| (val	/ 100UL)	% 10UL);
	else if (val < 10000UL)
		return (0x30303030UL
			| (val			% 10)	<< (3UL * 8UL)
			| ((val	/ 10)	% 10)	<< (2UL * 8UL)
			| ((val	/ 100)	% 10)	<< (1UL * 8UL)
			| (val	/ 1000)	% 10);
	else if (val < 100000UL)
		return (0x3030303030UL
			| (val				% 10UL)	<< (4UL * 8UL)
			| ((val	/ 10UL)		% 10UL)	<< (3UL * 8UL)
			| ((val	/ 100UL)	% 10UL)	<< (2UL * 8UL)
			| ((val	/ 1000UL)	% 10UL)	<< (1UL * 8UL)
			| (val	/ 10000UL)	% 10UL);
	else if (val < 1000000UL)
		return (0x303030303030UL
			| (val				% 10UL)	<< (5UL * 8UL)
			| ((val	/ 10UL)		% 10UL)	<< (4UL * 8UL)
			| ((val	/ 100UL)	% 10UL)	<< (3UL * 8UL)
			| ((val / 1000UL)	% 10UL)	<< (2UL * 8UL)
			| ((val / 10000UL)	% 10UL)	<< (1UL * 8UL)
			| (val	/ 100000UL)	% 10UL);
	else if (val < 10000000UL)
		return (0x30303030303030UL
			| (val					% 10UL)	<< (6UL * 8UL)
			| ((val	/ 10UL)			% 10UL)	<< (5UL * 8UL)
			| ((val	/ 100UL)		% 10UL)	<< (4UL * 8UL)
			| ((val / 1000UL)		% 10UL)	<< (3UL * 8UL)
			| ((val / 10000UL)		% 10UL)	<< (2UL * 8UL)
			| ((val	/ 100000UL)		% 10UL)	<< (1UL * 8UL)
			| (val	/ 1000000UL)	% 10UL);
	else if (val < 100000000UL)
		return (0x3030303030303030UL
			| (val					% 10UL)	<< (7UL * 8UL)
			| ((val	/ 10UL)			% 10UL)	<< (6UL * 8UL)
			| ((val	/ 100UL)		% 10UL)	<< (5UL * 8UL)
			| ((val / 1000UL)		% 10UL)	<< (4UL * 8UL)
			| ((val / 10000UL)		% 10UL)	<< (3UL * 8UL)
			| ((val	/ 100000UL)		% 10UL)	<< (2UL * 8UL)
			| ((val	/ 1000000UL)	% 10UL)	<< (1UL * 8UL)
			| (val	/ 10000000UL)	% 10UL);
	else
		return (0);
}

#if defined(__GNUC__) && defined(__clang__)
__attribute__((__alloc_size__(1),__unused__,__aligned__(64),__hot__))
#elif defined(__GNUC__) && !defined(__clang__)
__attribute__((__alloc_size__(1),__unused__,__aligned__(64),__optimize__("O0")))
#endif
static void		*__string_table(register const size_t limit)
{
	register const volatile size_t	fizz		= (*((const t_a_size_t*)"fizz\0\0\0\0"));
	register const volatile size_t	buzz		= (*((const t_a_size_t*)"buzz\0\0\0\0"));
	register const volatile size_t	fizzbuzz	= (*((const t_a_size_t*)"fizzbuzz"));
	register const volatile size_t	newline		= (*((const t_a_size_t*)"\n\0\0\0\0\0\0\0"));
	register size_t					i;
    register size_t					i_mod3;
    register size_t					i_mod5;
    register size_t					i_mod15;
	register size_t					index;
	register size_t *__restrict__	table;

	if (!(table = (__typeof__(table))valloc(limit * sizeof(*table) * 2)))
		return ((void*)0);
	i = 1;
    i_mod15 = 15UL;
    i_mod5 = 5UL;
    i_mod3 = 3UL;
	index = 0;
	__builtin_prefetch(table, 1, 1);
	while (i != limit)
	{
		if (i == i_mod15)
		{
			*((size_t*)table + index) = fizzbuzz;
			i_mod15 += 15UL;
			i_mod5 += 5UL;
			i_mod3 += 3UL;
		}
		else if	(i == i_mod5)
		{
			*((size_t*)table + index) = buzz;
			i_mod5 += 5UL;
		}
		else if (i == i_mod3)
		{
			*((size_t*)table + index) = fizz;
			i_mod3 += 3UL;
		}
		else
			*((size_t*)table + index) = str_int(i);
		index++;
		*((size_t*)table + index) = newline;
		index++;
		i++;
	}
	return (table);
}

#if defined(__GNUC__) && defined(__clang__)
__attribute__((__aligned__(64),__cold__))
#elif defined(__GNUC__) && !defined(__clang__)
__attribute__((__aligned__(64),__cold__,__optimize__("Ofast")))
#endif
int		main(void)
{
	register const volatile size_t	limit = 100000000UL;
	register void					*fizz_buzz_buff;

	if (!(fizz_buzz_buff = __string_table(limit)))
		return (-1);
	else
	{
		write(1, fizz_buzz_buff, limit * 8 * 2);
		free(fizz_buzz_buff);
	}
}
