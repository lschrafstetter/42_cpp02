/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:38:37 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/27 09:44:47 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
 public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Point(const Point &point);
	~Point();
	Point &operator=(const Point &point);

	Fixed get_x() const;
	Fixed get_y() const;
	
 private:
	const Fixed x;
	const Fixed y;
};

#endif