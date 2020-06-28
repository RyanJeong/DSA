#   Linked List<br>
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
