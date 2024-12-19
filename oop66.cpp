// Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.

#include<iostream>

using namespace std;

// For selection sort function
template <typename T>

void selection ( T arr[] , int n){

  for(int i = 0; i < n; i++){

    int min_index = i;
    
    for(int j = i ; j <n ; j++){

      if(arr[min_index] > arr[j] ){

        min_index = j;
      }

    }
      
    if(min_index!=i){

      T temp = arr[i] ;
      arr[i] = arr[min_index] ;
      arr[min_index] = temp ;
    }
  }
}

// For display function 
template <typename T>

void display(T arr[],int n){

  for(int k = 0; k < n; k++){

    cout << arr[k] << " ";
  }

  cout<<"\n";
}

int main(){

  int n;
  
  int intarr[] = {64,55,33,22,11,10,89,79,98,52,100};
  cout<<"\nOriginal int array\n";
  display(intarr , 11);
  selection( intarr , 11);
  cout<<"\nSorted  int array\n";
  display(intarr , 11);
  
  float floatarr[] = {64.22,55.12,33.92,22.11,11.22,10.99};
  cout<<"\nOriginal float array\n";
  display( floatarr , 6);
  selection( floatarr , 6);
  cout<<"\nSorted  float array\n";
  display(floatarr , 6);
  return 0;
}
