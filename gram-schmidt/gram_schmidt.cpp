#include "vector_operations.h"
#include <vector>

vector<vector<double>> gram_schmidt_classic(int n,vector<vector<double>> vec){
    
    vector<vector<double>> orthonorm_vec(n, vector<double>(n, 0.0));
    
    double norm_0=norm_of_vector(n,vec[0]);
    orthonorm_vec[0]=(division_with_scalar(n,vec[0],norm_0));
    
    
    for(int k=1;k<n;k++){
        vector<double>& temp=vec[k];
        for(int i=0;i<k;i++){
            double p=scalar(n,vec[k],orthonorm_vec[i]);
            temp=dif_of_vectors(n,temp,multiplication_with_scalar(n,orthonorm_vec[i],p));
        }
        temp=division_with_scalar(n,temp,norm_of_vector(n,temp));
        orthonorm_vec[k]=temp;
    }
    
    return orthonorm_vec;
}

vector<vector<double>> gram_schmidt_modified(int n,vector<vector<double>> vec){
    
   vector<vector<double>> orthonorm_vec(n, vector<double>(n, 0.0));
   
    for(int k=0;k<n;k++){
        
        vector<double>& temp=vec[k];
        temp=division_with_scalar(n,temp,norm_of_vector(n,temp));
        orthonorm_vec[k]=temp;
        
        for(int j=k+1;j<n;j++){
            double p=scalar(n,vec[j],orthonorm_vec[k]);
            vec[j]=dif_of_vectors(n,vec[j],multiplication_with_scalar(n,orthonorm_vec[k],p));
        }
    }
    
    return orthonorm_vec;
    
}
