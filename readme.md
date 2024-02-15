# Data Structures in C Programming Language

C is a programming language that requires the concept of pointers for understanding a number of data structures. A pointer is a variable that stores the memory address of another variable whose address is assigned to the pointer. There can be pointers to pointers to store memory address of a pointer. The ampersand '&' symbol denotes 'the address of' .

int *ptr;<br>
int \*\*pptr;<br>
ptr=&x;<br>
pptr= &ptr;<br>
int arr[10];<br>
arr[10]={2,4}; <br><!--max_size of array is 10-->
int (*ptr)[10]=&arr;<!--typecasting pointer to an array>--> <br>

<!--*(*ptr+i) gives the ith element of the array. -->

int* ptr_arr[3]={&arr[0],&arr[1],&arr[2]};
<br>
void (*function_name)(int)=&function_name;
<br>
enum boolean{false,true}<!-- false=0, true=1-->
<br>
typedef struct node{<br>
int data;<br>
typedef struct node* next;<br>
}Node;
<br>
Node *createnode(){ <br>
//CODE for creation of Nodes<br>
}<br>

<!--Function of type Node>
void function (Node* n) { <br>
}<br>-->

malloc():dynamic memory allocation in heap area is the work of the malloc() function returns a void pointer. This can be assigned to a variable of any data type.
<br>
calloc(): Allocates memory for an array and initializes all elements to zero.
<br>
realloc(): This changes the size of a block of memory pointed by ptr to new_size bytes. If there isn't enough space to reallocate the area.
<br>
# Data Structure

Data Structure is a way to store and organize  data so that this can be accessed and manipulated using specific functions or methods. 
## Definition:
Data structure is a way  of organizing and storing  data items into a specific memory so that the data can be used efficiently or the data can be accessed and manipulated efficiently. 

Always optimized implementations of Data Structures are studied. Optimization is a very important process.

(Set of algorithms that we can use to structure data in memory)

## Types of Data structures:

- Primitive Data Structure: basic data types are primitive data structures  like char , int , float , double. Pointers are also Primitive Data structures.

- struct,enum,union are  user-defined types.

- Non-Primitive Data Structures: The non-primitive  data structures are made up of other data structures or primitive data types. 
