#ifndef SAT_HPP_
#define SAT_HPP_

#include "global.h"
#include "PCH.hpp"

namespace pl::math {

struct vec2
{
  double x;
  double y;
};

// Returns the dot products of two vectors
FORCE_INLINE_
double
dot(const vec2& A, const vec2& B)
{
  return A.x * B.x + A.y * B.y;
}

// Linear transform to find the orthogonal vector of the edge
extern vec2
calculateNormalisedProjectionAxis(const vec2& current_point,
                                  const vec2& next_point);

// Project the vertices of each polygon onto a axis
extern void
computeProjections(const std::vector<vec2>& bounds_a,
                   const std::vector<vec2>& bounds_b,
                   const vec2& axis_normalised,
                   std::vector<double>& projections_a,
                   std::vector<double>& projections_b);

// Check if the projections of two polygons overlap
extern bool
isOverlapping(const std::vector<double>& projections_a,
              const std::vector<double>& projections_b);

// Check if two convex polygons intersect
extern bool
separatingAxisIntersect(const std::vector<vec2>& bounds_a,
                        const std::vector<vec2>& bounds_b);

} // namespace pl::math

#endif // SAT_HPP_