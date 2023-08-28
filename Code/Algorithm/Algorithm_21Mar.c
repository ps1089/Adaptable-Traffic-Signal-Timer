#include <stdio.h>
#include<math.h>

//int Intersection[4];
int count_of_vehicles[3];
float WavgCount[3];
int m = 0;
//For input
int s ;
//For GSTAnalysis 
int z = 0;
float sum=0;
// Function declarations

void startmsg();
void input(char *name);
void Weighted_Average();
void Algorithm();
void GSTConditions(float GST_sqroot);
void GSTAnalysis(float GST_final);

int main()
{
  int k;
  while (k <= 4)
  {

    startmsg();
    //input();
    Weighted_Average();
    Algorithm();
    k++;
    m++;
    //For continous execution.
    if (k == 4)
      k = 0;
    if (m == 4)

      m = 0;
  }
  return 0;
}

void startmsg()
{
  char name[4] = "PQRS";
  printf("\nFor intersection %c: \n", name[m]);
  // for (int k = 0; k <= 3; k++)
  // {
  //  printf("The elements are: %c\n", name[k]);
  //}
  // Calling the function using Refrence
  input(name);
}

void input(char *name)
{

  // Necessary //
  s = m;
  for (int i = 0; i < 3; i++)
  {
    printf("Enter the count of vehicles on %c intersection:",name[s]);
    scanf("%d", &count_of_vehicles[i]);
    s++;
    if(s==4)
     s=0;
  }
  printf("\n");
}
void Weighted_Average()
{

  
  int CountAddition = 0;

  for (int p = 0; p < 3; p++)
  {
    CountAddition += count_of_vehicles[p];
  }
  // Weighted Average Calculation
  for (int p = 0; p < 3; p++)
  {
    WavgCount[p] = (float)(count_of_vehicles[p] / (float)(CountAddition));
  }
}

void Algorithm()
{
  float GST;
  double GST_sqroot;
  double temp2;
  int q = 0;
  float temp = ((WavgCount[q] * (float)count_of_vehicles[q]) + (WavgCount[q + 1] * (float)count_of_vehicles[q + 1]) + (WavgCount[q + 2] * (float)count_of_vehicles[q + 2]));
  float temp1 = (WavgCount[q] * (float)count_of_vehicles[q]) / temp;
  //Using sqroot 
  temp2 =pow((double)temp1,0.5);  
  
  GST_sqroot = temp2 * 40; 
  // using ceil
  printf("The GreenSignalTime is :%.lf\n", ceil(GST_sqroot));
  
 
GSTConditions(GST_sqroot);

}
void GSTConditions(float  GST_sqroot)
{

float GST_final ;
if(GST_sqroot <=3.00 )
{

GST_final = 3.00;
}
else
{
  GST_final=GST_sqroot;
}

GSTAnalysis(GST_final);

}
void GSTAnalysis(float GST_final)
{
float GST_total[100];
GST_total[z] = GST_final; 
sum += GST_total[z];
z++;
if(z%4==0)  
{
 printf("\n\n");
 printf("The Total GreenSignalTime for entire cycle is: %.lf\n", ceil(sum));
}
}
