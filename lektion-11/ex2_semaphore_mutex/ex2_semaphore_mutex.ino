#include <krnl.h>

// Kernel variables
struct k_t *pt1,*pt2, *pt3, *sem1, *sem2, *sem3, *mutex;

// Stacks
char s1[200]; 
char s2[200];
char s3[200];

//Task 1
void t1(void)
{
  //Create semaphore timer
  k_set_sem_timer(sem1,40);
  while (1) {
    // Wait for semaphore timer
    k_wait(sem1,0);  
    // Write high on pin 13 when task 1 is called
    digitalWrite(13,HIGH);  
    // Wait on available mutex semaphore
    k_wait(mutex,0);     
    // Use 10 milliseconds of processor time
    k_eat_time(10);
    // Write high on pin 13 when task 1 is finished
    digitalWrite(13,LOW);
    // Realease mutex semaphore
    k_signal(mutex);
  }
}

void t2(void)
{
  k_set_sem_timer(sem2,60);
  while (1) {
    k_wait(sem2,0);
    digitalWrite(12,HIGH);
    //k_wait(mutex,0);  
    k_eat_time(20);
    digitalWrite(12,LOW);
    //k_signal(mutex);
  }
}

void t3(void)
{
  k_set_sem_timer(sem3,80);
  while (1) {
    k_wait(sem3,0);
    digitalWrite(11,HIGH);
    k_wait(mutex,0);  
    k_eat_time(20);
    digitalWrite(11,LOW);
    k_signal(mutex);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  // Initialise kernel with 3 tasks, 4 semaphores and 5 message ques
  k_init(3,4,5);
  // Create kernel tasks and assign pointer
  pt1=k_crt_task(t1,1,s1,200); 
  pt2=k_crt_task(t2,2,s2,200);
  pt3=k_crt_task(t3,3,s3,200);
  // Create semaphores
  sem1 = k_crt_sem(0,1);
  sem2 = k_crt_sem(0,1);
  sem3 = k_crt_sem(0,1);
  mutex = k_crt_sem(1,1);
  // Start kernel
  k_start(1);
}

void loop()
{
}
