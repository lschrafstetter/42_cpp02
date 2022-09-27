/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:25:35 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/27 10:16:49 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
 public:
  Fixed();
  Fixed(const int i);
  Fixed(const float f);
  ~Fixed();
  Fixed(const Fixed &fixed);
  Fixed &operator=(Fixed fixed);
	void swap(Fixed &first, Fixed &second); //normally "friend" swap, but not allowed due to 42 norm

  int getRawBits(void) const;

  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  int raw_value_;
  static const int fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif