#ifndef EDGE2D_HPP_
#define EDGE2D_HPP_ 

#include "Point2D.hpp"


class Edge2D {


    public: 

     Edge2D ( const Point2D &, const Point2D &); 

     bool operator == (const Edge2D &) const; 

     bool operator < (const Edge2D &) const; 

    // Getter 
    [[nodiscard]]  Point2D p1 () const; 

    [[nodiscard]]  Point2D p2 () const; 


    private: 
    
    Point2D mp1; 
    Point2D mp2; 



}; 




#endif