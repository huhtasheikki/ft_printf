/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:00:34 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/10/07 09:23:04 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //REMOVE
#include "includes/ft_printf.h"
#include <limits.h>

#include <stdio.h>

/*
typedef union uni
{
	float f1;
	struct {
		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} parts;
}	float_cast;
*/

int		main(void)
{
	int				num;
	unsigned int	num2;
	char			*str;
	float			f;
	long double 	dip;
	double 			dip2;
	double			dip3;
//	float_cast		d1;

//	float_cast d1 = { .f1 = 0.15625 };
//	d1.f1 = -0.015625;
//	printf("floatti %f\n", d1.f1);
//	printf("sign = %x\n", d1.parts.sign);
//	printf("exponent = %x\n", d1.parts.exponent);
//	printf("mantisa = %x\n", d1.parts.mantissa);

	printf("O %.0p, %.p\n", 0, 0);
	ft_printf("F %.0p, %.p\n", 0, 0);

	printf("O %.5p\n", 0);
	ft_printf("F %.5p\n", 0);

//	printf("O %2.9p\n", 1234)
//	ft_printf("F %2.9p\n", 1234)

	ft_putendl("__________");

	printf("%#.f\n", 4.5);
	ft_printf("%#.f\n", 4.5);
//	while(1);

	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("\n");
	ft_printf("%\n");
	ft_printf("\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);



	printf("sizeof(double)=%lu sizeof(float)=%lu \n", sizeof(double), sizeof(float));


	dip = 5.32e-1;
	dip2 = 1.0000000000000002;
//	dip2 = 3.32e-4;
//	dip2 = 15.321450;

	f = 10;

	str = ft_strnew(8);
	ft_strncat(str, "Seppo Hovi on Pianisti", 8);

	num = 4000;
	num2 = 3000;

	ft_printf("Moikka %d\n", 10);

	printf("O %f \n", 12.434);
	ft_printf("F %f \n", 12.434);
	ft_printf("F %d %i %o %u %x %X \n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);


	printf("Original Moi X%7d num2=%d\n", num, num);
	ft_putendl("-------");
	ft_printf("F Moi X%8X num2=%+d\n", num, num);
	printf("O Moi X%8X num2=%+d\n", num, num);
	ft_putchar('\n');

/* INT_MIN */
	ft_putendl("INT_MIN\n=========");
	ft_printf("F %d %i %o %u %x %X \n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	printf("O %d %i %o %u %x %X \n", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	ft_putchar('\n');

/* INT_MAX */
	ft_putendl("INT_MAX\n=========");
	ft_printf("F %d %i %o %u %x %X \n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
	ft_printf("O %d %i %o %u %x %X \n", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
	ft_putchar('\n');

/* UINT_MAX */
	ft_putendl("UINT_MAX\n=========");
	ft_printf("F %d %i %o %u %x %X \n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	printf("O %d %i %o %u %x %X \n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	ft_putchar('\n');

	ft_printf("TEST F X%-+12dX \n", 4321);
	printf("TEST O X%-+12dX \n", 4321);

//	while(1);
	printf("\nMoi %22.7d\n", num);

	ft_printf("MAIN F %u %u \n", -1, UINT_MAX);
	printf("MAIN O %u %u \n", -1, UINT_MAX);

	ft_printf("MAIN F %020.10x %x \n", -1, UINT_MAX);
	printf("MAIN O %020.10x %x \n", -1, UINT_MAX);

	ft_printf("QMAIN F %010.8d %+10.8d \n", 4321, 4321);
	printf("QMAIN O %010.8d %+10.8d \n", 4321, 4321);

	ft_printf("%#08x\n", 42);
	printf("%#08x\n", 42);

	printf("O %ld\n", 2147483648);
	ft_printf("F %ld\n", 2147483648);

//	printf("O %llx \n", 9223372036854775808);
//	ft_printf("F %llx \n", 9223372036854775808);

	printf("O %-12f\n", 12.41341);
	ft_printf("F %-12f\n", 12.41341);

	printf("%5%\n");
	ft_printf("%5%\n");
	ft_printf("%%\n");

	printf("char: |%2c| |%c| \n", 'c', 'D');
	ft_printf("char: |%2c| |%c| \n", 'c', 'D');

	printf("str: |%s|\n", "Seppo Hovi on pianisti");
	ft_printf("str: |%s|\n", "Seppo Hovi on pianisti");

	printf("O str: |%-7.3s| \n", NULL);
	ft_printf("F str: |%-7.3s| \n", NULL);

	printf("O str: |%-7.3%| \n");
	ft_printf("F str: |%-7.3%| \n");

	ft_printf("|%s|\n", str);
	printf("|%s|\n", str);

	printf("sizeof long:%lu\n", sizeof(unsigned long long));

	printf("O ptr:|%p|\n", str);
	ft_printf("F ptr:|%p|\n", str);

	printf("O float: |%f|\n", f);
	printf("O #float: |%#f|\n", f);

	printf("STR STR O |%*s|\n", -32, str);
	ft_printf("STR STR F |%*s|\n", -32, str);

	ft_putendl("DING");
	printf("O |%#.o| |%.0o| |%.0o| \n", 0, 0, 3);
	ft_printf("F |%#.o| |%.0o| |%.0o| \n", 0, 0, 3);

	printf("O |%0*.3d|\n", 10, -41);
	ft_printf("F |%0*.3d|\n", 10, -41);

	printf("O |%0*.3d|\n", 10, -41);
	ft_printf("F |%0*.3d|\n", 10, -41);

	printf("O |%08.3i|\n", -8473);
	ft_printf("F |%08.3i|\n", -8473);
	ft_putendl("LOPPU");

	ft_putnbr(printf("%-5c\n", 0));
	ft_putendl(" RETURN VALUE PRINTF");
	ft_putnbr(ft_printf("%-5c\n", 0));
	ft_putendl(" RETURN VALUE FT_PRINTF");

	printf("O %08.3d \n", -8473);
	ft_printf("F %08.3d \n", -8473);

	printf("O ptr:|%.p|\n", 0);
	ft_printf("F ptr:|%.p|\n", 0);

	printf("%#o\n", 1);
	ft_printf("%#o\n", 1);

	printf("%#o\n", 0);
	ft_printf("%#o\n", 0);

	printf("#float: |%#.18f| \n", 10.0000000001);
	ft_printf("#float: |%#.18f| \n", 10.0000000001);

//	printf("#double: |%#.18Lf| \n", 1.0000000001);
//	ft_printf("#double: |%#.18Lf| \n", 1.0000000001);

	printf("%Lf can be written %Le\n", dip, dip);
	ft_printf("%Lf can be written %Le\n", dip, dip);
	printf("O %f can be written %e\n", dip2, dip2);
	ft_printf("F %f can be written %e\n", dip2, dip2);
//	ft_printf("Moi %+-ll 4.2d", num2);

	printf("sizeof(long double):%lu \n", sizeof(long double));
	printf("sizeof(double):%lu \n", sizeof(double));
	printf("sizeof(float):%lu \n", sizeof(float));
	printf("sizeof(char):%lu \n", sizeof(char));
	printf("sizeof(uint16_t):%lu \n", sizeof(uint16_t));
	printf("sizeof(uint64_t):%lu \n", sizeof(uint64_t));
	printf("sizeof(uint128_t):%lu \n", sizeof(uint64_t));
	printf("sizeof(long):%lu \n", sizeof(long));
	printf("sizeof(intmax_t):%lu \n", sizeof(intmax_t));
	printf("sizeof(unsigned short int):%lu \n", sizeof(unsigned short int));
	printf("sizeof(unsigned int):%lu \n", sizeof(unsigned int));
	printf("sizeof(unsigned long):%lu \n", sizeof(unsigned long));

	dip3 = -1.0000000000000002;

	printf("O dip3 1.0000000000000004 = |%.17f| |%e| \n", dip3, dip3);
	ft_printf("F dip3 1.0000000000000004 = |%.17f| |%e| \n", dip3, dip3);

	dip = -1.1;
//	dip = -1.11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111;
	ft_printf("dip %Le \n", dip);

	t_ldbits	james;
	char		*prefixi;
	prefixi = ft_strnew(3);
	dip3 = 4.9406564584124654E-324;
	dip = -4.9406564584124654E-324;
	james.ld = 1.0;

	char	merkki[4];

/* LONG DOUBLE = 0.0 */
	james.bits.m = 0;
	james.bits.integer = 0;
	james.bits.exp = 0;
	james.bits.sign = 0;
	ft_printf("F positive zero: %Lf\n", james.ld);
	printf("0 positive zero: %Lf\n", james.ld);

/* LONG DOUBLE = -0.0 */
	james.bits.m = 0;
	james.bits.integer = 0;
	james.bits.exp = 0;
	james.bits.sign = 1;
	ft_printf("F negative zero: %Lf\n", james.ld);
	printf("O negative zero: %Lf\n", james.ld);

/* LONG DOUBLE =  inf */
	james.ld = 1. / 0;
//	james.shifter.m = 0;
//	james.shifter.integer = 0;
//	james.shifter.exp = james.shifter.exp | 2047; //0x7FF;
//	james.shifter.sign = 1;
	ft_printf("F positive inf: %Lf %Lg\n", james.ld, james.ld);
	ft_printf("F james.bits.exp= %u sign=%u\n", james.bits.exp, james.bits.sign);

	printf("O positive inf: %Lf %Lg\n", james.ld, james.ld);
	printf("O james.bits.exp= %u\n", james.bits.exp);

/* LONG DOUBLE =  -inf */
	james.ld = 1. / 0;
//	james.shifter.m = 0;
//	james.shifter.integer = 0;
//	james.shifter.exp = james.shifter.exp | 2047; //0x7FF;
	james.bits.sign = 1;
	ft_printf("F positive inf: %Lf %Lg\n", james.ld, james.ld);
	printf("O positive inf: %Lf %Lg\n", james.ld, james.ld);

/* LONG DOUBLE = nan */
	james.ld = 1. / 0;
	james.bits.m = 3213;
	james.bits.integer = 1;
	james.bits.exp = 0x7FFF;
	james.bits.sign = 1;
	ft_printf("F NAN?: %Lf %Lg\n", james.ld, james.ld);
	printf("O NAN?: %Lf %Lg\n", james.ld, james.ld);

/* LONG DOUBLE = nan */
//	james.ld = 1. / 0;
	james.bits.m = 0x7FFFFFFFFFFF;
	james.bits.integer = 0;
	james.bits.exp = 0x7FFF;
	james.bits.sign = 0;
	ft_printf("F NAN?: %Lf %Lg\n", james.ld, james.ld);
	printf("O NAN?: %Lf %Lg\n", james.ld, james.ld);
	printf("O james.bits.exp= %x\n", james.bits.exp);

/*
	dip = -2.2E-320;
//	dip = -1.1E-320;

	ft_ftoa_bit(dip3, 6, prefixi);
	ft_lftoa_bit(dip / 100, 6, prefixi);
//	ft_ftoa_bit(dip, 6);
	printf("dip %e \n", dip3);
	printf("dip %Le \n", dip / 10000000);

	printf("SPECIEAL: %Lf\n", james.ld);
//	printf("+0=|%Lf| -0=|%Lf|\n", 0x00000000000000000000, 0x80000000000000000000);
*/

//	printf("0x7FFF : %u\n", 0x7FFF);

	dip = -4.9406564584124654E-323;
	printf("O EEEE e=|%Le| .0e=|%.0Le| \n", dip, dip);
	ft_printf("F EEEE e=|%Le| .0e=|%.0Le| \n", dip, dip);

	printf("O %f\n", -5.02999949);
	ft_printf("F %f\n", -5.02999949);

	dip = 1.2E0;
	printf("THIS THIS O %Le \n", dip);
	ft_printf("THIS THIS O %Le \n", dip);
//	ft_putendl("ft_lftoe dip");
//	ft_putendl(ft_lftoe(dip, 6, str));

	t_ldbits		frank;

	printf("O this %.0f float\n", 1.6);
	ft_putendl("==========");
	ft_printf("O this %.0f float\n", 1.6);

	frank.ld = 1.2E2;
	frank.bits.exp = 0x7FFE;
	printf("O exp=0 eli %Le \n", frank.ld);
	ft_printf("F exp=0 eli %Le \n", frank.ld);
//	printf("O exp:|%u| \n", frank.bits.exp >> 3);
//	ft_putendl("ft_lftoe frank.ld");
//	ft_putendl(ft_lftoe(frank.ld, 6, str));

	printf("%.03s|\n", "hi ");
	ft_printf("%.03s|\n", "hi ");

	printf("%jx\n", 4294967295);
	ft_printf("%jx\n", 4294967295);

	printf("O %f\n", (double)INT_MAX);
	ft_printf("F %f\n", (double)INT_MAX);

	printf("O %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f\n", 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5);
	ft_printf("F %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f %-5.0f\n", 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5);
	printf("O %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", 10.05, 10.15, 10.25, 10.35, 10.45, 10.55, 10.65, 10.75, 10.85, 10.95);
	printf("O %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n", 0.05, 0.151, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75, 0.85, 0.95);
	ft_printf("F %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n", 0.05, 0.151, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75, 0.85, 0.95);
	printf("O %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n", 10.05, 10.15, 10.25, 10.35, 10.45, 10.55, 10.65, 10.75, 10.85, 10.95);
	ft_printf("F %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f %-5.1f\n", 10.05, 10.15, 10.25, 10.35, 10.45, 10.55, 10.65, 10.75, 10.85, 10.95);

	printf("O %.0f %.1f %.2f %.3f \n", 0.5, 0.25, 0.125, 0.0625);
	ft_printf("F %.0f %.1f %.2f %.3f \n", 0.5, 0.25, 0.125, 0.0625);

	frank.ld = 0.125;
	printf("O 0.125 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	frank.ld = 0.25;
	printf("O 0.25 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	frank.ld = 0.26;
	printf("O 0.26 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	frank.ld = 2.5;
	printf("O 2.5 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	frank.ld = 3.5;
	printf("O 3.5 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	frank.ld = 4.5;
	printf("O 4.5 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	frank.ld = 14.5;
	printf("O 14.5 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	frank.ld = 1.8E37;
	printf("O 1.8e37 exp=%x mantissa=%llx \n", frank.bits.exp, frank.bits.m);
	printf("O ISO |%Lf|\n", frank.ld);
	ft_printf("O ISO |%Lf|\n", frank.ld);

	printf("%f\n", 573.924);
	ft_printf("%f\n", 573.924);

/*
	ft_printf("0.1 + 0.11 = |%.23f|\n", 0.1 + 0.11);
	printf("0.1 + 0.11 = |%.23f|\n", 0.1 + 0.11);
*/

/*
	ft_printf("F |%jx|\n", 4294967295);
	printf("O |%jx|\n", 4294967295);

	printf("O |%.o| |%#.o| |%#.0o| |%#o| \n", 0, 0, 0, 3);
	ft_printf("F |%.o| |%#.o| |%#.0o| |%#o| \n", 0, 0, 0, 3);

	printf("O |%.0f| \n", LONG_MAX - 0.1);
	ft_printf("O |%.0f| \n", LONG_MAX - 0.1);
*/

/*
	frank.ld = (long double)LONG_MAX;
	printf("O LONG_MAX exp=|%x| mantissa=|%llx| \n", frank.bits.exp, frank.bits.m);
	printf("O LONG_MAX=|%d| LONG_MAX/10 = |%d|  \n", (int)LONG_MAX, (int)(LONG_MAX / 10));
	printf("log10= |%d| \n", ft_log10((long double)LONG_MAX));
*/





//	frank.ld = 1;
	frank.ld = 0.1;
//	frank.bits.integer = 1;
	frank.bits.m = 0xfffffffffffffff;
//	frank.bits.exp = 0x2;
//	frank.bits.sign = 1;
	ft_putendl("123456789|123456789|123456789|123456789|123456789|123456789|12345");
	int i5 = 62;
	while(i5 >= 0)
	{
		if ((frank.bits.m >> i5) & 1)
			ft_putnbr(1);
		else
			ft_putnbr(0);
		i5--;
	}
	ft_putendl(" ");

	printf("int=|%d| exp=|%u| mantissa=|%llx|\n", frank.bits.integer, (frank.bits.exp >> 1), frank.bits.m);
	printf("O exp 3 m=0 : |%.51Lf|\n", frank.ld);
	ft_printf("F exp 3 m=0 : |%.51Lf|\n", frank.ld);
	printf("exp 3 m=0 : |%Le|\n", frank.ld);

	printf("O UINT_MAX=|%Lf|\n", (long double)ULONG_MAX * 2 * 2);
	ft_printf("O UINT_MAX=|%Lf|\n", (long double)ULONG_MAX * 2 * 2);
	ft_printf("F UINT_MAX=|%Lf|\n", (long double)ULONG_MAX);

	frank.ld = 1.7E30;
	printf("ISO-D = |%Lf|\n", frank.ld);
	ft_printf("ISO-D = |%Lf|\n", frank.ld);

	printf("-3.5 =|%.f|%.f|%.f|%.f|%.f|%.f|%.f|%.f|%.f|%.f||\n", -0.5, -1.5, -2.5, -3.5, -4.5, -5.5, -6.5, -7.5, -8.5, -9.5);
	ft_printf("-3.5 =|%.f|%.f|%.f|%.f|%.f|%.f|%.f|%.f|%.f|%.f||\n", -0.5, -1.5, -2.5, -3.5, -4.5, -5.5, -6.5, -7.5, -8.5, -9.5);

	frank.bits.m = 0;
	frank.bits.exp = 1;
	frank.bits.sign = 0;
	printf("SMALLEST F=\n|%.4934Lf|\n", frank.ld);
	ft_printf("SMALLEST F=\n|%.4934Lf|\n", frank.ld);

	printf("prosentti a =|%a|\n", 0.5623132515);

	frank.ld = 1434434434434434.543;
	printf("O a=|%La|\n", frank.ld);

	printf("Log2 50=|%llu|\n", ft_logbase2(1.1258999068427777777e+15));

	printf("O {%*3d}\n", 5, 0);
	ft_printf("F {%*3d}\n", 5, 0);

	printf("O |%05.*d|\n", -15, 42);
	ft_printf("F |%05.*d|\n", -15, 42);

	printf("O {%*c}\n", -15, 0);
	ft_printf("O {%*c}\n", -15, 0);

	ft_printf("F %b\n", NULL);

	printf("O %2.9p\n", 1234);
	ft_printf("F %2.9p\n", 1234);

	printf("O %#.o, %#.0o\n", 0, 0);
	ft_printf("F %#.o, %#.0o\n", 0, 0);

	printf("O %#.3o\n", 1);
	ft_printf("F %#.3o\n", 1);

	ft_putnbr(printf("O {%*+c}\n", -15, 0));
	ft_putchar('\n');
	ft_putnbr(ft_printf("F {%*+c}\n", -15, 0));
	ft_putchar('\n');

	char	nullstr[5];
	nullstr[0] = '\0';
	nullstr[1] = '\0';
	nullstr[2] = '\0';
	nullstr[3] = '\0';
	nullstr[4] = '\0';
	char	nullc;

	nullc = '\0';


	ft_putnbr(printf("%s", nullstr));
	ft_putchar('\n');
	ft_putnbr(printf("%c%c%c%c\n", nullc, nullc, nullc, nullc));
	ft_putchar('\n');
	ft_putnbr(ft_printf("%c%c%c%c\n", nullc, nullc, nullc, nullc));
	ft_putchar('\n');
	ft_putchar('\n');

	ft_putnbr(printf("O {%.*d}\n", 0, 42));
	ft_putchar('\n');
	ft_putnbr(ft_printf("F {%.*d}\n", 0, 42));
	ft_putchar('\n');

	printf("O {%#.5x}\n", 1);
	ft_printf("F {%#.5x}\n", 1);

	printf("O |%.*d|\n", 0, 42);
	ft_printf("O |%.*d|\n", 0, 42);

	james.ld = ft_pow(10, 40) * 123;
//	james.bits.exp = 43;
	printf("MIKSI O |%Lf|\n", james.ld);
	ft_printf("MIKSI F |%Lf|\n", james.ld);

	return (0);
}
