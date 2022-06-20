}
ListNode* reverseList(ListNode* a) {
if(!a||!a->next)
return a;
ListNode *ans = NULL;
call(a,&ans);
return ans;
}
};
```
​
**3. Itreative, Time- O(N)**
​
```
class Solution {
public:
ListNode* reverseList(ListNode* a) {
if(!a||!a->next)
return a;
ListNode *p = a , *q = a->next , *r = NULL;
while(p)
{
p->next = r;
r = p;
p = q;
if(q)
q=q->next;
}
return r;