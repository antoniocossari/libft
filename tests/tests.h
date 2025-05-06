/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acossari <acossari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:56:25 by acossari          #+#    #+#             */
/*   Updated: 2025/05/06 12:56:30 by acossari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

/* Assertions for runtime checks (prints file:line if false, then aborts) */
# include <assert.h>

/* String functions used in comparisons: strcmp, strncmp, memcmp */
# include <string.h>

/* malloc/free, abort(), strdup (if needed) */
# include <stdlib.h>

/* POSIX I/O for pipe(), read(), write() */
# include <unistd.h>

/* INT_MAX, INT_MIN for boundary tests */
# include <limits.h>

/* Include your library’s public API */
# include "libft.h"

#endif /* TESTS_H */
