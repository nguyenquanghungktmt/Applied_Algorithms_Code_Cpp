#include <iostream> 
#include <algorithm>
using namespace std; 
/*
void combSort() 
{ 
    // Initialize gap 
    int gap = n; 
  
    // Initialize swapped as true to make sure that 
    // loop runs 
    bool swapped = true; 
  
    // Keep running while gap is more than 1 and last 
    // iteration caused a swap 
    while (gap != 1 || swapped == true) 
    { 
        // Find next gap 
        gap = (gap * 10) / 13; 
        if (gap < 1) gap = 1;
  
        swapped = false; 
        for (i = 0; i < n - gap; i++) 
        { 
            if (a[i] > a[i + gap]) 
            { 
                swap(a[i], a[i + gap]); 
                swapped = true; 
            } 
        } 
    } 
} 
*/

int main() 
{ 
    int n, i;
    cin >> n;
    float a[n];
    for (i = 0; i < n; i++) cin >> a[i];
  
    //combSort(); 
    sort(a, a + n);
    for (i = 0; i < n; i++) cout << a[i] << ' ';
} 