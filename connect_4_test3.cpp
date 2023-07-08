#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

int sum1,sum2;    ///global declaration

int  menu_system()
{
    initwindow(700,1000,"",-10,-5);
    ///initialize the bars
      setfillstyle(SOLID_FILL,RED);
      bar(50,50,200,200);
      setfillstyle(SOLID_FILL,BLUE);
      bar(400,50,550,200);
      setfillstyle(SOLID_FILL,RED);
      bar(400,400,550,550);
      setfillstyle(SOLID_FILL,BLUE);
      bar(50,400,200,550);

      for(int i=125;i<=475;i+=10)
      {
          setcolor(9);
          setlinestyle(SOLID_LINE,2,3);
          line(125,125,i,125);
          line(475,125,475,i);
          line(125,475,i,475);
          line(125,125,125,i);
          delay(100);
      }

      rectangle(205,90,390,120);
      outtextxy(239,100,"::: CONNECT 4 :::");
      outtextxy(205,250,"PLAYER 1");
      outtextxy(310,250,"PLAYER 2 ");
      setcolor(6);
      circle(230,250,30);
      setcolor(3);
      circle(350,250,50);

      rectangle(210,415,390,465);
      outtextxy(225,420,"PRESS s TO BEGIN :");
      outtextxy(225,440,"PRESS q TO QUIT : ");

      rectangle(120,560,465,600);
      outtextxy(120,580,"Connect 4 similar balls in any direction(H/V/D) to WIN");

      char ch=getch();
      return ch;
}
class creation
{
    public:
                    struct
                     {

                         int L,T,R,B;
                      }m1,m2,m3,m4;

    public:
                     int move_detect1()
                     {
                         m1.L=200;
                         m1.T=200;
                         m1.R=250;
                         m1.B=250;
                         bar(m1.L,m1.T,m1.R,m1.B);
                         ///setfillstyle(7,7);
                         return 1;
                     }

                     int move_detect2()
                     {
                         m2.L=250;
                         m2.T=200;
                         m2.R=300;
                         m2.B=250;
                         bar(m2.L,m2.T,m2.R,m2.B);
                         ///setfillstyle(7,6);
                         return 1;
                     }

                      int move_detect3()
                      {
                         m3.L=250;
                         m3.T=250;
                         m3.R=300;
                         m3.B=300;
                         bar(m3.L,m3.T,m3.R,m3.B);
                         ///setfillstyle(7,5);
                         return 1;
                      }
                      int move_detect4()
                      {
                         m4.L=200;
                         m4.T=250;
                         m4.R=250;
                         m4.B=300;
                         bar(m4.L,m4.T,m4.R,m4.B);
                         ///setfillstyle(7,4);
                         return 1;

                      }

};

 struct slider_coord
    {
        int l,t,r,b;
    }s;

    struct coord
    {
        int x,y;
    }ar_coord[6][6];

  struct binary_coord
     {
         int bin;
     }bin_arr[6][6];

int animation(int N)
{
    int    k=20;
    while(k>0){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=N-1;j++)
        {
            if(bin_arr[i][j].bin==1){delay(80);setcolor(rand()%10);cleardevice();
            circle(rand()%ar_coord[i][j].x,rand()%ar_coord[i][j].y,70);}
            else if(bin_arr[i][j].bin==2){delay(80);
            setcolor(rand()%10);cleardevice();
            circle(rand()%ar_coord[i][j].x,rand()%ar_coord[i][j].y,100);}
            else
            continue;
        }
    }

    delay(100);
    k--;
}
return 1;
}

