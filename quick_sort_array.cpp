#include <cstdlib>  //Includes abs()
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_ARRAY_LEN 100 

//A class for integer coordinate pairs in the (x,y) space
class CoordinatePairs
{
public:
	CoordinatePairs();
	//Default Constructor
	//Initializes (x1,y1) = (0,0) and (x2,y2) = (0,0)
	
	CoordinatePairs(int in_x1, int in_y1, int in_x2, int in_y2);
	//Constructor initializing all member values to input parameter values in 
	//the order x1, y1, x2, y2.
	
	void set_pair1(int in_x1, int in_y1);
	//Pre-condition:  Properly initialized CoordinatePair object.
	//Post-condition: The values of (x1, y1) will be changed to the input parameter
	//                values of this function.
	
	void set_pair2(int in_x2, int in_y2);
	//Pre-condition:  Properly initialized CoordinatePair object.
	//Post-condition: The values of (x2, y2) will be changed to the input parameter
	//                values of this function.
	
	void get_pair1(int &out_x1, int &out_y1);
	//Pre-condition:  Properly initialized CoordinatePair object.
	//Post-condition: Call by Reference.
	//                Let's the user read the values of (x1, y1) out into (out_x1, out_y1).

	void get_pair2(int &out_x2, int &out_y2);
	//Pre-condition:  Properly initialized CoordinatePair object.
	//Post-condition: Call by Reference.
	//                Let's the user read the values of (x2, y2) out into (out_x2, out_y2).
	
	int calculate_manhattan_distance();  
	//Pre-condition:  Properly initialized CoordinatePair object.
	//Post-condition: Returns the Manhattan distance between a pair of (x,y) coordinates,
	//                equal to |x1-x2| + |y1-y2|. Google for more information.

/*

    WRITE ANY PUBLIC MEMBER FUNCTIONS YOU WANT TO USE HERE.
    
    For example, you might want to use these (but you don't have to):
    friend ostream &operator<<(ostream &, CoordinatePairs &);
	friend istream &operator>>(istream &, CoordinatePairs &);
    
    Overloading the I/O stream operators is an implementation choice and 
    not a necessity.
*/

private:

/*

    WRITE ANY PRIVATE HELPER MEMBER FUNCTIONS YOU WANT TO USE HERE.

*/

	int x1;  //Coordinate pair 1: x value
	int y1;  //Coordinate pair 1: y value
	int x2;  //Coordinate pair 2: x value
	int y2;  //Coordinate pair 2: y value

};

//////////////////CoordinatePairs Class Implementation ///////////////////////////

//Default Constructor
//Initializes (x1,y1) = (0,0) and (x2,y2) = (0,0)
CoordinatePairs::CoordinatePairs()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}


//Constructor initializing all member values to input parameter values in 
//the order x1, y1, x2, y2.
CoordinatePairs::CoordinatePairs(int in_x1, int in_y1, int in_x2, int in_y2)
{
	x1 = in_x1;
	y1 = in_y1;
	x2 = in_x2;
	y2 = in_y2;
}

//Pre-condition:  Properly initialized CoordinatePair object.
//Post-condition: The values of (x1, y1) will be changed to the input parameter
//                values of this function.
void CoordinatePairs::set_pair1(int in_x1, int in_y1)
{
	x1 = in_x1;
	y1 = in_y1;
	return;
}

//Pre-condition:  Properly initialized CoordinatePair object.
//Post-condition: The values of (x2, y2) will be changed to the input parameter
//                values of this function.
void CoordinatePairs::set_pair2(int in_x2, int in_y2)
{
	x2 = in_x2;
	y2 = in_y2;
	return;
}


//Pre-condition:  Properly initialized CoordinatePair object.
//Post-condition: Call by Reference.
//                Let's the user read the values of (x1, y1) out into (out_x1, out_y1).
void CoordinatePairs::get_pair1(int &out_x1, int &out_y1)
{
	out_x1 = x1;
	out_y1 = y1;
	return;
}


//Pre-condition:  Properly initialized CoordinatePair object.
//Post-condition: Call by Reference.
//                Let's the user read the values of (x2, y2) out into (out_x2, out_y2).
void CoordinatePairs::get_pair2(int &out_x2, int &out_y2)
{
	out_x2 = x2;
	out_y2 = y2;
	return;
}


//Pre-condition:  Properly initialized CoordinatePair object.
//Post-condition: Returns the Manhattan distance between a pair of (x,y) coordinates,
//                equal to |x1-x2| + |y1-y2|. Google for more information.
int CoordinatePairs::calculate_manhattan_distance()  
{
	return abs(x1-x2)+ abs(y1-y2); //abs() from cstdlib.
}


int partition (CoordinatePairs arr[], int low, int hi)
{
	int pivot = arr[hi].calculate_manhattan_distance();
	int i = low;

	for (int j = low; j<hi; j++)
	{
		if (arr[j].calculate_manhattan_distance() <= pivot)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[hi]);
	return i;
}

void swap (int& i, int& j)
{
	int temp;
	temp = i;
	i = j;
	i = temp;

	return;

}	

void quick_sort(CoordinatePairs arr[], int low, int high) 
{ 
	int pivot;
	
	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot-1);
		quick_sort(arr, pivot+1, high);
	}
	
	return;
}
	

int main() 
{ 
	int num_pairs;
		
	CoordinatePairs array[MAX_ARRAY_LEN];

	ifstream in_stream;
	in_stream.open("input.txt");
	int num1, num2, num3, num4;
	num_pairs = 0;
	while(!in_stream.eof())
	{
		in_stream >> num1 >> num2 >> num3 >> num4;
		array[num_pairs].set_pair1(num1, num2);
		array[num_pairs].set_pair2(num3, num4);
		num_pairs++;
	}
	int x1, y1, x2, y2;
	for(int i = 0; i < num_pairs; i++)
	{
		array[i].get_pair1(x1,y1);
		array[i].get_pair2(x2,y2);
	}

	in_stream.close();

	quick_sort(array, 0, num_pairs-1); 
	
	for (int i=0; i<num_pairs; i++)
	{
		array[i].get_pair1(x1,y1);
		array[i].get_pair2(x2,y2);
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << " manhattan_distance " << array[i].calculate_manhattan_distance() << endl;
	}

	return 0;
}
