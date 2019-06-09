#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("[%d] ", root->data);  // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);  // ��� �湮
		preorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		postorder(root->right);// �����ʼ���Ʈ����ȸ
		printf("[%d] ", root->data);  // ��� �湮
	}
}

//����� �� ��ȯ
int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
	{
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}

//�ܸ� ����� ���� ��ȯ
int get_leaf_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
		{
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}
	return count;
}

int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	return height;

}

int main(void)
{
	printf("���� ��ȸ=");
	inorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	preorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	postorder(root);
	printf("\n");

	printf("��� ���� =");
	printf("%d", get_node_count(root));
	printf("\n");
	printf("�ܸ� ��� ���� =");
	printf("%d",get_leaf_count(root));
	printf("\n");
	printf("���� =");
	printf("%d", get_height(root));
	printf("\n");

	return 0;


}