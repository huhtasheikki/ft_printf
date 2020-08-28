/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:16:55 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/26 17:02:52 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static long double		round_float(long double f, int prec)
{
	t_ldbits				ldu;
//	int						i;
//	uintmax_t				d_temp;
	long double				ld_temp;

	ld_temp = ft_pow(10, prec);

	ldu.ld = f - (uintmax_t)f;
//	i = 0;
//	d_temp = 1;
//	while (i++ < prec)
//		d_temp *= 10;
	if (ldu.bits.m == 0 && (uintmax_t)(f * ld_temp) % 2 == 0)
		return (f);
	else
		return (f + (0.5 / ld_temp));
}

static char				*dot_float_str(long double f, int prec)
{
	unsigned long long		num;
	char					*f_part;
	size_t					i;

/* KORJAA TAMA */
	i = 1;
	if (prec < 1 || !(f_part = ft_strnew(prec + 2)))
		return (NULL);
	f_part[0] = '.';
	while (prec-- > 0)
	{
/*
		temp = get_first_decimal(f);
		f = f - (unsigned long long)f;
		f *= 10;
		if (prec == 0)
		{
			if (get_first_decimal(f) > 5 || \
				(get_first_decimal(f) == 5 && temp % 2))
				temp++;
		}
		f_part[i++] = temp + '0';
*/

		f = f - (unsigned long long)f;
		f *= 10.0;
		num = (unsigned long long)f;
		if (prec == 0)
		{
//			if (get_first_decimal(f) > 5 || \
//				(get_first_decimal(f) == 5 && num % 2))
//			if ((f - num > 0.5) || ((f - num == 0.5) && (int)f % 2 == 1))
//				f_part[i] = (num + 1) + '0';
//			else
				f_part[i] = num + '0';
		}
		else
		{
//			f *= 10.0;
//			num = (unsigned long long)f;
//			f -= num;
			f_part[i] = (num % 10) + '0';
		}
		i++;

	}
	f_part[i] = '\0';
	return (f_part);
}

static int				powtwotopowten(int pow)
{
	long double			temp;
	int					tenpowers;
	int					i;

	i = 0;
	temp = 1;
	tenpowers = 0;
	while (pow-- > 0)
		temp *= 2;
	while (temp > 1 || temp < -1)
	{
		temp /= 10;
		tenpowers++;
	}
	return (tenpowers);
}

static char				*special_cases(t_ldbits ldu, char *sign)
{
	if (ldu.bits.sign & 1)
		*sign = '-';
//	if (!(ldu.bits.exp & 0x7FFF) && !ldu.bits.m)
//		return (ft_strdup("0.0"));
	if (ldu.bits.exp == 0x7FFF)
	{
		if (ldu.bits.m == 0)
			return (ft_strdup("inf"));
		else
		{
			*sign = '\0';
			return (ft_strdup("nan"));
		}
	}
	return (NULL);
}

char					*ft_lftoe(long double f, size_t prec, char *sign)
{
	t_ldbits				ldu;
	t_backtold				back;
	char					*mantissa;
	char					*exponent;
	char					*ret;
	size_t					len;

	len = 0;
	ldu.ld = f;
	if ((ret = special_cases(ldu, sign)))
		return (ret);
	if (ldu.bits.sign & 1)
		*sign = '-';
/*
	back.bits.m = ldu.bits.m;
	back.bits.integer = ldu.bits.integer;
	back.bits.exp = 1;
	back.bits.sign = 0;
*/
	back.m = ldu.bits.m;
	mantissa = ft_lftoa_bit(back.ld, prec, sign);
//	printf("exponent inside: |%u|\n", ldu.bits.exp);
	exponent = ft_itoa(powtwotopowten(ldu.bits.exp - 16383));
//	len = ft_strlen(mantissa) + ft_strlen(exponent); + 2;
	ret = ft_strnew(ft_strlen(mantissa) + ft_strlen(exponent) + 3);
	ft_strcat(ret, mantissa);
	free(mantissa);
	if (ldu.bits.exp >= 16382)
		ft_strcat(ret, "e+");
	else
		ft_strcat(ret, "e-");
	ft_strcat(ret, exponent);
	free(exponent);
	return (ret);
}

/*
static char				*before_decimal_str(long double f)
{
	size_t					num[1000];
	long double				divi;
	size_t					i;
	size_t					len;
	size_t					str_len;
	char					*num_str;
	char					*temp_str;

	i = 0;
	str_len = 10;
	len = ft_log10(f);
	while (len > 8)
	{
		len -= 8;
		divi = ft_pow(10, len);
		num[i] = (size_t)(f / divi);
		f -= (num[i++] * divi);
		str_len += ft_uintlen_base(num[i++], 10);
	}
	num[i] = (size_t)f;
	str_len += ft_uintlen_base(num[i], 10);
	num_str = ft_strnew(str_len);
	size_t				j = 0;

	while (j <= i)
	{
		temp_str = ft_uintmaxtoa_base(num[j++], 10);
		ft_putendl(temp_str);
		ft_strcat(num_str, temp_str);
		free(temp_str);
	}
	return (num_str);
*/
/*
	while (len > 8)
	{
		num[i++] = (int)(f * (1 / ft_pow(10, len - 8)));
		len -= 8;
		num[i] = 
	}
*/
/*
}
*/

char					*ft_lftoa_bit(long double f, size_t prec, char* sign)
{
	t_ldbits				ldu;
	char					*digits_str;
	char					*decimals_str;
	char					*res;

	ldu.ld = f;
	if ((res = special_cases(ldu, sign)))
		return (res);
	if (f < 0)
		f = -f;
	if (prec < 19)
		f = round_float(f, prec); //delete this
//	digits_str = before_decimal_str(f);
	if (f <= ULONG_MAX)
		digits_str = ft_uintmaxtoa_base((uintmax_t)f, 10);
	else
		digits_str = ft_bignumtoa(f);
//		digits_str = ft_strdup(">ULONG_MAX");
	if (!(decimals_str = dot_float_str(f, prec)))
		decimals_str = ft_strnew(0);
	res = ft_strjoin(digits_str, decimals_str);
	free(digits_str);
	free(decimals_str);
	return (res);
}
