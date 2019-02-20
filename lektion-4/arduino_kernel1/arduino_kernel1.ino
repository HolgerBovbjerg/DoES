#include <krnl.h>
struct k_t *pt1; // pointer to hold reference to task 1
struct k_t *pt2; // pointer to hold reference to task 2
char s1[200]; // stack for task t1
char s2[200]; // stack for task t1

void t1(void){
   while (1) {  
    Serial.println("Hello World");
    k_sleep(1000);   // dont use delay bq delay is active waiting
  }                
}

void t2(void){
   while (1) {  
    digitalWrite(13, HIGH);
    k_sleep(1000);   // dont use delay bq delay is active waiting
    digitalWrite(13, LOW);
    k_sleep(1000);
  }                
} 

void setup(){
  Serial.begin(9600);  // for output from task 1
  pinMode(13, OUTPUT);
   k_init(2,0,0); 
// two task are created
//               |­­­­­­­­­­­­ function used for body code for task
//               |  |­­­­­­­­­ priority (lower number= higher prio)
//               |  | |­­­­­­­ array used for stak for task 
//               |  | |   |­­­ staksize for array s1
  pt1=k_crt_task(t1,11,s1,200);   

  pt2=k_crt_task(t2,11,s2,200); 
  
  k_start(10); // start kernel with tick speed 10 milli seconds
}
void loop(){ /* loop will never be called */ } 
