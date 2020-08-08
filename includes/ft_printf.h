/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:41:37 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/08 17:05:13 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

/* THESE SHOULD BE FOUND FROM .C FILES WHEN NEEDED*/
# include <stdarg.h>
# include "libft.h"

/*===================*/
/*   DEFINE MACROS   */
/*===================*/
/* FLAGS - macros*/
/* - if you add more flags, remember to change FLAGS_SIZE */
# define FLAGS "#0- +*$'"
# define FLAGS_SIZE 8
# define FLAGS_MASK 255 // 1111 1111
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
# define UP_L_INDEX 13

/* CONVERSION SPECIFIERS */
# define FORMAT_MASK 4095 // = 0000 1111 1111 1111 (cspdiouxXegb)
# define FORMAT_ID "diouxXfFeEgGaAcspnb%" // "cspdiouxXegb" "diouxXDOUeEfFgGaACcSspn%"
# define FORMAT_ID_SIZE 20
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
# define E_MASK // bonus feature
# define G_MASK // BONUS FEATURE
# define B_MASK // BONUS FEATURE
# define N_INDEX 17

# define PREFIX 2

/* VARIOUS ARGUMENTS LIST AND ALL THE RESTS */
typedef struct		s_all
{
	const char		*format;
	char			*format_ptr;
	va_list			args;
	t_list			*parsed_args; // THIS OR NOT
	t_list			*last_arg;
	size_t			*len;

	char			flags_str[FLAGS_SIZE + 1]; // CHANGE THE VALUE THE MIN NEEDED
	char			l_modifier_str[L_MOD_SIZE + 1]; // size?
	char			format_id_str[FORMAT_ID_SIZE + 1];
	void			(*convert_fun_ptr[FORMAT_ID_SIZE])(void*);
	void			(*flags_fun_ptr[FLAGS_SIZE])(void*);
	void			(*lmod_fun_ptr[L_MOD_SIZE])(void*);

	int				format_info;
	size_t			width;
	size_t			precision;
	int				flags;
//	char			format_id;
	int				format_id;

	intmax_t		arg_int;
//	int				arg_int;
	uintmax_t		arg_uint;
	long double		arg_double;
	size_t			arg_len;
	int				arg_base;
	size_t			combined_len; // DO WE NEED IT?

	char			prefix[PREFIX + 1];
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
int					get_variable(t_all *all);
int					ft_arg_convert(t_all *all);

void				convert_di(void *param);
void				convert_ouxx(void *param);

void				ft_parse(t_all *all);
void				get_variable_info(t_all *all); // change return value to int
void				ft_reset_format_info(t_all *all);

/* --- FLAGS --- */
void				ft_do_flags(t_all *all);

void				ft_flag_hash(void *param);
void				ft_flag_zero(void *param);
void				ft_flag_minus(void *param);
void				ft_flag_space(void *param);
void				ft_flag_plus(void *param);
/* ?????? MORE FLAGS */

/* --- L MODIFIERS --- */
void				ft_l_modifiers(t_all *all);

void				ft_h_mod(void *param);
void				ft_hh_mod(void *param);
void				ft_l_mod(void *param);
void				ft_ll_mod(void *param);
void				ft_upl_mod(void *param);
/* END OF L MODIFIERS */

int					ft_field_width(t_all *all);
int					get_format_id(t_all *all);
int					ft_variable_len(t_all *all);

void				combine_elements(t_all *all);
void				ft_full_str_to_list(t_all *all);
void				ft_precision(t_all *all);

#endif
