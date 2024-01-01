#include "SAT.hpp"
#include "PCH.hpp" // IWYU pragma: export
#include <algorithm>
#include <cmath>
#include <vector>

namespace pl::math {

// Linear transform to find the orthogonal vector of the edge
vec2
calculateNormalisedProjectionAxis(const vec2& current_point,
                                  const vec2& next_point)
{
  const double axis_x = -(next_point.y - current_point.y);
  const double axis_y = next_point.x - current_point.x;
  const double magnitude = hypot(axis_x, axis_y);

  vec2 axis_normalised;
  axis_normalised.x = axis_x / magnitude;
  axis_normalised.y = axis_y / magnitude;

  return axis_normalised;
}

// Project the vertices of each polygon onto a axis
void
computeProjections(const std::vector<vec2>& bounds_a,
                   const std::vector<vec2>& bounds_b,
                   const vec2& axis_normalised,
                   std::vector<double>& projections_a,
                   std::vector<double>& projections_b)
{
  projections_a.clear();
  projections_b.clear();

  for (size_t i = 0; i < bounds_a.size(); i++) {
    const double projection_a = dot(axis_normalised, bounds_a[i]);
    const double projection_b = dot(axis_normalised, bounds_b[i]);
    projections_a.push_back(projection_a);
    projections_b.push_back(projection_b);
  }
}

// Check if the projections of two polygons overlap
bool
isOverlapping(const std::vector<double>& projections_a,
              const std::vector<double>& projections_b)
{
  const double max_projection_a =
    *std::max_element(projections_a.begin(), projections_a.end());
  const double min_projection_a =
    *std::min_element(projections_a.begin(), projections_a.end());
  const double max_projection_b =
    *std::max_element(projections_b.begin(), projections_b.end());
  const double min_projection_b =
    *std::min_element(projections_b.begin(), projections_b.end());

  // True if projection overlaps but does not necessarily mean the polygons are
  // intersecting yet
  return !(max_projection_a < min_projection_b or
           max_projection_b < min_projection_a);
}

// Check if two convex polygons intersect
bool
separatingAxisIntersect(const std::vector<vec2>& bounds_a,
                        const std::vector<vec2>& bounds_b)
{
  std::vector<double> projections_a;
  std::vector<double> projections_b;
  projections_a.reserve(bounds_a.size());
  projections_b.reserve(bounds_b.size());

  for (size_t i = 0; i < bounds_a.size(); i++) {
    const vec2 current_point = bounds_a[i];
    const vec2 next_point = bounds_a[(i + 1) % bounds_a.size()];
    const vec2 axis_normalised =
      calculateNormalisedProjectionAxis(current_point, next_point);
    computeProjections(
      bounds_a, bounds_b, axis_normalised, projections_a, projections_b);

    if (!isOverlapping(projections_a, projections_b))
      return false;
  }

  for (size_t i = 0; i < bounds_b.size(); i++) {
    const vec2 current_point = bounds_b[i];
    const vec2 next_point = bounds_b[(i + 1) % bounds_b.size()];
    const vec2 axis_normalised =
      calculateNormalisedProjectionAxis(current_point, next_point);
    computeProjections(
      bounds_a, bounds_b, axis_normalised, projections_a, projections_b);

    if (!isOverlapping(projections_a, projections_b))
      return false;
  }

  // Intersects if all projections overlap
  return true;
}

} // namespace pl::math