**排序链表**

> 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
>
> 示例 1:
>
> ```
> 输入: 4->2->1->3
> 输出: 1->2->3->4
> ```
>
> 示例 2:
>
> ```
> 输入: -1->5->3->4->0
> 输出: -1->0->3->4->5
> ```



**解题思路**

学习数据结构的时候是个人都做过排序两个链表的题目，本题是对一个链表进行排序，把它拆成两个就可以了。

注意到复杂度要求，有什么O(nlgn)时间复杂度且O(1)空间复杂度的排序算法，当然是归并排序。