/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:25:31 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/27 13:28:17 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw_value_(0) {}

Fixed::Fixed(const int i) {
	this->raw_value_ = i << fractional_bits_;
}

Fixed::Fixed(const float f) {
  this->raw_value_ = roundf(f * (1 << this->fractional_bits_));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &fixed) {
	this->raw_value_ = fixed.getRawBits();
}

void Fixed::swap(Fixed &first, Fixed &second) {
  std::swap(first.raw_value_, second.raw_value_);
}

Fixed &Fixed::operator=(Fixed fixed) {
  // Copy and swap idiom
  Fixed::swap(*this, fixed);
  return *this;
}

Fixed &Fixed::operator++() {
  this->raw_value_++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return tmp;
}

Fixed &Fixed::operator--() {
  this->raw_value_--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return tmp;
}

Fixed Fixed::operator+=(const Fixed &rhs) {
  this->raw_value_ = this->raw_value_ + rhs.raw_value_;
	return *this;
}

Fixed Fixed::operator-=(const Fixed &rhs) {
  this->raw_value_ = this->raw_value_ - rhs.raw_value_;
	return *this;
}

Fixed Fixed::operator*=(const Fixed &rhs) {
  this->raw_value_ =
      ((long long)this->raw_value_ * (long long)rhs.getRawBits()) >>
      this->fractional_bits_;
  // This is for precision. For speed, use: (where the last 0 can be larger if
  // you subtract from the fractional bitshift before multiplying)
  // this->raw_value_ =
  //    ((this->raw_value_ >> this->fractional_bits_) * rhs.getRawBits() >>
  //     this->fractional_bits_) >>
  //    0;
	return *this;
}

Fixed Fixed::operator/=(const Fixed &rhs) {
  this->raw_value_ =
      ((long long)this->raw_value_ << this->fractional_bits_) /
      rhs.getRawBits();
  // Same for division as for multiplication:
  // this->raw_value_ =
  //    (this->raw_value_ << this->fractional_bits_) / (rhs.getRawBits() <<
  //     this->fractional_bits_);
	return *this;
}

int Fixed::getRawBits(void) const {
	return this->raw_value_;
}

void Fixed::setRawBits(int const raw) {
	this->raw_value_ = raw;
}

float Fixed::toFloat(void) const {
  return (float)this->raw_value_ / (1 << this->fractional_bits_);
}

int Fixed::toInt(void) const {
  return this->raw_value_ >> this->fractional_bits_;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	return f1 < f2 ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	return f1 > f2 ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}

bool operator==(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() == rhs.getRawBits() ? true : false;
}

bool operator!=(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() != rhs.getRawBits() ? true : false;
}

bool operator<(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() < rhs.getRawBits() ? true : false;
}

bool operator>(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() > rhs.getRawBits() ? true : false;
}

bool operator<=(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() <= rhs.getRawBits() ? true : false;
}

bool operator>=(const Fixed &lhs, const Fixed &rhs) {
  return lhs.getRawBits() >= rhs.getRawBits() ? true : false;
}

Fixed operator+(Fixed lhs, const Fixed &rhs) {
  lhs += rhs;
  return lhs;
}

Fixed operator-(Fixed lhs, const Fixed &rhs) {
  lhs -= rhs;
  return lhs;
}

Fixed operator*(Fixed lhs, const Fixed &rhs) {
  lhs *= rhs;
  return lhs;
}

Fixed operator/(Fixed lhs, const Fixed &rhs) {
  lhs /= rhs;
  return lhs;
}