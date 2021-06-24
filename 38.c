#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

typedef struct {
	int data;
	int height; // 높이를 저장해야 시간 복잡도를 보장할 수 있음.
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

int getHeight(Node* node) {
	if (node == NULL) return 0;
	return node->height;
}

// 모든 노드는 회전을 수행한 이후에 높이를 다시 계산
void setHeight(Node* node) {
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

int getDifference(Node* node) {
	if (node == NULL) return 0;
	Node* leftChild = node->leftChild;
	Node* rightChild = node->rightChild;
	return getHeight(leftChild) - getHeight(rightChild);
}



Node* rotateLL(Node* node) {
	Node* leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;
	leftChild->rightChild = node;
	setHeight(node); //회전 이후에 높이를 다시 계산
	return leftChild; //leftChild는 이후에 setHeight() 수행
}

Node* rotateRR(Node* node) {
	Node* rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	rightChild->leftChild = node;
	setHeight(node); //회전 이후에 높이를 다시 계산
	return rightChild; //leftChild는 이후에 setHeight() 수행
}

Node* rotateLR(Node* node) {
	Node* leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	setHeight(node->leftChild); // 회전 이후에 높이를 다시 계산
	return rotateLL(node); //해당 노드는 이후에 setHeight() 수행 

}

Node* rotateRL(Node* node) {
	Node* rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	setHeight(node->rightChild); 
	return rotateRR(node);

}

Node* balance(Node* node) {
	int difference = getDifference(node);
	if (difference >= 2) {
		if (getDifference(node->leftChild) >= 1) {
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		if (getDifference(node->rightChild) <= -1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node); //회전 이후에 높이를 다시 계산
	return node;
}

Node* insertNode(Node* node, int data) {
	if (!node) {
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;
		node->leftChild = node->rightChild = NULL;
	}
	else if (data < node->data) {
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {
		printf("데이터 중복이 발생했습니다.\n");
	}
	return node;
}