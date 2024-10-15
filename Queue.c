#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  //Defining the size of the queue

int rear = 0;  //Represents the last member of the queue
int front = 0;  //Represents the first member of the queue
int queue[SIZE];  //Variable storing the values of the queue

//Function to put a new member in the queue
void enqueue(int value)
{
    if (rear == SIZE)  //Checks if the list is full or not. If full then it won't pass the value for this function
    {
        printf("This Queue is full. Cannot Enqueue a new value.\n");
    }
    else
    {
        queue[rear] = value;  //Inserting the passed value in this function to the end of the queue
        rear++;  //Increment in the index of the queue array
        printf("%d has been added to the list\n", value);  //Confirmation message to the user
    }
}

//Function to dequeue the first member or the memeber in the front of the queue
void dequeue()
{
    if (rear == 0 || front >= rear)  //Checks if the queue is empty or not
    {
        printf("The Queue is Empty. Cannot remove anything.\n");
    }
    else
    {
        int data = queue[front];  //Stroring the value that is to be dequeued for reference
        front++;  //Incrementing the first member index to remove the member in first index
        printf("%d has been dequeued.\n", data);  //Prints the removed member to the user
    }
}

//Checks if the Queue is Empty or Not
void isEmpty()
{
    if (rear == 0 || front > rear)
    {
        printf("The Queue is Empty.\n");
    }
    else
    {
        printf("The Queue is NOT Empty\n");
    }
}

//Checks if the Queue is Full or Not
void isFull()
{
    if (rear == SIZE)
    {
        printf("The Queue is Full\n");
    }
    else
    {
        printf("The Queue is NOT Full\n");
    }
}

//Shows the very last member of the queue
void show_rear(){
    if (rear == 0 || front > rear){
        printf("The Queue is Empty\n");
    }
    else{
        printf("%d\n", queue[rear - 1]);
    }
}

//Shows the first member of the queue
void show_front(){
    if (rear == 0 || front > rear){
        printf("The Queue is Empty\n");
    }
    else{
        printf("%d\n", queue[front]);
    }
}

//Shows the number of members or size of the queue
void size_of_queue(){
    if (rear == 0 || front > rear){
        printf("The Queue is Empty\n");
    }
    else{
        int size = sizeof(queue)/sizeof(queue[0]);
        printf("%d\n", size);
    }
}

//Displays the entirety of the queue
void show()
{
    for (int i = front; i < rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

//Main Function
int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);  //Exceeds the size of the queue so shows "Queue is Full"
    isFull();
    show_rear();
    show_front();
    size_of_queue();
    show();
    dequeue();
    dequeue();
    show();

    return 0;
}