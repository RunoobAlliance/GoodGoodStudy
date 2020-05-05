LeetCode98题
https://leetcode-cn.com/problems/validate-binary-search-tree/submissions/
1、题目描述
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

2、思路和算法：递归
要解决这道题首先我们要了解二叉搜索树有什么性质可以给我们利用，由题目给出的信息我们可以知道：如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 
若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；它的左右子树也为二叉搜索树。
这启示我们设计一个递归函数recursion(root, lower, upper) 来递归判断，函数表示考虑以root为根的子树，判断子树中所有节点的值是否都在(l,r)(l,r) 的范围内（注意是开区间）。
如果root节点的值val不在(l,r)(l,r) 的范围内说明不满足条件直接返回，否则我们要继续递归调用检查它的左右子树是否满足，如果都满足才说明这是一棵二叉搜索树。
那么根据二叉搜索树的性质，在递归调用左子树时，我们需要把上界upper改为root.val，即调用recursion(root.left, lower, root.val)，因为左子树里所有节点的值均小于它的根节点的值。
同理递归调用右子树时，我们需要把下界lower改为root.val，即调用recursion(root.right, root.val, upper)。
函数递归调用的入口为recursion(root, -inf, +inf)，inf 表示一个无穷大的值。

3、代码实现
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, null, null);
    }
    private boolean rescure(TreeNode node, Integer lower, Integer upper) {
        if (node == null) {
            return true;
        }
        // 当前节点的值是否在界限内
        if (lower != null && node.val <= lower) return false;
        if (upper != null && node.val >= upper) return false;

        return isValidBST(node.left, lower, node.val) && isValidBST(node.right, node.val, upper);
    }
}
