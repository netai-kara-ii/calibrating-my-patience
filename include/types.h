#ifndef TYPES_H
#define TYPES_H


#include <complex>
#include <cstdint>
#include <memory>


// From eigen.
#include <Eigen/Dense>

/*
   Linear algebra (vector, matrix) and component-
   wise (ndarray) operation template dtypes, based on
   eigen. Use fixed sizes *only* when known at compile 
   time and are small.
 

   Why we do not change the storage order of these
   dtypes (i.e., row-major, or column major)? This
   has to do with Eigen's default order, which is
   column-major, meaning matrix columns are stored 
   contiguosly in memory. It also means that most 
   of their testing, and performance optimizations
   are rather suited for it.
  
   Even when most of the time we are traversing in
   our code eigen objects row-by-row, we work mainly
   with vectors. We take advantage of the fact that
   we flatten matrix or tensor objects to column vectors 
   (not always but most generally in complex n-space),
   much like it would happen either way in memory. 
  
   We must remember that, although we can work with 
   matrices and tensors, these are just some abstraction
   over an otherwise contiguous block of memory
   that is addressed accordingly.
  
   This minimises the effects of corrupting cache 
   locality, as row or column vector elements are 
   always memory contiguous regardless of the storage
   order. 
  
   See [1], [2], for the full discussions.
*/



template <typename T, Eigen::Index m = Eigen::Dynamic, Eigen::Index n = Eigen::Dynamic>
using ndarray = Eigen::Array<T, n, m>;


template <typename T, Eigen::Index m = Eigen::Dynamic, Eigen::Index n = Eigen::Dynamic>
using ndarray_ptr = std::shared_ptr<ndarray<T, n, m>>;


template <typename T, Eigen::Index n = Eigen::Dynamic>
using vector = Eigen::Matrix<T, n, 1>;


template <typename T, Eigen::Index n = Eigen::Dynamic, Eigen::Index m = Eigen::Dynamic>
using matrix = Eigen::Matrix<T, n, m>;


enum linear_solver_type {
    dense_choleschy,
    dense_qr,
    dense_schur
};






#endif


/*
   references:
  
    [1]. Eigen. Tux Family Org. [The Matrix Class, Fixed vs. Dynamic Size] 
            https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
  
    [2]. Tux Family Org.[Storage Orders, Storage Orders in Eigen]
            https://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html 
*/
