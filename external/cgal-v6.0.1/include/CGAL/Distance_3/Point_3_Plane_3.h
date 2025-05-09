// Copyright (c) 1998-2021
// Utrecht University (The Netherlands),
// ETH Zurich (Switzerland),
// INRIA Sophia-Antipolis (France),
// Max-Planck-Institute Saarbruecken (Germany),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org)
//
// $URL: https://github.com/CGAL/cgal/blob/v6.0.1/Distance_3/include/CGAL/Distance_3/Point_3_Plane_3.h $
// $Id: include/CGAL/Distance_3/Point_3_Plane_3.h 50cfbde3b84 $
// SPDX-License-Identifier: LGPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Geert-Jan Giezeman, Andreas Fabri

#ifndef CGAL_DISTANCE_3_POINT_3_PLANE_3_H
#define CGAL_DISTANCE_3_POINT_3_PLANE_3_H

#include <CGAL/Distance_3/internal/squared_distance_utils_3.h>

#include <CGAL/Point_3.h>
#include <CGAL/Plane_3.h>

namespace CGAL {
namespace internal {

template <class K>
inline typename K::FT
squared_distance(const typename K::Point_3& pt,
                 const typename K::Plane_3& plane,
                 const K& k)
{
  typedef typename K::Vector_3 Vector_3;

  typename K::Construct_vector_3 vector = k.construct_vector_3_object();

  Vector_3 diff = vector(plane.point(), pt);
  return squared_distance_to_plane(plane.orthogonal_vector(), diff, k);
}

template <class K>
inline typename K::FT
squared_distance(const typename K::Plane_3& plane,
                 const typename K::Point_3& pt,
                 const K& k)
{
  return squared_distance(pt, plane, k);
}

} // namespace internal

template <class K>
inline
typename K::FT
squared_distance(const Point_3<K>& pt,
                 const Plane_3<K>& plane)
{
  return K().compute_squared_distance_3_object()(pt, plane);
}

template <class K>
inline
typename K::FT
squared_distance(const Plane_3<K>& plane,
                 const Point_3<K>& pt)
{
  return K().compute_squared_distance_3_object()(plane, pt);
}

} // namespace CGAL

#endif // CGAL_DISTANCE_3_POINT_3_PLANE_3_H
