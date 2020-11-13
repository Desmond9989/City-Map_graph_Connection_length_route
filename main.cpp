#include<iostream>
#include<string.h>
#include <limits.h> 
#include <stdio.h> 
#include <vector> 
#include<iomanip>
#define limit 20

using namespace std;

class graph {
	            
	             public : 
	                        int ADJ_mat[limit][limit];
							vector<vector<int> > AdjList; 
                            int number_of_nodes=0;
                            int count=0;
                            int count_special=0;
                            int len;
                            int sumlocal=0;
                            int count2=0;
                            int dist;
                            int sum[limit];
                            int tracker=0;
                            int shortestpath;
                            string node_names[limit]; 
                            
                            string city_names[limit];
                            graph (){
                            	
                            	  for(int i=0;i<limit;i++)
                            	    for(int j=0;j<limit;j++)
                            	      ADJ_mat[i][j]=0;
                            	      
							        }
							path_l();
							int diji_algo(int source , int end); 
							 int printAllPath(int s, int d);
							 printAllPathsUtil(int u, int d, bool visited[],int path[], int &path_index);
 							int minDistance(int dist[], bool sptSet[]);      
						   void display()
							{
								 for(int i=0;i<number_of_nodes ;i++)
								 cout<<node_names[i]<<" ";
								  cout<<"\n";
								 for(int i=0;i<number_of_nodes;i++)
								 {
								 	
								 
                            	    for(int j=0;j<number_of_nodes;j++)
                            	    {
							          cout<<" "<<ADJ_mat[i][j];
					        		}
					        	cout<<"\n";	
							     }
						    }
						  void create_graph()
						  {
						  	  
						  	   try{
								 
								   cout<<"---INPUT the number of nodes--- \n";
						  	     cin>>number_of_nodes;
						  	     if(number_of_nodes>limit)
						  	     throw;
						  	     for(int i=0;i<number_of_nodes;i++){
						  	     	cout<<"enter the city name";
						  	     	cin>>node_names[i];
								   }
							}catch(...){cout<<"EXCEPTION HANDLED PLEASE RESTART";
							}
								   
						  	     cout<<"***enter EDGE***";
						  	     for(int i=0;i<number_of_nodes;i++)
						  	     { 
						  	        for(int j=0; j<number_of_nodes;j++)
						  	        {
						  	        	 cout<<"enter weight if there is a edge between "<<"["<<node_names[i]<<"]"<<"["<<node_names[j]<<"]";
						  	        	 cin>>ADJ_mat[i][j];
									  }
								   }
								   						  	     cout<<"cities added Successfully \n";

						  	     
							} 
							
							
						 void add_city()
						 {
						 	 
						 	 cout<<"enter the name of city \n";
						 	 number_of_nodes++;
						 	 cin>>node_names[number_of_nodes];
						 	 cout<<"City Added Successfully \n";
						 	 
						  }
						void remove_city()
						{
							string temp;
							count=0;
 						    cout<<"\n \n \n enter the name of city you want to delete \n";
						    cin>>temp;
						    try {
							
						    for(int i =0 ; i <number_of_nodes ; i++)
							{ 
							
							  if(temp==node_names[i])
							  {
							  	break;
								  }	
							  count++;	  
							}
							if(count==0)
			                  throw;
						}
						catch(...){
							cout<<"EXCEPTION HANDLED PLEASE RESTART";
						};
						  if(count==number_of_nodes)
						  {  
						  
						     for(int i=0;i<number_of_nodes;i++)
						     {
						     	 ADJ_mat[i][count]=0;
						     	 ADJ_mat[count][i]=0;
							 }
						  	 
						  	  
						  }
						    else {
						    	   for(int i=count; i < number_of_nodes ; i++)
								   {
								   	 node_names[i]=node_names[i+1];
									 } 	
							 
/*SETTING right to left */				   





                                     for(int i=count ; i< number_of_nodes-1 ; i++)
							       {
							       	  for(int j=0 ; j < number_of_nodes ; j++)
							       	   {
							       	   	    ADJ_mat[j][i]=ADJ_mat[j][i+1];
												   
										  }
								   }
								          
										
										
										
/*setting bottom to top */										
								     for(int i= count  ; i<number_of_nodes-1 ; i++)
							       {
							       	  for(int j=0 ; j < number_of_nodes; j++)
							       	   {
							       	   	    ADJ_mat[i][j]=ADJ_mat[i+1][j];
												   
										  }
								   }
								   number_of_nodes--;
										      
								   
								   
		                        }
		                        cout<<"REMOVED CITY \n";
                        }
                void add_edge_path()
				{ 
				
				 
                            string s1;
                            string s2;
                            count=0;
                            count2=0;
							cout<<"enter FIRST city name \n";
							cin>>s1;
							cout<<"enter SECOND city name \n ";
							cin>>s2;
							for(int i =0 ;i <number_of_nodes;i++)
							{
								if(s1==node_names[i])
								  {
								  	break;
								  }
								  else count++;
											}				
				
 				
				
				
				
				
			      
			       
					  for(int i=0;i<number_of_nodes;i++)
					 {
					 	 if(s2==node_names[i])
					 	 {
					 	 	break;
						  }
						  count2++;
						  
					 }
					  cout<<"enter DISTANCE BETWEEN "<<s1<<"-->"<<s2;
					  cin>>dist;
					  ADJ_mat[count][count2]=dist;
					  ADJ_mat[count2][count]=dist;
					  
					  cout<<"\n ADDED SUCCESSFULLY \n";
					 
					
						}   
						
						
						
