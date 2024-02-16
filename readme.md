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

- **Abstract Data Type**: A collection of data, along with methods (or functions) that  can be applied on them. ADT gives us the blueprint while data structure provides the implementation part.In this article, we will learn about ADT but before understanding what ADT is let us consider different in-built data types that are provided to us. Data types such as int, float, double, long, etc. are considered to be in-built data types and we can perform basic operations with them such as addition, subtraction, division, multiplication, etc. Now there might be a situation when we need operations for our user-defined data type which have to be defined. These operations can be defined only as and when we require them. So, in order to simplify the process of solving problems, we can create data structures along with their operations, and such data structures that are not in-built are known as Abstract Data Type (ADT).
Abstract Data type (ADT) is a type (or class) for objects whose behavior is defined by a set of values and a set of operations. The definition of ADT only mentions what operations are to be performed but not how these operations will be implemented. It does not specify how data will be organized in memory and what algorithms will be used for implementing the operations. It is called “abstract” because it gives an implementation-independent view. 

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
1. Efficient Memory Utilization : If you have large amount of data then this will consume more memory.
2.  Less Time Complexity : This helps us to access elements quickly rather than searching for each time.
3. Less Space Complexity :  It tells about the extra space which needs to be allotted apart from input space.
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

1. **Traversing**: Every data structure contains a set of  data elements.Traversing data structure means visiting each element of data structure in order to perform some specific operation like searching and sorting.
Example: If we need to calculate average of marks obtained by a student in six different subjects , we need to traverse the complete array of marks and calculate total sum, then we will divide the sum by the number of subjects i.e., 6 to find average.
2. **Insertion**: Insertion can  be defined as the process of adding the elements to the data structure at any location. If the size of data structure is 'n' then we can only insert n-1 data elements to that.
3. **Deletion**: The process of removing an element from the given data  structure is known as deletion. We can delete an element from data structure at any random location. If we try to delete an element from an empty data structure underflow occurs.
4.**Searching**: The process of finding the location of an element in the data structure is  called as searching. There are five algorithms to perform searching: 
- - LINEAR SEARCH
- - BINARY SEARCH
- - TERNARY SEARCH
- - FIBONACCI SEARCH
- - JUMP SEARCH 

 5.**Sorting**: The process of arranging the data structure in a specific order is known as sorting. There are many sorting algorithms and there are nine Sorting algorithms:
 - - BUBBLE SORT
 - - SELECTION SORT
 - - INSERTION SORT
 - - MERGE SORT
 - - QUICK SORT
 - - BUCKET SORT
 - - HEAP SORT
 - - SHELL SORT
 - - RADIX SORT
 - - WAVE SORT

6.**MERGING**: When two different lists list A and list B of size M and N respectively , of similar type of elements , clubbed or joined together to produce a third list C of size M+N , then this process is called merging.

# Algorithms:

Pseudo code or  high level  instructions used to perform operations on these data structures and with these data structures. Algorithms can be presented in Flowcharts.

## Characteristics of an algorithm:

1. **Input**: An algorithm should have some input values , either hard-coded or user provided values.We may pass 0 or some input value to the algorithm.
2. **Output**: we will get 1 or more desirable output at the end of an algorithm.
3. **Unambiguous algorithm** : An algorithm should be unambiguous , i.e , the instruction should be  clear and simple.
4. **Finiteness**: An algorithm should have finiteness i.e, limited number of lines.
5. **Effectiveness**: An algorithm should produce correct output with correct input in minimum number of possible steps.

# Approaches to algorithms:

1. **Brute Force Algorithm**:  This involves checking all possible cases for a problem. This approach works well when there aren't many data elements. Simple , comprehensive algorithm that systematically explores every option until a problem's answer is discovered. Also known as exhaustive search algorithm that searches all possible options to provide required solution.<br>
   
           1. optimization: Finding all solutions of a problem and then comparing space and time complexities.The least Space and time complexity taking efficient algorithm is the best solution known. then this will terminate if the best solution is known.
           2.Sacrificing: As soon as the best solution is found , the algorithm will stop.


2. **Divide and Conquer Algorithm**: The problem is divided into sub problems  in such a way that the problem becomes easier to solve.Each sub problem is analyzed individually  and solutions are obtained for each sub problem.The solutions of the sub problems are combined back to get the original solution in case. of **Divide and Merge** algorithm. Here the algorithm is broken down into simplest possible problems.

3. **Greedy Algorithm**:  (This makes locally optimal choice at each step and hope that these local optima can lead to a global ....) An algorithm paradigm that makes the optimal choice of each iteration with the  hope of getting the best solution.This is easy to implement and has faster execution time. There are rare cases in which this provides the optimal solution.

The major categories of algorithms in syllabus are :

1.**Sort**: Algorithms to arrange data elements in a data structure in a specific order.

2.**Search**: Algorithms to find a target element in the data structure.

3.**Delete**: Algorithms to delete a specific element in the data structure.

4.**Insert**: Algorithms to  insert new elements into the existing data structure.

5.**Update**:  Algorithm to modify the value of an already present element in the data structure.

6.**Dynamic Programming**: An optimization over plain recursion which means calling a function inside itself(the same function). Where ever,  we see a recursive solution that has repeated calls for same inputs, we can optimize this with **Dynamic Programming** : The idea is to simply store the results of sub problems ,so that we do not need to recompute them when needed later.

**Algorithmic analysis**:

The algorithmic analysis involves two levels ,i.e, first is before creating an algorithm , and second is after creating an algorithm.

There are two types of analysis of an algorithm:

**priori analysis**: Here , Priori analysis is the theoretical analysis of an algorithm which is done before implementing the algorithm.

**posterior analysis**: Here , Posterior analysis is a practical analysis of an algorithm.The practical analysis is achieved with the help of a programming language  and a computer.

Algorithm Complexity

1. Time complexity: Time complexity is the rate at which  an  algorithm's running time increases/decreases with the size of input. 

2. Space  complexity - It refers to the extra space required by an algorithm to solve a problem.

#  Time and Space Complexity Analysis:

1. Time Complexity: Time complexity is the rate   at which an algorithm's running time grows/falls with respect to the size of input.

**Types of Cases while estimating the time complexity**:
- Worst Case: The case in which the entire data structure is searched and gets exhausted is worst case .When the  worst possible input case occurs, this gives us the maximum amount of time that can be taken.
- Average Case: This case  assumes that all inputs have equal probability of occurring. The searching is at the middle of the linear data structure in this case. 
- Best Case: Best case is  when the input has the smallest possible size for which the function can be called.

**Types of Time complexities**:

- **Worst Case Time complexity**:  The worst case scenario when the input size can be any value. This is associated to the maximum amount of time  required while searching the last element in the data structure or inserting any element at the end of the data structure or at the deepest level. Big oh Notation represents Worst Case Time complexity. 

- **Average Case Time Complexity**: Average case Time complexity is the time complexity of an algorithm when the algorithm searches for an element somewhere in the middle of linear data structures or in case of skewed Binary Trees or somewhere in the middle levels of a non-linear data structure.(This occurs when all the inputs have equal probability of occurring). Theta notation  represents the average case Time Complexity

- **Best Case Time Complexity**: Best case time complexity is the best possible case that can happen to any data structure like element search getting successful at the beginning of the data structures as in arrays or inserting elements at the beginning of linear data structures like arrays or updating the value at the zeroth  index of the data structure. Omega Notation represents the Best Case Time Complexity.

# Asymptotic Notations

1.**Big-Oh Notation**: 

We can express algorithmic complexity using the big-oh Notation.For a problem of size N:

- A constant-time function/method is of "order 1":O(1)

- A linear-time function is "order N": O(N)

- A quadratic-time function is "Order N^2": O(N^2)

- Logarithmic (-time (vs input size)) functions have order log N : O(log N)
- A Cubic-time function have "order N^3": O(N^3)
- A factorial-time function have "order N!":O(N!)
- O(N log (N)) function

1.**Big-Oh Notation**: 

**Definition**: Let g and f be functions from the set of natural numbers to itself .The function f is said to be O(g),if there is a constant c>0 and a natural number n0 such that f(n)<=cg(n) for all n>n0.

*NOTE*: Big-Oh of g is a set 

Big-O notation gives the upper bound idea mathematically described below: 

" f(n) = O(g(n)) if there exists a positive integer  n0 and a positive constant c, such that f(n)<=c.g(n) for all n>=n0. "

Big-O of N gives the upper bound of the function.

2.**Theta Notation**: 

Theta notation represents both an upper bound ("upper limit") and a lower bound ("lower limit") of the function. 

"Theta of g(n)= {f(n): there exist positive constants c1,c2 and n0 such that 0<=c1*g(n)<=f(n)<=c2*g(n) for all n>n0}"

This means that f(n)=theta of(g(n)),if there are positive constants n0 and c such that , to the right of n0 and c such that , to the right of n0 the f(n)  always lies on or above c1*g(n) and below c2*g(n).
 
3.**Omega Notation**:

Omega Notation specifies the asymptotic lower bound for function f(n). For a given function g(n), Omega of (g(n)) is denoted by:

Ω (g(n)) = {f(n): there exist positive constants c and n0 such that  c*g(n) >= f(n) for all n ≥ n0}. 

This means that, f(n) = Ω(g(n)), If there are positive constants n0 and c such that, to the right of n0 the f(n) always lies on or above c*g(n).

# SPACE COMPLEXITY:

The space complexity of an algorithm is the amount of space required to solve a problem and produce an output. Similar to the space complexity , space complexity is also expressed as big o notation.

space complexity=Auxillary space + input size
Space Complexity includes two types:
1. **Constant Space**: The space required does not grow with an increase in input
2. **Non-Constant space**

1. Suppose that L1 is a Regular language and L2 is a context-free language. L1 intersection L2 is regular and context-free language.L1.L2 is Regular and context-free if there is no dependency among L1 and L2. L1-L2 is not necessarily  context-free. L1 U L2 is either Regular or Context-free Language.

2. let P be an array containing an integers let t be the lowest upper bound on the number of comparisons of the array elements required to find the minimum and maximum values in arbitrary array of n elements which of the following choices is correct

Tournament Method Problem

3. The sequence of procedure calls corresponds to a pre order
traversal of the activation tree .
4. The sequence of procedure calls corresponds to a post order
traversal of the activation tree .
4. (210)3 =(21)10=(15)6

5. Every SLR(1) grammar is unambiguous but there are certain unambiguous grammars which are not in SLR(1)

6. For already sorted array , Insertion sort does the minimum number of comparisons.

7. If a binary search tree contains 'n' distinct elements , The time complexity of picking an element in T that is smaller than maximum element in T is O(1) keeping the maximum element in the Tree T only in the right subtree and the second largest element in the tree at the root of the tree. 

8. exit() , sleep() functions is the standard C library function that will always invoke a system call when executed from single-threaded process in a UNIX/Linux operating system.

9. Creation of a new file in foo , Renaming of an existing file in foo requires a full scan of foo for successful completion.

10. In an undirected connected plane graph G, there are eight vertices and five faces . The number of edges in G is Eleven to eleven.

11. consider the following grammar (that admits a series of declarations , followed by expressions) and the associated syntax directed translation actions , given as pseudo-code:

P-> D*E*<br>
D->int ID (record that ID.lexeme is of type int)<br>
D->bool ID(record that ID.lexeme  is of type bool)<br>
E->E1+E2<br>
E->!E1<br>
E->ID<br>
 
 The actions can be used to type-check syntactically correct integer variable declarations and integer expression

 12. Code :
 int simpleFunction(int y[], int n ,int x)
 {
    int total=Y[0],loopIndex;
    for (loopIndex=1;loopIndex<=n-1;loopIndex++)
    {
        total=x*total+(y[loopIndex]);
    }
    return total;
 } 
 Let Z be an array of 10 elements with Z[i]=1 for all i such that 0<=i<=9.The value returned by SimpleFunction(Z,10,2) is 1023 

The function takes three arguments, two arrays and one integer. It returns an integer value.

 
Let H be a binary min-heap consisting of n elements implemented as an array. What is the worst-Case time complexity of an optimal algorithm to find the maximum element in H?<br>
Ans : Theta of log N  

Syntax error : Syntax Analyzer 
Lexical environment error: Lexical analyzer
Semantic analysis error: Semantics analyzer
Machine-dependant optimizations: Machine dependent optimizer

# POINTERS:


#include <stdio.h><br>
int main(){
    
int arr[4][5];<br>
int i,j;<br>
for(i=0;i<4;i++)<br>
{
  for (j=0;j<5;j++){
 
 arr[i][j] = 10*i+j;

  }

}

printf("%d",*(arr[1]+9));

return 0;
}
Explanation:

arr[1]+9 = *(arr+1) + 9 //arr is again a pointer but to the 2D array arr[4][5]
 
arr+1 = arr + sizeof(*arr)

      = arr + 5 * sizeof (int)
     
*(arr+1)+9 = arr + 5 * sizeof(int) + sizeof(**arr) * 9

//* operator in *(arr+1) just changes the type of the pointer here
        
        = arr + 5 * sizeof(int) + 9 * sizeof(int)
        
        = arr + 14 * sizeof(int)
        
        14/5=2 and 14%5=4

        ans=10*2+4=24

