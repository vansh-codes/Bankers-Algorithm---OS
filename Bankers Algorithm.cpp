	#include <stdio.h>

//Implementation of Banker's Algorithm to check if the system is in safe state or not :)

int main() 
	{
	    int n, m;
	
	    // Define the number of processes and resources
	    n = 5;   	//Number of processes
	    m = 4; 		//Number of resources
	
	
	    // Define the available resources	
	    int available[m];
	    available[0] = 1;
	    available[1] = 5;
	    available[2] = 2;
	    available[3] = 0;
	    
	    // Define the maximum resources required by each process
	    int maxNeed[n][m] = {
	        {0, 0, 1, 2},
	        {1, 7, 5, 0},
	        {2, 3, 5, 6},
	        {0, 6, 5, 2},
	        {0, 6, 5, 6}
	    };
	
	
	    // Define the resources currently allocated to each process
	    int allocation[n][m] = 
			{
		        {0, 0, 1, 2},
		        {1, 0, 0, 0},
		        {1, 3, 5, 4},
		        {0, 6, 3, 2},
		        {0, 0, 1, 4}
		    };
	
	
	    // Calculate the need matrix
	    int remainingNeed[n][m];
	    for (int i = 0; i < n; i++) 
			{
		        for (int j = 0; j < m; j++) 
					{
			            remainingNeed[i][j] = maxNeed[i][j] - allocation[i][j];
			        }
		    }
	
	    // Initialize a safety algorithm to check if the system is in a safe state
	    int availResources[m];     //represents available resources at any given time 
	    
		int avail[24],size=0;     //to store availability values
		
	    for (int i = 0; i < m; i++) 
			{
		        availResources[i] = available[i];
		        avail[i]=available[i];
		    }
		    
		size = 4;  //avail size   
		
	    int finish[n];    //represents whether process finished executing or not
	    for (int i = 0; i < n; i++) 
			{
		        finish[i] = 0;
		    }
	
	    int safeSeq[n];    //safe sequence in which system can execute safely without getting into deadlock
	    int count = 0;     //no. of process that finished executing
	
	    while (count < n) 
			{
		        int found = 0;
		        for (int i = 0; i < n; i++) 
					{
			            if (finish[i] == 0) 
						{
							
			                int j;
			                for (j = 0; j < m; j++) 
								{
				                    if (remainingNeed[i][j] > availResources[j]) 
										{
					                        break;
					                    }
				                }

			                if (j == m) 
								{										        					                
				                    for (int k = 0; k < m; k++) 
										{
					                        availResources[k] += allocation[i][k];
					                        avail[size++]=availResources[k];
					                	}
					                	
				                    safeSeq[count++] = i; 
				                    finish[i] = 1;		
				                    found = 1;
				                    
				                }
			            }
			        }
			        
		        if (found == 0) 
					{
			            printf("The system is not in a safe state.\n");
			            return 0;
			        }
		    }
		    
		int availabalityTable[n+1][m];
		int add=0;
		for(int i=0;i<n+1;i++)
			{
				for(int j=0;j<m;j++)
					{
						availabalityTable[i][j]=avail[add++];
					}	
			}	
			
	    // If we reached here, the system is in a safe state
	    printf("The system is in a safe state. \nSafe sequence: ");
	    for (int i = 0; i < n; i++) 
			{
		        printf("P%d", safeSeq[i]);
		        if (i < n - 1) 
					{
			            printf(" -> ");
			        }
		    }
	    printf("\n\n");
		printf("-----------------------------\n\n");
		printf("Table: \n\n");
		printf("%-10s | %-15s | %-15s | %-20s | %-20s\n","Process","Allocations","Max.Need","Current Availablity","Remaining Need");
		printf("%-10s | %-15s | %-15s | %-20s | %-15s\n"," ", "A  B  C  D","A  B  C  D","A   B   C   D","A  B  C  D");
		for(int i=0;i<n;i++)
		{
			printf("%-2s P%-7d"," ",i);
			printf("%-s"," | ");			
			for(int j=0;j<m;j++)
				{
					printf("%-2d ",allocation[i][j]);
				}
			
			printf("%-3s"," ");
			printf("%-s"," | ");			
			for(int j=0;j<m;j++)
				{
					printf("%-2d ",maxNeed[i][j]);
				}
			printf("%-3s"," ");
			printf("%-s"," | ");
			for(int j=0;j<m;j++)
				{
					printf("%-3d ",availabalityTable[i][j]);
				}	
			printf("%-4s"," ");
			printf("%-s"," | ");
			for(int j=0;j<m;j++)
				{
					printf("%-2d ",remainingNeed[i][j]);
				}			
			printf("\n");
		}
		printf("%-49s"," ");
		for(int i=0;i<m;i++)
			{
				printf("%-4d",availabalityTable[5][i]);
			}
			
			
		printf("\n\n");
		printf("Completed by -Vansh Chaurasiya\nRegistration No. 12217737\n");
	    return 0;
	}
