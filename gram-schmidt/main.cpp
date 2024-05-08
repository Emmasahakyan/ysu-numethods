#include <iostream>
#include <vector>
#include "vector_operations.h"
#include "gram_schmidt.h"

int main()
{
    int n=0;
    cout<<"Enter the dimension of R:"<<endl;
    cin>>n;
    
    cout<<"Enter the vectors:"<<endl;
    
    vector<vector<double>> vec;
    
    for(int i=0;i<n;i++){
        vector<double> v_i;
        for(int j=0;j<n;j++){
            double v_ij;
            cin>>v_ij;
            v_i.push_back(v_ij);
        }    
        vec.push_back(v_i);
    }
    cout<<endl;
  
    string method;
    cout << "Which Gram-Schmidt method do you want to orthogonalize vectors with: classic or modified." << endl;
    cin>>method;
    cout << endl;
    
    if(method[0]=='c' || method[0]=='C'){
        vec=gram_schmidt_classic(n,vec);
    }
    else{
        vec=gram_schmidt_modified(n,vec);
    }
  
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
     cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout <<scalar(n,vec[i],vec[j])<< " ";
        }
        cout << endl;
    }
    
    
    return 0;
}