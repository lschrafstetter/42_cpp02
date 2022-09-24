/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:25:35 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/23 13:15:44 by lschrafs         ###   ########.fr       */
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
  Fixed &operator=(const Fixed &fixed);

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