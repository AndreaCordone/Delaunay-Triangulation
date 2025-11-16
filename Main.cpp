#include "Point2D.hpp"
#include "Edge2D.hpp"
#include "Triangle.hpp"

#include<map>




int main () {


// Definire il maxi triangle 
// Per ogni punto verificare se cade dentro il maxi triangle
// Se un punto p1 cade dentro metto il maxi triangle nella lista dei bad triangle
// Creo altri triangoli partendo dai veritici del maxi triangle collengandoli al punto p1
// Faccio una lista degli edge dei nuovi triangoli bad e escludo gli edge in comune 


// Define the first bigger triangle containing all the points
// As rule of thumbs if the points are contained in a squere of lenght L, then the triangle size should be 2*L

// Find Max and Min of set of points
// Assuming all the points are contained in a vector 
std::vector<Point2D> points; 

points.emplace_back(1.0, 2.0);
points.emplace_back(3.5,-0.2);
points.emplace_back(0.0, 0.0);
points.emplace_back(6.4, -8.1);
points.emplace_back(5.2,  7.7);
points.emplace_back(-2.0, 9.9);
points.emplace_back(7.8, -6.3);
points.emplace_back(9.1, 4.5);

// Setting the min and max value to the first point in the list 
double minX = points[0].xcord(); 
double minY = points[0].ycord(); 

double maxX = points[0].xcord(); 
double maxY = points[0].ycord(); 

// Looping trough the list to find the min and max
for (const auto & p : points) {

    if (p.xcord() < minX ) minX = p.xcord(); 
    if (p.ycord() < minY ) minY = p.ycord(); 

    if (p.xcord() > maxX) maxX = p.xcord(); 
    if (p.ycord() > maxY) maxY = p.ycord(); 

}

// Compute the center of the square that contain all the points

double dx = maxX-minX; 
double dy = maxY-minY; 

double xc = dx / 2; 
double yc = dy / 2; 

// Chose the trinagle lenght to be the the max between dx,dy and multiply by 2
double L = std::max(dx,dy); 

std::cout<<"The coordinates of teh max and min points"<<std::endl; 
std::cout<<"MaxX:"<<maxX <<";"<<"MinX:"<<minX<<std::endl; 
std::cout<<"MaxY:"<<maxY <<";"<<"MinY:"<<minY<<std::endl; 

// Create the super triangle to start the algorith. 

Point2D V1 (xc-L, yc-L); 
Point2D V2 (xc+L, yc-L); 
Point2D V3 (xc, yc+L); 

Triangle super_tria (V1,V2,V3); 

// Create a Triangle List the first element is the super tirnagle. 
std::vector<Triangle> tria_list; 
tria_list.emplace_back(super_tria); 




// Iterate trough each point in points

for (const auto & p : points) {

    // create a bad trinagle list 
    std::vector<Triangle> bad_tria_list; 

    // Iterate trough each triangle and check if the first point is within the circumcircle 

    for (const auto & tria : tria_list){

        if (tria.containedInCircumcircle(p)) {
            bad_tria_list.emplace_back(tria);

        }
    }

    // Create a polygon, whihc is a collection of edges
    std::vector<Edge2D> polygon; 
    
    //Ccreate a unordered map to count if an edge is shared 
    std::map<Edge2D,int> edge_count; 

    // Iterate trough the bad triangle list and create a polygon made from the tringle edge not shared 

    for (const auto & t : bad_tria_list){

        for (const auto & e: t.get_edges()) {

            // check if an edge is not shared between bad triangles and if yes then add it to poligon
            edge_count[e]++; 

        }
    }

    




}

}; 


