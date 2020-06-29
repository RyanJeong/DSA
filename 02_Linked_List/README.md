#   Linked List<br>
> In computer science, a **linked list** is a data structure consisting of a group of nodes which together represent a sequence. Under the simplest form, each node is composed of a datum and a reference (in other words, a link) to the next node in the sequence; more complex variants add additional links. This structure allows for efficient insertion or removal of elements from any position in the sequence.<br>

##  Basic Concepts and Nomewnclature<br>
* Each record of a linked list is often called an **element** or **node**.<br>
* The field of each node that contains the address of the next node is usually called the ** *next* link** or ** *next* pointer**. The remaining fields are known as the **data, information, value, cargo, or payload** fields.<br>
* The **head** of a list is its first node. The **tail** of a list may refer either to the rest of the list after the head, or to the last node in the list. In Lisp and some derived languages, the next node may be called the **cdr** (pronounced could-er) of the list, while the payload of the head node may be called the car.<br>

##  Features<br>
* Is able to grow in size as needed<br>
* Does not require the shifting of items during insertions and deletions<br>

##  Key Differences Between Array List and Linked List<br>

|                | Array List                                                                                                              | Linked List |
|----------------|-------------------------------------------------------------------------------------------------------------------------|-------------|
| get/set access | <ul><li>accessing an element (get/set) at an index is O(1) for this reason the ArrayList implements the RandomAccess interface </li></ul>| <ul><li>accessing an element (get/set) at an index is O(n) because we must proceed through a sequence of node pointers to get to the correct position</li></ul> |
| add/remove at first and last positions | <ul><li>add at the last position is O(1) in general</li><li>an additional O(n) cost is incurred when **the array's capacity is increase**</li><li>if the capacity is maintained efficiently, the overall average cost is still O(1)</li><li>remove at the last position is always O(1)</li><li>add/remove at the first position is always O(n) because the entire array is shifted</li></ul> | <ul><li>add/remove at the first or last positions is O(1)<br>(with doubly-linked lists)</ul></li>| 
| add/remove at arbitrary position| <ul><li>add/remove at arbitrary position is O(n) due to shifting</ul></li> | <ul><li>add/remove at arbitrary position is O(n) due to sequencing through pointers</ul></li>| 
| space usage | <ul><li>wasted space varies according to the number of unused array positions</li><li>in order to keep average add time efficient, O(n) wasted space must be created at capacity increases</ul></li> | <ul><li>the links are "wasted" by virtue of not holding data thus there is always O(n) wasted space</ul></li>|

##  Types of Linked Lists<br>
*   [Singly Linked List](./singly)<br>
*   [Circular Linked List](./circular)<br>
*   [Doubly Linked List](./doubly)<br>
