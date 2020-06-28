#   Linked List<br>
##  Key Differences Between ArrayList and Linked List<br>

|                | Array List                                                                                                                | Linked List |
|----------------|:-------------------------------------------------------------------------------------------------------------------------:|:-----------:|
| get/set access 
| accessing an element (get/set) at an index is O(1);<br>
  for this reason the ArrayList implements the RandomAccess interface 
| accessing an element (get/set) at an index is O(n) because we must proceed through a sequence of node pointers to get to the correct position 
|
| add/remove at first and last positions 
| add at the last position is O(1) in general;<br>
  an additional O(n) cost is incurred when **the array's capacity is increase**;<br>
  if the capacity is maintained efficiently, the overall average cost is still O(1)<br>
  remove at the last position is always O(1)<br>
  add/remove at the first position is always O(n) because the entire array is shifted 
| add/remove at the first or last positions is O(1) (with doubly-linked lists)
| 
| add/remove at arbitrary position
| add/remove at arbitrary position is O(n) due to shifting 
| add/remove at arbitrary position is O(n) due to sequencing through pointers
| 
| space usage 
| wasted space varies according to the number of unused array positions;<br>
  in order to keep average add time efficient, O(n) wasted space must be created at capacity increases	
| the links are "wasted" by virtue of not holding data; thus there is always O(n) wasted space
|

##  Types of Linked Lists<br>
*   [Singly Linked List](./singly)<br>
*   [Circular Linked List](./circular)<br>
*   [Doubly Linked List](./doubly)<br>
