#ifndef TRINAGLE_HPP_
#define TRIANGLE_HPP_


#include "Point2D.hpp"
#include "Edge2D.hpp"


class Triangle {


    public:

    // Constructor
    Triangle (const Point2D &, const Point2D &, const Point2D &); 

    // compute the circle which contain the triangle (triangle vertices A,B,V are on the circumference)
    void computeCircCenter (); 


    // Check if a point is within the CircumCircle
    bool containedInCircumcircle (const Point2D & ) const; 


    // Getter for triangles Edges
    const std::vector<Edge2D> & get_edges() const; 

    private:
        
    Point2D mA; 
    Point2D mB; 
    Point2D mC; 

    std::vector<Edge2D> mEdges; 

    // Circumcenter center and radius
    Point2D mCircCenter{}; 
    double mCircRadious{}; 



}; 




#endif