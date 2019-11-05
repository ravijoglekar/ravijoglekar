//
//  Created by Ravi Joglekar on 05/11/19.
//  Copyright © 2019 Ravi Joglekar. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int a[10][10], m, n, flag=1, count=0;
    
    cout<<"Enter the matrix rows and columns:\n";
    cin>>m>>n;
    
    cout<<"\nEnter the elements:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    
    cout<<"\nEntered Matrix is:\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    //Logic to set all elements of the matrix to zero
    while(flag)
    {
        flag=0;
        for(int i=0;i<m;i++)
        {
            for(int j=(i%2);j<n;j++)
            {
                if(a[i][j]==0)
                {
                    //left
                    if(j!=0)
                    {
                        if(a[i][j-1]==1)
                        {
                            a[i][j]=9;
                            flag=1;
                        }
                    }
                            
                    //right
                    if(j!=n-1)
                    {
                        if(a[i][j+1]==1)
                        {
                            a[i][j]=9;
                            flag=1;
                        }
                    }
                            
                    //top
                    if(i!=0)
                    {
                        if(a[i-1][j]==1)
                        {
                            a[i][j]=9;
                            flag=1;
                        }
                    }
                            
                    //bottom
                    if(i!=m-1)
                    {
                        if(a[i+1][j]==1)
                        {
                            a[i][j]=9;
                            flag=1;
                        }
                    }
                }
                
                else if(a[i][j]==1)
                {
                    //left
                    if(j!=0)
                    {
                        if(a[i][j-1]==0)
                        {
                            a[i][j-1]=9;
                            flag=1;
                        }
                    }
                            
                    //right
                    if(j!=n-1)
                    {
                        if(a[i][j+1]==0)
                        {
                            a[i][j+1]=9;
                            flag=1;
                        }
                    }
                            
                    //top
                    if(i!=0)
                    {
                        if(a[i-1][j]==0)
                        {
                            a[i-1][j]=9;
                            flag=1;
                        }
                    }
                            
                    //bottom
                    if(i!=m-1)
                    {
                        if(a[i+1][j]==0)
                        {
                            a[i+1][j]=9;
                            flag=1;
                        }
                    }
                }
                ++j;
            }
        }
    
        //If flag is set unset the flag and set the elements 1
        if(flag)
        {
            count++;
            cout<<"\nEntered Matrix on day:"<<count<<endl;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]==9)
                    {
                        a[i][j]=1;
                    }
                    cout<<a[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
    }
    
    cout<<"\nNumber of days to set the matrix:"<<count<<endl;

    return 0;
}
