#include "Point2D.hpp"
#include "Edge2D.hpp"
#include "Triangle.hpp"

#include<map>
#include <fstream>
#include<cstdlib>
#include<ctime>



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
int N = 5;
double perturb = 0; // maximum displacement

std::srand(std::time(0));
for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        double x = i / double(N-1) + perturb * ((std::rand() / double(RAND_MAX)) - 0.5);
        double y = j / double(N-1) + perturb * ((std::rand() / double(RAND_MAX)) - 0.5);
        points.emplace_back(x, y);
    }
}





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

double xc = minX + dx / 2; 
double yc = minY + dy / 2; 

// Chose the trinagle lenght to be the the max between dx,dy and multiply by 2
double L = std::max(dx,dy);  

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
        for (const auto & e : t.get_edges()) {
            // If an edgne is shared between two trinagle the count is increased. If an edge is not shared then the 
            // count will be one
            edge_count[e]++; 
        }
    }

    // Create the polygon with edges not shared between truangle (i.e count is one)

    for (const auto [e,c] : edge_count){
        if ( c ==1 ) { 
            polygon.emplace_back(e); 
        }
    }


    // remove the bad triangle from the list 
    for (const auto & t_bad : bad_tria_list) {
        auto t_it = std::find(tria_list.begin(), tria_list.end(), t_bad); 
        if (t_it != tria_list.end()){
            tria_list.erase(t_it); 
        }
    }

    // once I creted the polygong I need to create trinagles with one edge which is the polygon edge
    // and the other two triangle edge are those connecting the base to th epoint p

    // create the new set of triangles

    for (const auto & e : polygon) {
        tria_list.emplace_back(e.p1(), e.p2(), p);
    }

}


// this is for consistency, once the trinagulation is done I need to removw all trinagle with vertex 
// connected to the super triangle I cerated at the beginning
    tria_list.erase(
    std::remove_if(tria_list.begin(), tria_list.end(),
        [&](const Triangle & t){
            return t.has_vertex(V1) || t.has_vertex(V2) || t.has_vertex(V3);
        }),
    tria_list.end());


// Print the trinagle list on a file 
std::ofstream file("./triangles.txt");
for (const auto & t : tria_list){
    file << t.V1().xcord() << " " << t.V1().ycord() << " "
         << t.V2().xcord() << " " << t.V2().ycord() << " "
         << t.V3().xcord() << " " << t.V3().ycord() << "\n";
}
file.close();





}; 


