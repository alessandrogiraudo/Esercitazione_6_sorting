#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();

    T tmp;

    for(unsigned int i = 0; i < n-1; i++)
    {
        for(unsigned int j = i+1; j < n; j++)
        {
            if(v[j] < v[i]) 
            {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
};

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    const unsigned int n = v.size();

   
   
    T tmp;

    //Enqueue 

    for(unsigned int i = 0; i < n; i++){
        unsigned int node = i;

        while(node > 0)
        {
            unsigned int root;
            // determinate children
            if(node % 2 == 1) {
                root = (node - 1) / 2; // left
            } 
            else {
                root = (node - 2) / 2; // right
            }
            // check if children is larger than parent
            if(v[node] > v[root]) {
                tmp = v[node];
                v[node] = v[root];
                v[root] = tmp;
                node = root;
            } else {
                break;
            }
        } 
    }

    // Dequeue
    bool swap = true;

    for(unsigned int i = n-1 ; i > 0; i--){
        // move the max to the end 
        tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        
        unsigned int node1 = 0;

        // cycle from the end to the start
        while(swap) 
        {
            unsigned int left = 2 * node1 + 1;
            unsigned int right = 2 * node1 + 2;  
            unsigned int largest = node1;

            // find the largest node from the two children and root
            if (left < i && v[left] > v[largest]) 
            {
                largest = left;
            }
            if (right < i && v[right] > v[largest]) 
            {
                largest = right;
            }
            if(largest == node1) 
            {
                break;
            }
            // check if in the root position there's a biggest number than the largest found
            if(v[node1] < v[largest]) 
            {
                tmp = v[node1];
                v[node1] = v[largest];
                v[largest] = tmp;
                node1 = largest;
            }
            else
            {
                swap = false;
            }
        }
    }



}
}