int winner_check(int N)
{
    sum1=sum2=0;
  ///ROW CHECK
  for(int i=0;i<=N-1;i++)
  {
      for(int j=N-1;j>=0;j--)
      {
          if(bin_arr[i][j].bin==1){
          sum1+=1;
          sum2=0;}
          else if(bin_arr[i][j].bin==2){
          sum2+=1;
          sum1=0;}
          else if(bin_arr[i][j].bin==0){
              sum1=sum2=0;
          continue;}
      }
      if(sum1==4||sum2==4||sum1>4||sum2>4)
      return true;
      else
      continue;
  }
  sum1=sum2=0;

///COLUMN CHECK
  for(int i=0;i<=N-1;i++)
  {
      for(int j=0;j<N;j++)
      {
          if(bin_arr[j][i].bin==1){
          sum1+=1;
          sum2=0;}
          else if(bin_arr[j][i].bin==2){
          sum2+=1;
          sum1=0;}
          else if(bin_arr[j][i].bin==0){
              sum1=sum2=0;
          continue;}
      }
      if(sum1==4||sum2==4||sum1>4||sum2>4)
      return true;
      else
      continue;
  }

      sum1=sum2=0;

      ///LEFT TO RIGHT DIAGONAL CHECK
    for(int i=0;i<N;i++)
    {
        if(bin_arr[i][i].bin==1){
        sum1+=1;sum2=0;}
        else if(bin_arr[i][i].bin==2){
        sum2+=1;sum1=0;}
        else if(bin_arr[i][i].bin==0)
        continue;
    }

       if(sum1==4||sum1>4||sum2==4||sum2>4)
       return true;

       sum1=sum2=0;
       ///RIGHT TO LEFT DIAGONAL CHECK

       for(int i=0;i<=N-1;i++)
       {
               if(bin_arr[i][N-i-1].bin==1){
               sum1+=1;sum2=0;}
               else if(bin_arr[i][N-i-1].bin==2){
               sum2+=1;sum1=0;}
               else if(bin_arr[i][N-i-1].bin==0){
               sum1=sum2=0;}
       }

       if(sum1==4||sum2==4||sum1>4||sum2>4){
       return true;}
}

int maze_genarator(int N )
{
            for(int i=100;i<=100*N;i+=100)
           {
            for(int j=50;j<=100*N;j+=100)
            {
                 setcolor(9);
                 setlinestyle(SOLID_LINE,3,2);
                 rectangle(j,i,j+100,i+100);
            }

        }

return 1;
}



    int slider_init(int l1,int t1,int r1,int b1)
    {
        s.l=l1; s.t=t1; s.r=r1; s.b=b1;
        rectangle(s.l,s.t,s.r,s.b);
        return 1;
    }

    int slider_position()
    {
        return s.l;
    }



int movement(int sw,int N)
{
    char ch=getch();

    if(ch=='a'&&s.l>=100&&sw==1)
    {
        s.l=s.l-100;
        s.r-=100;
        cleardevice();
        rectangle(s.l,s.t,s.r,s.b);
        circle(s.l+50,s.t+50,30);

    }
    else if(ch=='a'&&s.l>=100&&sw==2)
    {
        s.l=s.l-100;
        s.r-=100;
        cleardevice();
        rectangle(s.l,s.t,s.r,s.b);
        circle(s.l+50,s.t+50,50);

    }
    else if(ch=='d'&&s.r<=100*N&&sw==1)
    {
        s.l=s.l+100;
        s.r+=100;
        cleardevice();
        rectangle(s.l,s.t,s.r,s.b);
        circle(s.l+50,s.t+50,30);

    }
    else if(ch=='d'&&s.r<=100*N&&sw==2)
    {
        s.l=s.l+100;
        s.r+=100;
        cleardevice();
        rectangle(s.l,s.t,s.r,s.b);
        circle(s.l+50,s.t+50,50);

    }
    else if(ch==' '){
    return ch;}

}

int map_centre(int N)
{
    int temp1=50;
    int temp2=100;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            ar_coord[i][j].x=temp1+50;
            ar_coord[i][j].y=temp2+50;
            temp1+=100;
        }
        temp2+=100;
        temp1=50;
    }
    return 1;
}

