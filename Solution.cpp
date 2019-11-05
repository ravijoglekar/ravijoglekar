//
//  Created by Ravi Joglekar on 04/11/19.
//  Copyright © 2019 Ravi Joglekar. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    //Data declarations
    int a[10][10], m, n, count =0, flag=0;
    
    cout<<"Enter the matrix row  and column"<<endl;
    cin>>m>>n;
    cout<<"\nEnter the matrix\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }
        
    //Logic for finding the adjucent buildings which are considered as 1 unit
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                flag=1;
                if(i>0 && a[i-1][j]==1)
                {
                    flag=0;
                }
            }
            if(a[i][j]==0 || (j == (n-1)))
            {
                if(flag)
                {
                    flag=0;
                    count++;
                }
            }
        }
    }
    
    
    //Print the number of clusters found
    
    cout<<"\nThe number of clusters are: "<<count<<endl;
    return 0;
}
