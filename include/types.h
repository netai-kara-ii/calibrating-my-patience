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
   eigen. Use fixed sizes *only* when they are known 
   at compile time and are small. 

   Since we cannot partially specialise templated 
   aliases and we want to retain flexibility, we 
   use default template parameters.

   The downside is that behaviour cannot be
   specialised: the internal structure cannot be
   selectively modified to suit each type, and 
   cannot change based on specific conditions.  
   In principle it only works as a fallback, 
   but this is enough for our purposes.
 
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
  
   Full discussions may be found in [1], [2].

*/



template <typename T, Eigen::Index m = Eigen::Dynamic, Eigen::Index n = Eigen::Dynamic>
using ndarray = Eigen::Array<T, n, m>;


template <typename T, Eigen::Index m = Eigen::Dynamic, Eigen::Index n = Eigen::Dynamic>
using ndarray_ptr = std::shared_ptr<ndarray<T, n, m>>;


template <typename T, Eigen::Index n = Eigen::Dynamic>
using vector = Eigen::Matrix<T, n, 1>;


template <typename T, Eigen::Index n = Eigen::Dynamic, Eigen::Index m = Eigen::Dynamic>
using matrix = Eigen::Matrix<T, n, m>;


/*
  Solver types for linear systems of the form 
  Ax = b where 

        A is an m x n matrix, with 
        columns [a_1, ..., a_n]; and,

        x = [x_1, ..., x_n]  is an n-dimensional
        vector; 
  
  and thus,
                           
                        | x_1 |
    Ax = [a_1, ... a_n] | ... | = x_1 a_1 + ... + x_n a_n.
                        | x_n |
  
  At this stage, we dare not include sparse 
  solvers.

 */

enum linear_solver_type {
    dense_choleschy,
    dense_qr,
    dense_schur
};


enum gradient_type {
    numerical,
    analytic
};

enum population_initialization_type {
    latin_hypercube
};


#endif


/*
   references:
  
    [1]. Eigen. Tux Family Org. [The Matrix Class, Fixed vs. Dynamic Size] 
            https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
  
    [2]. Eigen. Tux Family Org.[Storage Orders, Storage Orders in Eigen]
            https://eigen.tuxfamily.org/dox/group__TopicStorageOrders.html 
*/
