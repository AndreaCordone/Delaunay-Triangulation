#include "Edge2D.hpp"


constexpr Edge2D::Edge2D (const Point2D & A, const Point2D & B) : mp1 (A < B ? A:B), mp2 (A < B ? B:A) {};

constexpr bool Edge2D::operator == (const Edge2D & AB) const {

    return mp1 == AB.p1() && mp2 == AB.p2(); 

}; 


constexpr bool Edge2D::operator < (const Edge2D & AB) const {

    return std::make_tuple(mp1,mp2) < std::make_tuple(AB.p1(), AB.p2()); 

}; 


// Gettter 

[[nondiscard]] constexpr Point2D Edge2D::p1 () const 
{ 
    return mp1; 
}; 

[[nondiscard]] constexpr Point2D Edge2D::p2 () const 
{ 
    return mp2; 
}; 
