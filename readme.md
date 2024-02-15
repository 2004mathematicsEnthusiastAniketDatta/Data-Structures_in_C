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

- Primitive Data Structure: basic data types are primitive data structures  like char , int , float , double. Pointers are also Primitive data structure or data typed variables.

- struct,enum,union are  user-defined types.

- Non-Primitive Data Structures: The non-primitive  data structures are made up of other data structures or primitive data types. 
-  Non-Primitive data types are classified into Linear Data Structure and Non-Linear Data Structure.
- - **Linear Data Structures**: The arrangement of data in a sequential manner is known as Linear Data Structure. The data structure used for this purpose are **Arrays** , **Linked List** , **Stack** and **Queues**. In this linear data structure , one element is connected to another element in a linear form.
- - **Non-Linear Data Structure**: when one data element is connected to the 'n' numbers
of data elements in a non-linear form as in **Trees** , **Graphs** and other non-linear data structures. We call those Data Structures - **Non-Linear Data Structures**. In this case , elements are arranged in random manner. 

# Algorithms and abstract data types:

ALGORITHMS -> ABSTRACT DATA TYPES -> SET OF RULES

- **Algorithms**: logical steps to solve a given problem in  most efficient  way possible.

- **Abstract Data Types**: To structure the data in memory , 'n0' algorithms are proposed, and all these algorithms are Abstract Data Types.

                        Or 

- **Abstract Data Type**: A collection of data, along with methods (or functions) that  can be applied on them. ADT gives us the blueprint while data structure provides the implementation part.

- **Data**: Data can be defined as the elementary value or collection of values.
Data is the  raw information used by programs to perform tasks. This consists of various items such as text(mainly UTF-8), images,(Code points) emojis-> UTF-16 ,UTF-32 and so on.

- **Type**: A set of rules defining how data should be manipulated.

- **Record**: Record can be defined as the collection of various data items.

-  **Field**: Fields contain individual pieces of information referred to by names.

- **File**: file is a collection of records of one type of entity. 

- **Entity**: An entity represents class of certain objects.  
- **Attribute**: Class of certain objects  contains various attributes  (which describe
some particular property of entity). Each attribute represents some particular property of that class of certain objects. 

# Need of Data Structures:

As applications are getting more complex and amount of data is increasing day by day, there may arise the following  problems:
1. Efficient Memory Utilization : If you have large amount of data then it will consume more
2.  Time Complexity : This helps us to access elements quickly rather than searching for each time.
3. Space Complexity :  It tells about the extra space which needs to be allotted apart from input space.
4. Processors speed : As data is growing day by day to the billions of files per entity, processor may fail to deal with the amount of data.
5. Data Structure: consider an inventory size of 106 items in a store, if our application needs to search for a particular item, 106 items is needed to be traversed every time, resulting in slow down procedure.
6. Multiple Requests: If thousands of users are searching data  simultaneously on a web Server, then there are chances that to be failed to search during the process.
7.   Sorting & Searching Algorithm : They use Abstract Data Type(ADT) (like Set , List in python)
8.   Graph  Traversal Algorithm : Depth First Search and Breadth First Search both uses Stack ADT
9.   Dynamic Programming Problems : Coin Change Problem , Knapsack Problem etc.

To solve this problem , Data Structures are used . To form a data structure in such a way that all items are not required to be searched and required data can be searched instantly.

# Advantages of Data Structure

- **Efficiency**: If the choice of a data structure for implementing a particular ADT is proper, the programs become very efficient in terms of time and Space
- **Reusability**: The data structures provide reusability which means that multiple clients programs can use the data structure.
- **Abstraction**: The data structures specified by the ADT also provides a level of abstraction . The client cannot see the internal working of data structures, so understanding the implementation will be enough. 

#  Types of Data structures

Data Structure is classified into primitive and non-primitive data structure.Non-Primitive data structure is further classified into Linear and Non-Linear Data Structure.
Linear Data Structure is further classified into static and dynamic Linear data structure depending upon the  of static memory allocation , dynamic memory allocation in the heap with the help of malloc(),calloc() and realloc() functions in C programming language.

Arrays are both static and dynamic linear  data structure .

Linked List , Stack and Queue are dynamic linear Data Structures.

Non-Linear Data structures , in our syllabus , is divided into  two types - Trees and Graphs.


The implementations of each of the data structures are in the codes of the repository.

 # Operations on Data Structure

 

