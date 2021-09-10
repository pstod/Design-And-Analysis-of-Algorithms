//============================================================================
// Name        : n_queens_recursive_backtracking.cpp
// Author      : Priyadarshan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

		#include <iostream>
		using namespace std;




		class Nqueen
		{
			int *A;int n;int s_no;

		public:
			Nqueen(int n){this->n=n; A= new int[n];s_no=0;}
			void nqueens(int k );
			bool place(int k, int j);
			void display();

		};


		void Nqueen::nqueens(int k )
		{

			for(int j=1;j<=n;j++)			//to check each possible solution(col position) for a row
			{
				if (place(k,j))
				{
					A[k-1]=j;
					if(k==n)
						display();
											//if( (k+1)==(n/2)+1 ) eg k=3,n=4 or k=  to remove mirror img sols

					nqueens(k+1);			//to check postion in next row (here same row condition addressed)

				}

			}

		}
		bool Nqueen::place(int k, int j)
		{
			for(int i=1;i<k;i++)
			{
				if( (j==A[i-1]) || abs(k-i)==abs(j-A[i-1]))			//to check same col and same diagonal not true
					return false;

			}

			return true;
		}
		void Nqueen::display( )
		{
			char * c= new char[n];

			cout<<endl;
			s_no ++;
			cout<<"Solution Number :"<<s_no<<endl;
			cout<<"Solution Array :";
			for(int i=0;i<n;i++)
			{
				cout<<A[i]<<" ";
			}
			cout<<endl;
			for(int i=0;i<n;i++)
			{
					c[i]='-';
			}
			for(int i=0;i<n;i++)
			{
				c[A[i]-1]='Q';
				cout<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<c[i]<<" ";
				}
				c[A[i]-1]='-';
			}

			cout<<endl;
			delete[] c;
		}


		int main()
		{	int n;
			// enter value of n
			cout<<"Enter the value of n for a n x n chessboard"<<endl;
			cin>>n;
			if(n==2||n==3){cout<<"No Solution";}
			Nqueen obj(n);
			obj.nqueens(1);

			return 0;
		}




