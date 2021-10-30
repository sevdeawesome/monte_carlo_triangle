#include <iostream>


using namespace std;

int main(){
    int NUM_RUNS = 10000;
    int side_length = 100;
    int num_in, num_out = 0;

    // double rand1 = (rand() % 101); //random number between 0 and 100


    for(int i = 0; i < NUM_RUNS; i++){
        double rand1 = side_length * (rand() % 1001); //random number between 0 and 1000 * side_length
        double rand2 = side_length * (rand() % 1001);
        double rand3 = side_length * (rand() % 1001);

        cout << rand1 << " " << rand2 << " " << rand3;
    }

// side_length = a

// int num_in, num_out

//     for( n runs ){
//         rand1 = a * rand()
//         rand2 = a * rand()
//         rand3 = a * rand()

//         if(center within triangle){
//           num_in++
//         }
//         else{
//           num_out++
//         }

//     }


// center_within_triangle(a1,a2,a3){
  
// }


    return 0;
}
