# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        mp={}
        for i,val in enumerate(inorder):
            mp.update({val:i})
        self.pre=0    
        def util(self,preorder,inorder,l,h,mp):
            if l>h:
                return None
            curr=self.pre
            self.pre+=1
            node=TreeNode(preorder[curr])
            if l==h:
                return node
            node.left=util(self,preorder,inorder,l,mp[preorder[curr]]-1,mp)
            node.right=util(self,preorder,inorder,mp[preorder[curr]]+1,h,mp)
            return node
        
        return util(self,preorder,inorder,0,len(inorder)-1,mp)
