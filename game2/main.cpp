#include <iostream>
#include "cases.h"
#include<cstdlib>
using namespace std;

int main()
{
    system("color f5") ;
    int n,y,b ,a,o,s;

    cout << "le taille du tableau   " ;
    cin >> n ;
    system("CLS") ;
    cases tab[n][n] ;


    cout << "le nbr des bombe    " ;
    cin >> b ;
    system("CLS") ;



// 7atan les bomb

    for (int i=0;i<b;i++)
    {
            y=rand()%(n*n) ;
            a=y/n ;
            o=y%n ;

            tab[a][o].bomb=true;
            tab[a][o].nbr=9 ;

    }

//ta3mir enmwamer
    for (int i=0;i<n;i++)
   {
       for (int j=0 ; j<n ; j++)
       {
           if (tab[i][j].nbr!=9 )
           {


                s=0;
                if (tab[i+1][j].bomb && i+1<n) s++;
                if (tab[i][j+1].bomb&& j+1<n) s++;
                if (tab[i+1][j+1].bomb&& j+1<n && i+1<n) s++;
                if (tab[i-1][j].bomb&&i-1>=0) s++;
                if (tab[i][j-1].bomb&&j-1>=0) s++;
                if (tab[i-1][j-1].bomb && i-1>=0 && j-1>=0  ) s++;
                if (tab[i+1][j-1].bomb && i+1<n && j-1>=0  ) s++;
                if (tab[i-1][j+1].bomb && i-1>=0 && j+1<n  ) s++;

                tab[i][j].nbr=s;
            }

       }
   }




 cout << endl ;
  y=0 ;
   do
   {

       for (int i=0;i<n;i++)
       {
           cout << endl ;
           for (int j=0 ; j<n ; j++)
           {
                if(tab[i][j].used==true) cout <<  tab[i][j].nbr<< " " ;
                else cout << tab[i][j].ch << " " ;

           }
       }







        y++ ;
        cout << endl << endl ;
        cout << "choisit  un case   "  ;

        //system("CLS") ;

        cin >> a >> o ;
        tab[a][o].used=true ;

   }while(  tab[a][o].bomb!=true && y<(n*n)-1 )  ;

   if (!(y<(n*n)-1))
   {
       cout << "YOU WIN " ;


       for (int i=0;i<n;i++)
       {
           cout << endl ;
           for (int j=0 ; j<n ; j++)
           {
                if(tab[i][j].bomb==false) cout <<  tab[i][j].nbr<< " " ;
                else cout << tab[i][j].ch << " " ;

           }
       }


   }
   else cout << "YOU LOSE "  ;



/*
   for (int i=0;i<n;i++)
   {
       cout << endl ;
       for (int j=0 ; j<n ; j++)
       {
           if (tab[i][j].nbr==9) cout << tab[i][j].ch << " " ;
           else cout << tab[i][j].nbr << " " ;

       }
   }

*/




    return 0;
}
