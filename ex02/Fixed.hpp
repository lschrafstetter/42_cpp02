/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:25:35 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/23 15:19:49 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const int i);
  Fixed(const float f);
  ~Fixed();
  Fixed(const Fixed& fixed);
  Fixed& operator=(const Fixed& fixed);

  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  Fixed operator+=(const Fixed& rhs);
	Fixed operator-=(const Fixed& rhs);
	Fixed operator*=(const Fixed& rhs);
	Fixed operator/=(const Fixed& rhs);

  int getRawBits(void) const;

  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
	static Fixed &min(Fixed& f1, Fixed& f2);
	static const Fixed &min(const Fixed& f1, const Fixed& f2);
	static Fixed &max(Fixed& f1, Fixed& f2);
	static const Fixed &max(const Fixed& f1, const Fixed& f2);

 private:
  int raw_value_;
  static const int fractional_bits_ = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

inline bool operator==(const Fixed& lhs, const Fixed& rhs);
inline bool operator!=(const Fixed& lhs, const Fixed& rhs);
inline bool operator<(const Fixed& lhs, const Fixed& rhs);
inline bool operator>(const Fixed& lhs, const Fixed& rhs);
inline bool operator<=(const Fixed& lhs, const Fixed& rhs);
inline bool operator>=(const Fixed& lhs, const Fixed& rhs);

inline Fixed operator+(Fixed lhs, const Fixed& rhs);
inline Fixed operator-(Fixed lhs, const Fixed& rhs);
inline Fixed operator*(Fixed lhs, const Fixed& rhs);
inline Fixed operator/(Fixed lhs, const Fixed& rhs);

#endif