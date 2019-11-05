//
//  Created by Ravi Joglekar on 05/11/19.
//  Copyright © 2019 Ravi Joglekar. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a[10][10], m, n, flag=1, count=0;
    
    cout<<"Enter the number of rows and columns\n";
    cin>>m>>n;
    
    cout<<"\nEnter the elements:\n";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>a[i][j];

    cout<<"\nDisplay the entered matrix:\n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    //Program Logic to find set all the elements
    //Bruteforce algorithm
    while(flag)
    {
        //To check if there was an assignment
        flag=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                //First row
                if(i==0)
                {
                    //First Column
                    if(j==0)
                    {
                        if(a[i][j]==1)
                        {
                            if(a[i][j+1]==0)
                            {
                                a[i][j+1]=9;
                                flag=1;
                            }
                            if(a[i+1][j]==0)
                            {
                                a[i+1][j]=9;
                                flag=1;
                            }
                        }
                    }
                    
                    //Last column
                    else if(j==(n-1))
                    {
                        if(a[i][j]==1)
                        {
                            if(a[i][j-1]==0)
                            {
                                a[i][j-1]=9;
                                flag=1;
                            }
                            if(a[i+1][j]==0)
                            {
                                a[i+1][j]=9;
                                flag=1;
                            }
                        }
                    }
                    
                    //All other columns
                    else
                    {
                        if(a[i][j]==1)
                        {
                            if(a[i][j-1]==0)
                            {
                                a[i][j-1]=9;
                                flag=1;
                            }
                            if(a[i+1][j]==0)
                            {
                                a[i+1][j]=9;
                                flag=1;
                            }
                            if(a[i][j+1]==0)
                            {
                                a[i][j+1]=9;
                                flag=1;
                            }
                        }
                    }
                }
                
                //Last row
                else if(i==(n-1))
                {
                    //First Column
                    if(j==0)
                    {
                        if(a[i][j]==1)
                        {
                            if(a[i][j+1]==0)
                            {
                                a[i][j+1]=9;
                                flag=1;
                            }
                            if(a[i-1][j]==0)
                            {
                                a[i+1][j]=9;
                                flag=1;
                            }
                        }
                    }
                    
                    //Last column
                    else if(j==(n-1))
                    {
                        if(a[i][j]==1)
                        {
                            if(a[i][j-1]==0)
                            {
                                a[i][j-1]=9;
                                flag=1;
                            }
                            if(a[i-1][j]==0)
                            {
                                a[i-1][j]=9;
                                flag=1;
                            }
                        }
                    }
                    
                    //All other columns
                    else
                    {
                        if(a[i][j]==1)
                        {
                            if(a[i][j-1]==0)
                            {
                                a[i][j-1]=9;
                                flag=1;
                            }
                            if(a[i-1][j]==0)
                            {
                                a[i-1][j]=9;
                                flag=1;
                            }
                            if(a[i][j+1]==0)
                            {
                                a[i][j+1]=9;
                                flag=1;
                            }
                        }
                    }
                }
                
                //All other elements
                else
                {
                    if(a[i][j]==1)
                    {
                        if(a[i][j-1]==0)
                        {
                            a[i][j-1]=9;
                            flag=1;
                        }
                        if(a[i-1][j]==0)
                        {
                            a[i-1][j]=9;
                            flag=1;
                        }
                        if(a[i][j+1]==0)
                        {
                            a[i][j+1]=9;
                            flag=1;
                        }
                        if(a[i+1][j]==0)
                        {
                            a[i+1][j]=9;
                            flag=1;
                        }
                    }
                }
            }
        }
        if(flag)
        {
            count++;
            
            //assign the garbage value to 1 and display everyday progress
            cout<<"\nMatrix for Day:"<<count<<endl;
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

    
    cout<<"\nMatrix with all the elements set:\n";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    cout<<"\nThe number of days needed to set all the elements:";
    cout<<count<<endl;
    return 0;
}
