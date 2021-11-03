#include <iostream>
#include <cmath>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>    


using namespace std;

class methods{
    public:
        methods(){

        }
        //is the center point within the pink triangle??
        bool is_intriangle(double a, double b, double c, double side_length){
            double x_center = 0;
            double y_center = side_length * sqrt(3.0) / 4;

            double y1 = sqrt(3.0) * a / 2.0;   //from 30-60-90 triangle
            double y2 =  sqrt(3.0) * b / 2.0;
            double x1 = (side_length/2.0) - (a/2.0);
            double x2 = -(b/2.0);
            double x3 = c - (side_length / 2.0); //bottom line of equilateral triangle
            double y3 = 0;


            double sum_triangles = herons(x1,y1,x2 ,y2,x_center, y_center) + herons(x2,y2,x3,y3,x_center, y_center) + herons(x1,y1,x3,y3,x_center, y_center);
            if(abs(herons(x1,y1,x2,y2,x3,y3) - sum_triangles) < 1){
                return true;
            }
            return false;
        }

        
        //area of a triangle given 3 points
        double herons(double x1, double y1, double x2, double y2, double x3, double y3){
            double a = distance_between_two_points(x1,y1,x2,y2);
            double b = distance_between_two_points(x2,y2,x3,y3);
            double c = distance_between_two_points(x3,y3,x1,y1);
            double s = (a + b + c) / 2.0;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }

        //distance between two points
        double distance_between_two_points(double x1, double y1, double x2, double y2){
            double x = pow((x1 - x2),2.0) + pow((y1 - y2),2.0);
            return sqrt(x);
        }
};




int main(){
    int NUM_RUNS = 10000;
    double side_length = 100;
    int num_in= 0;
    int num_out = 0;

    methods methods;

  
    srand (time(NULL));
    for(int i = 0; i < NUM_RUNS; i++){
        double rand1 = (side_length * double(rand() % 1001))/1000; //random number between 0 and side_length
        double rand2 = (side_length * double(rand() % 1001))/1000; 
        double rand3 = (side_length * double(rand() % 1001))/1000; 

        if(methods.is_intriangle(rand1,rand2,rand3, side_length)){
            num_in++;
        }
        else{
            num_out++;
        }

        cout << "Is it in: " << methods.is_intriangle(rand1,rand2,rand3, side_length) << ":    SIDE LENGHTS: " << rand1 << " " << rand2 << " " << rand3 << endl;
        cout << "NUM IN " << num_in << " NUM OUT " << num_out  << endl;
    }
    return 0;
}



/*
!TESTING
            // cout << "X2 " << b << " x2 " << x3;
            // cout << "y2 " << b << " y2 " << y3;
            // cout << endl;



        // cout << methods.herons(10.2, 2.3, 3.1231, 3.12, 3.4, 6.6);
        // cout << methods.is_intriangle(45,45,45,100);
        // cout << methods.herons(0,0,1,0,0,1);



*/