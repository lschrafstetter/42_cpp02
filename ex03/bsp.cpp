/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschrafs <lschrafs@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:38:48 by lschrafs          #+#    #+#             */
/*   Updated: 2022/09/27 10:05:36 by lschrafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed get_cross_product(Point const v1, Point const v2) {
  return (v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x());
}

// Returns the vector from a to b
Point vector(Point a, Point b) {
  Point vector = Point(b.get_x() - a.get_x(), b.get_y() - a.get_y());
  return vector;
}

// If crossproduct of vector ab and vector bc is positive, orientation is
// counterclockwise (1), else clockwise (-1)
int orientation(Point a, Point b, Point c) {
  Point const vector_a_b = vector(a, b);
  Point const vector_b_c = vector(b, c);
  Fixed cross_product = get_cross_product(vector_a_b, vector_b_c);

  if (cross_product == 0) return 0;
  return (cross_product > 0 ? 1 : -1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  int sum_of_orientations = orientation(a, b, point) +
                            orientation(b, c, point) + 
														orientation(c, a, point);
	return (sum_of_orientations == 3 || sum_of_orientations == -3 ? true : false);
}