int display_centre(int N)///vector<unsigned int>vector1,vector<unsigned int>vector2,vector<unsigned int>vector3,vector<unsigned int>vector4)
{

  setcolor(1);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=N-1;j++)
        {
                if(bin_arr[j][i].bin==1){
                 setcolor(6);
                 setfillstyle(SOLID_FILL,RED);
                 /// floodfill(ar_coord[j][i].x,ar_coord[j][i].y,WHITE);
                circle(ar_coord[j][i].x,ar_coord[j][i].y,30);



              }
                else if(bin_arr[j][i].bin==2)
                {

                   setcolor(3);
                   setfillstyle(SOLID_FILL,BLUE);
                circle(ar_coord[j][i].x,ar_coord[j][i].y,50);}
            }
        }


return 1;
}

int binary_matrix(int sw1,int pos,int N)///vector<unsigned int>&vect1,vector<unsigned int>&vect2,vector<unsigned int>&vect3,vector<unsigned int>&vect4)      ///pos1 gets the s.l value
{
    int temp1=pos+50;   ///x coordinate
    /// int temp2=s.t+50;   ///y coordinate
    int i=temp1/100-1;    ///identify the column no

    ///column numbering starts from 1,2,3,4...Row numbering starts from 0,1,2,3...


            for(int j=N-1;j>=0;j--)
            {
                if(bin_arr[j][i].bin==0)
                {
                    bin_arr[j][i].bin=sw1;
                    break;
                }
                else
                continue;
            }

        return 1;




}

int main()
{
            int gd=DETECT,gm;
            initgraph(&gd,&gm,"C\\TC\\BGI");
            char ch='\0' ;
            int n , sw=1,pos;

     if(menu_system()=='s')
{
    cleardevice();
    while(ch!='y')                                                                          ///initialisation loop
    {
        cout<<"Enter the Dimention"<<endl;
        cin>>n;
        maze_genarator(n);
        cout<<"Lock Dimension(y/n) ?"<<endl;
        cin>>ch;
        if(ch!='y')
        {
            cleardevice();
            continue;
        }
        else{

                map_centre(n);
                 }
                 break;
       }
       slider_init(50,0,150,100);

       while(1)              ///main game loop
       {


           maze_genarator(n);

           ch=movement(sw,n);
           pos=slider_position();


          if(ch==' ')
          {
              pos=slider_position();
              binary_matrix(sw,pos,n);///vector1,vector2,vector3,vector4);

                int k;
                creation create;  ///object creation

         ///cout<<"Enter a random number , 0 to quit\n";
         ///cin>>k;
for(int d=0;d<=5;d++){
         for(k=1;k<=4;k++)
         {

         ///cleardevice();
    rectangle(200,200,250,250);
    rectangle(250,200,300,250);
    rectangle(250,250,300,300);
    rectangle(200,250,250,300);


         switch(k)
         {
            case 1:   create.move_detect1();
                             break;
            case 2:   create.move_detect2();
                             break;
            case 3:    create.move_detect3();
                             break;
            case 4:   create.move_detect4();
                             break;
           default : cout<<"Invalid !\n";
                             break;
            }

         ///  if(k==4)
            ///         k=1;
            delay(100);
            cleardevice();
            setcolor(9);


    rectangle(200,200,250,250);
    rectangle(250,200,300,250);
    rectangle(250,250,300,300);
    rectangle(200,250,250,300);
    outtextxy(200,330,">>>LOADING<<<");

         }

}
              cleardevice();
              if(sw==1)
              sw=2;
              else
              sw=1;
          }


            display_centre(n);///vector1,vector2,vector3,vector4);


            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<bin_arr[i][j].bin<<" ";
                }
                cout<<endl;
            }
                cout<<endl;


               if(winner_check(n)==true)
               {
                   if(sw==1){
                   cout<<"PLAYER 2 WINS"<<endl;
                   animation(n);break;}
                   else if(sw==2){
                   cout<<"PLAYER 1 WINS"<<endl;
                   animation(n);break;}
               }
               else
               continue;

       }
}
else if(menu_system()=='q'){
    cleardevice();
closegraph();
exit(1);}

          getch();
         return 0;

}

