// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2015 Qingnan Zhou <qnzhou@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
//
#ifndef IGL_COPYLEFT_CGAL_ORDER_FACETS_AROUND_EDGE_H
#define IGL_COPYLEFT_CGAL_ORDER_FACETS_AROUND_EDGE_H
#include "../../igl_inline.h"
#include <Eigen/Core>
#include <vector>

namespace igl 
{
  namespace copyleft
  {
    namespace cgal 
    {
      /// Given a directed edge, sort its adjacent faces.  Assuming the
      /// directed edge is (s, d).  Sort the adjacent faces clockwise around the
      /// axis (d - s), i.e. left-hand rule.  An adjacent face is consistently
      /// oriented if it contains (d, s) as a directed edge.
      ///
      /// For overlapping faces, break the tie using signed face index, smaller
      /// signed index comes before the larger signed index.  Signed index is
      /// computed as (consistent? 1:-1) * (face_index + 1).
      ///
      /// @param[in] V  #V by 3 list of vertices.
      /// @param[in] F  #F by 3 list of faces
      /// @param[in] s  Index of source vertex.
      /// @param[in] d  Index of destination vertex.
      /// @param[in] adj_faces  List of adjacent face signed indices.
      /// @param[out] order  List of face indices that orders adjacent faces around edge
      ///     (s, d) clockwise.
      template<
        typename DerivedV,
        typename DerivedF,
        typename DerivedI >
      IGL_INLINE
      void order_facets_around_edge(
          const Eigen::MatrixBase<DerivedV>& V,
          const Eigen::MatrixBase<DerivedF>& F,
          size_t s, 
          size_t d, 
          const std::vector<int>& adj_faces,
          Eigen::PlainObjectBase<DerivedI>& order,
          bool debug=false);
      /// \overload
      /// \brief This function is a wrapper around the one above.  Since the ordering
      /// is circular, the pivot point is used to define a starting point.  So
      /// order[0] is the index into adj_face that is immediately after the
      /// pivot face (s, d, pivot point) in clockwise order.
      ///
      /// @param[in] pivot_point  A point that forms pivot with edge (s,d)
      template<
        typename DerivedV,
        typename DerivedF,
        typename Derivedpivot_point,
        typename DerivedI>
      IGL_INLINE
      void order_facets_around_edge(
        const Eigen::MatrixBase<DerivedV>& V,
        const Eigen::MatrixBase<DerivedF>& F,
        size_t s, 
        size_t d, 
        const std::vector<int>& adj_faces,
        const Eigen::MatrixBase<Derivedpivot_point>& pivot_point,
        Eigen::PlainObjectBase<DerivedI>& order);
    }
  }
}

#ifndef IGL_STATIC_LIBRARY
#include "order_facets_around_edge.cpp"
#endif
#endif
