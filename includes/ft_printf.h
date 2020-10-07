/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:41:37 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/10/07 09:54:12 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

/* THESE SHOULD BE FOUND FROM .C FILES WHEN NEEDED*/
# include <stdarg.h>
# include "../srcs/libft/libft.h"

# include <limits.h>

# include <stdio.h> // DELETE DELETE!!!!

/*===================*/
/*   DEFINE MACROS   */
/*===================*/
/* FLAGS - macros*/
/* - if you add more flags, remember to change FLAGS_SIZE */
# define FLAGS "#0- +"
# define FLAGS_SIZE 5
# define FLAGS_MASK 31 // 1111 1111
# define HASH_INDEX 0
# define ZERO_INDEX 1
# define MINUS_INDEX 2
# define SPACE_INDEX 3
# define PLUS_INDEX 4
# define STAR_INDEX 5
# define DOLLAR_INDEX 6
# define APOSTROPHE_INDEX 7
# define CDINPSU_MASK 245768

/* PRECISION - macros  */
# define PRECISION_INDEX 8

/* LENGTH MODIFIERS - macros*/
# define L_MODIFIER "hhllL"
# define L_MOD_MASK 15872 // 0011 1110 0000 0000
# define L_MOD_INDEX 9
# define L_MOD_LAST 13
# define L_MOD_SIZE 5
# define H_INDEX 9
# define HH_INDEX 10
# define L_INDEX 11
# define LL_INDEX 12
# define UPL_INDEX 13

/* CONVERSION SPECIFIERS */
# define FORMAT_MASK 4095 // = 0000 1111 1111 1111 (cspdiouxXegb)
# define FORMAT_ID "diouxXeEfFgGaACcSspnb%" // "diouxXDOUeEfFgGaACcSspn%"
# define FORMAT_ID_SIZE 22
# define DIOUXX_MASK 63
# define OUXX_MASK 60
# define AAEEFFGG_MASK 16320
# define DI_MASK 3
# define D_INDEX 0
# define I_INDEX 1
# define O_INDEX 2
# define U_INDEX 3
# define X_INDEX 4
# define UPX_INDEX 5
# define E_INDEX 6 // NOT DONE
# define UPE_INDEX 7 // NOT DONE
# define F_INDEX 8
# define UPF_INDEX 9
# define G_INDEX 10 // NOT DONE
# define UPG_INDEX 11 // NOT DONE
# define A_INDEX 12 // NOT DONE
# define UPA_INDEX 13 // NOT DONE
# define UPC_INDEX 14 // NOT DONE
# define C_INDEX 15 // NOT DONE
# define UPS_INDEX 16 //NOT DONE
# define S_INDEX 17 // NOT DONE
# define P_INDEX 18 // NOT DONE
# define N_INDEX 19 // NOT DONE
# define B_INDEX 20 // NOT DONE
# define PERCENT_INDEX 21

# define PREFIX 2

/* VARIOUS ARGUMENTS LIST AND ALL THE RESTS */

/* TRY TO REPLACE WITH THIS INSIDE T_ALL STRUCT, is this correct?
*/

typedef struct			s_bitshift
{
	unsigned long long	m : 63;
	unsigned long long	integer : 1;
	unsigned short		exp : 15;
	unsigned short		sign : 1;
}						t_bitshift;

typedef union			u_ldbits
{
	long double			ld;
	t_bitshift			bits;
}						t_ldbits;

typedef union			u_backtold
{
	unsigned long long	m;
	long double			ld;
}						t_backtold;

// TARKISTA TAA TARKKAAN
/*
typedef union			f_bits
{
	double				arg_f;
	struct				s_argf_bit
	{
		intmax_t		mantissa : 52;
		intmax_t		exponent : 11;
		intmax_t		sign : 1;
	}					t_fbit;
}						u_fbit;
*/

typedef struct		s_all
{
	char			*format_ptr; //used
	va_list			args; //used
	t_list			*parsed_args; //used
	t_list			*last_arg; //used
	size_t			*len; //used

	char			flags_str[FLAGS_SIZE + 1]; //used
	char			l_modifier_str[L_MOD_SIZE + 1]; // size?
	char			format_id_str[FORMAT_ID_SIZE + 1];
	void			(*convert_fun_ptr[FORMAT_ID_SIZE])(void*);
	void			(*flags_fun_ptr[FLAGS_SIZE])(void*);
	void			(*lmod_fun_ptr[L_MOD_SIZE])(void*);

	int				format_info;
	size_t			width;
	size_t			precision;
	int				format_id;

	intmax_t		arg_int;
	uintmax_t		arg_uint;
//	u_fbit			double_union;
	long double		arg_double;
	char			*arg_str;
	void			*arg_ptr;
	size_t			arg_len;
	int				arg_base;
	size_t			combined_len; // DO WE NEED IT?

	char			prefix[PREFIX + 1];
	size_t			prefix_len;
	char			padding_char;
	size_t			padding_len;
	char			*padding_str;
	char			*convert_str;
	char			*full_str;
}					t_all;

/*=====================*/
/* FUNCTION PROTOTYPES */
/*=====================*/
int					ft_printf(const char *format, ...);
int					ft_initialize(t_all *all, const char *format, size_t *len);
int					ft_parse(t_all *all);
int					get_variable(t_all *all);
int					get_variable_info(t_all *all);
int					get_format_id(t_all *all);
int					ft_arg_convert(t_all *all);

void				convert_di(void *param);
void				convert_ouxx(void *param);
void				convert_double(void *param);
void				convert_percent(void *param);
void				convert_char(void *param);
void				convert_str(void *param);
void				convert_ptr(void *param);

void				ft_reset_format_info(t_all *all); //ok, check unused

/* --- FLAGS --- */
void				ft_do_flags(t_all *all); //OK

void				ft_flag_hash(void *param); //OK
void				ft_flag_zero(void *param); //OK
void				ft_flag_minus(void *param); //OK
void				ft_flag_space(void *param); //OK
void				ft_flag_plus(void *param); //OK
/* ?????? MORE FLAGS */

/* --- L MODIFIERS --- */
void				ft_l_modifiers(t_all *all);

/*
void				ft_h_mod(void *param);
void				ft_hh_mod(void *param);
void				ft_l_mod(void *param);
void				ft_ll_mod(void *param);
void				ft_upl_mod(void *param);
*/
/* END OF L MODIFIERS */

int					ft_field_width(t_all *all);
//int					get_format_id(t_all *all);
int					ft_variable_len(t_all *all);

void				combine_elements(t_all *all);
void				ft_full_str_to_list(t_all *all);
void				ft_precision(t_all *all);

void				get_percent(t_all *all);
void				get_char(t_all *all);
void				get_str(t_all *all);
void				get_ptr(t_all *all);

size_t				ft_precision_asterisk(t_all *all);
size_t				ft_width_asterisk(t_all *all);
int					ft_create_padding_str(t_all *all);

//char				*ft_etoa(t_all *all); // DELETE AND move toLIBFT
char				*ft_ftoa_bit(double f, size_t prec, char *sign); // DELETE AND move toLIBFT
char				*ft_lftoa_bit(long double f, size_t prec, char *sign); // DELETE
char				*ft_lftoe(long double f, size_t prec, char *sign);
int					get_first_decimal(long double f);
long double			get_decimal_remain(long double f);

void				future_feature(void *param);
#endif
