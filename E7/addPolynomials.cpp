#include<iostream>
using namespace std;
struct Node {
	int coeff;
	int powx;
	int powy;
	struct Node* next;
};

void create_node(int c, int p1, int p2, struct Node** temp)
{
	struct Node* r;
	struct Node* z = *temp;
	r = (struct Node*)malloc(
		sizeof(struct Node));
	r->coeff = c;
	r->powx = p1;
	r->powy = p2;
	if (z == NULL) {
		(*temp) = r;
		(*temp)->next = (*temp);
	}
	else {
		r->next = z->next;
		z->next = r;
		(*temp) = r;
	}
}

void add_poly(struct Node* poly1, struct Node* poly2, struct Node** temp) {
	struct Node* start1 = poly1;
	struct Node* start2 = poly2;
	poly1 = poly1->next;
	poly2 = poly2->next;

	while ((poly1 != start1 && poly2 != start2)) {
		struct Node* r;
		struct Node* z = *temp;
		r = (struct Node*)malloc(sizeof(struct Node));
		r->coeff = 0;

		if (poly1->powx > poly2->powx) {
			r->coeff = poly1->coeff;
			r->powx = poly1->powx;
			r->powy = poly1->powy;
			poly1 = poly1->next;
		}

		else if (poly1->powx < poly2->powx) {
			r->coeff = poly2->coeff;
			r->powx = poly2->powx;
			r->powy = poly2->powy;
			poly2 = poly2->next;
		}

		else {
			if (poly1->powy > poly2->powy) {
				r->coeff = poly1->coeff;
				r->powx = poly1->powx;
				r->powy = poly1->powy;
				poly1 = poly1->next;
			}
			else if (poly1->powy <
				poly2->powy) {
				r->coeff = poly2->coeff;
				r->powx = poly2->powx;
				r->powy = poly2->powy;
				poly2 = poly2->next;
			}
			else {
				r->coeff = poly2->coeff
					+ poly1->coeff;
				r->powx = poly1->powx;
				r->powy = poly1->powy;
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
		}

		if (z == NULL) {
			(*temp) = r;
			(*temp)->next = (*temp);
		}

		else {
			r->next = z->next;
			z->next = r;
			(*temp) = r;
		}
	}
	while (poly1 != start1 || poly2 != start2) {

		if (poly1 != start1) {
			struct Node* r;
			struct Node* z = *temp;
			r = (struct Node*)malloc(
				sizeof(struct Node));
			r->coeff = poly1->coeff;
			r->powx = poly1->powx;
			r->powy = poly1->powy;
			poly1 = poly1->next;
			if (z == NULL) {
				(*temp) = r;
				(*temp)->next = (*temp);
			}
			else {
				r->next = z->next;
				z->next = r;
				(*temp) = r;
			}
		}

		if (poly2 != start2) {
			struct Node* r;
			struct Node* z = *temp;
			r = (struct Node*)malloc(
				sizeof(struct Node));
			z->coeff = poly2->coeff;
			z->powx = poly2->powx;
			z->powy = poly2->powy;
			poly2 = poly2->next;
			if (z == NULL) {
				(*temp) = r;
				(*temp)->next = (*temp);
			}
			else {
				r->next = z->next;
				z->next = r;
				(*temp) = r;
			}
		}
	}

	struct Node* r;
	struct Node* z = *temp;
	r = (struct Node*)malloc(
		sizeof(struct Node));
	r->coeff = 0;

	//Appending Remaining
	if (start1->powx > start2->powx) {
		r->coeff = start1->coeff;
		r->powx = start1->powx;
		r->powy = start1->powy;
	}

	else if (start1->powx < start2->powx) {
		r->coeff = start2->coeff;
		r->powx = start2->powx;
		r->powy = start2->powy;
	}

	else {
		if (start1->powy > start2->powy) {
			r->coeff = start1->coeff;
			r->powx = start1->powx;
			r->powy = start1->powy;
		}
		else if (start1->powy < start2->powy) {
			r->coeff = start2->coeff;
			r->powx = start2->powx;
			r->powy = poly2->powy;
		}
		else {
			r->coeff = start2->coeff
				+ start1->coeff;
			r->powx = start1->powx;
			r->powy = start1->powy;
		}
	}


	if (z == NULL) {
		(*temp) = r;
		(*temp)->next = (*temp);
	}

	else {
		r->next = z->next;
		z->next = r;
		(*temp) = r;
	}
}

void display(struct Node* node)
{
	struct Node* start = node;
	node = node->next;
	while (node != start &&
		node->coeff != 0) {
		std::cout << node->coeff;
		if (node->powx != 0)
			std::cout << "x^" << node->powx;
		if (node->powx != 0 &&
			node->powy != 0)
			std::cout << " * ";
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

	create_node(5, 2, 1, &poly1);
	create_node(4, 1, 2, &poly1);
	create_node(3, 1, 1, &poly1);
	create_node(2, 1, 0, &poly1);
	create_node(3, 0, 1, &poly1);
	create_node(2, 0, 0, &poly1);

	create_node(3, 1, 2, &poly2);
	create_node(4, 1, 0, &poly2);
	create_node(2, 0, 1, &poly2);
	create_node(6, 0, 0, &poly2);
	add_poly(poly1, poly2, &store);
	std::cout << "Polynomial 1"
		<< "\n";
	display(poly1);
	std::cout << "Polynomial 2"
		<< "\n";
	display(poly2);
	std::cout << "Polynomial after addition"
		<< "\n";
	display(store);
	return 0;
}