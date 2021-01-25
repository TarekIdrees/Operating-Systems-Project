#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int SizeOfPartition,SizeOfProcesses,Policy;
    cout<<"Please enter the number of Partition !"<<endl;
    cin>>SizeOfPartition;
    int Partition[SizeOfPartition];
    int temp[SizeOfPartition];
    for(int i=1; i<=SizeOfPartition; i++)
    {
        cout<<"Enter size of Partition"<<i<<" :";
        cin>>Partition[i];
    }
    int Allocator[SizeOfPartition];
    for( int i = 1 ; i<=SizeOfPartition; i++)
    {
        Allocator[i]=0;
    }
    cout<<"please enter the number of processes !"<<endl;
    cin>>SizeOfProcesses;
    int Processes[SizeOfProcesses];
    for(int i=1; i<=SizeOfProcesses; i++)
    {
        cout<<"Enter size of processes"<<i<<" :";
        cin>>Processes[i];
    }
    cout<<"Select the policy you want to apply :"<<endl;
    cout<<"1.First fit"<<endl<<"2.Worst fit"<<endl<<"3.Best fit"<<endl;
    cin>>Policy;
    if(Policy==1)
    {
        for( int i = 1 ; i <=SizeOfProcesses; i++)
        {

            for( int j = 1; j<=SizeOfPartition; j++)
            {

                if(Processes[i] <= Partition[j] )
                {
                    cout<<"Partition "<<j<<" ("<<Partition[j]<<" KB"<<")"<<" = "<<"Process "<<i<<" ( "<<Processes[i]<<" KB"<<" )"<<",";
                    cout<<"Rest of Partition "<<j<<" = "<< Partition[j]-Processes[i]<<" KB "<<endl;
                    Allocator[j]=1;
                    Partition[j]-=Processes[i];
                    break;
                }

            }
        }
        for( int k=1 ; k<=SizeOfPartition; k++)
        {
            if(Allocator[k]==0)
                cout<<"Partition "<<k<<"( "<<Partition[k]<<" KB"<<")"<<" = "<<"Empty"<<endl;
        }
    }
    else if (Policy == 2 )
    {
        for( int i = 1 ; i <=SizeOfProcesses; i++)
        {
            int Max=-1;
            for( int j = 1; j<=SizeOfPartition; j++)
            {
                if (Partition[j] >= Processes[i])
                {
                    if(Max==-1)
                        Max=j;
                    else if (Partition[Max]  <  Partition[j])
                        Max=j;
                }
            }
            cout<<"Partition "<<Max<<" ("<<Partition[Max]<<" KB"<<")"<<" = "<<"Process "<<i<<" ( "<<Processes[i]<<" KB"<<" )"<<",";
            cout<<"Rest of Partition "<<Max<<" = "<< Partition[Max]-Processes[i]<<" KB "<<endl;
            Allocator[Max]=1;
            Partition[Max]-=Processes[i];
        }
        for(int k = 1 ; k<=SizeOfPartition; k++)
        {
            if ( Allocator[k]==0)
            cout<<"Partition "<<k<<"( "<<Partition[k]<<" KB"<<")"<<" = "<<"Empty"<<endl;
        }
    }
    else if (Policy==3)
    {
        for( int i = 1 ; i <=SizeOfProcesses; i++)
        {
            int BestIndex=-1;
            for( int j = 1 ; j <=SizeOfPartition; j++)
            {

                if (Partition[j] >= Processes[i])
                {
                    if(BestIndex==-1)
                        BestIndex=j;
                    else if (Partition[BestIndex]  >  Partition[j])
                        BestIndex=j;
                }
            }
            cout<<"Partition "<<BestIndex<<" ("<<Partition[BestIndex]<<" KB"<<")"<<" = "<<"Process "<<i<<" ( "<<Processes[i]<<" KB"<<" )"<<",";
            cout<<"Rest of Partition "<<BestIndex<<" = "<< Partition[BestIndex]-Processes[i]<<" KB "<<endl;
            Allocator[BestIndex]=1;
            Partition[BestIndex]-=Processes[i];
        }
        for(int k = 1 ; k<=SizeOfPartition; k++)
        {
            if ( Allocator[k]==0)
            cout<<"Partition "<<k<<"( "<<Partition[k]<<" KB"<<")"<<" = "<<"Empty"<<endl;
        }

    }
    return 0;
}
