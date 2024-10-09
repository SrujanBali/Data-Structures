#include<stdio.h>
#include<stdlib.h>

#define SIZE 5  //Defines the number of elements that can be stored in the list.

int top = -1;  //Variable for the last added element in the list.       {-1 as computers start counting from 0 and not 1.}
int stack_list[SIZE];  //Main list that is to be manipulated and that stores the data.


//Function to add a new element in the list
void push(int value)
{
    if (top >= SIZE - 1) //Checks if the array has space to add new element.
    {
        printf("OverFlow!\n");  // Message to user about the overflow in the list.
    }
    else
    {
        top++;      //Increment to the last element variable.
        stack_list[top] = value;  //Sets the last element value to the value passed in the function's parameter.
        printf("PushDone!\n");     //Confirmation to the User.
    }
}


//Function to remove the element at the top of the list/stack
void pop()
{
    if (top == -1)  //Checks if the array is empty. You cannot remove from something that is empty.
    {
        printf("EMPTY STACK LIST, cannot complete task.\n");  //Message to user about the empty list.
    }
    top--;
    printf("PopDone\n");  //Confirmation to the User.
}


//Function to see the last added element in the list
void peek()
{
    if (top == -1)  //Checks if the array is empty. You cannot see something in something that is empty.
    {
        printf("EMPTY STACK LIST, cannot complete task.\n");  //Message to user about the empty list.
    }
    printf("%d", stack_list[top]);  //Displaying the element.
}


//Function to show the entire list
void show()
{
    if (top == -1)  //Checks if the array is empty. No point in showing empty things.
    {
        printf("There is nothing to show in the stack/list\n");  //Message to user about he empty list.
    }
    for (int i = 0; i <= top; i++)  // For-loop to go through each element in the array and display them.
    {
        printf("%d ", stack_list[i]);  //Displays the list to the User.
    }
    printf("\n");
}


//Function to check for Empty List
void isEmpty()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }
}


//Function to check for Full List
void isFull()
{
    if (top == SIZE - 1)
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("The stack is not full\n");
    }
}


//Main Function to run all the functions for the created STACK.
int main()
{
    push(3);   
    push(4);
    push(5);
    push(6);
    push(7);
    isFull();
    isEmpty();
    show();
    push(9);                // Overflow
    pop();
    show();

    // show();
    return 0;
}