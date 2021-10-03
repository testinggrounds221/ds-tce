#include<iostream>
using namespace std;

struct Node {
	int coeff;
	int powx;
	int powy;
	struct Node* next;
};

void appendLast(int c, int p1, int p2, struct Node** temp)
{
	struct Node* last;
	struct Node* resultLast = *temp;
	last = (struct Node*)malloc(sizeof(struct Node));
	last->coeff = c;
	last->powx = p1;
	last->powy = p2;
	if (resultLast == NULL) {
		(*temp) = last;
		(*temp)->next = (*temp);
	}
	else {
		last->next = resultLast->next;
		resultLast->next = last;
		(*temp) = last;
	}
}

void addPolynomial(struct Node* poly1, struct Node* poly2, struct Node** temp) {
	struct Node* last1 = poly1;
	struct Node* last2 = poly2;
	poly1 = poly1->next;
	poly2 = poly2->next;

	while ((poly1 != last1 && poly2 != last2)) {
		struct Node* newNode;
		struct Node* resultLast = *temp;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->coeff = 0;

		if (poly1->powx > poly2->powx) {
			newNode->coeff = poly1->coeff;
			newNode->powx = poly1->powx;
			newNode->powy = poly1->powy;
			poly1 = poly1->next;
		}

		else if (poly1->powx < poly2->powx) {
			newNode->coeff = poly2->coeff;
			newNode->powx = poly2->powx;
			newNode->powy = poly2->powy;
			poly2 = poly2->next;
		}

		else {
			if (poly1->powy > poly2->powy) {
				newNode->coeff = poly1->coeff;
				newNode->powx = poly1->powx;
				newNode->powy = poly1->powy;
				poly1 = poly1->next;
			}
			else if (poly1->powy <
				poly2->powy) {
				newNode->coeff = poly2->coeff;
				newNode->powx = poly2->powx;
				newNode->powy = poly2->powy;
				poly2 = poly2->next;
			}
			else {
				newNode->coeff = poly2->coeff
					+ poly1->coeff;
				newNode->powx = poly1->powx;
				newNode->powy = poly1->powy;
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
		}

		if (resultLast == NULL) {
			(*temp) = newNode;
			(*temp)->next = (*temp);
		}

		else {
			newNode->next = resultLast->next;
			resultLast->next = newNode;
			(*temp) = newNode;
		}
	}

	//Appending Remaining
	while (poly1 != last1 || poly2 != last2) {

		if (poly1 != last1) {
			struct Node* newNode;
			struct Node* resultLast = *temp;
			newNode = (struct Node*)malloc(
				sizeof(struct Node));
			newNode->coeff = poly1->coeff;
			newNode->powx = poly1->powx;
			newNode->powy = poly1->powy;
			poly1 = poly1->next;
			if (resultLast == NULL) {
				(*temp) = newNode;
				(*temp)->next = (*temp);
			}
			else {
				newNode->next = resultLast->next;
				resultLast->next = newNode;
				(*temp) = newNode;
			}
		}

		if (poly2 != last2) {
			struct Node* newNode;
			struct Node* resultLast = *temp;
			newNode = (struct Node*)malloc(
				sizeof(struct Node));
			resultLast->coeff = poly2->coeff;
			resultLast->powx = poly2->powx;
			resultLast->powy = poly2->powy;
			poly2 = poly2->next;
			if (resultLast == NULL) {
				(*temp) = newNode;
				(*temp)->next = (*temp);
			}
			else {
				newNode->next = resultLast->next;
				resultLast->next = newNode;
				(*temp) = newNode;
			}
		}
	}

	struct Node* newNode;
	struct Node* resultLast = *temp;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->coeff = 0;

	//Last Term and Coefficients
	if (last1->powx > last2->powx) {
		newNode->coeff = last1->coeff;
		newNode->powx = last1->powx;
		newNode->powy = last1->powy;
	}

	else if (last1->powx < last2->powx) {
		newNode->coeff = last2->coeff;
		newNode->powx = last2->powx;
		newNode->powy = last2->powy;
	}

	else {
		if (last1->powy > last2->powy) {
			newNode->coeff = last1->coeff;
			newNode->powx = last1->powx;
			newNode->powy = last1->powy;
		}
		else if (last1->powy < last2->powy) {
			newNode->coeff = last2->coeff;
			newNode->powx = last2->powx;
			newNode->powy = poly2->powy;
		}
		else {
			newNode->coeff = last2->coeff
				+ last1->coeff;
			newNode->powx = last1->powx;
			newNode->powy = last1->powy;
		}
	}


	if (resultLast == NULL) {
		(*temp) = newNode;
		(*temp)->next = (*temp);
	}

	else {
		newNode->next = resultLast->next;
		resultLast->next = newNode;
		(*temp) = newNode;
	}
}

void display(struct Node* node)
{
	struct Node* start = node;
	node = node->next;
	while (node != start && node->coeff != 0) {
		std::cout << node->coeff;
		if (node->powx != 0)
			std::cout << "x^" << node->powx;
		if (node->powx != 0 &&
			node->powy != 0)
			std::cout << "*";
		if (node->powy != 0)
			std::cout << "y^" << node->powy;
		if (node != start &&
			node->next->coeff != 0) {
			std::cout << " + ";
		}
		node = node->next;
	}
	std::cout << node->coeff;
	if (node->powx != 0)
		std::cout << "x^" << node->powx;
	if (node->powy != 0)
		std::cout << "y^" << node->powy;
	std::cout << "\n\n";
}

int main()
{
	struct Node* poly1 = NULL;
	struct Node* poly2 = NULL;
	struct Node* store = NULL;

	appendLast(4, 2, 1, &poly1);
	appendLast(7, 1, 2, &poly1);
	appendLast(3, 1, 1, &poly1);
	appendLast(6, 1, 0, &poly1);
	appendLast(2, 0, 1, &poly1);
	appendLast(1, 0, 0, &poly1);

	appendLast(9, 1, 2, &poly2);
	appendLast(2, 1, 0, &poly2);
	appendLast(7, 0, 1, &poly2);
	appendLast(8, 0, 0, &poly2);

	std::cout << "Polynomial 1" << "\n";
	display(poly1);
	std::cout << "Polynomial 2" << "\n";
	display(poly2);
	std::cout << "Resultant Polynomial" << "\n";
	addPolynomial(poly1, poly2, &store);
	display(store);
	return 0;
}