			void remove_edge_path()
			{
				
				            string s1;
                            string s2;
                            count=0;
                            count2=0;
							cout<<"enter FIRST city name \n";
							cin>>s1;
							cout<<"enter SECOND city name \n ";
							cin>>s2;
							for(int i =0 ;i <number_of_nodes;i++)
							{
								if(s1==node_names[i])
								  {
								  	break;
								  }
								  else count++;
											}				
				
 				
				
				
				
				
			      
			       
					  for(int i=0;i<number_of_nodes;i++)
					 {
					 	 if(s2==node_names[i])
					 	 {
					 	 	break;
						  }
						  count2++;
						  
					 }
				
				
				
				ADJ_mat[count][count2]=0;
					  ADJ_mat[count2][count]=0;
				
				cout<<"DELETED SUCCESSFULLY\n";
				 }     
                        
                        
                        
                        
                       
                        
				
				
				
				
				
				
				
	void path_between_cities()
	{
		      string helper1;
		      string helper2;
		      count=0;
		      count2=0;
		      	cout<<"enter FIRST city name \n";
							cin>>helper1;
							cout<<"enter SECOND city name \n ";
							cin>>helper2;
							for(int i =0 ;i <number_of_nodes;i++)
							{
								if(helper1==node_names[i])
								  {
								  	break;
								  }
								  else count++;
											}				
				
 				
				
				
				
				
			      
			       
					  for(int i=0;i<number_of_nodes;i++)
					 {
					 	 if(helper2==node_names[i])
					 	 {
					 	 	break;
						  }
						  count2++;
						  
					 }
				
		      
		      
		      
		      
		      
		      
		      
		      
		       shortestpath =diji_algo(count,count2);
		       if(shortestpath==INT_MAX)
		        cout<<"----no path----- between => \n"<<helper1<<"-"<<helper2;
		        else 
		         cout<<"----conneceted----- between => \n"<<helper1<<"-"<<helper2;		      
		      
		      
				}			
				
				
				
				
vector<vector<int> > convert( vector<vector<int> > a) 
{ 
	vector<vector<int> > adjList(a.size()); 
	for (int i = 0; i < a.size(); i++) 
	{ 
		
		for (int j = 0; j < a[i].size(); j++) 
		{ 
			if (a[i][j] == 1) 
			{ 
				adjList[i].push_back(j); 
			} 
		} 
	} 
	return adjList; 
}
				
				
							
};



graph::minDistance(int dist[], bool sptSet[]) 
{ 
	  
	int min = INT_MAX, min_index; 

	for (int v = 0; v < number_of_nodes; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 




graph::diji_algo(int src , int end )
{  
     int V=number_of_nodes;
	 int dist[V]; 
	 bool sptSet[V];
	 for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false;
			dist[src] = 0; 
          for (int count = 0; count < V - 1; count++) { 
          	int u = minDistance(dist, sptSet); 
          		sptSet[u] = true;
          			for (int v = 0; v < V; v++) 
          				if (!sptSet[v] && ADJ_mat[u][v] && dist[u] != INT_MAX	&& dist[u] + ADJ_mat[u][v] < dist[v]) 
				dist[v] = dist[u] + ADJ_mat[u][v]; 
	} 
	
	return dist[end];
	
	
}


graph::printAllPathsUtil(int u, int d, bool visited[],int path[], int &path_index)
							{
								
	int flag=0;
	visited[u] = true; 
	path[path_index] = u; 
	path_index++; 

	// If current vertex is same as destination, then print 
	// current path[] 
	 
	if (u == d) 
	{  		 
		for (int i = 0; i<path_index-1; i++)
		{
		   
		   sumlocal+=ADJ_mat[path[i+1]][path[i]];
		      	
        }
        
         
        sum[tracker]=sumlocal;
        tracker++;
		cout << endl;
 		 sumlocal=0;
		  
		  
		 
		
	} 
	else // If current vertex is not destination 
	{ 
 
		// Recur for all the vertices adjacent to current vertex 
		vector<int>::iterator i; 
		 
		for (i = AdjList[u].begin(); i != AdjList[u].end(); ++i) 
			if(!visited[*i]) 
				printAllPathsUtil(*i, d, visited, path, path_index); 
	 
	} 

	// Remove current vertex from path[] and mark it as unvisited 
	path_index--; 
	visited[u] = false;

	 
 
 
 }
								
							

graph::printAllPath(int s,int d)
{
		// Mark all the vertices as not visited 
	bool *visited = new bool[number_of_nodes]; 
    int len;
	// Create an array to store paths 
	int *path = new int[number_of_nodes]; 
		for (int i = 0; i < number_of_nodes; i++) 
		path[i]=0; 
	int path_index = 0; // Initialize path[] as empty 

	// Initialize all vertices as not visited 
	for (int i = 0; i < number_of_nodes; i++) 
		visited[i] = false; 

	// Call the recursive helper function to print all paths 
	printAllPathsUtil(s, d, visited, path, path_index); 
	 cout<<"enter the length of path for which you want count? \n";
	 cin>>len;
	 for(int i=0;i<tracker;i++)
	 {
	 	if(sum[i]==len)
	 	count_special++;
	 }
	 if(count_special >0)
	 cout<<"NUMBER OF paths of length n are \n"<<count_special<<endl;
	else 
	 cout<<"NO PATH OF SUCH LENGTH \n";
}

  

graph::path_l()
{
	
	int s,d;
	s=0;
	d=0;
	 //temp array
	 int temp[number_of_nodes][number_of_nodes];
	 for(int i=0;i<number_of_nodes;i++)
	 {
	 	for(int j=0; j< number_of_nodes;j++)
	     {
	     	if(ADJ_mat[i][j]>0) 
			 temp[i][j]=1;
			 else
				 temp[i][j]=0;

			 
		 }
	 }
vector<vector<int> > a; 
vector<int> p;
 for(int i=0;i<number_of_nodes;i++)
  {
  	 for(int j=0;j<number_of_nodes;j++)
  	 {
  	 	 p.push_back(temp[i][j]);
	   }
	   a.push_back(p);
	   p.clear();
	   
  }
  	 AdjList = convert(a); 
  	 
  	 // possible paths
  	 cout<<"enter the name of source city \n";
  	 string source;
  	 cin>>source;
  	 cout<<"enter the name of destination city";
  	 string dest;
  	 cin>>dest;
  	 for(int i =0 ; i <number_of_nodes ; i++)
							{ 
							
							  if(source==node_names[i])
							  {
							  	break;
								  }	
							  s++;	  
							}
	for(int i =0 ; i <number_of_nodes ; i++)
							{ 
							
							  if(dest==node_names[i])
							  {
							  	break;
								  }	
							  d++;	  
							}						
							
	 
 
	 
	 
  
	printAllPath(s, d); 
	 
	 
}







int main()
{	
graph g1;

int c;


do
{
	
cout<<"---WELCOME MENU---\n";	
cout<<"1.CREATE GRAPH \n2.DISPLAY \n3.ADD CITY \n4.REMOVE CITY \n5.ADD DIRECT ROUTE\n 6.REMOVE DIRECT ROUTE\n7.CHECK IF CONNECTED\n8.NUMBER OF PATHS OF LEN N\n9.EXIT \n ";
cout<<"\nPLEASE ENTER CHOICE \n";
cin>>c;
switch(c)
{
	 case 1: g1.create_graph();
	 break;
	 case 2: g1.display();
	 break;
	 case 3: g1.add_city();
	         g1.display();
	 break;
	 case 4: g1.remove_city();
	 break;
	 case 5: g1.add_edge_path();
	 break;
	 case 6: g1.remove_edge_path();
	 break;
	 case 7 : g1.path_between_cities();
	 break;
	 case 8 : g1.path_l();
	 break;
}

}while(c!=9);
















}
