
```
// https://www.quora.com/What-is-the-best-deletion-algorithm-for-a-binary-search-tree-without-using-an-additional-parent-node
function deleteNode (head, data) 
   IF head = null THEN 
      return null 
   ELSE IF data < head.data THEN 
      head.left = deleteNode(head.left, data) 
   ELSE IF data > head.data THEN 
      head.right = deleteNode(head.right, data) 
   ELSE // data = head.data 
      IF head.left = null THEN 
         temp = head.right 
         delete(head) // if no garbage collection 
         return temp 
      ELSE IF head.right = null THEN 
         temp = head.left 
         delete(head) // if no garbage collection 
         return temp 
      ELSE // left and right childs definitely exist 
         head.data = findMin(head.right) 
         head.right = deleteNode(head.right, head.data) 
      ENDIF 
   ENDIF 
   return head 
ENDfunction 
```