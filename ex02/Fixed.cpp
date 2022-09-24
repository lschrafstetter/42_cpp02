/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:25:31 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/23 15:17:55 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) {
	this->raw_value_ = i << fractional_bits_;
}

Fixed::Fixed(const float f) {
  this->raw_value_ = roundf(f * (1 << this->fractional_bits_));
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  this->raw_value_ = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  // Copy and swap idiom
  int new_raw_value = fixed.getRawBits();
  raw_value_ = new_raw_value;
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

Fixed Fixed::operator+=(const Fixed &rhs) {
	
}

Fixed Fixed::operator-=(const Fixed &rhs) {
	
}

Fixed Fixed::operator*=(const Fixed &rhs) {
	
}

Fixed Fixed::operator/=(const Fixed &rhs) {
	
}

inline Fixed operator+(Fixed lhs, const Fixed &rhs) {
	lhs += rhs;
	return lhs;
}

inline Fixed operator-(Fixed lhs, const Fixed &rhs) {
	
}

inline Fixed operator*(Fixed lhs, const Fixed &rhs) {
	
}

inline Fixed operator/(Fixed lhs, const Fixed &rhs) {
	
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->raw_value_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->raw_value_ = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->raw_value_ / (1 << this->fractional_bits_);
}

int Fixed::toInt(void) const {
  return this->raw_value_ >> this->fractional_bits_;
}