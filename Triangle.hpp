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

    // Getter for triangles vertices 
    const Point2D & V1 () const; 
    const Point2D & V2 () const; 
    const Point2D & V3 () const; 
    

    // Check if a point is one of the vertices
    bool has_vertex (const Point2D &) const; 

    // compare operator 
    bool operator==(const Triangle& other) const; 

    // Validity check used in case of degenerate triangles d = 0 in circumcircle formula (determinate = 0)
    bool isValid () const {return mIsValid; }


    private:
        
    Point2D mA; 
    Point2D mB; 
    Point2D mC; 

    std::vector<Edge2D> mEdges; 

    // Circumcenter center and radius
    Point2D mCircCenter{}; 
    double mCircRadious{}; 


    // insert a bool member to invalidate trangle
    bool mIsValid = true; 

}; 




#endif