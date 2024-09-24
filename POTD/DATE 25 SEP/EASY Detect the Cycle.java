public class Solution {
    public static boolean detectCycle(Node<Integer> head) {
        // Write your code here.
        Node<Integer> slow = head;
        Node<Integer> fast = head;
        while(fast != null){
            slow = slow.next;
            if(fast.next == null)return false;
            fast = fast.next.next;
            if(slow == fast)return true;
        }
        return false;
    }
}
