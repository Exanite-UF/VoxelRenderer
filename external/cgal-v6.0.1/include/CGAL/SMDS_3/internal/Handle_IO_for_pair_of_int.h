// Copyright (c) 2016 GeometryFactory
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org).
//
// $URL: https://github.com/CGAL/cgal/blob/v6.0.1/SMDS_3/include/CGAL/SMDS_3/internal/Handle_IO_for_pair_of_int.h $
// $Id: include/CGAL/SMDS_3/internal/Handle_IO_for_pair_of_int.h 50cfbde3b84 $
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-Commercial
//
//
// Author(s)     : Laurent Rineau

#ifndef CGAL_INTERNAL_MESH_3_INTERNAL_HANDLE_IO_FOR_PAIR_OF_INT_H
#define CGAL_INTERNAL_MESH_3_INTERNAL_HANDLE_IO_FOR_PAIR_OF_INT_H

#include <CGAL/license/SMDS_3.h>

#include <CGAL/disable_warnings.h>

#include <utility>
#include <CGAL/SMDS_3/io_signature.h>
#include <ostream>
#include <istream>
#include <variant>

namespace CGAL {
template <>
struct Get_io_signature<std::pair<int, int> > {
  std::string operator()() const
  {
    return std::string("std::pair<i,i>");
  }
}; // end Get_io_signature<std::pair<int, int> >

template <>
class Output_rep<std::pair<int, int> > : public IO_rep_is_specialized {
  typedef std::pair<int, int> T;
  const T& t;
public:
  //! initialize with a const reference to \a t.
  Output_rep( const T& tt) : t(tt) {}
  //! perform the output, calls \c operator\<\< by default.
  std::ostream& operator()( std::ostream& out) const {
    if(IO::is_ascii(out)) {
      out << t.first << " " << t.second;
    } else {
      CGAL::write(out, t.first);
      CGAL::write(out, t.second);
    }
    return out;
  }
};

template <>
class Output_rep<std::variant<int,
                                std::pair<int, int> > >
  : public IO_rep_is_specialized
{
  typedef std::variant<int, std::pair<int, int> > Variant;
  const Variant& v;
public:
  Output_rep(const Variant& v) : v(v) {}
  std::ostream& operator()( std::ostream& out) const {
    if(v.index() == 1) {
      out << IO::oformat(std::get<std::pair<int, int> >(v));
    } else {
      out << std::get<int>(v);
    }
    return out;
  }
};

template <>
class Input_rep<std::pair<int, int> > : public IO_rep_is_specialized {
  typedef std::pair<int, int> T;
  T& t;
public:
  //! initialize with a const reference to \a t.
  Input_rep( T& tt) : t(tt) {}
  //! perform the output, calls \c operator\<\< by default.
  std::istream& operator()( std::istream& in) const {
    if(IO::is_ascii(in)) {
      in >> t.first >> t.second;
    } else {
      CGAL::read(in, t.first);
      CGAL::read(in, t.second);
    }
    return in;
  }
};
} // end namespace CGAL

#include <CGAL/enable_warnings.h>

#endif // CGAL_INTERNAL_MESH_3_INTERNAL_HANDLE_IO_FOR_PAIR_OF_INT_H
