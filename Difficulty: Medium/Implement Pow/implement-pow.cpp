//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double solve( double x , int y ){
      if( y <= 0 ){
          return (double)1;
      }
      
      if( y == 1 ){
          return (double)x ;
      }
      
      
      if( y%2 == 1 ){
          
          double temp = solve(x,y/2);
          
          return temp*temp*x ;
          
      }
      else if( y%2 == 0 ){
           double temp = solve(x,y/2);
          
          return temp*temp ;
          
      }
    }
    double power(double b, int e) {
        // code here
           if( b == 0 ){
            return (double)0 ;
        }
         
        bool negFlag = b < 0 ? true : false ;
        b = abs(b) ;
        
    
        double ans = solve( b , abs(e) ) ;
        
        if( negFlag and abs(e) % 2 == 1){
            
            ans = ans*(-1) ;
        }
        
        if( e < 0 ){
            return ((double)1/(double)ans) ;
        }
        
        return (double)ans ;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends