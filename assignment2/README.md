### Question 2: Disadvantages of “LinkedList extractMax Sorting”
One of the main disadvantages of this method of sorting is that it has a bad running time of O(n^2). It has to Find the largest value in the list which is an O(n) operation and has to run for every element in the list  

Another disadvantage is that it only appears to sort the list but it reality the labs' implementation is just printing out the max elements in sequence. This is not a clear disadvantage however because one can just use the output of extractMax() to create a new sorted linked list  

### Question 3: For the current specification, is it a problem if we perform extractMax to an empty list? What should we do if such thing happens?

if we perform extract max to an empty list, it will throw an error of trying to access a NULL pointer.  

We should have an if condition to return a null pointer if extractMax() is called on an empty list
