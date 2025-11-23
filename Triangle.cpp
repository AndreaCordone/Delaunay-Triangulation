#include "Triangle.hpp"


Triangle::Triangle (const Point2D & A, const Point2D & B, const Point2D & C)
:   mA(A), 
    mB(B), 
    mC(C),
    mEdges{Edge2D(mA,mB), Edge2D(mB,mC), Edge2D(mC,mA)}
{
    computeCircCenter(); 
}


void Triangle::computeCircCenter(){

    
    double ax = mA.xcord(), ay = mA.ycord(); 
    double bx = mB.xcord(), by = mB.ycord();
    double cx = mC.xcord(), cy = mC.ycord(); 
    
    
    
    // Compute a circumcircle from a triangle, google for detail on the formula. 
    double d = 2*(ax*(by-cy) + bx*(cy-ay) + cx*(ay-by));
    
    if (fabs(d) < 1e-12) { // degenerate
        mIsValid = false; 
        return;
    }

    double ux = ((ax*ax + ay*ay)*(by - cy) +
                (bx*bx + by*by)*(cy - ay) +
                (cx*cx + cy*cy)*(ay - by)) / d;
    
    double uy = ((ax*ax + ay*ay)*(cx - bx) +
                (bx*bx + by*by)*(ax - cx) +
                (cx*cx + cy*cy)*(bx - ax)) / d;
    
    mCircCenter = Point2D(ux, uy);
    // The radious is computed as distance between CircumCenter and one of the triangle vertices (either A,B,C) is the same
    mCircRadious = mCircCenter.distance_to(mA);


}


bool Triangle::containedInCircumcircle ( const Point2D & p) const {

    if (!mIsValid) return false; 
    double eps = 1e-12; 
    double dist2 = mCircCenter.distance_to_squared(p); 
    double rad2 = mCircRadious*mCircRadious; 
    return dist2 <= rad2 + eps; 

}


// Getter of trinagles edges 
const std::vector<Edge2D> & Triangle::get_edges () const {

    return mEdges; 


}

// check if a point is a vertex
bool Triangle::has_vertex(const Point2D & V) const {

    return mA == V || mB == V || mC == V; 

}


 // Getter for triangles vertices 
    const Point2D & Triangle::V1 () const {
        return mA; 
    }
    const Point2D & Triangle::V2 () const {
        return mB; 
    }
    const Point2D & Triangle::V3 () const {
        return mC; 
    }


    // compare operator 
    bool Triangle::operator==(const Triangle& other) const {
        return mA == other.mA && mB == other.mB && mC == other.mC;
    }