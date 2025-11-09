#ifndef EDGE2D_HPP_
#define EDGE2D_HPP_ 

#include "Point2D.hpp"


class Edge2D {


    public: 

    constexpr Edge2D ( const Point2D &, const Point2D &); 

    constexpr bool operator == (const Edge2D &) const; 

    constexpr bool operator < (const Edge2D &) const; 

    // Getter 
    [[nondiscard]] constexpr Point2D p1 () const; 

    [[nondiscrd]] constexpr Point2D p2 () const; 


    private: 
    
    Point2D mp1; 
    Point2D mp2; 



}; 




#endif