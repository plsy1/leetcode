只做了递归解法的，就说一下递归的。   
    
比如给个链表：   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1->2->3   
    
运行此算法的过程是这样的：   
      
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
1->2->3->NULL&nbsp;&nbsp;&nbsp;&nbsp;
1->3->2->NULL&nbsp;&nbsp;&nbsp;&nbsp;
3->2->1->NULL&nbsp;&nbsp;&nbsp;&nbsp;   
    
就是从后往前，挨个的把next与当前node的指向关系对调了。
